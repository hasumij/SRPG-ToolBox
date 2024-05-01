#include "ScriptData.h"

#include <filesystem>
#include <format>
#include <fstream>

#include "ConfigManager.h"
#include "ScriptNames.h"
#include "SectionNames.h"

namespace fs = std::filesystem;

ScriptData::ScriptData(FileReader *pFileReader, const uint32_t idx) :
	DataBase(pFileReader, idx)
{
	m_decrypt = false;
	loadData();
}

ScriptData::ScriptData(const std::wstring &inputFolder, const uint32_t &idx) :
	DataBase(idx)
{
	buildData(inputFolder);
}

void ScriptData::Pack(FileWriter &fileWriter) const
{
	if (m_data.empty())
		return;

	fileWriter.Write<uint32_t>(m_name.size);
	fileWriter.WriteBytesVec(m_name.data);

	for (const MemData<uint32_t> &data : m_data)
	{
		std::vector<uint8_t> dat;

		// Read the file associated with data from disk
		readFromFile(data.fileName, dat);

		fileWriter.Write<uint32_t>(static_cast<uint32_t>(dat.size()));
		fileWriter.WriteBytesVec(dat);
	}
}

uint32_t ScriptData::Size() const
{
	uint32_t size = 0;
	size += 4;           // Name size
	size += m_name.size; // Name data

	for (const MemData<uint32_t> &data : m_data)
		size += (data.size + 2 /* 2-Bytes null-terminator */);

	size += 4; // Material count

	return size;
}

std::wstring ScriptData::buildOutDir(const std::wstring &outputFolder) const
{
	return std::format(L"{}/{}/", outputFolder, getFolderName());
}

void ScriptData::add2Config(const fs::path &file) const
{
	Config.Add2Array(getFolderName(), file.wstring(), {});
}

void ScriptData::write2File(const std::wstring &filePath, const std::vector<uint8_t> &data) const
{
	const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
	std::wofstream file(filePath, std::ios::out | std::ios::binary);

	if (file.fail())
		throw std::runtime_error(std::format("Failed to open file: {}", ws2s(filePath)));

	file.imbue(utf8_locale);

	std::size_t size = data.size();

	if (data.back() == 0x0)
		size -= 2;

	file.write(reinterpret_cast<const wchar_t *>(data.data()), size / 2);
	file.close();
}

void ScriptData::readFromFile(const std::wstring &filePath, std::vector<uint8_t> &data) const
{
	const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
	std::wifstream file(filePath, std::ios::in | std::ios::binary);

	if (file.fail())
		throw std::runtime_error(std::format("Failed to open file: {}", ws2s(filePath)));

	file.imbue(utf8_locale);
	std::wstringstream buffer;
	buffer << file.rdbuf();

	buffer.seekg(0, std::ios::end);
	std::size_t size = buffer.tellg() * 2;
	buffer.seekg(0, std::ios::beg);

	data.resize(size, 0);
	std::memcpy(data.data(), (uint8_t *)buffer.str().c_str(), size);

	data.push_back(0x0);
	data.push_back(0x0);

	file.close();
}

void ScriptData::loadData()
{
	InitMemData<uint32_t>(m_name, *m_pFileReader);

	m_data.push_back(InitMemData<uint32_t>(*m_pFileReader, ~0, false));
}

void ScriptData::buildData(const std::wstring &inputFolder)
{
	nlohmann::ordered_json j = Config.GetNext(SECTION_NAMES[m_idx]);
	if (j.empty())
		j = Config.GetNext("Plugins");

	if (j.empty()) return;

	m_name = s2ws(j["name"].get<std::string>());

	const std::wstring dirPath = std::format(L"{}/{}", inputFolder, getFolderName());

	const std::wstring filePath = std::format(L"{}/{}", dirPath, m_name.ToWString());

	if (!fs::exists(filePath))
		throw std::runtime_error(std::format("File not found: {}", ws2s(filePath)));

	m_data.push_back(MemData<uint32_t>(filePath, static_cast<uint32_t>(getFileSizeUTF16(filePath))));
}

bool ScriptData::isPlugin() const
{
	return (std::find(SCRIPT_NAMES.begin(), SCRIPT_NAMES.end(), m_name.ToWString()) == SCRIPT_NAMES.end());
}

std::wstring ScriptData::getFolderName() const
{
	if (isPlugin()) return L"Plugins";

	return s2ws(SECTION_NAMES[m_idx]);
}
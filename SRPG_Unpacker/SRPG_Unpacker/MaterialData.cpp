#include "MaterialData.h"

#include <filesystem>

#include "ConfigManager.h"
#include "SectionNames.h"

namespace fs = std::filesystem;

MaterialData::MaterialData(FileReader *pFileReader, const uint32_t idx) :
	DataBase(pFileReader, idx)
{
	m_decrypt = false;
	loadData();
}

MaterialData::MaterialData(const std::wstring &inputFolder, const uint32_t &idx) :
	DataBase(idx)
{
	buildData(inputFolder);
}

void MaterialData::Pack(FileWriter &fileWriter) const
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

uint32_t MaterialData::Size() const
{
	uint32_t size = 0;
	size += 4;           // Name size
	size += m_name.size; // Name data

	for (const MemData<uint32_t> &data : m_data)
	{
		size += 4; // Data size
		size += data.size;
	}

	return size;
}

void MaterialData::add2Config(const fs::path &file) const
{
	Config.Add2Array(SECTION_NAMES[m_idx], file.wstring(), {});
}

void MaterialData::loadData()
{
	InitMemData<uint32_t>(m_name, *m_pFileReader);

	m_data.push_back(InitMemData<uint32_t>(*m_pFileReader, ~0, false));
}

void MaterialData::buildData(const std::wstring &inputFolder)
{
	const std::wstring dirPath     = std::format(L"{}/{}", inputFolder, s2ws(SECTION_NAMES[m_idx]));
	const nlohmann::ordered_json j = Config.GetNext(SECTION_NAMES[m_idx]);

	if (j.empty()) return;

	m_name = s2ws(j["name"].get<std::string>());

	const std::wstring filePath = std::format(L"{}/{}", dirPath, m_name.ToWString());

	if (!fs::exists(filePath))
		throw std::runtime_error(std::format("File not found: {}", ws2s(filePath)));

	m_data.push_back(MemData<uint32_t>(filePath, static_cast<uint32_t>(fs::file_size(filePath))));
}
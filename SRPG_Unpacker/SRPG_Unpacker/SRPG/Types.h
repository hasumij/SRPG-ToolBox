#pragma once

enum class SRPGClasses
{
	UNITDATA                 = 0,
	CLASSDATA                = 1,
	WEAPONDATA               = 2,
	ITEMDATA                 = 3,
	SKILLDATA                = 4,
	STATEDATA                = 5,
	CLASSGROUPDATA           = 201,
	CLASSGROUPENTRYDATA      = 202,
	CLASSTYPEDATA            = 200,
	WEAPONTYPEDATA           = 203,
	DIFFICULTYDATA           = 205,
	FONTDATA                 = 207,
	NPCDATA                  = 208,
	RACEDATA                 = 221,
	ORIGINALDATA             = 226,
	MULTICOMMANDDATA         = 227,
	RESTSHOPDATA             = 225,
	QUESTDATA                = 223,
	RESTAREADATA             = 224,
	FACIALDATA               = 209,
	COMPATIBLEDATA           = 210,
	SUPPORTDATA              = 211,
	VARIABLEDATA             = 212,
	CHOICEDATA               = 213,
	SHOPLAYOUT               = 215,
	SHOPDATA                 = 214,
	NEWSKILLDATA             = 216,
	FUSIONDATA               = 218,
	METAMORDATA              = 219,
	ITEMCONVERTDATA          = 220,
	CHARREPLACEDATA          = 222,
	MOVETYPEDATA             = 204,
	TYPEIDDATA               = 2502,
	UNITIDDATA               = 2500,
	CLASSIDDATA              = 2501,
	ANIMEIDDATA              = 2509,
	RPASSDATA                = 2510,
	REWARDDATA               = 2511,
	MOTIONIDDATA             = 2512,
	PAIRKEYDATA              = 2513,
	REFCUTINDATA             = 2514,
	JUMPIDDATA               = 2515,
	PARAMHEADDATA            = 2516,
	GEN_JSDATA               = 2517,
	GEN_EVDATA               = 2518,
	TITLESDATA               = 2519,
	CHANGEINFODATA           = 2520,
	RESDATA                  = 300,
	MEDIADATA                = 301,
	UIRESDATA                = 302,
	INSTALLEDFONTDATA        = 303,
	VIDEODATA                = 304,
	MAPDATA                  = 400,
	PASSDATA                 = 100,
	PASSCHIPDATA             = 101,
	PASSGROUPDATA            = 103,
	TESTMEMBER               = 401,
	ITEMGROUPDATA            = 405,
	STRINGDATA               = 406,
	FORCESORTIEDATA          = 407,
	ANIMEDATA                = 600,
	FRAMELIST                = 601,
	FRAMEDATA                = 602,
	SPRITEDATA               = 603,
	FRAMEORIGINAL            = 604,
	INTEROPANIMEDATA         = 700,
	INTEROPMEDIADATA         = 702,
	INTEROPGRAPHICSDATA      = 701,
	INTEROPUIDATA            = 703,
	INTEROPTEXTUIDATA        = 704,
	INTEROPSCREENDATA        = 705,
	INTEROPSTRINGDATA        = 706,
	GALLERYGROUPDATA         = 805,
	DICTIONARYCONDITION      = 804,
	CHARACTERDATA            = 800,
	WORDDATA                 = 801,
	GALLERYDATA              = 802,
	SOUNDMODEDATA            = 803,
	EVENTDATA                = 500,
	EVENTPAGE                = 501,
	EVENTCOMMAND             = 502,
	VARIABLECONDITIONDATA    = 510,
	ITEMCONDITIONDATA        = 505,
	UNITCONDITIONDATA        = 506,
	MAPPOSDATA               = 508,
	FORCEENTRY               = 507,
	LINEPOSDATA              = 509,
	SWITCHDATA               = 206,
	SWITCHACTIONDATA         = 503,
	EVENTACTIONDATA          = 504,
	REINFORCECONTAINER       = 402,
	REINFORCEDATA            = 403,
	PATTERNDATA              = 404,
	SCRIPTCODEDATA           = 2503,
	MATERIALDATA             = 2504,
	MAPBASE                  = 2505,
	UNITSTATUSDATA           = 2506,
	CHECKDATA                = 2507,
	IMAGEIDDATA              = 2508,
	MAPTREEDATA              = 900,
	DAYNIGHTDATA             = 901,
	MESSAGELAYOUTDATA        = 1000,
	COMMANDLAYOUTDATA        = 1001,
	RESOURCELAYOUTDATA       = 1002,
	TROPHYDATA               = 10000,
	INVENTORYDATA            = 10016,
	TURNSTATEDATA            = 10013,
	DYNAMICUNITEVENT         = 10004,
	EXECUTEREFDATA           = 10005,
	CLEARSAVEDATA            = 10006,
	COMPLETERECOLLECTIONDATA = 10007,
	COMPLETESWITCHDATA       = 10008,
	COMPLETEGRAPHICSDATA     = 10009,
	COMPLETEMEDIADATA        = 10010,
	RENDERPOOLDATA           = 10011,
	FONTGROUPDATA            = 10012,
	BACKLOGDATA              = 10014,
	DECORATIONDATA           = 10017,
	METAMORHISTORY           = 10015,
	MEMDATA                  = 10019,
	MYDECODATA               = 10020,
	OCCUPYDATA               = 10021,
	JIMODATA                 = 10022,
	MOSTRECENTINFO           = 10023
};

enum class Command
{
	MESSAGESHOW          = 0,
	MESSAGEERASE         = 1,
	MESSAGETITLE         = 101,
	MESSAGETEROP         = 2,
	STILLMESSAGE         = 3,
	MESSAGESCROLL        = 100,
	CHOICESHOW           = 103,
	INFOWINDOW           = 102,
	SCREENSCROLL         = 200,
	SCREENEFFECT         = 201,
	SCREENSTATECHANGE    = 202,
	BACKGROUNDCHANGE     = 203,
	SCREENSHAKE          = 204,
	GRAPHICSSHOW         = 400,
	GRAPHICSHIDE         = 401,
	ANIMATIONPLAY        = 402,
	ANIMATIONSTOP        = 403,
	MUSICPLAY            = 300,
	MUSICSTOP            = 301,
	SOUNDPLAY            = 302,
	SOUNDSTOP            = 303,
	MOVEOBJECTSHOW       = 404,
	MOVEOBJECTHIDE       = 405,
	SCENECHANGE          = 500,
	SCRIPTEXECUTE        = 501,
	WAITACTION           = 502,
	SWITCHACTION         = 503,
	VARIABLEACTION       = 504,
	EVENTSKIP            = 505,
	SAVECALL             = 506,
	SYSTEMSETTINGS       = 507,
	ENVIRONMENTACCESS    = 508,
	CONSOLELOG           = 509,
	VIDEOPLAY            = 304,
	OBJECTADJUST         = 510,
	DAICE                = 511,
	UNITAPPEAR           = 1000,
	UNITREMOVE           = 1001,
	UNITMOVE             = 1002,
	UNITASSIGN           = 1003,
	ITEMCHANGE           = 1101,
	GOLDCHANGE           = 1100,
	PARAMATERCHANGE      = 1102,
	SKILLCHANGE          = 1103,
	HPRECOVERY           = 1200,
	EXPERIENCEPLUS       = 1202,
	CLASSCHANGE          = 1203,
	MAPCHIPCHANGE        = 1403,
	MAPSCROLL            = 1404,
	VICTORYMAP           = 1401,
	FORCEBATTLE          = 1301,
	DAMAGEHIT            = 1201,
	LOCATIONFOCUS        = 1402,
	ITEMUSE              = 1300,
	CHAPTERSHOW          = 1400,
	UNITINFOCHANGE       = 1501,
	UNITSTATECHANGE      = 1502,
	MAPINFOCHANGE        = 1503,
	MAPSTATECHANGE       = 1504,
	EVENTSTATECHANGE     = 1500,
	BONUSCHANGE          = 1600,
	TROPHYCHANGE         = 1601,
	RELATIVETURNMEASURE  = 1602,
	ITEMDURABILITYCHANGE = 1603,
	UNITSTATEADDITION    = 1604,
	UNITCAPACITYCHANGE   = 1605,
	UNITSLIDE            = 1606,
	UNITFUSION           = 1607,
	UNITMETAMOR          = 1608,
	UNITALLCOMMAND       = 1609,
	UNITPERFORMANCE      = 1800,
	MAPPOSCHOOSE         = 1700,
	MAPPOSOPERATION      = 1701
};

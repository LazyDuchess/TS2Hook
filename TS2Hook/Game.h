#pragma once
#include "Types.h"
#include "Encoding.h"

int DllExport SwapLot(int lotID, int neighborhoodID);

DllExport char* GetCASLotName();
DllExport char* GetYACASLotName();

void DllExport SetCASLotName(const char* lotName);
void DllExport SetYACASLotName(const char* lotName);

// This is likely NOT it.
class cTSString {
public:
	char* str;
	std::wstring GetWString() {
		return Encoding::UTF8ToWString(std::string(str));
	}
	std::string GetString() {
		return std::string(str);
	}
private:
	virtual void Func();
};



namespace TS {

	enum NeighborhoodType {
		Invalid,
		Main,
		Campus,
		Downtown,
		Suburb,
		Village,
		Lakes,
		Island
	};

	class cTSBehavior {

	};

	// HUGE Todo
	class cEdithObject
	{
	private:
		virtual void Function0();
		virtual void Function1();
		virtual void Function2();
		virtual void Function3();
		virtual void Function4();
		virtual void Function5();
		virtual void Function6();
		virtual void Function7();
		virtual void Function8();
		virtual void Function9();
		virtual void Function10();
		virtual void Function11();
		virtual void Function12();
		virtual void Function13();
		virtual void Function14();
		virtual void Function15();
		virtual void Function16();
		virtual void Function17();
		virtual void Function18();
		virtual void Function19();
		virtual void Function20();
		virtual void Function21();
		virtual void Function22();
		virtual void Function23();
		virtual void Function24();
		virtual void Function25();
		virtual void Function26();
		virtual void Function27();
		virtual void Function28();
		virtual void Function29();
		virtual void Function30();
		virtual void Function31();
		virtual void Function32();
		virtual void Function33();
		virtual void Function34();
		virtual void Function35();
		virtual void Function36();
		virtual void Function37();
		virtual void Function38();
		virtual void Function39();
		virtual void Function40();
		virtual void Function41();
		virtual void Function42();
		virtual void Function43();
		virtual void Function44();
		virtual void Function45();
		virtual void Function46();
	public:
		virtual int GetID();
	private:
		virtual void Function48();
		virtual void Function49();
		virtual void Function50();
		virtual void Function51();
		virtual void Function52();
		virtual void Function53();
		virtual void Function54();
		virtual void Function55();
		virtual void Function56();
		virtual void Function57();
		virtual void Function58();
		virtual void Function59();
		virtual void Function60();
		virtual void Function61();
		virtual void Function62();
		virtual void Function63();
		virtual void Function64();
		virtual void Function65();
		virtual void Function66();
		virtual void Function67();
		virtual void Function68();
		virtual void Function69();
		virtual void Function70();
		virtual void Function71();
		virtual void Function72();
		virtual void Function73();
		virtual void Function74();
		virtual void Function75();
		virtual void Function76();
		virtual void Function77();
		virtual void Function78();
		virtual void Function79();
		virtual void Function80();
		virtual void Function81();
		virtual void Function82();
		virtual void Function83();
		virtual void Function84();
		virtual void Function85();
		virtual void Function86();
		virtual void Function87();
		virtual void Function88();
	public:
		virtual cTSBehavior* GetBehavior();
	private:
		virtual void Function90();
		virtual void Function91();
		virtual void Function92();
		virtual void Function93();
		virtual void Function94();
		virtual void Function95();
		virtual void Function96();
		virtual void Function97();
		virtual void Function98();
		virtual void Function99();
		virtual void Function100();
		virtual void Function101();
		virtual void Function102();
		virtual void Function103();
		virtual void Function104();
		virtual void Function105();
		virtual void Function106();
		virtual void Function107();
		virtual void Function108();
		virtual void Function109();
		virtual void Function110();
		virtual void Function111();
		virtual void Function112();
		virtual void Function113();
		virtual void Function114();
		virtual void Function115();
		virtual void Function116();
		virtual void Function117();
		virtual void Function118();
		virtual void Function119();
		virtual void Function120();
		virtual void Function121();
		virtual void Function122();
		virtual void Function123();
		virtual void Function124();
		virtual void Function125();
		virtual void Function126();
		virtual void Function127();
		virtual void Function128();
		virtual void Function129();
		virtual void Function130();
		virtual void Function131();
		virtual void Function132();
		virtual void Function133();
		virtual void Function134();
		virtual void Function135();
		virtual void Function136();
		virtual void Function137();
		virtual void Function138();
		virtual void Function139();
		virtual void Function140();
		virtual void Function141();
		virtual void Function142();
		virtual void Function143();
		virtual void Function144();
		virtual void Function145();
		virtual void Function146();
		virtual void Function147();
		virtual void Function148();
		virtual void Function149();
		virtual void Function150();
		virtual void Function151();
		virtual void Function152();
		virtual void Function153();
		virtual void Function154();
		virtual void Function155();
		virtual void Function156();
		virtual void Function157();
		virtual void Function158();
		virtual void Function159();
		virtual void Function160();
		virtual void Function161();
		virtual void Function162();
		virtual void Function163();
		virtual void Function164();
		virtual void Function165();
		virtual void Function166();
		virtual void Function167();
		virtual void Function168();
		virtual void Function169();
		virtual void Function170();
		virtual void Function171();
		virtual void Function172();
		virtual void Function173();
		virtual void Function174();
		virtual void Function175();
		virtual void Function176();
		virtual void Function177();
		virtual void Function178();
		virtual void Function179();
		virtual void Function180();
		virtual void Function181();
		virtual void Function182();
		virtual void Function183();
		virtual void Function184();
		virtual void Function185();
		virtual void Function186();
		virtual void Function187();
		virtual void Function188();
		virtual void Function189();
		virtual void Function190();
		virtual void Function191();
		virtual void Function192();
		virtual void Function193();
		virtual void Function194();
		virtual void Function195();
		virtual void Function196();
		virtual void Function197();
		virtual void Function198();
		virtual void Function199();
		virtual void Function200();
		virtual void Function201();
		virtual void Function202();
		virtual void Function203();
		virtual void Function204();
		virtual void Function205();
		virtual void Function206();
		virtual void Function207();
		virtual void Function208();
		virtual void Function209();
		virtual void Function210();
		virtual void Function211();
		virtual void Function212();
		virtual void Function213();
		virtual void Function214();
		virtual void Function215();
		virtual void Function216();
		virtual void Function217();
		virtual void Function218();
		virtual void Function219();
		virtual void Function220();
		virtual void Function221();
		virtual void Function222();
		virtual void Function223();
		virtual void Function224();
		virtual void Function225();
		virtual void Function226();
		virtual void Function227();
		virtual void Function228();
		virtual void Function229();
		virtual void Function230();
		virtual void Function231();
		virtual void Function232();
		virtual void Function233();
		virtual void Function234();
		virtual void Function235();
		virtual void Function236();
		virtual void Function237();
		virtual void Function238();
		virtual void Function239();
		virtual void Function240();
	public:
		virtual bool RunTree(cTSBehavior* behavior, int objectID, char* behaviorName, int arg1, int arg2, int arg3, int arg4);
	}; //Size: 0x0004

	class cTSPerson {
	private:
		// TODO
		virtual void QueryInterface();
		virtual void AddRef();
		virtual void Release();
		virtual void fn1();
		virtual void fn2();
		virtual void fn3();
		virtual void fn4();
		virtual void fn5();
	public:
		// I'm not sure...
		virtual cEdithObject* AsEdithObject();
	};

	class cEdithObjectModule {
	private:
		// TODO
		virtual void QueryInterface();
		virtual void AddRef();
		virtual void Release();
		virtual void Init();
		virtual void Shutdown();
		virtual void Save();
		virtual void Load();
		virtual void SplitLoad();
		virtual void UpdateSimObjects();
		virtual void InitForNewLot();
		virtual void PostLoad();
		virtual void AggregateAdd();
		virtual void AggregateFind();
		virtual void AggregateRemove();
		virtual void AddObject();
		virtual void ConstructObject();
		virtual void MakeNewOutOfWorldObject();
		virtual void KillObject();
		virtual void AddToKillQueue();
		virtual void AddToKillQueueWhenNoLongerInUseQueue();
		virtual void KillObjectsInvalidatedByResize();
		virtual void FlushKillQueue();
		virtual void HasObjectWithSelector();
		virtual void AddObjectsWithSelectorToKillQueue();
	public:
		virtual void DeleteAllObjects();
	private:
		virtual void PostSim();
		virtual void MinuteChanged();
		virtual void HourChanged();
		virtual void DayChanged();
		virtual void GetObjectFromID();
		virtual void GetValidatedObjectFromID();
		virtual void GetObjectList();
		virtual void GetFunctionalObjects();
		virtual void GetObjects();
		virtual void GetInstances();
		virtual void UpdateSelectablePeople();
		virtual void IsSelectableSimAwakeVisibleAndInWorld();
		virtual void ShouldLiveModeStop();
		virtual void InCASLot();
	public:
		virtual cTSPerson* GetSelectedPerson();
	};

	class cTSSimSystem {

	};

	DllExport cTSSimSystem* SimSystem();

	// Not finished
	class cTSCheatParser {
	public:
		void ExecuteCommand(char* command) {
			typedef void func(cTSCheatParser*, char*);
			return ((func*)0x00b211b0)(this, command);
		};
	};

	class cCheatCommand {
	private:
		int unk1 = 0;
		int unk2 = 0;
		virtual void* QueryInterface(int unk, void** unk2) {
			typedef void* __stdcall func(int, void**);
			return ((func*)0x0043731f)(unk, unk2);
		}
		virtual void AddRef() {
			typedef void __stdcall func();
			return ((func*)0x00437348)();
		}
		virtual int Release() {
			typedef int __stdcall func();
			return ((func*)0x0043734f)();
		}
	public:
		virtual void OnRegister(void* parser, void* state) {
			typedef void __stdcall func(void*, void*);
			return ((func*)0x00437361)(parser, state);
		}
		virtual void Execute(void* arguments) {

		}
		virtual const char* Name() {
			return "\0";
		}
		virtual const char* Description(void* commandHelpType) {
			return "\0";
		}
		virtual int HandlesAllArguments() {
			return 0;
		}
		virtual int GetConditionalLevelAdjustment() {
			return 0;
		}
		virtual void Free(char unknown) {
			delete this;
		}
	};

	class cTSCheatSystem {
	private:
		virtual void Queryinterface();
		virtual void AddRef();
		virtual void Release();
	public:
		virtual cTSCheatParser* AsParser();
		virtual void RegisterCheat(cCheatCommand* command);
	};

	DllExport cTSCheatSystem* CheatSystem();

	class cTSNeighborhoodInfo {
		//TODO
	private:
		virtual void QueryInterface();
		virtual void AddRef();
		virtual void Release();
		virtual void SetName();
		virtual void Name();
		virtual void SetDescription();
		virtual void Description();
		virtual void SetGroupPrefix();
		virtual void GroupPrefix();
		virtual void SetOriginalGroupPrefix();
		virtual void OriginalGroupPrefix();
		virtual void SetID();
		virtual void ID();
		virtual void SetFlag();
		virtual void Flag();
		virtual void IsEqual();
		virtual void IsEqual2();
	public:
		virtual void SetNeighborhoodType(NeighborhoodType type);
		virtual NeighborhoodType NeighborhoodType();
	private:
		virtual void SetTime();
		virtual void NeighborhoodTime();
	};

	class cTSNeighborhood {
	private:
		// TODO
		virtual void Queryinterface();
		virtual void AddRef();
		virtual void Release();
		virtual void Write();
		virtual void Read();
		virtual void GetGZCLSID();
		virtual void Init();
		virtual void Shutdown();
		virtual void Save();
		virtual void IsStoryAlbumInLocalSpace();
		virtual void MarkStoryAlbumIsInLocalSpace();
	public:
		// Check these.
		virtual cTSNeighborhood* GetPrimaryNeighborhood();
		virtual void SetPrimaryNeighborhood(cTSNeighborhood* primaryNeighborhood);
		// TODO
	private:
		virtual void GetNeighborhoodGroupData();
		virtual void SetNeighborhoodGroupData();
		virtual cTSNeighborhoodInfo* GetNeighborhoodInfo();
		virtual void AsIGZPersistResource();
		virtual void SetupFamilyFirstDay();
		virtual void LoadLotInfos();
		virtual void UnloadLotInfos();
		virtual void SaveLotInfos();
		virtual void CleanupLotReferences();
		virtual void SaveLotInfo();
		virtual void GetLotFileInfo();
		virtual void GetNeighborhoodVar();
		virtual void SetNeighborhoodVar();
		virtual void UpdateInstanceVisitorTypes();
		virtual void PrepareAndTestLot();
	};

	class cTSGlobals {
	private:
		char pad[28];
		void* Simulator;
		char pad2[12];
		cTSNeighborhood* Neighborhood;

		// TODO
		virtual void QueryInterface();
		virtual void AddRef();
		virtual void Release();
		virtual void* GetSimulator();
		virtual void GetWantSimulator();
		virtual void GetMemorySimulator();
		virtual cTSNeighborhood* GetNeighborhood();
		virtual void GetNeighborhoodGroupData();
		virtual void NeighborhoodManager();
		virtual void FamilyManager();
		virtual void NeighborManager();
		virtual void NeighborhoodTerrain();
		virtual void NeighborhoodOccupantManager();
		virtual void GetLot();
		virtual void GetLotCatalog();
		virtual void GetUIBridge();
		virtual void GetCatalog();
		virtual void GetGameWideInventory();
		virtual void GetRouteManager();
		virtual void GetAttractionManager();
		virtual void GetEnvironmentScoreManager();
		virtual void ConfigurationManager();
		virtual void ConfigurationChangeManager();
		virtual void GameStateController();
		virtual void ObjectFolder();
		virtual void TypeAttributes();
	public:
		virtual cEdithObjectModule* ObjectManager();
	};

	DllExport cTSGlobals* Globals();

	class cTSLotInfo {
	private:
		// TODO - very different from MAC, likely very inaccurate.
		virtual void QueryInterface();
		virtual void AddRef();
		virtual void Release();
		//virtual void Destructor1();
		virtual void Destructor2();
		virtual void RemoveRef();
		virtual void RefCount();
		virtual void SetBaseLotInfo();
		virtual void GetBaseLotInfo();
		virtual void Clone();

	public:
		// Probs done?
		virtual void SetLocation(int x, int y);
		virtual void GetLocation(int* x, int* y);
		virtual void GetCurrentSize(int* x, int* y);

	private:
		// TODO
		virtual void GetBoundingRect();
		virtual void GetBoundingRectExcludingRoads();
		virtual void GetBoundingRectForRoads();

		// Not actually sure what's in here
		virtual void SetLotGroupName(char* name);
		//virtual void SetLotGroupName(cRZString* name);
		//virtual char* LotGroupName();

	public:
		// TODO
		virtual float NhoodToLotHeightOffset();
		virtual void SetNHoodToLotHeightOffset(float offset);
		virtual int LotID();
		virtual cTSString* LotName();
		virtual void SetLotID(int lotId);
	};

	class cTSGameStateController {
	private:
		// TODO - Also check the NonConst stuff.
		virtual void QueryInterface();
		virtual void AddRef();
		virtual void Release();
		virtual void Init();
		virtual void Shutdown();
		virtual void CurrentState();
	public:
		virtual cTSNeighborhoodInfo* CurrentNeighborhoodInfo();
	private:
		virtual void CurrentNeighborhoodInfoNonConst();
		virtual void NextNeighborhoodInfo();
	public:
		virtual cTSLotInfo* CurrentLotInfo();
		virtual cTSLotInfo* CurrentLotInfoNonConst();
	private:
		virtual void GetCurrentLotGroupID();
		virtual void GetCurrentLotID();
	public:
		virtual cTSLotInfo* NextLotInfo();
	private:
		virtual void CurrentFamily();
		virtual void FamilyIDToMoveIn();
		virtual void CurrentFamilyNonConst();
		virtual void LastNeighborhoodInfo();
		// DONE
	public:
		virtual bool InCommunityLot();
		virtual bool InCASLot();
		virtual bool InSecretLot();
		virtual bool InHotelLot();
		virtual bool IsTransitionInProgress();
		virtual void SetTransitionInProgress(bool inProgress);
		virtual bool TransitionsEnabled();
		virtual bool SaveLotEnabled();
	};

	DllExport cTSGameStateController* GameStateController();
}
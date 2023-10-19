#pragma once
#include "Types.h"
#include "Core.h"
#include "CommandParser.h"
#include <vector>

int DllExport SwapLot(int lotID, int neighborhoodID);

DllExport char* GetCASLotName();
DllExport char* GetYACASLotName();

void DllExport SetCASLotName(const char* lotName);
void DllExport SetYACASLotName(const char* lotName);

namespace TS {
	enum class InteractionType {
		Blocking = -1,
		Immediate = -2
	};

	enum class NeighborhoodType {
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

	class cTSObjectSelector : public cIGZUnknown {
	private:
		//virtual void fn0();
		//virtual void fn1();
		//virtual void fn2();
	public:
		virtual void SaveDefinition();
	private:
		virtual void GetDefinition();
		virtual void SetDefinition();
		virtual void SetDefID(short id);
	public:
		virtual bool GetObjectName(cIGZString* str);
		virtual char* GetObjectNameChar();
		virtual void SetObjectName(const char* name);
		virtual void SetObjectNameField(const char* name);
	private:
		virtual void fn11();
		virtual void fn12();
		virtual void fn13();
		virtual void fn14();
		virtual void fn15();
		virtual void fn16();
		virtual void fn17();
		virtual void fn18();
		virtual void fn19();
		virtual void fn20();
		virtual void fn21();
		virtual void fn22();
		virtual void fn23();
		virtual void fn24();
		virtual void fn25();
		virtual void fn26();
		virtual void fn27();
	public:
		virtual int GetGUID();
	private:
		virtual void fn29();
		virtual void fn30();
		virtual void fn31();
		virtual void fn32();
		virtual void fn33();
		virtual void fn34();
		virtual void fn35();
		virtual void fn36();
		virtual void fn37();
		virtual void fn38();
		virtual void fn39();
		virtual void fn40();
		virtual void fn41();
		virtual void fn42();
		virtual void fn43();
		virtual void fn44();
		virtual void fn45();
		virtual void fn46();
		virtual void fn47();
		virtual void fn48();
	public:
		// First Name
		virtual void GetCatalogName(cRZString* str);
		// idk
		virtual void GetCatalogSecondaryName(cRZString* str);
		// uuh
		virtual void GetCatalogDescription(cRZString* str);
	private:
		virtual void fn52();
		virtual void fn53();
		virtual void fn54();
		virtual void fn55();
		virtual void fn56();
		virtual void fn57();
		virtual void fn58();
		virtual void fn59();
		virtual void fn60();
		virtual void fn61();
		virtual void fn62();
		virtual void fn63();
		virtual void fn64();
		virtual void fn65();
	public:
		virtual int GetGroupID();
		virtual int GetFile();
	private:
		virtual void fn68();
	public:
		virtual int GetChildGroupId_SemiGlobal();
	private:
		virtual void fn70();
		virtual void fn71();
		virtual void fn72();
		virtual void fn73();
		virtual void fn74();
		virtual void fn75();
		virtual void fn76();
		virtual void fn77();
		virtual void fn78();
		virtual void fn79();
		virtual void fn80();
		virtual void fn91();
		virtual void fn92();
		virtual void fn93();
		virtual void fn94();
		virtual void fn95();
		virtual void fn96();
		virtual void fn97();
		virtual void fn98();
		virtual void fn99();
		virtual void fn100();
	};

	// HUGE Todo
	class cTSObject : public cIGZUnknown
	{
	private:
		//virtual void Function0();
		//virtual void Function1();
		//virtual void Function2();
		virtual void Function3();
		virtual void Function4();
		virtual void Function5();
		virtual void Function6();
		virtual void Function7();
	public:
		virtual cTSObject* AscTSTreeSim();
	private:
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
	public:
		virtual short GetTemp(short tempID);
		virtual void SetTemp(short tempID, short value);
	private:
		virtual void Function21();
		virtual void Function22();
		virtual void Function23();
		virtual void Function24();
	public:
		virtual bool GetMiscFlag(int flag);
	private:
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
		virtual short GetID();
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
	public:
		virtual cTSObjectSelector* GetSelector();
	private:
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
	public:
		virtual char* GetName();
	private:
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
	public:
			virtual void Reset(int unk1 = 0, int unk2 = 0, int unk3 = 0, int unk4 = 0);
	private:
		virtual void Function202();
		virtual void Function203();
	public:
		virtual void Cleanup(cTSObject* unk1 = 0, int unk2 = 0);
	private:
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
	public:
		virtual bool RunTree(cTSBehavior* behavior, short objectID, short treeID, short param1 = 0, short param2 = 0, short param3 = 0, short param4 = 0);
		// Runs a tree immediately by its BHAV name, in Private -> Semiglobal -> Global scopes. Not sure about the args.
		virtual bool RunTreeByName(cTSBehavior* behavior, short objectID, const char* behaviorName, short param1 = 0, short param2 = 0, short param3 = 0, short param4 = 0);
	}; //Size: 0x0004

	class cTSInteraction : public cIGZUnknown {
	private:
		int pad0;
		short pad1;
		short pad2;
		short pad3;
		short StackObjectID;
		short StackObjectID2; // use settargetobject for this better?
	private:
		//virtual void fn0();
		//virtual void fn1();
		//virtual void fn2();
		virtual void fn3();
		virtual void fn4();
		virtual void fn5();
		virtual void fn6();
		virtual void fn7();
		virtual void fn8();
		virtual void fn9();
		virtual void fn10();
		virtual void fn11();
		virtual void fn12();
		virtual void fn13();
		virtual void fn14();
		virtual void fn15();
		virtual void fn16();
		virtual void fn17();
		virtual void fn18();
		virtual void fn19();
		virtual void fn20();
		virtual void fn21();
		virtual void fn22();
		virtual void fn23();
		virtual void fn24();
		virtual void fn25();
		virtual void fn26();
	public:
		// Provide 4 parameters to pass to the interaction.
		virtual void SetStackVars(short vars[]);
	private:
		virtual void fn28();
		virtual void fn29();
		virtual void fn30();
		virtual void fn31();
		virtual void fn32();
		virtual void fn33();
		virtual void fn34();
		virtual void fn35();
		virtual void fn36();
		virtual void fn37();
		virtual void fn38();
		virtual void fn39();
		virtual void fn40();
		virtual void fn41();
		virtual void fn42();
		virtual void fn43();
		virtual void fn44();
		virtual void fn45();
		virtual void fn46();
		virtual void fn47();
		virtual void fn48();
		virtual void fn49();
		virtual void fn50();
		virtual void fn51();
		virtual void fn52();
		virtual void fn53();
		virtual void fn54();
		virtual void fn55();
		virtual void fn56();
		virtual void fn57();
		virtual void fn58();
		virtual void fn59();
		virtual void fn60();
		virtual void fn61();
		virtual void fn62();
		virtual void fn63();
		virtual void fn64();
	public:
		virtual void SetTargetObject(cTSObject* targetObject);
	private:
		virtual void fn66();
		virtual void fn67();
		virtual void fn68();
		virtual void fn69();
	};

	class cTSPerson : public cIGZUnknown {
	private:
		//virtual void Function0();
		//virtual void Function1();
		//virtual void Function2();
		virtual void Function3();
		virtual void Function4();
		virtual void Function5();
		virtual void Function6();
		virtual void Function7();
	public:
		virtual cTSObject* AsEdithObject();
	};

	/*
	class cTSPerson : public cIGZUnknown {
	private:
		// TODO
		virtual void fn1();
		virtual void fn2();
		virtual void fn3();
		virtual void fn4();
		virtual void fn5();
	public:
		// I'm not sure...
		virtual cTSObject* AsTSObject();
		virtual cTSObject* AsEdithObject();
	};*/

	class cEdithObjectModule : public cIGZUnknown {
	private:
		// TODO
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
	public:
		virtual void KillObject(short objectID);
		virtual void AddToKillQueue(short objectID);
	private:
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
	public:
		virtual cTSObject* GetObjectFromID(short objectID);
		virtual cTSObject* GetValidatedObjectFromID(short objectID);
		// I wonder why they're using a linked list for this.
		virtual LinkedList<cTSObject>* GetObjectList();
	private:
		virtual std::vector<cTSObject*>* GetFunctionalObjects();
	public:
		virtual std::vector<cTSObject*>* GetObjects();
	private:
		virtual void GetInstances();
		virtual void UpdateSelectablePeople();
		virtual void IsSelectableSimAwakeVisibleAndInWorld();
		virtual void ShouldLiveModeStop();
	public:
		virtual bool InCASLot();
		virtual cTSPerson* GetSelectedPerson();
		virtual void SetSelectedPerson(cTSPerson* person);
		virtual void AdvanceSelectedPerson();
	public:
		// TODO
		virtual cTSObject* GetObjectByGUID(int guid);
		virtual cTSPerson* GetPersonByGUID(int guid);
		// I believe this is inaccurate, it returns the current capacity of the object list, not the amount, which is usually higher and grows to avoid heap allocs.
		virtual int GetObjectCount();
		virtual std::vector<cTSPerson*>* GetSims();
		virtual std::vector<cTSPerson*>* GetSelectableSims();
	};

	class cTSSimSystem {

	};

	DllExport cTSSimSystem* SimSystem();

	// Not finished
	class cTSCheatParser {
	public:
		void ExecuteCommand(const char* command) {
			typedef void func(cTSCheatParser*, const char*);
			return ((func*)0x00b211b0)(this, command);
		};
	};

	class cCheatCommand : public cIGZUnknown {
	private:
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
		virtual void Execute(nGZCommandParser::cArguments* arguments) {

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

	class cTSCheatSystem : public cIGZUnknown {
	public:
		virtual cTSCheatParser* AsParser();
		virtual void RegisterCheat(cCheatCommand* command);
	};

	DllExport cTSCheatSystem* CheatSystem();

	class cTSNeighborhoodInfo : public cIGZUnknown {
		//TODO
	private:
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

	class cTSNeighborhood : public cIGZUnknown {
	private:
		// TODO
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

	class cTSSimulator : public cIGZUnknown {
	private:
		//char pad[20];
		//short global0;
		//short global1;
		//short ZoomLevel;
		//virtual void fn0();
		//virtual void fn1();
		//virtual void fn2();
		virtual void fn3();
		virtual void Read();
		virtual void fn5();
		virtual void fn6();
		virtual void fn7();
		virtual void fn8();
		virtual void fn9();
		virtual void fn10();
		virtual void fn11();
		virtual void fn12();
		virtual void fn13();
		virtual void fn14();
	public:
		virtual short GetGlobal(short id);
		virtual void SetGlobal(short id, short value);
	private:
		virtual void fn17();
	public:
		virtual int GetTicks();
	private:
		virtual void fn19();
	public:
		virtual void SetSpeed(short speed, bool message = true);
		virtual short GetSpeed();
	private:
		virtual void fn22();
		virtual void fn23();
	public:
		virtual void Pause(bool message = true);
		virtual void Resume(bool message = true);
		virtual bool IsPaused();
		virtual short GetMode();
		virtual short SetMode(short mode, short subMode);
		virtual int GetFunds();
		virtual void SetFunds(int funds);
	};

	class cTSNeighbor : public cIGZUnknown {
	private:
		//virtual void fn0();
		//virtual void fn1();
		//virtual void fn2();
		virtual void fn3();
		virtual void fn4();
		virtual void fn5();
		virtual void fn6();
		virtual void fn7();
	public:
		virtual short GetID();
	private:
		virtual void fn9(); //GetID again.
	public:
		virtual cTSObjectSelector* GetSelector();
	};

	class cTSNeighborManager : public cIGZUnknown {
	private:
		//virtual void fn0();
		//virtual void fn1();
		//virtual void fn2();
		virtual void fn3();
		virtual void fn4();
		virtual void fn5();
		virtual void fn6();
		virtual void fn7();
		virtual void fn8();
		virtual void fn9();
		virtual void fn10();
		virtual void fn11();
		virtual void fn12();
		virtual void fn13();
		virtual void fn14();
		virtual void fn15();
	public:
		virtual cTSNeighbor* FindNeighborByID(int id, bool unk = true);
		virtual cTSNeighbor* FindNeighborByGUID(int guid);
	private:
		virtual void fn18();
		virtual void fn19();
		virtual void fn20();
	public:
		virtual void DeleteCharacter(cTSNeighbor* character);
	private:
		virtual void fn22();
		virtual void fn23();
		virtual void fn24();
		virtual void fn25();
		virtual void fn26();
		virtual void fn27();
		virtual void fn28();
		virtual void fn29();
		virtual void fn30();
		virtual void fn31();
		virtual void fn32();
		virtual void fn33();
		virtual void fn34();
		virtual void fn35();
		virtual void fn36();
		virtual void fn37();
		virtual void fn38();
		virtual void fn39();
	};

	class cTSGlobals : public cIGZUnknown {
	private:
		char pad[28];
		cTSSimulator* Simulator;
		char pad2[12];
		cTSNeighborhood* Neighborhood;

		// QueryInterface
		// AddRef
		// Release
		// TODO
	public:
		virtual cTSSimulator* GetSimulator();
	private:
		virtual void GetWantSimulator();
		virtual void GetMemorySimulator();
		virtual cTSNeighborhood* GetNeighborhood();
		virtual void GetNeighborhoodGroupData();
		virtual void NeighborhoodManager();
		virtual void FamilyManager();
	public:
		virtual cTSNeighborManager* NeighborManager();
	private:
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
	private:
		virtual void fn27();
		virtual void fn28();
		virtual void fn29();
		virtual void fn30();
	public:
		virtual bool TestingCheatsEnabled();
		virtual bool TextDebuggingEnabled();
	};

	DllExport cTSGlobals* Globals();

	class cTSLotInfo : public cIGZUnknown {
	private:
		// TODO - very different from MAC, likely very inaccurate.
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
		virtual cRZString* LotName();
		virtual void SetLotID(int lotId);
	};

	class cTSGameStateController : public cIGZUnknown {
	public:
		DllExport void FlipUI(int ui, int unk = 0, int unk2 = 0);
	private:
		// TODO - Also check the NonConst stuff.
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

	class cEdithObjectTestSim {
	private:
		virtual void placeholder(); // to have vtable at 0 addr.
	public:
		int unk;
		// Sim testing.
		cTSPerson* person;
		// Target object.
		cTSObject* object;
	};

	enum class DialogType {
		Ok,
		OkCancel,
		RetryCancel,
		YesNo,
		YesNoCancel,
		AbortRetryIgnore,
		DriveWalkCancel,
		DriveFlyCancel
	};

	enum class DialogResult {
		Ok = 0x5301814A,
		Yes = 0x5301814C,
		No = 0x53018149,
		Cancel = 0x53018147,
		Retry = 0x5301814B,
		Abort = 0x53018146,
		Ignore = 0x53018148
	};

	class cTSMainToolbar : public cIGZUnknown {
	private:
		//virtual void fn0();
		//virtual void fn1();
		//virtual void fn2();
		virtual void Init();
	public:
		virtual void MarkDirty();
		virtual bool Dirty();
		virtual bool ImposterDirty();
	private:
		virtual void Save();
		virtual void Load();
	public:
		virtual void InitForNewLot();
	private:
		virtual void fn10();
		virtual void fn11();
		virtual void SetViewWindow();
		virtual void GetViewWindow();
		virtual void fn14();
		virtual void fn15();
		virtual void SetSimulatorSpeed();
		virtual void GetSimulatorSpeed();
		virtual void fn18();
		virtual void fn19();
		virtual void fn20();
		virtual void fn21();
		virtual void fn22();
		virtual void fn23();
		virtual void fn24();
		virtual void fn25();
		virtual void fn26();
		virtual void fn27();
		virtual void fn28();
		virtual void fn29();
		virtual void fn30();
		virtual void fn31();
		virtual void fn32();
		virtual void fn33();
		virtual void fn34();
		virtual void fn35();
		virtual void fn36();
		virtual void fn37();
		virtual void fn38();
		virtual void fn39();
		virtual void fn40();
		virtual void fn41();
		virtual void fn42();
		virtual void fn43();
		virtual void fn44();
		virtual void fn45();
		virtual void fn46();
		virtual void fn47();
		virtual void fn48();
		virtual void fn49();
		virtual void fn50();
		virtual void fn51();
		virtual void fn52();
		virtual void fn53();
		virtual void fn54();
		virtual void fn55();
		virtual void fn56();
	public:
		virtual bool ShouldSnapObjectsToGrid();
		virtual int QuarterTileFloorPatternMode();
	private:
		virtual void SetIndividualRoofSlopeMode();
		virtual void IndividualRoofSlopeMode();
		virtual void SelectBuyModeTool();
		virtual void PurchaseObject();
		virtual void SetWholesaleMode();
		virtual void WholesaleMode();
		virtual void LastOpenedWholesaleMode();
		virtual void CurrentPriceParam();
		virtual void SetCurrentPriceParam();
		virtual void ChangePriceParam();
	public:
		virtual void CycleTimeOfDay();
	private:
		virtual void fn70();
		virtual void GetIsTopDownView();
		virtual void SetTopDownView();
		virtual void GetIsCeilingView();
		virtual void fn74();
		virtual void SelectNeighborhoodTool();
		virtual void LevelAndPositionAtGameWindowPoint();
		virtual void ReinitializeToolSystem();
		virtual void AddDefaultTools();
		virtual void RemoveDefaultTools();
		virtual void ViewMin();
		virtual void DoSimsModalDialog();
	public:
		virtual DialogResult MessageDialog(cIGZString* body, cIGZString* title, DialogType type = DialogType::Ok, int unk2 = 0, int unk3 = 0);
	};

	DllExport cTSMainToolbar* MainToolbar();

	DllExport cTSGameStateController* GameStateController();

	void DllExport AddCheatInteraction(std::vector<cTSInteraction*>* interactions, cTSPerson* person, cTSObject* object, InteractionType immediate, short flags, const char* name, short instanceId);

	DllExport cRZLanguageManager* LanguageManager();
}
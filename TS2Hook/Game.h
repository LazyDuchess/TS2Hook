#pragma once
int SwapLot(int lotID, int neighborhoodID)
{
	typedef int t_swaplot(int, int);
	return ((t_swaplot*)0x0093c710)(lotID, neighborhoodID);
}

// This is likely NOT it.
class cTSString {
public:
	char* str;
	virtual void Func();
};

namespace TS {

	// Temporary.
	class cTSCheatParser {
	public:
		void ExecuteCommand(char* command) {
			typedef void func(cTSCheatParser*, char*);
			return ((func*)0x00b211b0)(this, command);
		};
	};

	class cTSCheatSystem {
	private:
		virtual void Queryinterface();
		virtual void AddRef();
		virtual void Release();
	public:
		virtual cTSCheatParser* AsParser();
	};

	cTSCheatSystem* CheatSystem()
	{
		typedef cTSCheatSystem* func(void);
		return ((func*)0x00cd4260)();
	}

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
		virtual void GetNeighborhoodInfo();
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
	};

	cTSGlobals* Globals() {
		typedef cTSGlobals* func(void);
		return ((func*)0x00799a0d)();
	}

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
		virtual void CurrentNeighborhoodInfo();
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

	cTSGameStateController* GameStateController() {
		typedef cTSGameStateController* func(void);
		return ((func*)0x00799b65)();
	}
}
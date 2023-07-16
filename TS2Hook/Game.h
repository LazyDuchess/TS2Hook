#pragma once
int SwapLot(int lotID, int neighborhoodID)
{
	typedef int t_swaplot(int, int);
	return ((t_swaplot*)0x0093c710)(lotID, neighborhoodID);
}

class cRZString {
public:

};

namespace TS {

	class cTSNeighborhood {
	public:
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
		// Check these.
		virtual cTSNeighborhood* GetPrimaryNeighborhood();
		virtual void SetPrimaryNeighborhood(cTSNeighborhood* primaryNeighborhood);
		// TODO
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
	public:
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
	public:
		// TODO
		virtual void QueryInterface();
		virtual void AddRef();
		virtual void Release();
		virtual void Destructor1();
		virtual void Destructor2();
		virtual void RemoveRef();
		virtual void RefCount();
		virtual void SetBaseLotInfo();
		virtual void GetBaseLotInfo();
		virtual void Clone();

		// Probs done?
		virtual void SetLocation(int x, int y);
		virtual void GetLocation(int& x, int& y);
		virtual void GetCurrentSize(int& x, int& y);

		// TODO
		virtual void GetBoundingRect();
		virtual void GetBoundingRectExcludingRoads();
		virtual void GetBoundingRectForRoads();

		// Verify these
		virtual void SetLotGroupName(char* name);
		virtual void SetLotGroupName(cRZString* name);
		virtual char* LotGroupName();

		// TODO
		virtual void SetNHoodToLotHeightOffset(float offset);
		virtual float NhoodToLotHeightOffset();
		virtual void SetLotID(int lotId);
		virtual int LotID();
		virtual char* LotName();
	};

	class cTSGameStateController {
	public:
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
		virtual cTSLotInfo* CurrentLotInfo();
		virtual cTSLotInfo* CurrentLotInfoNonConst();
		virtual void GetCurrentLotGroupID();
		virtual void GetCurrentLotID();
		virtual cTSLotInfo* NextLotInfo();
		virtual void CurrentFamily();
		virtual void FamilyIDToMoveIn();
		virtual void CurrentFamilyNonConst();
		virtual void LastNeighborhoodInfo();
		// DONE
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
#pragma once
#include "Core.h"
#include "Types.h"

namespace nTSSG {
	class cLightingManager : public cIGZUnknown {
	public:
		void UpdateLightingState() {
			typedef void func(cLightingManager*);
			((func*)0x00aab480)(this);
		}
		// TODO
	private:
		virtual void Init();
		virtual void Shutdown();
		virtual void ParseConfigFilesAndLightOverrides();
		virtual void AttachToLotScene();
		virtual void DetachFromLotScene();
		virtual void AttachToNeighborhoodScene();
		virtual void DetachFromNeighborhoodScene();
		virtual void OncePerFrameUpdate();
		virtual void AttachToObjectLights();
		virtual void DetachFromObjectLights();
		virtual void UpdateObjectLighting();
		virtual void ChangeObjectLighting();
		virtual void ChangeObjectLightingForSpecificLight();
		virtual void FindTerrainColour();
		virtual void FindTerrainColour2();
		virtual void SetAutoLightingActive();
	public:
		virtual void SetLightingState(char* state);
		virtual void ForceLightingUpdate();
	private:
		virtual void AddBlobToHeightMap();
		virtual void ApplyLightSettingOverridesFromFile();
	public:
		virtual char* LightingState();

	};
	class cTSSGSystem
	{
	private:
		// TODO
		virtual void QueryInterface();
		virtual void AddRef();
		virtual void Release();
		virtual void HandleNotification();
		virtual void fn1();
		virtual void fn2();
		virtual void fn3();
		virtual void fn4();
		virtual void fn5();
		virtual void fn6();
		virtual void fn7();
		virtual void fn8();
		virtual void fn9();
		virtual void fn10();
		virtual void fn11();
		virtual void SetObjectModule();
	public:
		virtual void AnimationTimerAdjustment(int value);
	private: 
		virtual void OncePerFrameUpdate();
	public:
		virtual void SetFramePeriodOverride(int value);
	private:
		virtual void PreLoadLot();
		virtual void PostLoadLot();
		virtual void LoadPermanentAnimationCache();
		virtual void DoesCompositionResourceExist();
		virtual void GetCompositionResourceClone();
		virtual void GetShapeNodeClone();
		virtual void GetAnimResource();
		virtual void GetAnimResource2();
		virtual void PrepCinematicScene();
		virtual void PlayCinematicScene();
		virtual void UpdateCinematicScene();
		virtual void SetHideSceneFrameCount();
		virtual void UpdateNhoodReflectionSkycube();
		virtual void ObjectModule();
		virtual void SceneManager();
		virtual void WallManager();
		virtual void FenceManager();
		virtual void PoolManager();
		virtual void LotSkirt();
		virtual void FloorManager();
		virtual void Terrain();
		virtual void NHoodTerrain();
		virtual void NHoodOccupantManager();
		virtual void VideoBroadcastManager();
		virtual void LotImposterDisplay();
		virtual void NHoodAutomata();
		virtual void OverlayManager();
		virtual void QueryStrategyManager();
		virtual void LightRigManager();
		virtual void LightMapManager();
	public:
		virtual cLightingManager* LightingManager();
	private:
		virtual void ShadowManager();
		virtual void HomeAnimManager();
		virtual void HomeAnimTimer();
		virtual void CameraControllerManager();
		virtual void CinematicAnimRequest();
		virtual void IsCinematicSceneReadyToPlay();
		virtual void IsCinematicSceneActive();
		virtual void HideSceneFrameCount();
		virtual void RoofManager();
		virtual void LotImposterManager();
		virtual void I3DUIManager();
		virtual void RugManager();
		virtual void CurvedPoolManager();
		virtual void TerrainCutoutObjectManager();
		virtual void TerrainSnowManager();
		virtual void AwningManager();
		virtual void SeasonManager();
		virtual void CensorRenderStrategy();
		virtual void ShouldPathsBeDisplayed();
		virtual void ShouldLookAtBoxesBeDisplayed();
		virtual void ShouldMissingAnimationEffectBeDisplayed();
		virtual void IsAnimationPredictionEnabled();
		virtual void IsAnimationBackgroundLoadEnabled();
		virtual void AnimSpeed();
		virtual void GetReflectionTexture();
		virtual void CopyFromScratchPadFullscreenRTT();
		virtual void LoadCameraState();
		virtual void SaveCameraState();
		virtual void HighlightColor();
		virtual void ObjectFadeParams();
		virtual void CinematicCameraPosition();
		virtual void CinematicCameraDirection();
		virtual void CinematicSceneBoundingBox();
		virtual void RecentAnimList();
		virtual void ImportTerrainFromSC4SaveGame();
		virtual void IsSC4ValidForImport();
		virtual void RenderInsideObjectsOnVisibleLevelState();
		virtual void ForceNextFrame();
	};
}

namespace TS {
	DllExport nTSSG::cTSSGSystem* SGSystem();
}

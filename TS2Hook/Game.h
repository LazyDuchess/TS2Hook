#pragma once
int SwapLot(int lotID, int neighborhoodID)
{
	typedef int t_swaplot(int, int);
	return ((t_swaplot*)0x0093C710)(lotID, neighborhoodID);
}

namespace TS {
	class cTSGameStateController
	{
	public:
		virtual void QueryInterface();
		virtual void AddRef();
		virtual void Release();
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
		virtual bool SaveLotEnabled();
	}; //Size: 0x0008
	cTSGameStateController* GameStateController() {
		typedef cTSGameStateController* func(void);
		return ((func*)0x00799B65)();
	}
}
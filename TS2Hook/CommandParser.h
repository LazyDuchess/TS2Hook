#pragma once

namespace nGZCommandParser {
	class cArguments {
	private:
		int unk1;
		int unk2;
		int unk3;
		virtual void SplitIntoArguments();
		virtual void SwitchNoArguments();
		virtual void SwitchArguments();
		virtual void SwitchArguments2();
	public:
		int count;
		virtual char* operator[](int index);
	};
}
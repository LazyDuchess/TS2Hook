# TS2Hook
Hooking framework for TS2

Requires a No-CD version of Sims 2 Mansion & Garden to work, or Sims2RPC.

Requires the Direct3D SDK to build

## Structure
* `CustomSimCall` - Contains an .asi plugin that adds a custom SimAntics function to the game. Used by **"Downloads/ld_TS2Hook_TestObject.package"**
* `CustomCheat` - Contains an .asi plugin that adds custom cheats to the in-game console.
* `CustomInteraction` - Contains an .asi plugin that adds a custom interaction globally. Requires **"Downloads/ld_TS2Hook_CustomInteraction.package"**
* `TS2Hook` - Code for the main DLL, all plugins in this project depend on it. Compiled .dll goes into the same place as your **Sims2EP9.exe** file.
* `Downloads` - Packages with custom objects to test TS2Hook functionality.
* `TestScript` - Messy script to test TS2Hook functionality, mostly random notes, code snippets and experiments. Not included in the Solution by default.
* `D3DHook` - [Universal D3D Hooking Library](https://www.unknowncheats.me/forum/direct3d/335041-universal-d3d-hooking-library.html) used to hook into the renderer to display text and run code every frame.

# Installation

**TS2Hook.dll** goes into your Mansion & Garden TSBin folder. If you use Sims2RPC, the .asi files should be put into your **"TSBin/mods"** folder. If you use the [Ultimate ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader/releases), they should be placed in TSBin alongside **TS2Hook.dll**

The .package files in downloads go in your **"Documents/EA Games/The Sims 2/Downloads"** folder.

# Creating a Script using Visual Studio

* First of all, clone this repository and build the solution. You will get the output files in a **"Release"** directory, if you use the default Configuration.

* Create a new Dynamic-Link Library (DLL) Project and give it any name you like. Make sure you're building for x86.

![image](https://github.com/LazyDuchess/TS2Hook/assets/42678262/a71d5baf-5e6f-4066-ad0c-153c64c943c2)

* In the Solution Explorer, right click your project and go to Properties.

![image](https://github.com/LazyDuchess/TS2Hook/assets/42678262/a581d794-aee3-494a-ae12-32ae55fb57b9)

* Head to **Advanced** and change the Target File Extension to .asi

![image](https://github.com/LazyDuchess/TS2Hook/assets/42678262/c7a8f66d-e7ff-484a-a5c9-6eab80e99cf2)

* Head to **VC++ Directories** and locate the path to the **"TS2Hook"** folder, that contains all the header (.h) files and add it to **Include Directories**

* Locate the path to the **"Release"** folder where the TS2Hook solution was built to earlier, and add it to the **Library Directories**

![image](https://github.com/LazyDuchess/TS2Hook/assets/42678262/aac516fc-beb9-43e6-8524-861c8c1e0d0b)

* Now, head to **Linker** -> **Input** and write **"TS2Hook.lib"** into **Additional Dependencies**

![image](https://github.com/LazyDuchess/TS2Hook/assets/42678262/cd9d91a8-0682-440a-a6e2-d69cbb88e483)

Success! You now have access to the TS2Hook library. You can check the **"CustomCheat"** and **"CustomInteraction"** projects to see how to make your own Script class and how to add it to the ScriptManager in the **dllmain.cpp** file.

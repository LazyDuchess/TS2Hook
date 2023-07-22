# TS2Hook
Hooking framework for TS2


Requires the Direct3D SDK to build

## Structure
* `CustomCheat` - Contains an .asi plugin that adds custom cheats to the in-game console.
* `CustomInteraction` - Contains an .asi plugin that adds a custom interaction globally. Requires **"Downloads/ld_TS2Hook_CustomInteraction.package"**
* `TS2Hook` - Code for the main DLL, all plugins in this project depend on it. Compiled .dll goes into the same place as your Sims2EP9.exe file.
* `Downloads` - Packages with custom objects to test TS2Hook functionality.
* `TestScript` - Messy script to test TS2Hook functionality, mostly random notes, code snippets and experiments.
* `D3DHook` - [Universal D3D Hooking Library](https://www.unknowncheats.me/forum/direct3d/335041-universal-d3d-hooking-library.html) used to hook into the renderer to display text and run code every frame.

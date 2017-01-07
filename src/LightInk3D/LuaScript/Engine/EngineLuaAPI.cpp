

/* Copyright ChenDong(Wilbur), email <baisaichen@live.com>. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

 
#ifdef URHO3D_DATABASE

#include "../Precompiled.h"
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;

	extern void bind_class_Console(LuaModele & lm);
	extern void bind_class_DebugHud(LuaModele & lm);
	extern void bind_class_Engine(LuaModele & lm);

	void bind_engine_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModele lm(lua, "LightInk3D__", lrf);
		
		bind_class_Console(lm);
		bind_class_DebugHud(lm);
		bind_class_Engine(lm);

		// [Constant] unsigned DEBUGHUD_SHOW_NONE
		lrf["DEBUGHUD_SHOW_NONE"] = DEBUGHUD_SHOW_NONE;
		// [Constant] unsigned DEBUGHUD_SHOW_ALL
		lrf["DEBUGHUD_SHOW_STATS"] = DEBUGHUD_SHOW_STATS;
		// [Constant] unsigned DEBUGHUD_SHOW_MODE
		lrf["DEBUGHUD_SHOW_MODE"] = DEBUGHUD_SHOW_MODE;
		// [Constant] unsigned DEBUGHUD_SHOW_PROFILER
		lrf["DEBUGHUD_SHOW_PROFILER"] = DEBUGHUD_SHOW_PROFILER;
		// [Constant] unsigned DEBUGHUD_SHOW_MEMORY
		lrf["DEBUGHUD_SHOW_MEMORY"] = DEBUGHUD_SHOW_MEMORY;
		// [Constant] unsigned DEBUGHUD_SHOW_ALL
		lrf["DEBUGHUD_SHOW_ALL"] = DEBUGHUD_SHOW_ALL;
		// [Constant] unsigned DEBUGHUD_SHOW_EVENTPROFILER
		lrf["DEBUGHUD_SHOW_EVENTPROFILER"] = DEBUGHUD_SHOW_EVENTPROFILER;
		
		lrf["engine"] = GetSubsystem<Engine>(context);
		LuaDefAutoTool::def(lua, GetSubsystem<Engine>, "GetEngine");
		
		Console * console = GetSubsystem<Console>(context);
		if (console) { lrf["console"] = console; }
		LuaDefAutoTool::def(lua, GetSubsystem<Console>, "GetConsole");
		
		DebugHud * debugHud = GetSubsystem<DebugHud>(context);
		if (debugHud) { lrf["debugHud"] = debugHud; }
		LuaDefAutoTool::def(lua, GetSubsystem<DebugHud>, "GetDebugHud");


}

#endif



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

 

#include "../Precompiled.h"
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;

	extern void bind_class_Controls(LuaModule & lm);
	extern void bind_class_Input(LuaModule & lm);
	extern void bind_class_InputEvents(LuaModule & lm);
	

	void bind_input_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModule lm(lua, "LightInk3D__", lrf);
		
		bind_class_Controls(lm);
		bind_class_Input(lm);
		bind_class_InputEvents(lm);

		
		
		// [Enum] MouseMode
		lrf["MM_ABSOLUTE"] = MM_ABSOLUTE;
		lrf["MM_RELATIVE"] = MM_RELATIVE;
		lrf["MM_WRAP"] = MM_WRAP;
		lrf["MM_FREE"] = MM_FREE;
		lrf["MM_INVALID"] = MM_INVALID;
			

		lrf["input"] = GetSubsystem<Input>(context);
		LuaDefAutoTool::def(lua, GetSubsystem<Input>, "GetInput");


}


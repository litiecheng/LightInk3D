

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

#include "Precompiled.h"

#include "LuaScript/LuaScript.h"
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;
	static void LuaScriptAddEventHandlerLSSH(LuaScript * self, const String& eventName, LuaRef lrf)
	{
		lrf.push();
		self->AddEventHandler(eventName, -1); // 2 is the stack index of function
	}

	static void LuaScriptAddEventHandlerLSOSH(LuaScript * self, Object* sender, const String& eventName, LuaRef lrf)
	{
		lrf.push();
		self->AddEventHandler(sender, eventName, -1); // 3 is the stack index of function
	}
	void bind_class_LuaScript(LuaModule & lm)
	{
		lm
		[
			LuaRegister<LuaScript, void (Context *)>(lm.state(), "LuaScript", BaseClassStrategy<Object>())
				.disable_new()
				.def(static_cast<void(LuaScript::*)(const String&, const String&)>(&LuaScript::AddEventHandler), "AddEventHandlerSS")
				.def(static_cast<void(LuaScript::*)(Object*, const String&, const String&)>(&LuaScript::AddEventHandler), "AddEventHandlerOSS")
				.def(LuaScriptAddEventHandlerLSS, "AddEventHandlerLSS")
				.def(LuaScriptAddEventHandlerLSOS, "AddEventHandlerLSOS")
				.def(static_cast<void(LuaScript::*)(const String&)>(&LuaScript::RemoveEventHandler), "RemoveEventHandlerS")
				.def(static_cast<void(LuaScript::*)(Object*, const String&)>(&LuaScript::RemoveEventHandler), "RemoveEventHandlerOS")
				.def(&LuaScript::RemoveEventHandlers, "RemoveEventHandlers")
				.def(&LuaScript::RemoveAllEventHandlers, "RemoveAllEventHandlers")
				.def(&LuaScript::RemoveEventHandlersExcept, "RemoveEventHandlersExcept")
				.def(static_cast<void(LuaScript::*)(const String&)>(&LuaScript::HasEventHandler), "HasEventHandlerS")
				.def(static_cast<void(LuaScript::*)(Object*, const String&)>(&LuaScript::HasEventHandler), "HasEventHandlerOS")
				.def(&LuaScript::SetExecuteConsoleCommands, "SetExecuteConsoleCommands")
				.def(&LuaScript::GetExecuteConsoleCommands, "GetExecuteConsoleCommands")
				.def(&LuaScript::SetGlobalVar, "SetGlobalVar")
				.def(&LuaScript::GetGlobalVar, "GetGlobalVar")
				.def(&LuaScript::GetGlobalVars, "GetGlobalVars")
		];
		
		LuaDefAutoTool::def(lm.state(), EventNameRegistrar::RegisterEventName, "RegisterEventName");
	}
}


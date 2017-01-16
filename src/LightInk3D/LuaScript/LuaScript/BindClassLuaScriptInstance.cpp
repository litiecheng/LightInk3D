

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

#include "../LuaScript/LuaScriptInstance.h"
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;
	void bind_class_LuaScriptInstance(LuaScript * ls, LuaModule & lm)
	{
		lm
		[
			LuaRegister<LuaScriptInstance, void ()>(lm.state(), "LuaScriptInstance", BaseClassStrategy<Component>())
				.def(static_cast<bool (LuaScriptInstance::*)(const String&)>(&LuaScriptInstance::CreateObject), "CreateObjectS")
				.def(static_cast<bool (LuaScriptInstance::*)(LuaFile*, const String&)>(&LuaScriptInstance::CreateObject), "CreateObjectLFS")
				.def(&LuaScriptInstance::SetScriptFile, "SetScriptFile")
				.def(&LuaScriptInstance::SetScriptObjectType, "SetScriptObjectType")
				.def(static_cast<void (LuaScriptInstance::*)(const String&, int)>(&LuaScriptInstance::AddEventHandler), "AddEventHandlerSI")
				.def(static_cast<void (LuaScriptInstance::*)(const String&, const String&)>(&LuaScriptInstance::AddEventHandler), "AddEventHandlerSS")
				.def(static_cast<void (LuaScriptInstance::*)(Object*, const String&, int)>(&LuaScriptInstance::AddEventHandler), "AddEventHandlerOSI")
				.def(static_cast<void (LuaScriptInstance::*)(Object*, const String&, const String&)>(&LuaScriptInstance::AddEventHandler), "AddEventHandlerOSS")
				.def(static_cast<void (LuaScriptInstance::*)(const String&)>(&LuaScriptInstance::RemoveEventHandler), "RemoveEventHandlerS")
				.def(static_cast<void (LuaScriptInstance::*)(Object*, const String&)>(&LuaScriptInstance::RemoveEventHandler), "RemoveEventHandlerOS")
				.def(&LuaScriptInstance::RemoveEventHandlers, "RemoveEventHandlers")
				.def(&LuaScriptInstance::RemoveAllEventHandlers, "RemoveAllEventHandlers")
				.def(&LuaScriptInstance::RemoveEventHandlersExcept, "RemoveEventHandlersExcept")
				.def(static_cast<bool (LuaScriptInstance::*)(const String&) const>(&LuaScriptInstance::HasEventHandler), "HasEventHandlerS")
				.def(static_cast<bool (LuaScriptInstance::*)(Object*, const String&) const>(&LuaScriptInstance::HasEventHandler), "HasEventHandlerOS")
				.def(&LuaScriptInstance::GetScriptFile, "GetScriptFile")
				.def(&LuaScriptInstance::GetScriptObjectType, "GetScriptObjectType")
				
		];
		ls->ExecuteString(
			"LuaScriptObject = {}                                                \n"
			"function LuaScriptObject:Start()                                    \n"
			"end                                                                 \n"
			"function LuaScriptObject:Stop()                                     \n"
			"end                                                                 \n"
			"function LuaScriptObject:GetNode()                                  \n"
			"    return self.node                                                \n"
			"end                                                                 \n"
			"function LuaScriptObject:SubscribeToEvent(param1, param2, param3)   \n"
			"    local instance = self.instance                                  \n"
			"    if instance == nil then                                         \n"
			"        return                                                      \n"
			"    end                                                             \n"
			"    if param3 == nil then                                           \n"
			"        instance:SubscribeToEvent(param1, param2)                   \n"
			"    else                                                            \n"
			"        instance:SubscribeToEvent(param1, param2, param3)           \n"
			"    end                                                             \n"
			"end                                                                 \n"
			"function LuaScriptObject:UnsubscribeFromEvent(param1, param2)       \n"
			"    local instance = self.instance                                  \n"
			"    if instance == nil then                                         \n"
			"        return                                                      \n"
			"    end                                                             \n"
			"    if param2 == nil then                                           \n"
			"        instance:UnsubscribeFromEvent(param1)                       \n"
			"    else                                                            \n"
			"        instance:UnsubscribeFromEvent(param1, param2)               \n"
			"    end                                                             \n"
			"end                                                                 \n"
			"function LuaScriptObject:UnsubscribeFromEvents(sender)              \n"
			"    local instance = self.instance                                  \n"
			"    if instance == nil then                                         \n"
			"        return                                                      \n"
			"    end                                                             \n"
			"    instance:UnsubscribeFromEvents(sender)                          \n"
			"end                                                                 \n"
			"function LuaScriptObject:UnsubscribeFromAllEvents()                 \n"
			"    local instance = self.instance                                  \n"
			"    if instance == nil then                                         \n"
			"        return                                                      \n"
			"    end                                                             \n"
			"    instance:UnsubscribeFromAllEvents()                             \n"
			"end                                                                 \n"
			"function LuaScriptObject:UnsubscribeFromAllEventsExcept(eventTypes) \n"
			"    local instance = self.instance                                  \n"
			"    if instance == nil then                                         \n"
			"        return                                                      \n"
			"    end                                                             \n"
			"    instance:UnsubscribeFromAllEventsExcept(eventTypes)             \n"
			"end                                                                 \n"
			"function LuaScriptObject:HasSubscribedToEvent(param1, param2)       \n"
			"    local instance = self.instance                                  \n"
			"    if instance == nil then                                         \n"
			"        return                                                      \n"
			"    end                                                             \n"
			"    if param2 == nil then                                           \n"
			"        return instance:HasSubscribedToEvent(param1)                \n"
			"    else                                                            \n"
			"        return instance:HasSubscribedToEvent(param1, param2)        \n"
			"    end                                                             \n"
			"end                                                                 \n"
			"function ScriptObject()                                             \n"
			"    local o = {}                                                    \n"
			"    setmetatable(o, LuaScriptObject)                                \n"
			"    LuaScriptObject.__index = LuaScriptObject                       \n"
			"    return o                                                        \n"
			"end                                                                 \n"
			"function CreateScriptObjectInstance(object, instance)               \n"
			"    local o = {}                                                    \n"
			"    setmetatable(o, object)                                         \n"
			"    object.__index = object                                         \n"
			"    o.instance = instance                                           \n"
			"    o.node = instance:GetNode()                                     \n"
			"    local keys = {}                                                 \n"
			"    for k, v in pairs(o) do                                         \n"
			"        keys[k] = true                                              \n"
			"    end                                                             \n"
			"    -- Call start function                                          \n"
			"    o:Start()                                                       \n"
			"    local attrNames = {}                                            \n"
			"    for k, v in pairs(o) do                                         \n"
			"        if keys[k] == nil then                                      \n"
			"            table.insert(attrNames, k)                              \n"
			"        end                                                         \n"
			"    end                                                             \n"
			"    return o, attrNames                                             \n"
			"end                                                                 \n"
		);

	}
}


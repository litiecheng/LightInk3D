

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

#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Coroutine(LuaScript * ls)
	{
		// [Function] void coroutine.start(LuaFunction function)
		// [Function] void coroutine.sleep(float time)
		// [Function] void coroutine.waitevent(StringHash eventType)
		// [Function] void coroutine.sendevent(StringHash eventType)

		ls->ExecuteString(
			"local totalTime_ = 0                                                \n"
			"local sleepedCoroutines_ = {}                                       \n"
			"local waitEventCoroutines_ = {}                                     \n"
			"function coroutine.start(func)                                      \n"
			"    if func == nil then                                             \n"
			"        return nil                                                  \n"
			"    end                                                             \n"
			"    local co = coroutine.create(func)                               \n"
			"    return coroutine.resume(co)                                     \n"
			"end                                                                 \n"
			"function coroutine.sleep(time)                                      \n"
			"    local co = coroutine.running()                                  \n"
			"    if co == nil then                                               \n"
			"        return                                                      \n"
			"    end                                                             \n"
			"    sleepedCoroutines_[co] = totalTime_ + time                      \n"
			"    return coroutine.yield(co)                                      \n"
			"end                                                                 \n"
			"function coroutine.update(steptime)                                 \n"
			"    totalTime_ = totalTime_ + steptime                              \n"
			"    local coroutines = {}                                           \n"
			"    for co, wakeupTime in pairs(sleepedCoroutines_) do              \n"
			"        if wakeupTime < totalTime_ then                             \n"
			"            table.insert(coroutines, co)                            \n"
			"        end                                                         \n"
			"    end                                                             \n"
			"    for _, co in ipairs(coroutines) do                              \n"
			"        sleepedCoroutines_[co] = nil                                \n"
			"        coroutine.resume(co)                                        \n"
			"    end                                                             \n"
			"end                                                                 \n"
			"function coroutine.waitevent(event)                                 \n"
			"    local co = coroutine.running()                                  \n"
			"    if co == nil then                                               \n"
			"        return                                                      \n"
			"    end                                                             \n"
			"    if waitEventCoroutines_[event] == nil then                      \n"
			"        waitEventCoroutines_[event] = { co }                        \n"
			"    else                                                            \n"
			"        table.insert(waitEventCoroutines_[event], co)               \n"
			"    end                                                             \n"
			"    return coroutine.yield(co)                                      \n"
			"end                                                                 \n"
			"function coroutine.sendevent(event)                                 \n"
			"    local coroutines = waitEventCoroutines_[event]                  \n"
			"    if coroutines == nil then                                       \n"
			"        return                                                      \n"
			"    end                                                             \n"
			"    waitEventCoroutines_[event] = nil                               \n"
			"                                                                    \n"
			"    for _, co in ipairs(coroutines) do                              \n"
			"        coroutine.resume(co)                                        \n"
			"    end                                                             \n"
			"end                                                                 \n"
		);
	}
}


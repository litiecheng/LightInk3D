

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

#include "../../Precompiled.h"
#include "../../Engine/DebugHud.h"
#include "../../Resource/XMLFile.h"
#include "../../UI/Text.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_DebugHud(LuaModele & lm)
	{
		lm
		[
			LuaRegister<DebugHud, void ()>(lm.state(), "DebugHud", BaseClassStrategy<Object>())
				.def(&DebugHud::SetDefaultStyle, "SetDefaultStyle")
				.def(&DebugHud::SetMode, "SetMode")
				.def(&DebugHud::SetProfilerMaxDepth, "SetProfilerMaxDepth")
				.def(&DebugHud::SetProfilerInterval, "SetProfilerInterval")
				.def(&DebugHud::SetUseRendererStats, "SetUseRendererStats")
				.def(&DebugHud::Toggle, "Toggle")
				.def(&DebugHud::ToggleAll, "ToggleAll")
				.def(&DebugHud::GetDefaultStyle, "GetDefaultStyle")
				.def(&DebugHud::GetStatsText, "GetStatsText")
				.def(&DebugHud::GetModeText, "GetModeText")
				.def(&DebugHud::GetProfilerText, "GetProfilerText")
				.def(&DebugHud::GetMemoryText, "GetMemoryText")
				.def(&DebugHud::GetMode, "GetMode")
				.def(&DebugHud::GetProfilerMaxDepth, "GetProfilerMaxDepth")
				.def(&DebugHud::GetProfilerInterval, "GetProfilerInterval")
				.def(&DebugHud::GetUseRendererStats, "GetUseRendererStats")
				.def(static_cast<void(DebugHud::*)(const String&, const Variant&)>(&DebugHud::SetAppStats), "SetAppStatsV")
				.def(static_cast<void(DebugHud::*)(const String&, const String&)>(&DebugHud::SetAppStats), "SetAppStatsS")
				.def(&DebugHud::ResetAppStats, "ResetAppStats")
				.def(&DebugHud::ClearAppStats, "ClearAppStats")
		];
	}
}


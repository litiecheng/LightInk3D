

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
#include "Resource/Localization.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Localization(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Localization, void ()>(lm.state(), "Localization", BaseClassStrategy<Object>())
				.def(&Localization::GetNumLanguages, "GetNumLanguages")
				.def(static_cast<int(Localization::*)() const>(&Localization::GetLanguageIndex), "GetLanguageIndex")
				.def(static_cast<int(Localization::*)(const String&)>(&Localization::GetLanguageIndex), "GetLanguageIndexS")
				.def(static_cast<String(Localization::*)()>(&Localization::GetLanguage), "GetLanguage")
				.def(static_cast<String(Localization::*)(int)>(&Localization::GetLanguage), "GetLanguageI")
				.def(static_cast<void(Localization::*)(int)>(&Localization::SetLanguage), "SetLanguageI")
				.def(static_cast<void(Localization::*)(const String&)>(&Localization::SetLanguage), "SetLanguageS")
				.def(&Localization::Get, "Get")
				.def(&Localization::Reset, "Reset")
				.def(&Localization::LoadJSON, "LoadJSON")
				.def(&Localization::LoadJSONFile, "LoadJSONFile")
		];
	}
}

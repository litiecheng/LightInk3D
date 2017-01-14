

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
#include "UI/Slider.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Slider(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Slider, void ()>(lm.state(), "Slider", BaseClassStrategy<BorderImage>())
				.disable_new()
				.def(CreateObject<Slider>, "new")
				.def(&Slider::SetOrientation, "SetOrientation")
				.def(&Slider::SetRange, "SetRange")
				.def(&Slider::SetValue, "SetValue")
				.def(&Slider::ChangeValue, "ChangeValue")
				.def(&Slider::SetRepeatRate, "SetRepeatRate")
				.def(&Slider::GetOrientation, "GetOrientation")
				.def(&Slider::GetRange, "GetRange")
				.def(&Slider::GetValue, "GetValue")
				.def(&Slider::GetKnob, "GetKnob")
				.def(&Slider::GetRepeatRate, "GetRepeatRate")

		];
	}
}

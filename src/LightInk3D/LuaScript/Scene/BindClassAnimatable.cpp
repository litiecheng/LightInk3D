

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
#include "Scene/Animatable.h"
#include "Scene/ObjectAnimation.h"
#include "Scene/ValueAnimation.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Animatable(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Animatable, void ()>(lm.state(), "Animatable", BaseClassStrategy<Serializable>())
				.def(&Animatable::SetAnimationEnabled, "SetAnimationEnabled")
				.def(&Animatable::SetAnimationTime, "SetAnimationTime")
				.def(&Animatable::SetObjectAnimation, "SetObjectAnimation")
				.def(&Animatable::SetAttributeAnimation, "SetAttributeAnimation")
				.def(&Animatable::SetAttributeAnimationWrapMode, "SetAttributeAnimationWrapMode")
				.def(&Animatable::SetAttributeAnimationSpeed, "SetAttributeAnimationSpeed")
				.def(&Animatable::SetAttributeAnimationTime, "SetAttributeAnimationTime")
				.def(&Animatable::RemoveObjectAnimation, "RemoveObjectAnimation")
				.def(&Animatable::RemoveAttributeAnimation, "RemoveAttributeAnimation")
				.def(&Animatable::GetAnimationEnabled, "GetAnimationEnabled")
				.def(&Animatable::GetObjectAnimation, "GetObjectAnimation")
				.def(&Animatable::GetAttributeAnimation, "GetAttributeAnimation")
				.def(&Animatable::GetAttributeAnimationWrapMode, "GetAttributeAnimationWrapMode")
				.def(&Animatable::GetAttributeAnimationSpeed, "GetAttributeAnimationSpeed")
				.def(&Animatable::GetAttributeAnimationTime, "GetAttributeAnimationTime")

		];
	}
}

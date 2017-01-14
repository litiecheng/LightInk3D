

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
#include "Graphics/Zone.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Zone(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Zone, void ()>(lm.state(), "Zone", BaseClassStrategy<Drawable>())
				.disable_new()
				.def(CreateObject<Zone>, "new")
				.def(&Zone::SetBoundingBox, "SetBoundingBox")
				.def(&Zone::SetAmbientColor, "SetAmbientColor")
				.def(&Zone::SetFogColor, "SetFogColor")
				.def(&Zone::SetFogStart, "SetFogStart")
				.def(&Zone::SetFogEnd, "SetFogEnd")
				.def(&Zone::SetFogHeight, "SetFogHeight")
				.def(&Zone::SetFogHeightScale, "SetFogHeightScale")
				.def(&Zone::SetPriority, "SetPriority")
				.def(&Zone::SetHeightFog, "SetHeightFog")
				.def(&Zone::SetOverride, "SetOverride")
				.def(&Zone::SetAmbientGradient, "SetAmbientGradient")
				.def(&Zone::SetZoneTexture, "SetZoneTexture")
				.def(&Zone::GetInverseWorldTransform, "GetInverseWorldTransform")
				.def(&Zone::GetAmbientColor, "GetAmbientColor")
				.def(&Zone::GetAmbientStartColor, "GetAmbientStartColor")
				.def(&Zone::GetAmbientEndColor, "GetAmbientEndColor")
				.def(&Zone::GetFogColor, "GetFogColor")
				.def(&Zone::GetFogStart, "GetFogStart")
				.def(&Zone::GetFogEnd, "GetFogEnd")
				.def(&Zone::GetFogHeight, "GetFogHeight")
				.def(&Zone::GetFogHeightScale, "GetFogHeightScale")
				.def(&Zone::GetPriority, "GetPriority")
				.def(&Zone::GetHeightFog, "GetHeightFog")
				.def(&Zone::GetOverride, "GetOverride")
				.def(&Zone::GetAmbientGradient, "GetAmbientGradient")
				.def(&Zone::GetZoneTexture, "GetZoneTexture")
				.def(&Zone::IsInside, "IsInside")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
				.def(&Zone::ScreenToWorldPoint, "ScreenToWorldPoint")
		];
	}
}


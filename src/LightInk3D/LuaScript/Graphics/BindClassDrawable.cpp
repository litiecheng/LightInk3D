

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
#include "Graphics/Drawable.h"
#include "Graphics/Zone.h"
#include "Graphics/Camera.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Drawable(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Drawable, void ()>(lm.state(), "Drawable", BaseClassStrategy<Component>())
				.def(&Drawable::SetDrawDistance, "SetDrawDistance")
				.def(&Drawable::SetShadowDistance, "SetShadowDistance")
				.def(&Drawable::SetLodBias, "SetLodBias")
				.def(&Drawable::SetViewMask, "SetViewMask")
				.def(&Drawable::SetLightMask, "SetLightMask")
				.def(&Drawable::SetShadowMask, "SetShadowMask")
				.def(&Drawable::SetZoneMask, "SetZoneMask")
				.def(&Drawable::SetMaxLights, "SetMaxLights")
				.def(&Drawable::SetCastShadows, "SetCastShadows")
				.def(&Drawable::SetOccluder, "SetOccluder")
				.def(&Drawable::SetOccludee, "SetOccludee")
				.def(&Drawable::MarkForUpdate, "MarkForUpdate")
				.def(&Drawable::GetBoundingBox, "GetBoundingBox")
				.def(&Drawable::GetWorldBoundingBox, "GetWorldBoundingBox")
				.def(&Drawable::GetDrawableFlags, "GetDrawableFlags")
				.def(&Drawable::GetDrawDistance, "GetDrawDistance")
				.def(&Drawable::GetShadowDistance, "GetShadowDistance")
				.def(&Drawable::GetLodBias, "GetLodBias")
				.def(&Drawable::GetViewMask, "GetViewMask")
				.def(&Drawable::GetLightMask, "GetLightMask")
				.def(&Drawable::GetShadowMask, "GetShadowMask")
				.def(&Drawable::GetZoneMask, "GetZoneMask")
				.def(&Drawable::GetMaxLights, "GetMaxLights")
				.def(&Drawable::GetCastShadows, "GetCastShadows")
				.def(&Drawable::IsOccluder, "IsOccluder")
				.def(&Drawable::IsOccludee, "IsOccludee")
				.def(&Drawable::GetZone, "GetZone")
				.def(static_cast<bool(Drawable::*)() const>(&Drawable::IsInView), "IsInView")
				.def(static_cast<bool(Drawable::*)(Camera*) const>(&Drawable::IsInView), "IsInViewC")
		];
	}
}


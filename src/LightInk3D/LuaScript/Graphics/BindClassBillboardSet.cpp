

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
#include "Graphics/BillboardSet.h"
#include "Graphics/Material.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_BillboardSet(LuaModule & lm)
	{
		lm
		[
			LuaRegister<BillboardSet, void ()>(lm.state(), "BillboardSet", BaseClassStrategy<Drawable>())
				.disable_new()
				.def(CreateObject<BillboardSet>, "new")
				.def(&BillboardSet::SetMaterial, "SetMaterial")
				.def(&BillboardSet::SetNumBillboards, "SetNumBillboards")
				.def(&BillboardSet::SetRelative, "SetRelative")
				.def(&BillboardSet::SetScaled, "SetScaled")
				.def(&BillboardSet::SetSorted, "SetSorted")
				.def(&BillboardSet::SetFixedScreenSize, "SetFixedScreenSize")
				.def(&BillboardSet::SetFaceCameraMode, "SetFaceCameraMode")
				.def(&BillboardSet::SetAnimationLodBias, "SetAnimationLodBias")
				.def(&BillboardSet::Commit, "Commit")
				.def(&BillboardSet::GetMaterial, "GetMaterial")
				.def(&BillboardSet::GetNumBillboards, "GetNumBillboards")
				.def(&BillboardSet::GetBillboard, "GetBillboard")
				.def(&BillboardSet::IsScaled, "IsScaled")
				.def(&BillboardSet::IsSorted, "IsSorted")
				.def(&BillboardSet::IsFixedScreenSize, "IsFixedScreenSize")
				.def(&BillboardSet::GetFaceCameraMode, "GetFaceCameraMode")
				.def(&BillboardSet::GetAnimationLodBias, "GetAnimationLodBias")
			<=
			LuaRegister<Billboard, void ()>(lm.state(), "Billboard")
				.def(&Billboard::position_, "position")
				.def(&Billboard::size_, "size")
				.def(&Billboard::uv_, "uv")
				.def(&Billboard::color_, "color")
				.def(&Billboard::rotation_, "rotation")
				.def(&Billboard::direction_, "direction")
				.def(&Billboard::enabled_, "enabled")

		];
	}
}


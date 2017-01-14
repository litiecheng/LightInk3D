

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
#include "Graphics/RibbonTrail.h"
#include "Graphics/Material.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_RibbonTrail(LuaModele & lm)
	{
		lm
		[
			LuaRegister<RibbonTrail, void ()>(lm.state(), "RibbonTrail", BaseClassStrategy<Drawable>())
				.disable_new()
				.def(CreateObject<RibbonTrail>, "new")
				.def(&RibbonTrail::SetMaterial, "SetMaterial")
				.def(&RibbonTrail::SetVertexDistance, "SetVertexDistance")
				.def(&RibbonTrail::SetWidth, "SetWidth")
				.def(&RibbonTrail::SetStartColor, "SetStartColor")
				.def(&RibbonTrail::SetEndColor, "SetEndColor")
				.def(&RibbonTrail::SetStartScale, "SetStartScale")
				.def(&RibbonTrail::SetEndScale, "SetEndScale")
				.def(&RibbonTrail::SetTrailType, "SetTrailType")
				.def(&RibbonTrail::SetSorted, "SetSorted")
				.def(&RibbonTrail::SetLifetime, "SetLifetime")
				.def(&RibbonTrail::SetEmitting, "SetEmitting")
				.def(&RibbonTrail::SetUpdateInvisible, "SetUpdateInvisible")
				.def(&RibbonTrail::SetTailColumn, "SetTailColumn")
				.def(&RibbonTrail::SetAnimationLodBias, "SetAnimationLodBias")
				.def(&RibbonTrail::Commit, "Commit")
				.def(&RibbonTrail::GetMaterial, "GetMaterial")
				.def(&RibbonTrail::GetVertexDistance, "GetVertexDistance")
				.def(&RibbonTrail::GetWidth, "GetWidth")
				.def(&RibbonTrail::GetStartColor, "GetStartColor")
				.def(&RibbonTrail::GetEndColor, "GetEndColor")
				.def(&RibbonTrail::GetStartScale, "GetStartScale")
				.def(&RibbonTrail::GetEndScale, "GetEndScale")
				.def(&RibbonTrail::IsSorted, "IsSorted")
				.def(&RibbonTrail::GetLifetime, "GetLifetime")
				.def(&RibbonTrail::GetAnimationLodBias, "GetAnimationLodBias")
				.def(&RibbonTrail::GetTrailType, "GetTrailType")
				.def(&RibbonTrail::GetTailColumn, "GetTailColumn")
				.def(&RibbonTrail::IsEmitting, "IsEmitting")
				.def(&RibbonTrail::GetUpdateInvisible, "GetUpdateInvisible")

		];
	}
}


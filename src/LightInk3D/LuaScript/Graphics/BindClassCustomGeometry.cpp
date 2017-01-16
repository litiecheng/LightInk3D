

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
#include "Graphics/CustomGeometry.h"
#include "Graphics/Material.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_CustomGeometry(LuaModule & lm)
	{
		lm
		[
			LuaRegister<CustomGeometry, void ()>(lm.state(), "CustomGeometry", BaseClassStrategy<Drawable>())
				.disable_new()
				.def(CreateObject<CustomGeometry>, "new")
				.def(&CustomGeometry::Clear, "Clear")
				.def(&CustomGeometry::SetNumGeometries, "SetNumGeometries")
				.def(&CustomGeometry::SetDynamic, "SetDynamic")
				.def(&CustomGeometry::BeginGeometry, "BeginGeometry")
				.def(&CustomGeometry::DefineVertex, "DefineVertex")
				.def(&CustomGeometry::DefineNormal, "DefineNormal")
				.def(&CustomGeometry::DefineColor, "DefineColor")
				.def(&CustomGeometry::DefineTexCoord, "DefineTexCoord")
				.def(&CustomGeometry::DefineTangent, "DefineTangent")
				.def(&CustomGeometry::DefineGeometry, "DefineGeometry")
				.def(&CustomGeometry::Commit, "Commit")
				.def(static_cast<void(CustomGeometry::*)(Material*)>(&CustomGeometry::SetMaterial), "SetMaterialM")
				.def(static_cast<bool(CustomGeometry::*)(unsigned, Material*)>(&CustomGeometry::SetMaterial), "SetMaterialUM")
				.def(&CustomGeometry::GetNumGeometries, "GetNumGeometries")
				.def(&CustomGeometry::GetNumVertices, "GetNumVertices")
				.def(&CustomGeometry::IsDynamic, "IsDynamic")
				.def(&CustomGeometry::GetMaterial, "GetMaterial")
				.def(&CustomGeometry::GetVertex, "GetVertex")
			<=
			LuaRegister<CustomGeometryVertex, void ()>(lm.state(), "CustomGeometryVertex")
				.def(&Billboard::position_, "position")
				.def(&Billboard::normal_, "normal")
				.def(&Billboard::color_, "color")
				.def(&Billboard::texCoord_, "texCoord")
				.def(&Billboard::tangent_, "tangent")

		];
	}
}


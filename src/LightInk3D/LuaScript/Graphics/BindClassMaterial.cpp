

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
#include "../../Graphics/Material.h"
#include "../../Graphics/Technique.h"
#include "../../Scene/Scene.h"
#include "../../Scene/ValueAnimation.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Material(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Material, void ()>(lm.state(), "Material", BaseClassStrategy<Resource>())
				.disable_new()
				.def(CreateObject<Material>, "new")
				.def(&Material::SetNumTechniques, "SetNumTechniques")
				.def(&Material::SetTechnique, "SetTechnique")
				.def(&Material::SetShaderParameter, "SetShaderParameter")
				.def(&Material::SetShaderParameterAnimation, "SetShaderParameterAnimation")
				.def(&Material::SetShaderParameterAnimationWrapMode, "SetShaderParameterAnimationWrapMode")
				.def(&Material::SetShaderParameterAnimationSpeed, "SetShaderParameterAnimationSpeed")
				.def(&Material::SetTexture, "SetTexture")
				.def(static_cast<void(Material::*)(const Vector2&, float, const Vector2&)>(&Material::SetUVTransform), "SetUVTransformVFV")
				.def(static_cast<void(Material::*)(const Vector2&, float, float)>(&Material::SetUVTransform), "SetUVTransformVFF")
				.def(&Material::SetCullMode, "SetCullMode")
				.def(&Material::SetShadowCullMode, "SetShadowCullMode")
				.def(&Material::SetFillMode, "SetFillMode")
				.def(&Material::SetDepthBias, "SetDepthBias")
				.def(&Material::SetRenderOrder, "SetRenderOrder")
				.def(&Material::SetScene, "SetScene")
				.def(&Material::RemoveShaderParameter, "RemoveShaderParameter")
				.def(&Material::ReleaseShaders, "ReleaseShaders")
				.def(&Material::Clone, "Clone")
				.def(&Material::SortTechniques, "SortTechniques")
				.def(&Material::MarkForAuxView, "MarkForAuxView")
				.def(&Material::GetNumTechniques, "GetNumTechniques")
				.def(&Material::GetTechniques, "GetTechniques")
				.def(&Material::GetTechnique, "GetTechnique")
				.def(&Material::GetPass, "GetPass")
				.def(&Material::GetTexture, "GetTexture")
				.def(&Material::GetShaderParameter, "GetShaderParameter")
				.def(&Material::GetShaderParameterAnimation, "GetShaderParameterAnimation")
				.def(&Material::GetShaderParameterAnimationWrapMode, "GetShaderParameterAnimationWrapMode")
				.def(&Material::GetShaderParameterAnimationSpeed, "GetShaderParameterAnimationSpeed")
				.def(&Material::GetCullMode, "GetCullMode")
				.def(&Material::GetShadowCullMode, "GetShadowCullMode")
				.def(&Material::GetFillMode, "GetFillMode")
				.def(&Material::GetDepthBias, "GetDepthBias")
				.def(&Material::GetRenderOrder, "GetRenderOrder")
				.def(&Material::GetAuxViewFrameNumber, "GetAuxViewFrameNumber")
				.def(&Material::GetOcclusion, "GetOcclusion")
				.def(&Material::GetSpecular, "GetSpecular")
				.def(&Material::GetScene, "GetScene")
				
		];
	}
}


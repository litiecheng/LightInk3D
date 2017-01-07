

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
#include "../../Graphics/Technique.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Technique(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Technique, void ()>(lm.state(), "Technique", BaseClassStrategy<Resource>())
				.disable_new()
				.def(CreateObject<Technique>, "new")
				.def(&Technique::SetIsDesktop, "SetIsDesktop")
				.def(&Technique::CreatePass, "CreatePass")
				.def(&Technique::RemovePass, "RemovePass")
				.def(&Technique::ReleaseShaders, "ReleaseShaders")
				.def(&Technique::Clone, "Clone")
				.def(&Technique::IsDesktop, "IsDesktop")
				.def(&Technique::IsSupported, "IsSupported")
				.def(static_cast<bool(Technique::*)(unsigned int) const>(&Technique::HasPass), "HasPassU")
				.def(static_cast<bool(Technique::*)(const String&) const>(&Technique::HasPass), "HasPassS")
				.def(static_cast<Pass*(Technique::*)(unsigned) const>(&Technique::GetPass), "GetPassU")
				.def(static_cast<Pass*(Technique::*)(const String&) const>(&Technique::GetPass), "GetPassS")
				.def(static_cast<Pass*(Technique::*)(unsigned) const>(&Technique::GetSupportedPass), "GetSupportedPassU")
				.def(static_cast<Pass*(Technique::*)(const String&) const>(&Technique::GetSupportedPass), "GetSupportedPassS")
				.def(&Technique::GetNumPasses, "GetNumPasses")
				.def(&Technique::GetPassNames, "GetPassNames")
				.def(&Technique::GetPasses, "GetPasses")
			<=
			LuaRegister<Pass, void (const String&)>(lm.state(), "Pass", BaseClassStrategy<RefCounted>())
				.def(&Pass::SetBlendMode, "SetBlendMode")
				.def(&Pass::SetCullMode, "SetCullMode")
				.def(&Pass::SetDepthTestMode, "SetDepthTestMode")
				.def(&Pass::SetLightingMode, "SetLightingMode")
				.def(&Pass::SetDepthWrite, "SetDepthWrite")
				.def(&Pass::SetAlphaMask, "SetAlphaMask")
				.def(&Pass::SetIsDesktop, "SetIsDesktop")
				.def(&Pass::SetVertexShader, "SetVertexShader")
				.def(&Pass::SetPixelShader, "SetPixelShader")
				.def(&Pass::SetVertexShaderDefines, "SetVertexShaderDefines")
				.def(&Pass::SetPixelShaderDefines, "SetPixelShaderDefines")
				.def(&Pass::ReleaseShaders, "ReleaseShaders")
				.def(&Pass::GetName, "GetName")
				.def(&Pass::GetIndex, "GetIndex")
				.def(&Pass::GetBlendMode, "GetBlendMode")
				.def(&Pass::GetCullMode, "GetCullMode")
				.def(&Pass::GetDepthTestMode, "GetDepthTestMode")
				.def(&Pass::GetLightingMode, "GetLightingMode")
				.def(&Pass::GetShadersLoadedFrameNumber, "GetShadersLoadedFrameNumber")
				.def(&Pass::GetDepthWrite, "GetDepthWrite")
				.def(&Pass::GetAlphaMask, "GetAlphaMask")
				.def(&Pass::IsDesktop, "IsDesktop")
				.def(&Pass::GetVertexShader, "GetVertexShader")
				.def(&Pass::GetPixelShader, "GetPixelShader")
				.def(&Pass::GetVertexShaderDefines, "GetVertexShaderDefines")
				.def(&Pass::GetPixelShaderDefines, "GetPixelShaderDefines")
				
		];
	}
}


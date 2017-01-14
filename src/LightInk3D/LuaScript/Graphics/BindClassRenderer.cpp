

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
#include "Graphics/Renderer.h"
#include "Graphics/RenderPath.h"
#include "Graphics/Technique.h"
#include "Graphics/Texture2D.h"
#include "Graphics/Zone.h"
#include "Resource/XMLFile.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Renderer(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Renderer, void ()>(lm.state(), "Renderer", BaseClassStrategy<Object>())
				.def(&Renderer::SetNumViewports, "SetNumViewports")
				.def(&Renderer::SetViewport, "SetViewport")
				.def(static_cast<void(Renderer::*)(RenderPath*)>(&Renderer::SetDefaultRenderPath), "SetDefaultRenderPathR")
				.def(static_cast<void(Renderer::*)(XMLFile*)>(&Renderer::SetDefaultRenderPath), "SetDefaultRenderPathX")
				.def(&Renderer::SetDefaultTechnique, "SetDefaultTechnique")
				.def(&Renderer::SetHDRRendering, "SetHDRRendering")
				.def(&Renderer::SetSpecularLighting, "SetSpecularLighting")
				.def(&Renderer::SetTextureAnisotropy, "SetTextureAnisotropy")
				.def(&Renderer::SetTextureFilterMode, "SetTextureFilterMode")
				.def(&Renderer::SetTextureQuality, "SetTextureQuality")
				.def(&Renderer::SetMaterialQuality, "SetMaterialQuality")
				.def(&Renderer::SetDrawShadows, "SetDrawShadows")
				.def(&Renderer::SetShadowMapSize, "SetShadowMapSize")
				.def(&Renderer::SetShadowQuality, "SetShadowQuality")
				.def(&Renderer::SetShadowSoftness, "SetShadowSoftness")
				.def(&Renderer::SetShadowMapFilter, "SetShadowMapFilter")
				.def(&Renderer::SetReuseShadowMaps, "SetReuseShadowMaps")
				.def(&Renderer::SetMaxShadowMaps, "SetMaxShadowMaps")
				.def(&Renderer::SetDynamicInstancing, "SetDynamicInstancing")
				.def(&Renderer::SetNumExtraInstancingBufferElements, "SetNumExtraInstancingBufferElements")
				.def(&Renderer::SetMinInstances, "SetMinInstances")
				.def(&Renderer::SetMaxSortedInstances, "SetMaxSortedInstances")
				.def(&Renderer::SetMaxOccluderTriangles, "SetMaxOccluderTriangles")
				.def(&Renderer::SetOcclusionBufferSize, "SetOcclusionBufferSize")
				.def(&Renderer::SetOccluderSizeThreshold, "SetOccluderSizeThreshold")
				.def(&Renderer::SetThreadedOcclusion, "SetThreadedOcclusion")
				.def(&Renderer::SetMobileShadowBiasMul, "SetMobileShadowBiasMul")
				.def(&Renderer::SetMobileShadowBiasAdd, "SetMobileShadowBiasAdd")
				.def(&Renderer::SetMobileNormalOffsetMul, "SetMobileNormalOffsetMul")
				.def(&Renderer::ReloadShaders, "ReloadShaders")
				.def(&Renderer::GetNumViewports, "GetNumViewports")
				.def(&Renderer::GetViewport, "GetViewport")
				.def(&Renderer::GetDefaultRenderPath, "GetDefaultRenderPath")
				.def(&Renderer::GetDefaultTechnique, "GetDefaultTechnique")
				.def(&Renderer::GetHDRRendering, "GetHDRRendering")
				.def(&Renderer::GetSpecularLighting, "GetSpecularLighting")
				.def(&Renderer::GetDrawShadows, "GetDrawShadows")
				.def(&Renderer::GetTextureAnisotropy, "GetTextureAnisotropy")
				.def(&Renderer::GetTextureFilterMode, "GetTextureFilterMode")
				.def(&Renderer::GetTextureQuality, "GetTextureQuality")
				.def(&Renderer::GetMaterialQuality, "GetMaterialQuality")
				.def(&Renderer::GetShadowMapSize, "GetShadowMapSize")
				.def(&Renderer::GetShadowQuality, "GetShadowQuality")
				.def(&Renderer::GetShadowSoftness, "GetShadowSoftness")
				.def(&Renderer::GetReuseShadowMaps, "GetReuseShadowMaps")
				.def(&Renderer::GetMaxShadowMaps, "GetMaxShadowMaps")
				.def(&Renderer::GetDynamicInstancing, "GetDynamicInstancing")
				.def(&Renderer::GetNumExtraInstancingBufferElements, "GetNumExtraInstancingBufferElements")
				.def(&Renderer::GetMinInstances, "GetMinInstances")
				.def(&Renderer::GetMaxSortedInstances, "GetMaxSortedInstances")
				.def(&Renderer::GetMaxOccluderTriangles, "GetMaxOccluderTriangles")
				.def(&Renderer::GetOcclusionBufferSize, "GetOcclusionBufferSize")
				.def(&Renderer::GetOccluderSizeThreshold, "GetOccluderSizeThreshold")
				.def(&Renderer::GetThreadedOcclusion, "GetThreadedOcclusion")
				.def(&Renderer::GetMobileShadowBiasMul, "GetMobileShadowBiasMul")
				.def(&Renderer::GetMobileShadowBiasAdd, "GetMobileShadowBiasAdd")
				.def(&Renderer::GetMobileNormalOffsetMul, "GetMobileNormalOffsetMul")
				.def(&Renderer::GetNumViews, "GetNumViews")
				.def(&Renderer::GetNumPrimitives, "GetNumPrimitives")
				.def(&Renderer::GetNumBatches, "GetNumBatches")
				.def(&Renderer::GetNumGeometries, "GetNumGeometries")
				.def(&Renderer::GetNumLights, "GetNumLights")
				.def(&Renderer::GetNumShadowMaps, "GetNumShadowMaps")
				.def(&Renderer::GetNumOccluders, "GetNumOccluders")
				.def(&Renderer::GetDefaultZone, "GetDefaultZone")
				.def(&Renderer::GetDefaultMaterial, "GetDefaultMaterial")
				.def(&Renderer::GetDefaultLightRamp, "GetDefaultLightRamp")
				.def(&Renderer::GetDefaultLightSpot, "GetDefaultLightSpot")
				.def(&Renderer::DrawDebugGeometry, "DrawDebugGeometry")
		];
	}
}


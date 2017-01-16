

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
#include "Core/Variant.h"
#include "Graphics/RenderPath.h"
#include "Resource/XMLElement.h"
#include "Resource/XMLFile.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_RenderPath(LuaModule & lm)
	{
		lm
		[
			LuaRegister<RenderPath, void ()>(lm.state(), "RenderPath", BaseClassStrategy<RefCounted>())
				.def(&RenderPath::Clone, "Clone")
				.def(&RenderPath::Load, "Load")
				.def(&RenderPath::Append, "Append")
				.def(&RenderPath::SetEnabled, "SetEnabled")
				.def(&RenderPath::ToggleEnabled, "ToggleEnabled")
				.def(&RenderPath::SetRenderTarget, "SetRenderTarget")
				.def(&RenderPath::AddRenderTarget, "AddRenderTarget")
				.def(static_cast<void(RenderPath::*)(unsigned int)>(&RenderPath::RemoveRenderTarget), "RemoveRenderTargetU")
				.def(static_cast<void(RenderPath::*)(const String&)>(&RenderPath::RemoveRenderTarget), "RemoveRenderTargetS")
				.def(&RenderPath::RemoveRenderTargets, "RemoveRenderTargets")
				.def(&RenderPath::SetCommand, "SetCommand")
				.def(&RenderPath::AddCommand, "AddCommand")
				.def(&RenderPath::InsertCommand, "InsertCommand")
				.def(&RenderPath::RemoveCommand, "RemoveCommand")
				.def(&RenderPath::RemoveCommands, "RemoveCommands")
				.def(&RenderPath::SetShaderParameter, "SetShaderParameter")
				.def(&RenderPath::GetNumRenderTargets, "GetNumRenderTargets")
				.def(&RenderPath::GetNumCommands, "GetNumCommands")
				.def(&RenderPath::GetCommand, "GetCommand")
				.def(&RenderPath::GetShaderParameter, "GetShaderParameter")
			<=
			LuaRegister<RenderPathCommand, void ()>(lm.state(), "RenderPathCommand")
				.def(&RenderPathCommand::Load, "Load")
				.def(&RenderPathCommand::SetTextureName, "SetTextureName")
				.def(&RenderPathCommand::SetShaderParameter, "SetShaderParameter")
				.def(&RenderPathCommand::RemoveShaderParameter, "RemoveShaderParameter")
				.def(&RenderPathCommand::SetNumOutputs, "SetNumOutputs")
				.def(&RenderPathCommand::SetOutput, "SetOutput")
				.def(&RenderPathCommand::SetOutputName, "SetOutputName")
				.def(&RenderPathCommand::SetOutputFace, "SetOutputFace")
				.def(&RenderPathCommand::SetDepthStencilName, "SetDepthStencilName")
				.def(&RenderPathCommand::GetTextureName, "GetTextureName")
				.def(&RenderPathCommand::GetShaderParameter, "GetShaderParameter")
				.def(&RenderPathCommand::GetNumOutputs, "GetNumOutputs")
				.def(&RenderPathCommand::GetOutputName, "GetOutputName")
				.def(&RenderPathCommand::GetOutputFace, "GetOutputFace")
				.def(&RenderPathCommand::GetDepthStencilName, "GetDepthStencilName")
				.def(&RenderPathCommand::tag_, "tag")
				.def(&RenderPathCommand::type_, "type")
				.def(&RenderPathCommand::sortMode_, "sortMode")
				.def(&RenderPathCommand::pass_, "pass")
				.def(&RenderPathCommand::passIndex_, "passIndex")
				.def(&RenderPathCommand::metadata_, "metadata")
				.def(&RenderPathCommand::vertexShaderName_, "vertexShaderName")
				.def(&RenderPathCommand::pixelShaderName_, "pixelShaderName")
				.def(&RenderPathCommand::vertexShaderDefines_, "vertexShaderDefines")
				.def(&RenderPathCommand::pixelShaderDefines_, "pixelShaderDefines")
				.def(&RenderPathCommand::clearFlags_, "clearFlags")
				.def(&RenderPathCommand::clearColor_, "clearColor")
				.def(&RenderPathCommand::clearDepth_, "clearDepth")
				.def(&RenderPathCommand::clearStencil_, "clearStencil")
				.def(&RenderPathCommand::blendMode_, "blendMode")
				.def(&RenderPathCommand::enabled_, "enabled")
				.def(&RenderPathCommand::useFogColor_, "useFogColor")
				.def(&RenderPathCommand::markToStencil_, "markToStencil")
				.def(&RenderPathCommand::useLitBase_, "useLitBase")
				.def(&RenderPathCommand::vertexLights_, "vertexLights")
				.def(&RenderPathCommand::eventName_, "eventName")
			<=
			LuaRegister<RenderTargetInfo, void ()>(lm.state(), "RenderTargetInfo")
				.def(&RenderTargetInfo::Load, "Load")
				.def(&RenderTargetInfo::name_, "name")
				.def(&RenderTargetInfo::tag_, "tag")
				.def(&RenderTargetInfo::format_, "format")
				.def(&RenderTargetInfo::size_, "size")
				.def(&RenderTargetInfo::sizeMode_, "sizeMode")
				.def(&RenderTargetInfo::enabled_, "enabled")
				.def(&RenderTargetInfo::cubemap_, "cubemap")
				.def(&RenderTargetInfo::filtered_, "filtered")
				.def(&RenderTargetInfo::sRGB_, "sRGB")
				.def(&RenderTargetInfo::persistent_, "persistent")
				
		];
	}
}




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
#include "Graphics/Texture.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Texture(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Texture, void ()>(lm.state(), "Texture", BaseClassStrategy<Resource>())
				.disable_new()
				.def(CreateObject<Texture>, "new")
				.def(&Texture::SetNumLevels, "SetNumLevels")
				.def(&Texture::SetFilterMode, "SetFilterMode")
				.def(&Texture::SetAddressMode, "SetAddressMode")
				.def(&Texture::SetBorderColor, "SetBorderColor")
				.def(&Texture::SetSRGB, "SetSRGB")
				.def(&Texture::SetBackupTexture, "SetBackupTexture")
				.def(&Texture::SetMipsToSkip, "SetMipsToSkip")
				.def(&Texture::GetFormat, "GetFormat")
				.def(&Texture::IsCompressed, "IsCompressed")
				.def(&Texture::GetLevels, "GetLevels")
				.def(&Texture::GetWidth, "GetWidth")
				.def(&Texture::GetHeight, "GetHeight")
				.def(&Texture::GetDepth, "GetDepth")
				.def(&Texture::GetFilterMode, "GetFilterMode")
				.def(&Texture::GetAddressMode, "GetAddressMode")
				.def(&Texture::GetBorderColor, "GetBorderColor")
				.def(&Texture::GetSRGB, "GetSRGB")
				.def(&Texture::GetBackupTexture, "GetBackupTexture")
				.def(&Texture::GetMipsToSkip, "GetMipsToSkip")
				.def(&Texture::GetLevelWidth, "GetLevelWidth")
				.def(&Texture::GetLevelHeight, "GetLevelHeight")
				.def(&Texture::GetLevelDepth, "GetLevelDepth")
				.def(&Texture::GetUsage, "GetUsage")
				.def(static_cast<unsigned(Texture::*)(int, int) const>(&Texture::GetDataSize), "GetDataSizeII")
				.def(static_cast<unsigned(Texture::*)(int, int, int) const>(&Texture::GetDataSize), "GetDataSizeIII")
				.def(&Texture::GetRowDataSize, "GetRowDataSize")
				.def(&Texture::GetComponents, "GetComponents")
		];
	}
}




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
#include "Resource/Image.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<Image> ImageGetSubimage(const Image* self, const IntRect& rect)
	{
		return SharedPtr<Image>(self->GetSubimage(rect));
	}
	
	void bind_class_Image(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Image, void ()>(lm.state(), "Image", BaseClassStrategy<Resource>())
				.disable_new()
				.def(CreateObject<Image>, "new")
				.def(static_cast<bool(Image::*)(int, int, unsigned int)>(&Image::SetSize), "SetSizeIIU")
				.def(static_cast<bool(Image::*)(int, int, int, unsigned int)>(&Image::SetSize), "SetSizeIIIU")
				.def(static_cast<void(Image::*)(int, int, const Color&)>(&Image::SetPixel), "SetPixelIIC")
				.def(static_cast<void(Image::*)(int, int, int, const Color&)>(&Image::SetPixel), "SetPixelIIIC")
				.def(static_cast<void(Image::*)(int, int, unsigned)>(&Image::SetPixelInt), "SetPixelIntIIU")
				.def(static_cast<void(Image::*)(int, int, int, unsigned)>(&Image::SetPixelInt), "SetPixelIntIIIU")
				.def(&Image::FlipHorizontal, "FlipHorizontal")
				.def(&Image::FlipVertical, "FlipVertical")
				.def(&Image::Resize, "Resize")
				.def(&Image::Clear, "Clear")
				.def(&Image::ClearInt, "ClearInt")
				.def(&Image::SaveBMP, "SaveBMP")
				.def(&Image::SavePNG, "SavePNG")
				.def(&Image::SaveTGA, "SaveTGA")
				.def(&Image::SaveJPG, "SaveJPG")
				.def(&Image::IsCubemap, "IsCubemap")
				.def(&Image::IsArray, "IsArray")
				.def(&Image::IsSRGB, "IsSRGB")
				.def(static_cast<Color(Image::*)(int, int) const>(&Image::GetPixel), "GetPixelII")
				.def(static_cast<Color(Image::*)(int, int, int) const>(&Image::GetPixel), "GetPixelIII")
				.def(static_cast<unsigned(Image::*)(int, int) const>(&Image::GetPixelInt), "GetPixelIntII")
				.def(static_cast<unsigned(Image::*)(int, int, int) const>(&Image::GetPixelInt), "GetPixelIntIII")
				.def(&Image::GetPixelBilinear, "GetPixelBilinear")
				.def(&Image::GetPixelTrilinear, "GetPixelTrilinear")
				.def(&Image::GetWidth, "GetWidth")
				.def(&Image::GetHeight, "GetHeight")
				.def(&Image::GetDepth, "GetDepth")
				.def(&Image::GetComponents, "GetComponents")
				.def(&Image::IsCompressed, "IsCompressed")
				.def(&Image::GetCompressedFormat, "GetCompressedFormat")
				.def(&Image::GetNumCompressedLevels, "GetNumCompressedLevels")
				.def(&Image::GetNextLevel, "GetNextLevel")
				.def(&Image::GetNextSibling, "GetNextSibling")
				.def(&Image::ConvertToRGBA, "ConvertToRGBA")
				.def(&Image::GetCompressedLevel, "GetCompressedLevel")
				.def(ImageGetSubimage, "GetSubimage")
				
		];
	}
}

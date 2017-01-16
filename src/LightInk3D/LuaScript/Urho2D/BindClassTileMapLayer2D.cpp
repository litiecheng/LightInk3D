

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
#include "Scene/Node.h"
#include "Urho2D/TileMap2D.h"
#include "Urho2D/TileMapLayer2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_TileMapLayer2D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<TileMapLayer2D, void ()>(lm.state(), "TileMapLayer2D", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<TileMapLayer2D>, "new")
				.def(&TileMapLayer2D::SetDrawOrder, "SetDrawOrder")
				.def(&TileMapLayer2D::SetVisible, "SetVisible")
				.def(&TileMapLayer2D::GetTileMap, "GetTileMap")
				.def(&TileMapLayer2D::GetDrawOrder, "GetDrawOrder")
				.def(&TileMapLayer2D::IsVisible, "IsVisible")
				.def(&TileMapLayer2D::HasProperty, "HasProperty")
				.def(&TileMapLayer2D::GetProperty, "GetProperty")
				.def(&TileMapLayer2D::GetLayerType, "GetLayerType")
				.def(&TileMapLayer2D::GetWidth, "GetWidth")
				.def(&TileMapLayer2D::GetHeight, "GetHeight")
				.def(&TileMapLayer2D::GetTileNode, "GetTileNode")
				.def(&TileMapLayer2D::GetTile, "GetTile")
				.def(&TileMapLayer2D::GetNumObjects, "GetNumObjects")
				.def(&TileMapLayer2D::GetObject, "GetObject")
				.def(&TileMapLayer2D::GetObjectNode, "GetObjectNode")
				.def(&TileMapLayer2D::GetImageNode, "GetImageNode")

		];
	}
}

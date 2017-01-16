

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
#include "Urho2D/TileMapDefs2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_TileMapDefs2D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<TileMapObject2D, void ()>(lm.state(), "TileMapObject2D", BaseClassStrategy<RefCounted>())
				.def(&TileMapObject2D::GetObjectType, "GetObjectType")
				.def(&TileMapObject2D::GetName, "GetName")
				.def(&TileMapObject2D::GetType, "GetType")
				.def(&TileMapObject2D::GetPosition, "GetPosition")
				.def(&TileMapObject2D::GetSize, "GetSize")
				.def(&TileMapObject2D::GetNumPoints, "GetNumPoints")
				.def(&TileMapObject2D::GetPoint, "GetPoint")
				.def(&TileMapObject2D::GetTileGid, "GetTileGid")
				.def(&TileMapObject2D::GetTileSprite, "GetTileSprite")
				.def(&TileMapObject2D::HasProperty, "HasProperty")
				.def(&TileMapObject2D::GetProperty, "GetProperty")
			<=
			LuaRegister<Tile2D, void ()>(lm.state(), "Tile2D", BaseClassStrategy<RefCounted>())
				.def(&Tile2D::GetGid, "GetGid")
				.def(&Tile2D::GetSprite, "GetSprite")
				.def(&Tile2D::HasProperty, "HasProperty")
				.def(&Tile2D::GetProperty, "GetProperty")
			<=
			LuaRegister<PropertySet2D, void ()>(lm.state(), "PropertySet2D", BaseClassStrategy<RefCounted>())
				.def(&PropertySet2D::HasProperty, "HasProperty")
				.def(&PropertySet2D::GetProperty, "GetProperty")
			<=
			LuaRegister<TileMapInfo2D, void ()>(lm.state(), "TileMapInfo2D")
				.def(&TileMapInfo2D::GetMapWidth, "GetMapWidth")
				.def(&TileMapInfo2D::GetMapHeight, "GetMapHeight")
				.def(&TileMapInfo2D::ConvertPosition, "ConvertPosition")
				.def(&TileMapInfo2D::TileIndexToPosition, "TileIndexToPosition")
				.def(&TileMapInfo2D::PositionToTileIndex, "PositionToTileIndex")
				.def(&TileMapInfo2D::orientation_, "orientation")
				.def(&TileMapInfo2D::width_, "width")
				.def(&TileMapInfo2D::height_, "height")
				.def(&TileMapInfo2D::tileWidth_, "tileWidth")
				.def(&TileMapInfo2D::tileHeight_, "tileHeight")
		];
	}
}

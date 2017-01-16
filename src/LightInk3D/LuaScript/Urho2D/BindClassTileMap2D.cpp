

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
#include "Urho2D/TileMap2D.h"
#include "Urho2D/TileMapLayer2D.h"
#include "Urho2D/TmxFile2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	struct TM_IIB
	{
		int x_;
		int y_;
		bool result_;
	};
	static TM_IIB TileMap2DPositionToTileIndex(const TileMap2D* self, const Vector2& position)
	{
		TM_IIB iib;
		iib.result_ = self->PositionToTileIndex(iib.x_, iib.y_, position);
		return iib;
	}

	void bind_class_TileMap2D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<TileMap2D, void ()>(lm.state(), "TileMap2D", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<TileMap2D>, "new")
				.def(static_cast<void(TileMap2D::*)()>(&TileMap2D::DrawDebugGeometry), "DrawDebugGeometry")
				.def(&TileMap2D::SetTmxFile, "SetTmxFile")
				.def(&TileMap2D::GetTmxFile, "GetTmxFile")
				.def(&TileMap2D::GetInfo, "GetInfo")
				.def(&TileMap2D::GetNumLayers, "GetNumLayers")
				.def(&TileMap2D::GetLayer, "GetLayer")
				.def(&TileMap2D::TileIndexToPosition, "TileIndexToPosition")
				.def(TileMap2DPositionToTileIndex, "PositionToTileIndex")
			<=
			LuaRegister<TM_IIB, void ()>(lm.state(), "TM_IIB")
				.def(&TM_IIB::x_, "x")
				.def(&TM_IIB::y_, "y")
				.def(&TM_IIB::result_, "result")
		];
	}
}



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
#include "Graphics/OctreeQuery.h"
#include "Scene/Node.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_OctreeQuery(LuaModele & lm)
	{
		lm
		[
			LuaRegister<RayQueryResult, void ()>(lm.state(), "RayQueryResult")
				.def(&RayQueryResult::position_, "position")
				.def(&RayQueryResult::normal_, "normal")
				.def(&RayQueryResult::textureUV_, "textureUV")
				.def(&RayQueryResult::distance_, "distance")
				.def(&RayQueryResult::drawable_, "drawable")
				.def(&RayQueryResult::node_, "node")
				.def(&RayQueryResult::subObject_, "subObject")
			<=
			LuaRegister<OctreeQueryResult, void ()>(lm.state(), "OctreeQueryResult")
				.def(&OctreeQueryResult::drawable_, "drawable")
				.def(&OctreeQueryResult::node_, "node")
		];
	}
}


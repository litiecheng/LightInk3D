

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
 
#ifdef URHO3D_NAVIGATION

#include "Precompiled.h"
#include "Navigation/OffMeshConnection.h"
#include "Scene/Node.h"
#include <Detour/DetourNavMeshQuery.h>
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_OffMeshConnection(LuaModule & lm)
	{
		lm
		[
			LuaRegister<OffMeshConnection, void ()>(lm.state(), "OffMeshConnection", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<OffMeshConnection>, "new")
				.def(&OffMeshConnection::SetEndPoint, "SetEndPoint")
				.def(&OffMeshConnection::SetRadius, "SetRadius")
				.def(&OffMeshConnection::SetBidirectional, "SetBidirectional")
				.def(&OffMeshConnection::SetMask, "SetMask")
				.def(&OffMeshConnection::SetAreaID, "SetAreaID")
				.def(&OffMeshConnection::GetEndPoint, "GetEndPoint")
				.def(&OffMeshConnection::GetRadius, "GetRadius")
				.def(&OffMeshConnection::IsBidirectional, "IsBidirectional")
				.def(&OffMeshConnection::GetMask, "GetMask")
				.def(&OffMeshConnection::GetAreaID, "GetAreaID")

		];
	}
}

#endif
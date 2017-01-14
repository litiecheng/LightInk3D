

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
 
#ifdef URHO3D_NETWORK

#include "Precompiled.h"
#include "IO/PackageFile.h"
#include "Network/Connection.h"
#include "Scene/Scene.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Connection(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Connection, void ()>(lm.state(), "Connection", BaseClassStrategy<Object>())
				.def(static_cast<void(Connection::*)(int, bool, bool, const VectorBuffer&, unsigned int)>(&Connection::SendMessage), "SendMessageIBBVU")
				.def(static_cast<void(Connection::*)(int, bool, bool, const unsigned char*, unsigned int, unsigned int)>(&Connection::SendMessage), "SendMessageIBBCUU")
				.def(static_cast<void(Connection::*)(StringHash, bool, const VariantMap&)>(&Connection::SendRemoteEvent), "SendRemoteEventSHBV")
				.def(static_cast<void(Connection::*)(Node*, StringHash, bool, const VariantMap&)>(&Connection::SendRemoteEvent), "SendRemoteEventNSHBV")
				.def(&Connection::SetScene, "SetScene")
				.def(&Connection::SetIdentity, "SetIdentity")
				.def(&Connection::SetControls, "SetControls")
				.def(&Connection::SetPosition, "SetPosition")
				.def(&Connection::SetRotation, "SetRotation")
				.def(&Connection::SetConnectPending, "SetConnectPending")
				.def(&Connection::SetLogStatistics, "SetLogStatistics")
				.def(&Connection::Disconnect, "Disconnect")
				.def(&Connection::GetIdentity, "GetIdentity")
				.def(&Connection::GetScene, "GetScene")
				.def(&Connection::GetControls, "GetControls")
				.def(&Connection::GetTimeStamp, "GetTimeStamp")
				.def(&Connection::GetPosition, "GetPosition")
				.def(&Connection::GetRotation, "GetRotation")
				.def(&Connection::IsClient, "IsClient")
				.def(&Connection::IsConnected, "IsConnected")
				.def(&Connection::IsConnectPending, "IsConnectPending")
				.def(&Connection::IsSceneLoaded, "IsSceneLoaded")
				.def(&Connection::GetLogStatistics, "GetLogStatistics")
				.def(&Connection::GetAddress, "GetAddress")
				.def(&Connection::GetPort, "GetPort")
				.def(&Connection::GetRoundTripTime, "GetRoundTripTime")
				.def(&Connection::GetLastHeardTime, "GetLastHeardTime")
				.def(&Connection::GetBytesInPerSec, "GetBytesInPerSec")
				.def(&Connection::GetBytesOutPerSec, "GetBytesOutPerSec")
				.def(&Connection::GetPacketsInPerSec, "GetPacketsInPerSec")
				.def(&Connection::GetPacketsOutPerSec, "GetPacketsOutPerSec")
				.def(&Connection::ToString, "ToString")
				.def(&Connection::GetNumDownloads, "GetNumDownloads")
				.def(&Connection::GetDownloadName, "GetDownloadName")
				.def(&Connection::GetDownloadProgress, "GetDownloadProgress")
				.def(&Connection::SendPackageToClient, "SendPackageToClient")
			<=
			LuaRegister<RemoteEvent, void ()>(lm.state(), "RemoteEvent")
				.def(&RemoteEvent::senderID_, "senderID")
				.def(&RemoteEvent::eventType_, "eventType")
				.def(&RemoteEvent::eventData_, "eventData")
				.def(&RemoteEvent::inOrder_, "inOrder")
				
		];
	}
}

#endif
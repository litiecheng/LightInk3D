

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
#include "IO/VectorBuffer.h"
#include "Network/HttpRequest.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static VectorBuffer HttpRequestRead(HttpRequest* self, unsigned int size)
	{
		unsigned char* data = new unsigned char[size];
		self->Read(data, size);
		VectorBuffer buffer(data, size);
		delete[] data;
		return buffer;
	}
	void bind_class_HttpRequest(LuaModule & lm)
	{
		lm
		[
			LuaRegister<HttpRequest, void (const String&, const String&, const Vector<String>&, const String&)>(lm.state(), "HttpRequest", BaseClassStrategy<RefCounted>())
				.def(&HttpRequest::GetURL, "GetURL")
				.def(&HttpRequest::GetVerb, "GetVerb")
				.def(&HttpRequest::GetError, "GetError")
				.def(&HttpRequest::GetState, "GetState")
				.def(&HttpRequest::GetAvailableSize, "GetAvailableSize")
				.def(&HttpRequest::IsOpen, "IsOpen")
				.def(HttpRequestRead, "Read")
		];
	}
}

#endif
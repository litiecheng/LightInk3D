

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
#include "Math/StringHash.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static void reset_hash(StringHash * self, unsigned int value)
	{
		StringHash sh(value);
		*self = sh;
	}
	static void reset_hash(StringHash * self, const char * str)
	{
		StringHash sh(str);
		*self = sh;
	}
	static void reset_hash(StringHash * self, const StringHash & str)
	{
		*self = str;
	}
	void bind_class_StringHash(LuaModele & lm)
	{
		lm
		[
			LuaRegister<StringHash, void ()>(lm.state(), "StringHash")
				.def(&StringHash::operator+, "__add")
				.def(&StringHash::operator==, "__eq")
				.def(&StringHash::operator<, "__less")
				.def(&StringHash::Value, "Value")
				.def(&StringHash::ToString, "ToString")
				.def(&StringHash::ToHash, "ToHash")
				.def(StringHash::Calculate, "Calculate")
				.def(&StringHash::ZERO, "ZERO")
				.def(static_cast<void (*)(StringHash *, unsigned int)>, "reset_hashU")
				.def(static_cast<void (*)(StringHash *, const char *)>, "reset_hashC")
				.def(static_cast<void (*)(StringHash *, const StringHash &)>, "reset_hashSH")
				
		];
	}
}


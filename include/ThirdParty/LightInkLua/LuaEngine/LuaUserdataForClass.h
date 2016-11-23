


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
#ifndef LIGHTINK_LUAENGINE_LUAUSERDATAFORCLASS_H_
#define LIGHTINK_LUAENGINE_LUAUSERDATAFORCLASS_H_

#include "Common/Type.h"
#include "Common/Log.h"

namespace LightInk
{
	template<typename T>
	struct LuaUserdataForClass
	{
		LuaUserdataForClass(const T * p, bool luaGC) : m_obj((T*)p), m_luaGC(luaGC)
		{
			LogTrace("LuaUserdataForClass(T * p, bool luaGC)");
			LogTraceReturnVoid;
		}
		~LuaUserdataForClass()
		{
			LogTrace("~LuaUserdataForClass()");
			if (m_obj && m_luaGC)
			{
				delete m_obj;
			}
			m_obj = NULL;
			LogTraceReturnVoid;
		}
		T * m_obj;
		bool m_luaGC;
	};

}


#endif
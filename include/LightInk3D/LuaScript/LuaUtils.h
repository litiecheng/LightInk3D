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

#pragma once

#include "../Core/Context.h"
#include "../Container/Ptr.h"
#include "../Container/Str.h"
#include "LuaEngine/LuaStack.h"

struct lua_State;

namespace Urho3D
{
	 /// Create object.
    template<typename T>
    SharedPtr<T> CreateObject(Context* ct)
    {
        SharedPtr<T> tPtr(new T(ct));
        return tPtr;
    }

    /// Get subsystem.
    template<typename T>
    T* GetSubsystem(Context* ct)
    {
        return ct->GetSubsystem<T>();
    }
	
}

namespace LightInk
{
	
	//Urho3D::String
	template <>
	struct LuaStack <Urho3D::String>
	{
		static inline void push(lua_State * L, Urho3D::String & str)
		{
			lua_pushlstring (L, str.CString(), str.Length());
		}

		static inline Urho3D::String get(lua_State * L, int idx)
		{
			size_t len = 0;
			const char * str = luaL_checklstring(L, idx, &len);
			return(Urho3D::String(str, len));
		}
	};

	//const Urho3D::String
	template <>
	struct LuaStack <const Urho3D::String>
	{
		static inline void push(lua_State * L, const Urho3D::String & str)
		{
			lua_pushlstring (L, str.CString(), str.Length());
		}

		static inline Urho3D::String get(lua_State * L, int idx)
		{
			size_t len = 0;
			const char * str = luaL_checklstring(L, idx, &len);
			return(Urho3D::String(str, len));
		}
	};

	//const Urho3D::String &
	template <>
	struct LuaStack <const Urho3D::String &>
	{
		static inline void push(lua_State * L, const Urho3D::String & str)
		{
			lua_pushlstring (L, str.CString(), str.Length());
		}

		static inline Urho3D::String get(lua_State * L, int idx)
		{
			size_t len = 0;
			const char * str = luaL_checklstring(L, idx, &len);
			return(Urho3D::String(str, len));
		}
	};
	
	
	//vector
	template <typename T>
	struct LuaStack <Urho3D::PODVector<T> >
	{
		static inline void push(lua_State * L, typename Urho3D::PODVector<T> & vec)
		{
			lua_createtable(L, vec.Size(), 0);
			for (size_t i = 0; i < vec.Size(); ++i)
			{
				LuaStack<const T>::push(L, vec[i]);
				lua_rawseti(L, -2, i+1);
			}
		}

		static inline typename Urho3D::PODVector<T> get(lua_State * L, int idx)
		{
			if (!lua_istable(L, idx))
			{
				LogScriptErrorJump(L, "Error!!!The {} data is not a table, convert Urho3D::PODVector<T> failed!!!", idx);
			}
			idx = lua_absindex(L, idx);
			size_t len = lua_objlen(L, idx);
			Urho3D::PODVector<T> vec;
			vec.Reserve(len);
			for (size_t i = 1; i <= len; i++)
			{
				lua_rawgeti(L, idx, i);
				vec.Push(LuaStack<const T>::get(L, -1));
				lua_pop(L, 1);
			}
			LogTraceReturn(vec);
		}
	};

	//const vector
	template <typename T>
	struct LuaStack <const Urho3D::PODVector<T> >
	{
		static inline void push(lua_State * L, const typename Urho3D::PODVector<T> & vec)
		{
			lua_createtable(L, vec.Size(), 0);
			for (size_t i = 0; i < vec.Size(); ++i)
			{
				LuaStack<const T>::push(L, vec[i]);
				lua_rawseti(L, -2, i+1);
			}
		}

		static inline typename Urho3D::PODVector<T> get(lua_State * L, int idx)
		{
			if (!lua_istable(L, idx))
			{
				LogScriptErrorJump(L, "Error!!!The {} data is not a table, convert Urho3D::PODVector<T> failed!!!", idx);
			}
			idx = lua_absindex(L, idx);
			size_t len = lua_objlen(L, idx);
			Urho3D::PODVector<T> vec;
			vec.Reserve(len);
			for (size_t i = 1; i <= len; i++)
			{
				lua_rawgeti(L, idx, i);
				vec.Push(LuaStack<const T>::get(L, -1));
				lua_pop(L, 1);
			}
			LogTraceReturn(vec);
		}
	};

	//const vector &
	template <typename T>
	struct LuaStack <const Urho3D::PODVector<T> &>
	{
		static inline void push(lua_State * L, const typename Urho3D::PODVector<T> & vec)
		{
			lua_createtable(L, vec.Size(), 0);
			for (size_t i = 0; i < vec.Size(); ++i)
			{
				LuaStack<const T>::push(L, vec[i]);
				lua_rawseti(L, -2, i+1);
			}
		}

		static inline typename Urho3D::PODVector<T> get(lua_State * L, int idx)
		{
			if (!lua_istable(L, idx))
			{
				LogScriptErrorJump(L, "Error!!!The {} data is not a table, convert Urho3D::PODVector<T> failed!!!", idx);
			}
			idx = lua_absindex(L, idx);
			size_t len = lua_objlen(L, idx);
			Urho3D::PODVector<T> vec;
			vec.Reserve(len);
			for (size_t i = 1; i <= len; i++)
			{
				lua_rawgeti(L, idx, i);
				vec.Push(LuaStack<const T>::get(L, -1));
				lua_pop(L, 1);
			}
			LogTraceReturn(vec);
		}
	};
	
	
	//vector
	template <typename T>
	struct LuaStack <Urho3D::Vector<T> >
	{
		static inline void push(lua_State * L, typename Urho3D::Vector<T> & vec)
		{
			lua_createtable(L, vec.Size(), 0);
			for (size_t i = 0; i < vec.Size(); ++i)
			{
				LuaStack<const T>::push(L, vec[i]);
				lua_rawseti(L, -2, i+1);
			}
		}

		static inline typename Urho3D::Vector<T> get(lua_State * L, int idx)
		{
			if (!lua_istable(L, idx))
			{
				LogScriptErrorJump(L, "Error!!!The {} data is not a table, convert Urho3D::Vector<T> failed!!!", idx);
			}
			idx = lua_absindex(L, idx);
			size_t len = lua_objlen(L, idx);
			Urho3D::Vector<T> vec;
			vec.Reserve(len);
			for (size_t i = 1; i <= len; i++)
			{
				lua_rawgeti(L, idx, i);
				vec.Push(LuaStack<const T>::get(L, -1));
				lua_pop(L, 1);
			}
			LogTraceReturn(vec);
		}
	};

	//const vector
	template <typename T>
	struct LuaStack <const Urho3D::Vector<T> >
	{
		static inline void push(lua_State * L, const typename Urho3D::Vector<T> & vec)
		{
			lua_createtable(L, vec.Size(), 0);
			for (size_t i = 0; i < vec.Size(); ++i)
			{
				LuaStack<const T>::push(L, vec[i]);
				lua_rawseti(L, -2, i+1);
			}
		}

		static inline typename Urho3D::Vector<T> get(lua_State * L, int idx)
		{
			if (!lua_istable(L, idx))
			{
				LogScriptErrorJump(L, "Error!!!The {} data is not a table, convert Urho3D::Vector<T> failed!!!", idx);
			}
			idx = lua_absindex(L, idx);
			size_t len = lua_objlen(L, idx);
			Urho3D::Vector<T> vec;
			vec.Reserve(len);
			for (size_t i = 1; i <= len; i++)
			{
				lua_rawgeti(L, idx, i);
				vec.Push(LuaStack<const T>::get(L, -1));
				lua_pop(L, 1);
			}
			LogTraceReturn(vec);
		}
	};

	//const vector &
	template <typename T>
	struct LuaStack <const Urho3D::Vector<T> &>
	{
		static inline void push(lua_State * L, const typename Urho3D::Vector<T> & vec)
		{
			lua_createtable(L, vec.Size(), 0);
			for (size_t i = 0; i < vec.Size(); ++i)
			{
				LuaStack<const T>::push(L, vec[i]);
				lua_rawseti(L, -2, i+1);
			}
		}

		static inline typename Urho3D::Vector<T> get(lua_State * L, int idx)
		{
			if (!lua_istable(L, idx))
			{
				LogScriptErrorJump(L, "Error!!!The {} data is not a table, convert Urho3D::Vector<T> failed!!!", idx);
			}
			idx = lua_absindex(L, idx);
			size_t len = lua_objlen(L, idx);
			Urho3D::Vector<T> vec;
			vec.Reserve(len);
			for (size_t i = 1; i <= len; i++)
			{
				lua_rawgeti(L, idx, i);
				vec.Push(LuaStack<const T>::get(L, -1));
				lua_pop(L, 1);
			}
			LogTraceReturn(vec);
		}
	};
	
	
}


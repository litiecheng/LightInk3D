#
# Copyright (c) 2008-2016 the Urho3D project.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#

project (LightInk3D)

# Add targets
foreach (TARGET FreeType JO LZ4 PugiXml SDL StanHull)
    add_subdirectory (${TARGET})
endforeach ()


if (LightInk3D_LUA)
    add_subdirectory (LightInkLua)
endif ()

if (LightInk3D_NETWORK)
    add_subdirectory (libcurl)
    add_subdirectory (kNet)
	add_subdirectory (LightInkMsgPack)
endif ()


if (LightInk3D_SQLITE)
    add_subdirectory (SQLite)
endif ()

if (LightInk3D_NAVIGATION)
    add_subdirectory (Detour)
    add_subdirectory (DetourCrowd)
    add_subdirectory (DetourTileCache)
    add_subdirectory (Recast)
endif ()

if (LightInk3D_2DPHYSICS)
    add_subdirectory (Box2D)
endif ()

if (LightInk3D_3DPHYSICS)
    add_subdirectory (Bullet)
endif ()

if (NOT ANDROID AND NOT ARM AND NOT WEB)
    if (LightInk3D_OPENGL)
        add_subdirectory (ThirdParty/GLEW)
    elseif (NOT LightInk3D_D3D11)
        add_subdirectory (ThirdParty/MojoShader)
    endif ()
    if (NOT CMAKE_SYSTEM_NAME STREQUAL Linux)
        add_subdirectory (ThirdParty/LibCpuId)
    endif ()
endif ()


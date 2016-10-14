


local name = "ThirdParty"

local dirs = {
	"Box2D", 
	"Bullet", 
	"Common",
	"Detour", 
	"DetourCrowd", 
	"DetourTileCache", 
	"FreeType", 
	"GLEW", 
	"JO", 
	"kNet", 
	"LibCpuId", 
	"LightInkLua", 
	"LightInkMsgPack", 
	"LZ4", 
	"MojoShader", 
	"Mustache", 
	"PugiXml", 
	"rapidjson", 
	"Recast", 
	--"SDL", 
	"SQLite", 
	"StanHull",
	"STB", 
}

local output = g_output

local prefixInclude = "../../include/ThirdParty/"
local prefixSrc = "../../src/ThirdParty/"

set_project(name)
set_version("0.0.1")

add_subfiles("../LightInk3DOption.lua")

set_mode_config(name)


-- add target
target(name)

    -- set kind
    set_kind("shared")
	
	add_includedirs(prefixInclude)

	if output then
		set_targetdir(output.bin)
		set_objectdir(output.obj)
		set_headerdir(output.include)
	end

	add_options("LightInk3DLua")
	add_options("LightInk3DEMSCRIPTEN")
	add_options("LightInk3DSQLite")
	add_options("LightInk3DOPENGL")
	add_options("LightInk3DDX9")
	add_options("LightInk3DDX11")
	add_options("LightInk3D2D")
	add_options("LightInk3DPHYSICS")
	add_options("LightInk3DNAVIGATION")
	add_options("LightInk3DNETWORK")


for k, v in ipairs(dirs) do
	add_subdirs(v)
end


	
	


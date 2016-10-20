


local name = "ThirdParty"

local ThirdPartySubsystem = {
	"Box2D", 
	"Bullet", 
	"Civetweb", 
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
	"SDL", 
	"SQLite", 
	"StanHull",
	"STB", 
}
ThirdPartyCall = {}

local output = g_output

local prefixInclude = "../../include/ThirdParty/"
local prefixSrc = "../../src/ThirdParty/"

add_subfiles("../LightInk3DOption.lua")

for k, v in ipairs(ThirdPartySubsystem) do
	add_subdirs(v)
end

set_mode_config(name)


-- add target
target(name)

    -- set kind
    set_kind("static")
	
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
	add_options("LightInk3DDUMMYAUDIO")
	add_options("LightInk3DDISKAUDIO")
	add_options("LightInk3DVIDEO_DUMMY")

	for k, v in pairs(ThirdPartyCall) do
		v(prefixInclude, prefixSrc)
	end


	
	


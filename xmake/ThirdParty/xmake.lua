


local name = "ThirdParty"
local dirs = {
	Box2D = { option = "LightInk3D2D", }, 
	Bullet = { option = "LightInk3DPHYSICS", }, 
	Detour = { option = "LightInk3DNAVIGATION", }, 
	DetourCrowd = { option = "LightInk3DNAVIGATION", }, 
	DetourTileCache = { option = "LightInk3DNAVIGATION", }, 
	FreeType = { }, 
	GLEW = { option = "LightInk3DOPENGL", }, 
	JO = { }, 
	kNet = { option = "LightInk3DNETWORK", }, 
	LibCpuId = { plat = "linux", }, 
	LightInkLua = { option = "LightInk3DLua", }, 
	LightInkMsgPack = { option = "LightInk3DNETWORK", }, 
	LZ4 = { }, 
	MojoShader = { plat = "windows", option = "LightInk3DDX9", }, 
	Mustache = { }, 
	PugiXml = { }, 
	rapidjson = { }, 
	Recast = { option = "LightInk3DNAVIGATION", }, 
	SDL = { }, 
	SQLite = { option = "LightInk3DSQLite", }, 
	StanHull = { "", }, 
	STB = { "", }, 
}

local output = g_output

set_project(name)
set_version("0.0.1")

add_subfiles("../LightInk3DOption.lua")

set_mode_config(name)


local prefixInclude = "../../include/ThirdParty/"
local prefixSrc = "../../src/ThirdParty/"
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
		if (v.plat and not is_plat(v.plat)) or 
			(v.option and not is_option(v.option))then
			on_run(function()
				print(string.format("subdirs = %s, must plat = %s, option = %s", k, v.plat, v.option))
			end)
		else
			add_subdirs(k)
		end
		
	end
	
	
	
	
	


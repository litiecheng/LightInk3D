


local name = "LightInk3D"
local deps = { 
	ThirdParty = {
		include = "../../include/ThirdParty/",
		src = "../../src/ThirdParty/",
		},
}
local output = g_output

local ThirdPartySubsystem = {
	"../ThirdParty/Box2D", 
	"../ThirdParty/Bullet", 
	"../ThirdParty/Civetweb", 
	"../ThirdParty/Common",
	"../ThirdParty/Detour", 
	"../ThirdParty/DetourCrowd", 
	"../ThirdParty/DetourTileCache", 
	"../ThirdParty/FreeType", 
	"../ThirdParty/GLEW", 
	"../ThirdParty/JO", 
	"../ThirdParty/kNet", 
	"../ThirdParty/LibCpuId", 
	"../ThirdParty/LightInkLua", 
	"../ThirdParty/LightInkMsgPack", 
	"../ThirdParty/LZ4", 
	"../ThirdParty/MojoShader", 
	"../ThirdParty/Mustache", 
	"../ThirdParty/PugiXml", 
	"../ThirdParty/rapidjson", 
	"../ThirdParty/Recast", 
	"../ThirdParty/SDL", 
	"../ThirdParty/SQLite", 
	"../ThirdParty/StanHull",
	"../ThirdParty/STB", 
}

LightInk3DCall = {}

add_subfiles("../LightInk3DOption.lua")

for k, v in ipairs(ThirdPartySubsystem) do
	add_subdirs(v)
end

set_mode_config(name)


local prefixInclude = "../../include/LightInk3D/"
local prefixSrc = "../../src/LightInk3D/"
-- add target
target(name)

    -- set kind
    set_kind("shared")
	
	for k, v in pairs(deps) do
		-- add deps
		add_deps(k)
		-- add links
		add_links(k)
	end
	
	add_includedirs(prefixInclude)
	for k, v in pairs(deps) do
		add_includedirs(v.include)
		for kc, vc in pairs(LightInk3DCall) do
			vc(v.include, v.src)
		end
	end
	
	add_defines("Urho3D_EXPORTS", "URHO3D_IS_BUILDING")
	
	if output then
		set_targetdir(output.bin)
		set_objectdir(output.obj)
		set_headerdir(output.include)
		
		-- add link directory
		add_linkdirs(output.bin)
	else
		-- add link directory
		add_linkdirs("$(buildir)")
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

	local normalDir = { 
		Audio = "/**", 
		Container = "/**", 
		Core = "/**", 
		Graphics = "/*",
		Engine = "/**", 
		Input = "/**", 
		IO = "/**", 
		Math = "/**", 
		Resource = "/**", 
		Scene = "/**", 
		UI = "/**",
	}
	-- add headers
	add_headers(prefixInclude .. "*.h", prefixInclude .. "*.hpp")
	for k, v in pairs(normalDir) do
		add_headers(prefixInclude .. k .. v .. ".h", prefixInclude .. k .. v .. ".hpp")
	end
	
	
    -- add files
	add_files(prefixSrc .. "*.cpp")
    for k, v in pairs(normalDir) do
		add_files(prefixSrc .. k .. v .. ".cpp")
	end
	
	
	local optionDir = {
		LightInk3DLua = "LuaScript/**",
		LightInk3DSQLite = "Database/**",
		LightInk3DOPENGL = "Graphics/OpenGL/**",
		LightInk3DDX9 = "Graphics/Direct3D9/**",
		LightInk3DDX11 = "Graphics/Direct3D11/**", 
		LightInk3D2D = "2D/**",
		LightInk3DPHYSICS = "Physics/**",
		LightInk3DNAVIGATION = "Navigation/**",
		LightInk3DNETWORK = "Network/**",
	}
	
	
	for k, v in pairs(optionDir) do
		if is_option(k) then
			add_headers(prefixInclude .. v .. ".h", prefixInclude .. v .. ".hpp")
			add_files(prefixSrc .. v .. ".cpp")
		end
	end
	
	if is_option("LightInk3DDX9") then
		add_links("d3dcompiler", "d3d9")
	end
	
	if is_option("LightInk3DDX11") then
		add_links("d3dcompiler", "d3d11")
	end
	
	
	
	
	
	


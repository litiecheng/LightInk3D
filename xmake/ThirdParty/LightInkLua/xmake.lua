

local name = "LightInkLua"

local prefixInclude = "../../../include/ThirdParty/" .. name
local prefixSrc = "../../../src/ThirdParty/" .. name



-- add headers
add_headers(prefixInclude .. "/Atomic/mintomic.h.h", 
			prefixInclude .. "/LuaEngine/**.h", 
			prefixInclude .. "/LuaEngine/**.hpp", 
			prefixInclude .. "/LuaEngine/*.cpp")

	
-- add files
add_files(prefixSrc .. "/LuaEngine/**.cpp", prefixSrc .. "/LuaEngine/**.c")



	




local name = "LightInkMsgPack"

local prefixInclude = "../../../include/ThirdParty/" .. name
local prefixSrc = "../../../src/ThirdParty/" .. name



-- add headers
add_headers(prefixInclude .. "/Msgpack/**.h", 
			prefixInclude .. "/Msgpack/*.cpp")

	
-- add files
add_files(prefixSrc .. "/Msgpack/**.cpp")



	


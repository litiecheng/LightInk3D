

local name = "Common"

local prefixInclude = "../../../include/ThirdParty/" .. name
local prefixSrc = "../../../src/ThirdParty/" .. name



-- add headers
add_headers(prefixInclude .. "/*.h", prefixInclude .. "/*.cpp")

	
-- add files
add_files(prefixSrc .. "/*.cpp", prefixSrc .. "/*.c")



	


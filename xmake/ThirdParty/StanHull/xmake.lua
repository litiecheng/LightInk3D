

local name = "StanHull"

local prefixInclude = "../../../include/ThirdParty/" .. name
local prefixSrc = "../../../src/ThirdParty/" .. name



-- add headers
add_headers(prefixInclude .. "/*.h")

	
-- add files
add_files(prefixSrc .. "/*.cpp")



	


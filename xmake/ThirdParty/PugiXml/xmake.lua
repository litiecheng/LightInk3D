

local name = "PugiXml"

local prefixInclude = "../../../include/ThirdParty/" .. name
local prefixSrc = "../../../src/ThirdParty/" .. name

add_includedirs(prefixInclude)

-- add headers
add_headers(prefixInclude .. "/*.hpp")

	
-- add files
add_files(prefixSrc .. "/*.cpp")



	


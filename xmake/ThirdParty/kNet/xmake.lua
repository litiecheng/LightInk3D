

local name = "kNet"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DNETWORK") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name


		add_includedirs(prefixInclude)
		
		if is_plat("windows") then
			add_links("ws2_32")
		end
		
		-- add headers
		add_headers(prefixInclude .. "/*.h")
		add_headers(prefixInclude .. "/" .. name .. "/*.h")
		add_headers(prefixInclude .. "/" .. name .. "/*.inl")

		if is_plat("windows") then
			add_headers(prefixInclude .. "/" .. name .. "/win32/*.h")
		else
			add_headers(prefixInclude .. "/" .. name .. "/unix/*.h")
		end

			
		-- add files
		add_files(prefixSrc .. "/*.cpp")
		if is_plat("windows") then
			add_files(prefixSrc .. "/win32/*.cpp")
		else
			add_files(prefixSrc .. "/unix/*.cpp")
		end


	end
	
end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DNETWORK") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name


		add_includedirs(prefixInclude)
		
		if is_plat("windows") then
			add_links("ws2_32")
		end

	end
	
end
end

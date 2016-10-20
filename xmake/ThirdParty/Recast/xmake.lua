

local name = "Recast"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DNAVIGATION") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_includedirs(prefixInclude)

		-- add headers
		add_headers(prefixInclude .. "/*.h")

			
		-- add files
		add_files(prefixSrc .. "/*.cpp")



	end

end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DNAVIGATION") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_includedirs(prefixInclude)


	end

end
end


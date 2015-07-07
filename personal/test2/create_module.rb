wrappers = []

Dir.entries(Dir.pwd).each do |d|
	wrappers.push d if d =~ /\.i$/
end

wrapper = ""
wrapper << "%module ng\n"
wrapper << "%{\n"
wrappers.each do |w|
	wrapper << "#include #{w}\n"
end
wrapper << "%}\n"
wrappers.each do |w|
	wrapper << "%include #{w}\n"
end

puts wrapper

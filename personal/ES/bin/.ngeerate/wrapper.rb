module Wrapper
	module_function
	def create(outfile)
		usage if outfile.nil? or outfile == "help"
		@path = File.expand_path(File.dirname(__FILE__) + "/../../wrappers/")
		check_path  File.join(@path, outfile)
		@wrappers = []
		dirs = %w[core components systems]
		dirs.each do |d|
			add_wrappers File.join(@path, d)
		end
		File.open File.join(@path, outfile), 'w+' do |file|
			file << "%module ng\n"
			@wrappers.each do |w|
				file << "%include <#{w}>\n"
			end
		end
	end

	def usage
		puts "usage: ngeerate wrapper <outfile>"
		exit
	end

	def check_path outfile_path
		unless Dir.exist? File.dirname(outfile_path)
			puts "output directory not found"
			usage
		end
	end

	def add_wrappers(directory)
		Dir.entries(directory).each do |file_name|
			@wrappers.push file_name if file_name =~ /\.i$/
		end
	end
end

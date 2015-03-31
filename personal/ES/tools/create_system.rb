require 'erb'

@template_file = ""
@template_string = ""
@template_result = ""

def handle_arg(n)
	arg = ARGV[n]
	if arg.split('=').size == 2
		var = arg.split('=')[0]
		val = arg.split('=')[1]
		instance_variable_set("@#{var}", val)
		return 1
	end

	if arg.match /^-.*/
		case arg
		when "-t"
			@template_file = ARGV[n+1]
			return 2
		end
	end

	puts "unrecognized argument '#{arg}'"
	return 1
end

def process
	if File.exist? @template_file
		File.new(@template_file, 'r') do |content|
			@template_string = ERB.new(content).result
			return true
		end
	end
	return false
end


n = 0
while n < ARGV.size do
	n += handle_arg n
end

if process
	puts @template_string
else
	puts "An error occured"
end

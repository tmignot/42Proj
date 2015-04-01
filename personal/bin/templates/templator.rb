#!/usr/local/bin/ruby
require 'erubis'
require 'json'

def error(msg)
	puts "templator: error. (#{msg})"
	exit
end

def check_file(file)
	error "#{file} cannot be found" unless File.exist? file
end

def get_context
	context = {}
	if @list_vars
		context['list_vars'] = true
	elsif @context_string
		context = JSON.parse @context_string
		context['list_vars'] = false
	end
	return context
end


def print_vars(file)
	content = File.read file
	erubis = Erubis::Eruby.new content
	context = {	list_vars: true }
	puts erubis.evaluate context
	exit
end

def next_arg(n)
	ARGV[n + 1] if ARGV.size >= n + 1
end

def handle_args(n=0)
	if ARGV.size >= n+1 and ARGV[n].match /^-.*/
		case ARGV[n]
		when "-c", "--context" then @context_string = next_arg n
			handle_args n + 2
		when "-f", "--file" then @filename = next_arg n
			handle_args n + 2
		when "-o", "--output" then @outfile = next_arg n
			handle_args n + 2
		when "-l", "--list-vars" then @list_vars = true
			handle_args n + 1
		end
	end
end


handle_args()
error "missing template file name" unless @filename

check_file @filename
erubis = Erubis::Eruby.new(File.read @filename)
result = erubis.evaluate get_context

if @outfile
	File.open(@outfile, 'w') {|file| file.write result}
else
	puts result
end

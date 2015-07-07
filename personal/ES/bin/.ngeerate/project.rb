module Project
	module_function
	def create(name)
		@name = name
		usage if @name == "help"

		@template = get_template
		generate
	end

	def usage
		puts "usage: ngeerate project <name> [from <template>]"
		exit
	end

	def get_template
		ARGV.shift == "from" ? ARGV.shift : nil
	end

	def generate
		puts "#{@name} ngeerated from template #{@template}" unless @template.nil?
		puts "#{@name} ngeerated from default template" if @template.nil?
	end
end

#!/usr/bin/env ruby
require 'json'
File.open "#{File.join File.dirname(__FILE__), 'users.json'}" do |file|
	@data = JSON.parse file.read
end
i=0
@data.select do |u|
	p i, u
	i += 1
	true
end

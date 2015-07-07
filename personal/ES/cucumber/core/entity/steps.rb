#!/usr/local/bin/ruby

require_relative "../../../lib/#{RUBY_PLATFORM}/ng.so"
include Ng

When /^I call the entity factory$/ do
	@receive = Entity.new
end

Then /^I receive an Integer$/ do
	assert @receive.is_a? Integer
end

Given /^I have an entity$/ do
	@entity = Entity.new
end

When /^I call back the id$/ do
	@receive = @entity[:id]
end

And /^I have a system$/ do
	@system = ControllerSystem.new
end

When /^I add a component to the entity$/ do
	@system.add_component(@entity, ControllerSystem::Keyboard)
end

Then /^nothing$/ do end

And /^I have registered a component to the entity$/ do
	@entity[:kbd] = @system.add_component(@entity, ContollerSystem::Keyboard)
end

When /^I call back the component$/ do
	@receive = @entity[:kbd]
end

Then /^I receive its ID$/ do end

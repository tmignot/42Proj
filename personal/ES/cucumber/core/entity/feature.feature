Feature: Entity Manipulations
	In order to use entities
	As a game programmer
	I want to create them

	Scenario: Check entity.id
		Given I have an entity
		When I call back the id
		Then I receive an Integer

	Scenario: Attaching Components
		Given I have an entity
		And I have a system
		When I add a component to the entity
		Then nothing
	
	Scenario: Retreiving Components
		Given I have an entity
		And I have registered a component in it
		When I call back the component
		Then I receive its ID

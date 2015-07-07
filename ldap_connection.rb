#!/usr/bin/env ruby

require 'net/ldap'
require 'json'

ldap = Net::LDAP.new

ldap.host = 'ldap.42.fr'
ldap.port = 636
ldap.encryption :simple_tls

@users = []
if ldap.bind
	filter = Net::LDAP::Filter.contains('uid', 'mlalisse')
	ldap.search(base: "ou=paris,ou=people,dc=42,dc=fr", attributes: ['dn'], filter: filter) do |res|
		user = {}
		res.attribute_names().each do |attr|
			user[attr] = res[attr]
		end
    @users.push user
	end
	puts @users
	puts @users.count
else
	p "nobind"
end

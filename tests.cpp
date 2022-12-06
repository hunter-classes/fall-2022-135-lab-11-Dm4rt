#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "profile.h"

TEST_CASE("getUsername"){
	Profile p1("marco", "Marco");        
	Profile p2("tarma1", "Tarma Roving");    
	CHECK(p1.getUsername()=="marco");
	CHECK(p2.getUsername()=="tarma1");
}

TEST_CASE("getFullName"){
	Profile p1("marco", "Marco");        
	Profile p2("tarma1", "Tarma Roving");    
	CHECK(p1.getFullName()=="displayname (@Marco)");
	CHECK(p2.getFullName()=="displayname (@Tarma Roving)");
}

TEST_CASE("setDisplayName"){
	Profile p1("marco", "Marco");        
	Profile p2("tarma1", "Tarma Roving"); 
	p1.setDisplayName("Mark");
	p2.setDisplayName("Tarma R");	
	CHECK(p1.getFullName()=="displayname (@Mark)");
	CHECK(p2.getFullName()=="displayname (@Tarma R)");
}

TEST_CASE("constructors"){
	Profile p1("marco", "Marco");        
	Profile p2;    
	CHECK(p1.getUsername()=="marco");
	CHECK(p2.getUsername()=="");
	CHECK(p1.getFullName()=="displayname (@Marco)");
	CHECK(p2.getFullName()=="displayname (@)");
}
  


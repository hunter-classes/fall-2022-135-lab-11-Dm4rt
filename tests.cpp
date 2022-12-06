#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "profile.h"
#include "network.h"

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

TEST_CASE("addUser && numUsers"){
	Network myNetwork;
	CHECK(myNetwork.addUser("Skywalker101", "Luke Skywalker")==true);
	CHECK(myNetwork.getNumUsers()==1);
	CHECK(myNetwork.addUser("OBKenobi", "Obi Wan Kenobi")==true);
	CHECK(myNetwork.getNumUsers()==2);
	CHECK(myNetwork.addUser("SkywalkerOG", "Anakin Skywalker")==true);
	CHECK(myNetwork.getNumUsers()==3);
	//THE space should not be allowed in username
	CHECK(myNetwork.addUser("Darth Sidious", "Sheev Palpatine")==false);
	CHECK(myNetwork.getNumUsers()==3);
}

TEST_CASE("follow"){
	Network bw;
    bw.addUser("mario", "Mario");
    bw.addUser("luigi", "Luigi");
	CHECK(bw.isFollowing(0,1)==false);
	CHECK(bw.isFollowing(1,0)==false);
	CHECK(bw.follow("mario","luigi")==true);
	//CHECKS INDEX OF FOLLOWING ARRAY
	//SHOULD BE THE SAME ON BOTH ENDS (A->B and B->A)
	CHECK(bw.isFollowing(0,1)==true);
	CHECK(bw.isFollowing(1,0)==true);
}


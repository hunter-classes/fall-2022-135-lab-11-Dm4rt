#pragma once
#include "profile.h"

class Network{
	private:
	static const int MAX_USERS=20;
	Profile profiles[MAX_USERS];
	int numUsers;
	bool following[MAX_USERS][MAX_USERS];
	
	int findID(std::string usrn);
	public:
	Network();
	bool addUser(std::string usrn, std::string dspn);
	int getNumUsers();
	
	bool follow(std::string usrn1, std::string usrn2);
	void printDot();
	bool isFollowing(int,int);
};
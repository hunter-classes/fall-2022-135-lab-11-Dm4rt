#pragma once
#include "profile.h"

class Network{
	private:
	static const int MAX_USERS=20;
	Profile profiles[MAX_USERS];
	int numUsers;
	
	int findID(std::string usrn);
	public:
	Network();
	bool addUser(std::string usrn, std::string dspn);
	int getNumUsers();
	
};
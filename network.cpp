#include <iostream>
#include "profile.h"
#include "network.h"

	int Network::findID(std::string usrn){
		for(int x=0;x<numUsers;x++){
			if(usrn==profiles[x].getUsername()){
				return x;
			}
		}
		return -1;
	}
	Network::Network(){
		numUsers=0;
	}
	bool Network::addUser(std::string usrn, std::string dspn){
		if(numUsers!=20){
			for(int i=0;i<usrn.length();i++){
				if((usrn[i]<=90&&usrn[i]>=65)==false&&(usrn[i]>=97&&usrn[i]<=122)==false&&(usrn[i]>=48&&usrn[i]<=57)==false){
					return false;
				}
			}
			if(findID(usrn)!=-1){
				return false;
			}
			profiles[numUsers]=Profile(usrn,dspn);
			numUsers++;
			return true;
		}
		else{
			return false;
		}
	}
	
	int Network::getNumUsers(){
		return numUsers;
	}
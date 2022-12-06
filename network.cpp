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
		for(int y=0;y<MAX_USERS;y++){
			for(int x=0;x<MAX_USERS;x++){
				following[x][y]==false;
			}
		}
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
	
	bool Network::follow(std::string usrn1, std::string usrn2){
		int x=findID(usrn1);
		int y=findID(usrn2);
		if(x==-1||y==-1){
			return false;
		}
		else{
			following[x][y]=true;
			following[y][x]=true;
			return true;
		}
	}
	void Network::printDot(){
		std::cout<<"diagraph {"<<std::endl;
		std::string names[numUsers];
		for(int x=0;x<numUsers;x++){
			names[x]="\"@"+profiles[x].getUsername()+"\"";
			std::cout<<"  "<<names[x]<<std::endl;
		}
		std::cout<<"\n";
		std::cout<<"\n";
		for(int x=0;x<numUsers;x++){
			for(int j=0;j<numUsers;j++){
				if(following[x][j]==true){
					std::cout<<"  "<<names[x]<<" -> "<<names[j]<<std::endl;
				}
			}
		}
		std::cout<<"}"<<std::endl;
	}
	
	bool Network::isFollowing(int x, int y){
		if(following[x][y]==true){
			return true;
		}
		return false;
	}
#include <iostream>
#include "profile.h"

Profile::Profile(std::string usrn, std::string dspn){
	username=usrn;
	displayname=dspn;
}

Profile::Profile(){
	username="";
	displayname="";
}

std::string Profile::getUsername(){
	return username;
}

std::string Profile::getFullName(){
	std::string display= "displayname (@"+displayname+")";
	return display;
}

void Profile::setDisplayName(std::string dspn){
	displayname=dspn;
}
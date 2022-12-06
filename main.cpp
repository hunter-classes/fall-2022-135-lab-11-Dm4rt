#include <iostream>
#include "profile.h"
#include "network.h"

int main() {
    Profile p1("marco", "Marco");    
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    std::cout << p2.getUsername() << std::endl; // tarma1
    std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)
	
	Network nw;
	std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
	std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

	std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
	std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
	std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

	for(int i = 2; i < 20; i++)
		std::cout << nw.addUser("mario" + std::__cxx11::to_string(i), 
                 "Mario" + std::__cxx11::to_string(i)) << std::endl;   // true (1)

	std::cout << nw.addUser("yoshi", "Yoshi") << std::endl;     // false (0)
	
	
	Network bw;
    // add three users
    bw.addUser("mario", "Mario");
    bw.addUser("luigi", "Luigi");
    bw.addUser("yoshi", "Yoshi");

    // make them follow each other
    bw.follow("mario", "luigi");
    bw.follow("mario", "yoshi");
    bw.follow("luigi", "mario");
    bw.follow("luigi", "yoshi");
    bw.follow("yoshi", "mario");
    bw.follow("yoshi", "luigi");

    // add a user who does not follow others
    bw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        std::string usrn = "mario" + std::__cxx11::to_string(i);
        std::string dspn = "Mario " + std::__cxx11::to_string(i);
        bw.addUser(usrn, dspn);
        bw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    bw.follow("mario2", "luigi");

    bw.printDot();
  

}
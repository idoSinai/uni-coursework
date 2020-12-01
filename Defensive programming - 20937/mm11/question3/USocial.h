#ifndef USOCIAL_H_
#define USOCIAL_H_

#include "User.h"
#include <string>

class USocial {
	std::list<User*> _users;
public:
	~USocial();

	User* registerUser(std::string name, bool isBusiness = false); // assuming the user is not a 'business' unless mentioned otherwise
	void removeUser(User *user);
	User* getUserById(unsigned long id);
};

#endif /* USOCIAL_H_ */

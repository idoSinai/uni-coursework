#include "USocial.h"
#include "BusinessUser.h"
#include <algorithm>

USocial::~USocial() {
	std::for_each(_users.cbegin(), _users.cend(), [](User *user) {delete user; });
}

User* USocial::registerUser(std::string name, bool isBusiness) {
	User *usr = isBusiness ? new BusinessUser() : new User();
	/* Setting attributes */
	usr->_us = this;
	usr->_name = name;
	usr->_id = _users.size();

	_users.emplace_back(usr);
	return usr;
}

void USocial::removeUser(User *user) {
	/* search for a user by its id */
	auto itUser = std::find_if(_users.cbegin(), _users.cend(), [id = user->_id](const User *user) { return user->_id == id; }); 
	if (_users.end() == itUser) /* check if found */
		throw std::exception("Cant remove user which does not use this USocial");
	_users.erase(itUser);
	delete *itUser;
}

User* USocial::getUserById(unsigned long id) {
	/* search for a user by its id */
	auto itUser = std::find_if(_users.cbegin(), _users.cend(), [id](const User *user) { return user->_id == id; });
	if (_users.end() == itUser)
		throw std::exception("There is no user with this id in this USocial");
	return *itUser;
}
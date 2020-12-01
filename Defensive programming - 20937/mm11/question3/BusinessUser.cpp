#include "BusinessUser.h"

/*
Business user is able to send messages to any user
*/
void BusinessUser::sendMessage(User *usr, Message *msg) {
	if (!usr) {
		delete msg;
		throw std::exception("Tried to send to nullptr user");
	}
	if (User::getUs(*usr) !=  this->_us) {
		delete msg;
		throw std::exception("Tried to send message to someone who isn't using the same USocial!");
	}
	usr->receiveMessage(msg);
}

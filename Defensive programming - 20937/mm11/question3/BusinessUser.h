#ifndef BUSINESSUSER_H_
#define BUSINESSUSER_H_

#include "User.h"
#include "USocial.h"

/* Business user is different than user by the fact that it can send message to any user */
class BusinessUser : public User {
public:
	void sendMessage(User *usr, Message *msg);
};

#endif /* BUSINESSUSER_H_ */

#ifndef USER_H_
#define USER_H_

#include <string>
#include <list>
#include "Post.h"
#include "Message.h"

class USocial;

class User {
protected:
	USocial *_us;
	unsigned long _id;
	std::string _name;
	std::list<unsigned long> _friends;
	std::list<Post*> _posts;
	std::list<Message*> _receivedMsgs;

	User() = default;
	virtual ~User();

	/* Now class USocial can 
	   access protected members/methods of User */
	friend class USocial;

	static USocial* getUs(const User& user);

public:
	unsigned long getId();
	std::string getName();

	/* Friend's related methods*/
	void addFriend(User *user);
	void removeFriend(User *user);
	
	/* Post's related methods*/
	void post(std::string text);
	void post(std::string text, Media *media);
	std::list<Post*> getPosts();
	void viewFriendsPosts();

	/* Messages's related methods */
	void receiveMessage(Message *message);
	virtual void sendMessage(User *user, Message *message);
	void viewReceivedMessages();
};

#endif /* USER_H_ */

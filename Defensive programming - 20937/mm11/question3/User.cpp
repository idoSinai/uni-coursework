#include "User.h"
#include <algorithm>
#include "USocial.h"
#include <iostream>

User::~User() {
	std::for_each(_posts.cbegin(), _posts.cend(), [](Post *post) {delete post; });
	std::for_each(_receivedMsgs.cbegin(), _receivedMsgs.cend(), [](Message *msg) {delete msg; });
}

unsigned long User::getId() {
	return _id;
}

std::string User::getName() {
	return _name;
}

void User::addFriend(User *user) {
	if (!user)
		throw std::exception("Tried to add nullptr user!");
	if(std::find(this->_friends.cbegin(), this->_friends.cend() , user->_id) != this->_friends.cend()) // checking if not friends
		throw std::exception("Can't add frinds who already in your friends list!");
	if(user->_us != this->_us) // checking for different USocial
		throw std::exception("Can't add a friend who doesn't use the same USocial as yours!");
	this->_friends.emplace_back(user->_id);
}

void User::removeFriend(User *user) {
	if (!user) 
		throw std::exception("Tried to remove nullptr user!");
	if (std::find(this->_friends.cbegin(), this->_friends.cend(), user->_id) == this->_friends.cend()) // checking if friends
		throw std::exception("Can't remove users which aren't your friends!");
	if (user->_us != this->_us) // checking for different USocial
		throw std::exception("Can't remove a friend who doesn't use the same USocial as yours!");
	this->_friends.remove(user->_id);
}

void User::post(std::string text) {
	_posts.emplace_back(new Post(text));
}

void User::post(std::string text, Media* media) {
	_posts.emplace_back(new Post(text, media));
}

std::list<Post*> User::getPosts() {
	return _posts;
}

void User::viewFriendsPosts() {
	std::cout << "Friends's posts of user: " << _name << std::endl;
	for (auto friendId : _friends) { // moving through all of the user's friends
		std::cout << "Posts of friend " << _us->getUserById(friendId)->_name << ':' << std::endl;
		for (auto post : _us->getUserById(friendId)->_posts) { // moving through all of the friend's posts
			std::cout << post->getText() << std::endl;
			if (post->getMedia()) {
				std::cout << "attached media: ";
				post->getMedia()->Display();
			}
		}
		std::cout << std::endl;
	}
}

void User::receiveMessage(Message* message) {
	if (!message) 
		throw std::exception("Tried to receive nullptr message!");
	_receivedMsgs.emplace_back(message);
}

void User::sendMessage(User* user, Message* message) {
	if (!user) { 
		delete message;
		throw std::exception("Tried to send to nullptr user!");
	}
	if (std::find(this->_friends.cbegin(), this->_friends.cend(), user->_id) == this->_friends.cend()) { // checking if friends
		delete message;
		throw std::exception("Tried to send message to someone who isn't friend!");
	}
	if (user->_us != this->_us) { // checking for different USocial
		delete message;
		throw std::exception("Tried to send message to someone who isn't using the same USocial!");
	}
	user->receiveMessage(message);
}

void User::viewReceivedMessages() {
	std::cout << "Messages of user: " << _name << std::endl;
	for (auto msg : _receivedMsgs) 
		std::cout << *msg << std::endl;
	std::cout.put('\n');
}

USocial* User::getUs(const User& user) {
	return user._us;
}

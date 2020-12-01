#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "Media.h"
#include <iostream>
#include <string>

class Message {
	std::string _text;

public:
	Message(std::string newText);

	std::string getText();
	friend std::ostream& operator<<(std::ostream& os, const Message& msg); /* toString */
};

#endif /* MESSAGE_H_ */

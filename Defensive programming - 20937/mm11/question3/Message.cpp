#include "Message.h"

Message::Message(std::string newText) : _text(newText) 
{}


std::string Message::getText() {
	return _text;
}

/*
Overloading the << operator in order to print this object attributes's values
*/
std::ostream& operator<<(std::ostream& os, const Message& msg) {
	os << "[Message]: " << msg._text;
	return os;
}
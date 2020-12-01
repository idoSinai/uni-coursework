#include "Post.h"

Post::Post(std::string newText) : 
	_text(newText), 
	_media(nullptr) 
{}

Post::Post(std::string newText, Media *newMedia) : 
	_text(newText), 
	_media(newMedia) 
{}

Post::~Post() {
	delete _media;
}

std::string Post::getText() {
	return _text;
}

Media* Post::getMedia() {
	return _media;
}

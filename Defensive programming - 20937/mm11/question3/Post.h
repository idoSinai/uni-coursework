#ifndef POST_H_
#define POST_H_

#include "Media.h"
#include <string>

class Post {
	std::string _text;
	Media *_media;

public:
	Post(std::string newText);
	Post(std::string newText, Media *newMedia);
	~Post();

	std::string getText();
	Media* getMedia();
};

#endif /* POST_H_ */

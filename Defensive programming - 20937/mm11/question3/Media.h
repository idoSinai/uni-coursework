#ifndef MEDIA_H_
#define MEDIA_H_

#include <iostream>

class Media {
public:
	/* abstract function, denoted by = 0 */
	virtual void Display() = 0;
};


/* Specific types of media */
class Photo : public Media {
public:
	void Display();
};

class Video : public Media {
public:
	void Display();
};

class Audio : public Media {
public:
	void Display();
};

#endif /* MEDIA_H_ */

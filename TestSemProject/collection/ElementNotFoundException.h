#ifndef TESTSEMPROJECT_ELEMENTNOTFOUNDEXCEPTION_H
#define TESTSEMPROJECT_ELEMENTNOTFOUNDEXCEPTION_H


#include <stdexcept>

class ElementNotFoundException : public std::exception {
public:
	ElementNotFoundException(const char *msg) {
		this->msg = msg;
	}

	virtual char const *what() const noexcept {
		return msg;
	}

private:
	const char *msg;
};


#endif //TESTSEMPROJECT_ELEMENTNOTFOUNDEXCEPTION_H

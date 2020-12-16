#ifndef TESTSEMPROJECT_ELEMENTNOTFOUNDEXCEPTION_H
#define TESTSEMPROJECT_ELEMENTNOTFOUNDEXCEPTION_H


#include <stdexcept>

class ElementNotFoundException : public std::exception {
public:
	ElementNotFoundException(const char *msg) {
		this->msg = msg;
	}

	const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override {
		return msg;
	}

private:
	const char *msg;
};


#endif //TESTSEMPROJECT_ELEMENTNOTFOUNDEXCEPTION_H

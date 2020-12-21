#ifndef SEM_JSONLIBRARY_ELEMENTNOTFOUNDEXCEPTION_H
#define SEM_JSONLIBRARY_ELEMENTNOTFOUNDEXCEPTION_H


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


#endif //SEM_JSONLIBRARY_ELEMENTNOTFOUNDEXCEPTION_H

#ifndef SEM_JSONLIBRARY_ARRAYLIST_JSONFORMATEXCEPTION_H
#define SEM_JSONLIBRARY_ARRAYLIST_JSONFORMATEXCEPTION_H

#include <stdexcept>

class JsonFormatException : public std::exception {
public:
	JsonFormatException(const char *msg) {
		this->msg = msg;
	}

	virtual char const *what() const noexcept {
		return msg;
	}

private:
	const char *msg;
};

#endif //SEM_JSONLIBRARY_ARRAYLIST_JSONFORMATEXCEPTION_H

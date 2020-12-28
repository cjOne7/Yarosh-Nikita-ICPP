#pragma once

#include <stdexcept>

class JsonFormatException : public std::exception {
public:
	JsonFormatException(const char* msg) {
		this->msg = msg;
	}

	virtual char const* what() const noexcept {
		return msg;
	}

private:
	const char* msg;
};
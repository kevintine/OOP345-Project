#define _CRT_SECURE_NO_WARNINGS

#include "Utilities.h"


namespace sdds {
	// sets the current object's field width (m_widthField) to the newWidth
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}
	// returns current object's field width
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}
	// extracts a token from string str
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		// use the delimiter (m_delimiter) to extract the next token from str starting from next_pos
		if ()
		std::string token = str.substr(next_pos, str.find(getDelimiter()));
		more = true;
		return token;
	}
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}
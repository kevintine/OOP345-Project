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
		//	This function :
		//	uses the delimiter to extract the next token from str starting at position next_pos.
		//	If successful, return a copy of the extracted token found(without spaces at the beginning / end),
		//  update next_pos with the position of the next token, and set more to true (false otherwise).
		//	reports an exception if a delimiter is found at next_pos.
		//	updates the current object's m_widthField data member if its current value is less than the size of the token extracted.
		std::string token = str.substr(next_pos, str.find(getDelimiter()));
		more = true;
		next_pos = str.find(getDelimiter());
		if (next_pos == str.find(getDelimiter())) {
			throw "Found delimiter at next position";
			more = false;
		}
		if (getFieldWidth() < token.size())
			setFieldWidth(token.size());
		return token;

	}
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}
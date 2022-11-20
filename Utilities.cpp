#define _CRT_SECURE_NO_WARNINGS

#include "Utilities.h"
#include <algorithm> 
#include <string>

namespace sdds {
	char Utilities::m_delimiter = ' ';
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
		size_t curr_pos = next_pos;
		std::string token;
		more = true;
		next_pos = str.find(getDelimiter(), curr_pos);
		if (next_pos == std::string::npos) {
			token = str.substr(curr_pos);
			more = false;
		}
		else if (next_pos == curr_pos) {
			more = false;
			throw "No more tokens";
		}
		else {
			token = str.substr(curr_pos, next_pos - curr_pos);
			more = true;
		}
		token.erase(0, token.find_first_not_of(' '));
		token.erase(token.find_last_not_of(' ') + 1);
		if (m_widthField < token.length())
			m_widthField = token.length();
		next_pos++;
		return token;

	}
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}
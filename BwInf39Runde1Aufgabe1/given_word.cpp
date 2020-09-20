#include "given_word.h"


given_word::given_word(string word)
{
	for (int index = 0; index < word.length(); index++)
	{
		bool is_umlaut = static_cast<unsigned char>(word[index]) > 127;
		if (is_umlaut)
		{
			int special_char_number = static_cast<unsigned char>(word[index + 1]);
			umlaut_identifiers[index] = special_char_number;

			word.erase(index, 2);
			word.insert(index, "$");
		}
	}

	this->word = word;
	length = word.length();
	assigned = false;
}

void given_word::set_assigned(bool assigned)
{
	this->assigned = assigned;
}

bool given_word::get_assigned()
{
	return assigned;
}

int given_word::get_length()
{
	return length;
}

string given_word::get_word()
{
	return word;
}

int given_word::get_umlaut_code(int index)
{
	return this->umlaut_identifiers[index];
}
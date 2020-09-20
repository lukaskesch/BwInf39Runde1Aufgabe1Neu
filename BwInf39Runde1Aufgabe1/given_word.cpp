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

int given_word::get_length()
{
	return length;
}

string given_word::get_word()
{
	return word;
}

string given_word::print_word()
{
	stringstream sstream;
	for (int i = 0; i < word.size(); i++)
	{
		bool is_umlaut = word[i] == '$';
		if (is_umlaut)
		{
			int umlaut_code = get_umlaut_code(i);
			sstream << get_umlaut(umlaut_code);
		}
		else
		{
			sstream << word[i];
		}
	}

	return sstream.str();
}

string get_umlaut(int identifier)
{
	//Implement switch statement

}


int given_word::get_umlaut_code(int index)
{
	return this->umlaut_identifiers[index];
}
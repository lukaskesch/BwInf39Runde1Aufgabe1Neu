#pragma once

#include <string>
#include <map>

using namespace std;

class given_word
{
private:
	int length;
	bool assigned;
	string word;
	map<int, int> umlaut_identifiers;

public:
	given_word();
	given_word(string word);

	void set_assigned(bool assigned);
	bool get_assigned();
	int get_length();
	string get_word();

	friend bool operator<(given_word word_1, given_word word_2)
	{
		return word_1.length > word_2.length;
	}
};

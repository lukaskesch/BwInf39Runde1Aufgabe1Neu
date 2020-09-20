#include "BwInf39Runde1Aufgabe1.h"

void print_user_greetings() //O(1)
{
	cout << "Hello there!" << endl;
	cout << "This programm will loop through all the given test cases and print their solution." << endl;
}

void read_input(ifstream& input_file_stream) //O(n lg n)
{
	string line, word;

	getline(input_file_stream, line);
	stringstream input_stream_line_1(line);
	while (input_stream_line_1 >> word)
	{
		unkown_words.push_back(unkown_word(word));
	}
	solution = unkown_words;
	sort(unkown_words.begin(), unkown_words.end());

	getline(input_file_stream, line);
	stringstream input_stream_line_2(line);
	while (input_stream_line_2 >> word)
	{
		given_words.push_back(given_word(word));
	}
	sort(given_words.begin(), given_words.end());
}

void find_possible_words() //Worst: O(n^2)	Average: O(n)
{
	int current_index = 0;
	pair<int, int> index_given_word_length;
	index_given_word_length.first = current_index;
	index_given_word_length.second = given_words[current_index].get_length();

	for (int index1 = 0; index1 < given_words.size(); index1++)
	{
		given_word* given_word_object = &(given_words[index1]);

		bool change_in_word_length = index_given_word_length.second != (*given_word_object).get_length();
		if (change_in_word_length)
		{
			index_given_word_length.first = index1;
			index_given_word_length.second = (*given_word_object).get_length();
		}

		int index2 = index_given_word_length.first;
		for (index2; valid_index(index2, &index_given_word_length); index2++)
		{
			unkown_word* unkown_word_object = &(unkown_words[index2]);

			char given_char = (*unkown_word_object).get_given_char();
			int index_given_char = (*unkown_word_object).get_index_given_char();

			string word = (*given_word_object).get_word();

			bool no_given_char = given_char == ' ';
			if (no_given_char)
			{
				unkown_words[index2].possible_words.push_back(given_word_object);
				continue;
			}

			bool char_matches = given_char == word[index_given_char];
			bool is_umlaut = given_char == '$';

			if (char_matches && is_umlaut)
			{
				int umlaut_code1 = (*unkown_word_object).get_umlaut_code(index_given_char);
				int umlaut_code2 = (*given_word_object).get_umlaut_code(index_given_char);
				bool umlaut_matches = umlaut_code1 == umlaut_code2;

				if (umlaut_matches)
				{
					unkown_words[index2].possible_words.push_back(given_word_object);
				}
			}
			else if (char_matches)
			{
				unkown_words[index2].possible_words.push_back(given_word_object);
			}
		}
	}
}

bool valid_index(int index, pair<int, int>* index_given_word_length)
{
	bool out_of_bounce = index >= unkown_words.size();
	if (out_of_bounce)
	{
		return false;
	}

	bool change_in_word_length = (*index_given_word_length).second != unkown_words[index].get_length();
	if (change_in_word_length)
	{
		return false;
	}

	return true;
}

void solve() //O(n)
{

}

void print_solution() //O(n)
{
	stringstream output;
	for (int i = 0; i < solution.size(); i++)
	{
		unkown_word word = solution[i];
		output << word.print();
	}
	cout << output.str();
}

void cleanup() //O(n)
{
	given_words.clear();
	unkown_words.clear();
	solution.clear();
}

int main()
{
	print_user_greetings();
	unkown_word::preparation();

	for (int i = 0; i < number_of_tests; i++)
	{
		string file_name = "examples/raetsel";
		file_name.append(to_string(i));
		file_name.append(".txt");
		cout << endl << "file: " << file_name << endl;
		ifstream input_file_stream(file_name);

		/*string line;
		getline(input_file_stream, line);
		cout << line << "\nTest";

		getline(cin, line);*/


		read_input(input_file_stream);
		find_possible_words();
		solve();
		print_solution();
		cleanup();

		return 0;
	}
	return 0;
}
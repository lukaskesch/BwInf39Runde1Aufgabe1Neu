#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

#include "given_word.h"
#include "unkown_word.h"

using namespace std;

//Variables
const int number_of_tests = 5;
vector<given_word> given_words;
vector<unkown_word> unkown_words;
vector<unkown_word> solution;

//Methods
void print_user_greetings();
void read_input(ifstream& input_file_stream);
void find_possible_words();
void solve();
void print_solution();
void cleanup();
int main();

bool valid_index(int index, pair<int, int>* index_given_word_length);

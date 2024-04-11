#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

unsigned int word_counter;
vector<string> unigram_vector;	//	 holds all the values of the data
set<string> unigram_set;	//	use of sets to get rid of redundancies and just count the items themselves
fstream file;
string filename_input, filename_output, word;
ofstream out;

string* unigram_array = nullptr;
unsigned int* unigram_count;
unsigned int num_of_unigram;

long index;
unsigned int file_size;


void Word_Process(string& word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if ((int(word[i]) >= 65) && (int(word[i]) <= 90) || (int(word[i]) >= 97) && (int(word[i]) <= 122))	//	only capital/lower case letters allowed
		{
			if (!isalpha(word[i]))
			{
				word.erase(word.begin() + i);
				i--;
			}
			else
			{
				word[i] = tolower(word[i]);
			}
		}
		else
		{
			word.erase(word.begin() + i);
			i--;
		}
	}
}

void Copy2Array(const set<string>& s, string*& Arr)
{
	set<string>::iterator itr;
	itr = s.begin();

	unsigned int length = s.size();
	Arr = new string[length];

	for (long i = 0; i < length; i++)
	{
		Arr[i] = *itr;
		itr++;
	}
}


long Linear_Search(const string& unigram)
{
	for (long i = 0; i < num_of_unigram; i++)
	{
		if (unigram == unigram_array[i])
			return i;
	}

	return -1;
}


void displayVector(vector<string>& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
}

void displaySet(set<string>& s)
{
	set<string>::iterator itr;

	for (itr = s.begin(); itr != s.end(); itr++)
	{
		cout << *itr << " ";
	}
}

void displayArray(string*& Arr)
{
	unsigned int length = Arr->length();

	for (int i = 0; i < length; i++)
	{
		cout << Arr[i] << " ";
	}
}

int main()
{
	filename_input = "C:\\3304 Input File\\data.txt";

	file.open(filename_input.c_str());
	word_counter = 0;

	while (file >> word)
	{
		word_counter++;
		Word_Process(word);
		unigram_vector.push_back(word);
		unigram_set.insert(word);
	}
	Copy2Array(unigram_set, unigram_array);


	
	num_of_unigram = unigram_set.size();	//	makes the number set to the amount of unigrams, integer
	unigram_count = new unsigned int[num_of_unigram]();	//	creates array pointer, array; i kept messing this up bc of parenthesis
	file_size = unigram_vector.size();	//	takes size of vector, 8

	/*
	for (int i = 0; i < 8; i++)		//	used this to see if Linear_Search works, which it does
	{
		long index = Linear_Search(unigram_vector[i]);

		cout << index << " ";
	}
	cout << endl;
	*/

	//	Counting unigram occurences
	for (int i = 0; i < file_size; i++)
	{
		index = Linear_Search(unigram_vector[i]);	//	inputs string one at a time for all strings available, 

		if (index >= 0)		//	I messed up here, since Linear Search will spit out 0's in the beginning
			unigram_count[index]++;		//	such strange code, 
		else
			cout << "could not find" << endl;
	}
	int first = unigram_count[0];
	int second = unigram_count[1];
	int third = unigram_count[2];
	int fourth = unigram_count[3];
	int fifth = unigram_count[4];
	cout << first << endl;
	cout << second << endl;
	cout << third << endl;
	//cout << fourth << endl;
	//cout << fifth << endl;
	


	displayVector(unigram_vector);	//	checking values
	cout << endl << endl;
	displaySet(unigram_set);	//	checking values
	cout << endl << endl;
	displayArray(unigram_array);

	out.open("C:\\3304 Output File\\unigram counts.csv");
	out << "Unigram" << ',' << "Count" << endl;

	for (unsigned int t = 0; t < num_of_unigram; t++)
	{
		out << unigram_array[t] << ',' << unigram_count[t] << endl;
	}

	out.close();
	
}
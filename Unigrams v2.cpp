#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

fstream file;
int word_counter = 0;
int index, fileSize;
int count1;
string word, filename_input, filename_output;

ofstream out;

vector<string> file_vector;
set<string> file_set;
string* file_arr = nullptr;
int* unigram_count;

void Process_Word(string& word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if ((int(word[i]) >= 65) && (int(word[i]) <= 90) || (int(word[i]) <= 97) && (int(word[i]) <= 122))
		{
			if (!isalpha(word[i]))
			{
				word.erase(word.begin() + i);
				i--;
			}
			else
				word[i] = tolower(word[i]);
		}
	}
}

void CopyOverArray(const set<string>& s, string*& Arr)
{
	set<string>::iterator itr = s.begin();
	int length = s.size();	//	necessary so Arr[i] doesn't start complaining later

	Arr = new string[length];

	for (int i = 0; i < length; i++)
	{
		Arr[i] = *itr;
		itr++;
	}
}

int LinearSearch(const string& unigram)
{
	for (int i = 0; i < count1; i++)
	{
		if (unigram == file_arr[i])		//	checks the vector against the string array and spits out the array index value
			return i;
	}

	return -1;
}



void displayVector(vector<string>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
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
	for (int i = 0; i < Arr->length(); i++)
	{
		cout << Arr[i] << " ";
	}
}



int main()
{
	filename_input = "C:\\3304 Input File\\data1.txt";

	file.open(filename_input.c_str());

	while (file >> word)
	{
		word_counter++;
		Process_Word(word);
		file_vector.push_back(word);
		file_set.insert(word);
	}
	CopyOverArray(file_set, file_arr);

	count1 = file_set.size();
	fileSize = file_vector.size();
	unigram_count = new int[count1]();

	//displayVector(file_vector);
	//cout << endl;
	//displaySet(file_set);
	//cout << endl << word_counter << endl << endl;
	//displayArray(file_arr);

	for (int i = 0; i < fileSize; i++)
	{
		index = LinearSearch(file_vector[i]);

		if (index >= 0)
			unigram_count[index]++;
		else
			cout << "Could not find";
	}

	out.open("C:\\3304 Output File\\output1.csv");
	out << "Unigram" << ',' << "Count" << endl;

	for (int i = 0; i < count1; i++)
	{
		out << file_arr[i] << ',' << unigram_count[i] << endl;
	}

	out.close();
}
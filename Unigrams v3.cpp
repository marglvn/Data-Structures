#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>

using namespace std;


fstream file;	//
//int word_counter;
//int index;
int setcount;
vector<string> file_contents;	//
set<string> file_unique_contents;	//
string filename_input, word;	//
ofstream out;	//

string* dataArray = nullptr;	//-
int* unigram_count;


void Word_Process(string& word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if ((int(word[i])) >= 65 && (int(word[i])) <= 90 || (int(word[i])) >= 97 && (int(word[i])) <= 122)
			word[i] = tolower(word[i]);
		else
		{
			word.erase(word.begin() + i);
			i--;
		}

	}
}

void CopyToArray(set<string>& s, string*& Arr)
{
	set<string>::iterator itr = s.begin();
	int length = s.size();

	Arr = new string[length];

	for (int i = 0; i < length; i++)
	{
		Arr[i] = *itr;
		itr++;
	}
}

int LinearSearch(const string& unigram, string*& dataset)	//	can be modified by bringing in both data sets
{
	for (int i = 0; i < setcount; i++)
	{
		if (unigram == dataset[i])
			return i;
	}

	return -1;
}

void Copy(string*& dataset, vector<string>& v, int*& count)
{
	int wordcount = v.size();
	int index;

	for (int i = 0; i < wordcount; i++)
	{
		index = LinearSearch(v[i], dataset);

		if (index >= 0)
			count[index]++;
		else
			cout << "Could not find";
	}
}

/*
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

void displayArray(string*& Array)
{
	for (int i = 0; i < Array->length(); i++)
	{
		cout << Array[i] << " ";
	}
}

void displayInt(int*& arr)
{
	for (int i = 0; i < setcount; i++)
	{
		cout << arr[i] << " ";
	}
}
*/

int main()
{
	/*
	fstream file;	//
	//int word_counter;
	//int index;
	int setcount = 0;
	vector<string> file_contents;	//
	set<string> file_unique_contents;	//
	string filename_input, word;	//
	ofstream out;	//
	string* dataArray = nullptr;	//-
	int* unigram_count;

	string* dataArray = nullptr;	//-
	int* unigram_count;
	*/

	filename_input = "C:\\3304 Input File\\data.txt";

	file.open(filename_input.c_str());

	//word_counter = 0;

	while (file >> word)
	{
		Word_Process(word);
		file_contents.push_back(word);
		file_unique_contents.insert(word);
	}

	CopyToArray(file_unique_contents, dataArray);

	setcount = file_unique_contents.size();
	unigram_count = new int[setcount]();

	Copy(dataArray, file_contents, unigram_count);

	
	/*
	for (int i = 0; i < word_counter; i++)
	{
		index = LinearSearch(file_contents[i]);

		if (index >= 0)
			unigram_count[index]++;
		else
			cout << "Could not find";
	}
	*/

	cout << "Unigram Count" << endl;
	
	for (int i = 0; i < setcount; i++)
	{
		cout << dataArray[i] << " " << unigram_count[i] << endl;
	}


	//displayInt(unigram_count);
	//displayVector(file_contents);
	//cout << endl;
	//displaySet(file_unique_contents);
	//cout << endl;
	//displayArray(dataArray);


}
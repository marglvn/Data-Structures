#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>

using namespace std;

fstream file;
int word_counter;
vector<string> file_contents;
set<string> file_unique_contents;
string filename_input, word;
ofstream out;

string* dataArray = nullptr;

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

int main()
{
	filename_input = "C:\\3304 Input File\\data.txt";

	file.open(filename_input.c_str());

	word_counter = 0;

	while (file >> word)
	{
		word_counter++;
		Word_Process(word);
		file_contents.push_back(word);
		file_unique_contents.insert(word);
	}

	CopyToArray(file_unique_contents, dataArray);

	displayVector(file_contents);
	cout << endl;
	displaySet(file_unique_contents);
	cout << endl;
	displayArray(dataArray);


}
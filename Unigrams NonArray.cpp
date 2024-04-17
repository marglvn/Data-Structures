#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void Word_Process(string& word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if (int(word[i]) >= 65 && int(word[i]) <= 90 || int(word[i]) >= 97 && int(word[i]) <= 122)
			word[i] = tolower(word[i]);
		else
		{
			word.erase(word.begin() + i);
			i--;
		}
	}
}

int LinearSearch(string& unigram, set<string>& s)	//	Having trouble cycling through the set
{
	set<string>::iterator itr = s.begin();
	int size = s.size();

	for (itr = s.begin(); itr != s.end(); itr++)
	{
		int i = 0;
		if (unigram == *itr)
		{
			
			return i;
		}
		i++;
	}

	return -1;
}

void FillCount(vector<string>& v, set<string>& s, int* unique, int counter)
{
	int index;

	for (int i = 0; i < counter; i++)
	{
		index = LinearSearch(v[i], s);
		unique[index]++;
	}
}

void display(vector<string>& v, set<string>& s)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	cout << endl;

	set<string>::iterator itr;

	for (itr = s.begin(); itr != s.end(); itr++)
		cout << *itr << " ";
}

int main()
{
	fstream file;
	string filename_input, word;
	int counter = 0;
	vector<string> rawdata;
	set<string> dataset;
	int* unique_count;
	int number;
	set<string>::iterator itr;

	filename_input = "C:\\3304 Input File\\data.txt";

	file.open(filename_input.c_str());

	while (file >> word)
	{
		counter++;
		Word_Process(word);
		rawdata.push_back(word);
		dataset.insert(word);
	}

	number = dataset.size();
	unique_count = new int[number]();

	FillCount(rawdata, dataset, unique_count, counter);

	cout << "Unigram     Count" << endl;

	itr = dataset.begin();

	for (int i = 0; i < number; i++)
	{
		cout << *itr << "          " << unique_count[i] << endl;
		itr++;
	}
}
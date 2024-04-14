#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>

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

void CopySetArray(set<string>& s, string*& arr)
{
	set<string>::iterator itr = s.begin();
	int length = s.size();

	arr = new string[length];

	for (int i = 0; i < length; i++)
	{
		arr[i] = *itr;
		itr++;
	}
}

int LinearSearch(const string& unigram, string*& arr)
{
	int dataquantity = arr->size();

	for (int i = 0; i < dataquantity; i++)
	{
		if (unigram == arr[i])
			return i;
	}
	return -1;
}

void fillCount(vector<string>& v, string*& arr, int*& arrCount, int word_counter)
{
	int index;

	for (int i = 0; i < word_counter; i++)
	{
		index = LinearSearch(v[i], arr);
		arrCount[index]++;
	}
}

/*
void displayUnigram(int*& arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void displayArray(string*& arr)
{
	for (int i = 0; i < arr->size(); i++)
	{
		cout << arr[i] << " ";
	}
}
*/

int main()
{
	fstream file;
	string filename_input, word;
	int word_counter = 0;
	vector<string> rawdata;
	set<string> dataset;
	string* dataArray;
	int* unigram_count;
	int unique_unigrams;
	ofstream out;
	string filename_output;
	//int index;

	filename_input = "C:\\3304 Input File\\data.txt";

	file.open(filename_input.c_str());

	while (file >> word)
	{
		word_counter++;
		Word_Process(word);
		rawdata.push_back(word);
		dataset.insert(word);
	}

	CopySetArray(dataset, dataArray);

	unique_unigrams = dataset.size();
	unigram_count = new int[unique_unigrams]();

	fillCount(rawdata, dataArray, unigram_count, word_counter);

	/*
	for (int i = 0; i < word_counter; i++)
	{
		index = LinearSearch(rawdata[i], dataArray);
		unigram_count[index]++;
	}

	//displayUnigram(unigram_count, unique_unigrams);
	*/

	filename_output = "C:\\3304 Output File\\unigrams.csv";

	out.open(filename_output);

	out << "Unigram" << ',' << "Count" << endl;

	for (int i = 0; i < unique_unigrams; i++)
	{
		out << dataArray[i] << ',' << unigram_count[i] << endl;
	}

	out.close();
}
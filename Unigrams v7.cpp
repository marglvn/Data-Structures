#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>

using namespace std;

class WordCount
{
	private:

		int* unique_count;

	public:

		WordCount(int num)
		{
			unique_count = new int[num]();
		}

		void count(int index)
		{
			unique_count[index]++;
		}

		int display(int index)
		{
			return unique_count[index];
		}
};

class DataSet
{
	private:

		string* dataset;

	public:

		DataSet(int num)
		{
			dataset = new string[num];
		}

		void add(int index, string word)
		{
			dataset[index] = word;
		}

		string display(int index)
		{
			return dataset[index];
		}

		int size()
		{
			return dataset->size();
		}

};

void Process_Word(string& word)
{
	for (int i = 0; i < word.size(); i++)
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

void Fill(fstream& f, string word, int& word_counter, vector<string>& v, set<string>& s)
{
	while (f >> word)
	{
		word_counter++;
		Process_Word(word);
		v.push_back(word);
		s.insert(word);
	}
}

void CopyArray(set<string>& s, DataSet arr)
{
	set<string>::iterator itr = s.begin();
	int length = s.size();

	for (int i = 0; i < length; i++)
	{
		arr.add(i, *itr);
		itr++;
	}
}

int LinearSearch(string& unigram, DataSet arr)
{
	int size = arr.size();

	for (int i = 0; i < size; i++)
	{
		if(unigram == arr.display(i))
		return i;
	}

	return -1;
}

void FillCount(vector<string>& v, DataSet arr, WordCount arrCount, int word_counter)
{
	int index;

	for (int i = 0; i < word_counter; i++)
	{
		index = LinearSearch(v[i], arr);
		arrCount.count(index);
	}
}

int main()
{
	fstream file;
	string filename_input, word;
	int word_counter = 0;
	vector<string> rawdata;
	set<string> dataset;
	int data_amount;

	filename_input = "C:\\3304 Input File\\data.txt";
	file.open(filename_input.c_str());

	Fill(file, word, word_counter, rawdata, dataset);
	
	data_amount = dataset.size();

	DataSet data(data_amount);
	WordCount count(data_amount);

	CopyArray(dataset, data);

	FillCount(rawdata, data, count, word_counter);

	cout << "Unigram     Count" << endl;

	for (int i = 0; i < data_amount; i++)
	{
		cout << data.display(i) << "          " << count.display(i) << endl;
	}
}
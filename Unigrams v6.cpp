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

		void addCount(int index)
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

		string* data;

	public:

		DataSet(int num)
		{
			data = new string[num];
		}

		void addValue(int index, const string& word)
		{
			data[index] = word;
		}

		string display(int index) const
		{
			return data[index];
		}

		int size()
		{
			return data->size();
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

void CopyArray(set<string>& dataset, DataSet data)
{
	set<string>::iterator itr = dataset.begin();
	int length = dataset.size();

	for (int i = 0; i < length; i++)
	{
		data.addValue(i, *itr);
		itr++;
	}
}

int LinearSearch(const string& unigram, DataSet arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (unigram == arr.display(i))
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
		arrCount.addCount(index);
	}
}

int main()
{
	fstream file;
	string filename_input, filename_output, word;
	int word_counter = 0;
	int unique_count;
	vector<string> rawdata;
	set<string> dataset;
	

	filename_input = "C:\\3304 Input File\\data.txt";

	file.open(filename_input.c_str());

	while (file >> word)
	{
		word_counter++;
		Process_Word(word);
		rawdata.push_back(word);
		dataset.insert(word);
	}
	unique_count = dataset.size();
	DataSet data(unique_count);
	CopyArray(dataset, data);

	WordCount count(unique_count);

	FillCount(rawdata, data, count, word_counter);

	cout << "Unigram     Count" << endl;

	for (int i = 0; i < unique_count; i++)
	{
		cout << data.display(i) << "          " << count.display(i) << endl;
	}
}
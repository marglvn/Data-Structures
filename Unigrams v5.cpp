#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

class WordCount
{
	private:

		int* wordcount;

	public:

		WordCount(int num)
		{
			wordcount = new int[num]();
		}

		void addCount(int index)
		{
			wordcount[index]++;
		}

		int getCount(int index) const
		{
			return wordcount[index];
		}
};

class DataSet
{
	private:

		string* dataarray;

	public:

		DataSet(int num)
		{
			dataarray = new string[num];
		}

		void addValue(int num, const string& value)
		{
			dataarray[num] = value;
		}

		string getValue(int num) const
		{
			return dataarray[num];
		}

		int size()
		{
			return dataarray->size();
		}

};

void Word_Process(string& word)
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

void CopyOverArray(set<string>& s, DataSet arr)
{
	set<string>::iterator itr = s.begin();
	int length = s.size();

	for (int i = 0; i < length; i++)
	{
		arr.addValue(i, *itr);
		itr++;
	}
}

int LinearSearch(const string& unigram, DataSet arr)
{
	int dataquantity = arr.size();

	for (int i = 0; i < dataquantity; i++)
	{
		if (unigram == arr.getValue(i))
			return i;
	}

	return -1;
}

void FillCount(vector<string>& v, DataSet arr, WordCount countArr, int word_counter)
{
	int index;

	for (int i = 0; i < word_counter; i++)
	{
		index = LinearSearch(v[i], arr);
		countArr.addCount(index);
	}
}

int main()
{
	fstream file;
	string filename_input, filename_output, word;
	int word_counter = 0;
	vector<string> rawdata;
	set<string> dataset;
	//string* dataArray;
	//int* unique_unigrams;
	int unique_count;

	filename_input = "C:\\3304 Input File\\data.txt";

	file.open(filename_input.c_str());

	while (file >> word)
	{
		word_counter++;
		Word_Process(word);
		rawdata.push_back(word);
		dataset.insert(word);
	}
	DataSet data(dataset.size());

	CopyOverArray(dataset, data);

	WordCount count1(dataset.size());
	unique_count = dataset.size();
	//unique_unigrams = new int[unique_count]();

	FillCount(rawdata, data, count1, word_counter);

	cout << "Unigram     Count" << endl;

	for (int i = 0; i < unique_count; i++)
	{
		cout << data.getValue(i) << "          " << count1.getCount(i) << endl;
	}

	system("pause");
	//data.~DataSet();
	//count1.~WordCount();
}
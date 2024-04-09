#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <list>
#include <time.h>
#include <Windows.h>


using namespace std;

unsigned int word_counter;
long i, index;
string word, one_string_unigram;
ifstream in;
vector<string>file;
set<string> unigram_set;
string* unigram_array = nullptr;
unsigned int* unigram_counts;
unsigned int num_of_unique_unigrams;
unsigned int file_size;
string foldername_filename;
ofstream out;



void Process_Word(string& word)
{
	for (i = 0; i < word.length(); i++)
	{
		if ((int(word[i]) >= 65) && (int(word[i]) <= 128))	//	to ensure that
		{
			if (!isalnum(word[i]))	//	 if the character is not a number
			{
				word.erase(word.begin() + i);	//	erase that letter
				i--;	//	necessary to not skip characters
			}
			else
			{
				word[i] = tolower(word[i]);		//	convert the character
			}
		}
		else
		{
			word.erase(word.begin() + i);	//	erase that letter
			i--;	//	necessary to not skip characters
		}
	}
}



void Copy_Set_To_Array(const set<string>& s, string*& Arr)
{
	set<string>::iterator set_iter;
	unsigned int length = s.size();

	Arr = new string[length];

	set_iter = s.begin();
	for (i = 0; i < length; i++)
	{
		Arr[i] = *set_iter;
		set_iter++;
	}
}



void Compute_1_Filename(string directory, string& filename)
{
	WIN32_FIND_DATAA findfiledata;
	HANDLE hfind;
	string file_extension = "*.txt";
	string directory_file_ext = directory + file_extension;
	hfind = FindFirstFileA(directory_file_ext.c_str(), &findfiledata);

	if (hfind != INVALID_HANDLE_VALUE)
		filename = directory + findfiledata.cFileName;
	else
	{
		cout << "No file was present in C:\\3304 Input File\\ " << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
}



long Linear_Search(const string& unigram)
{
	for (long i = 0; i < num_of_unique_unigrams; i++)
	{
		if (unigram == unigram_array[i])
			return i;
	}

	return -1;
}



int main()
{
	clock_t begin, end;
	begin = clock();

	Compute_1_Filename("C:\\3304 Input File\\", foldername_filename);
	cout << "Your Name(s) " << endl;
	cout << "Unigram Counter " << endl;
	cout << "Counting Unigrams from: " << foldername_filename << endl;

	in.open(foldername_filename);
	word_counter = 0;

	while (in >> word)
	{
		word_counter++;
		Process_Word(word);
		file.push_back(word);
		unigram_set.insert(word);
	}
	file_size = file.size();
	if (file_size == 0)
	{
		cout << "Empty File" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	num_of_unique_unigrams = unigram_set.size();
	Copy_Set_To_Array(unigram_set, unigram_array);
	
	unigram_counts = new unsigned int[num_of_unique_unigrams]();

	file_size = file.size();

	//	Count unigram occurences
	for (word_counter = 0; word_counter < file_size; word_counter++)
	{
		index = Linear_Search(file[word_counter]);

		if (index >= 0)
			unigram_counts[index]++;
		else
			cout << "Could not find " << one_string_unigram << " in the unigram_array" << endl;
	}

	//	Output unigram counts
	out.open("C:\\3304 Output File\\unigram counts.csv");
	out << "Unigram" << ',' << "Count" << endl;

	for (unsigned int t = 0; t < num_of_unique_unigrams; t++)
	{
		out << unigram_array[t] << ',' << unigram_counts[t] << endl;
	}

	out.close();

	delete[] unigram_array;
	unigram_array = nullptr;

	delete[] unigram_counts;
	unigram_counts = nullptr;

	end = clock();
	cout << "Elapsed Time: " << double(end - begin) / CLOCKS_PER_SEC << endl;
	system("pause");
}
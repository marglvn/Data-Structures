#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

struct values
{
	string index;
	int occurence;
};

//template <class T>
void transfer(vector<values>& v, fstream& f)
{
	values V;
	string line;

	while (getline(f, line))
	{
		stringstream stream(line);
		string cell;

		while (getline(stream, cell, ' '))
		{
			int i = 0;
			V.index = cell;
			V.occurence = i;
			v.push_back(V);
			//i++;
		}
	}
}

/*
void fix(vector<values>& v)
{
	values V;

	for (int i = 0; i < v.size(); i++)
	{
		string temp = v[i].index;
		for (int j = 0; j < temp.size(); j++)
		{
			string temp2;
			while (temp[j] >= '65' || temp[j] <= '90' && temp[j] >= '97' || temp[j] <= '122')
			{
				while (temp[j] < 65 || temp[j] > 90 && temp[j] < 97 || temp[j] > 122)
				{
					temp.erase(j);
				}

				temp2 = j;
			}
			v[i].index = temp2;
		}
	}
}
*/

void fix(vector<values>& v)
{
	values V;

	for (int i = 0; i < v.size(); i++)
	{
		string temp;
		for (int j = 0; v[i].index.size(); j++)
		{
			if (isalpha(v[i].index[j]))
			{
				temp += v[i].index[j];
			}
		}
		v[i].index = temp;
	}
}

void display(vector<values>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].index << " " << v[i].occurence << endl;
	}
}

int main()
{
	fstream file;
	string fileName;
	vector<values> matrix;

	cout << "Enter file name: ";
	getline(cin, fileName);

	file.open(fileName.c_str());

	if (file.is_open())
	{
		cout << "Opening...\n";
		transfer(matrix, file);

		display(matrix);

		fix(matrix);

		display(matrix);
	}
}
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Solution
{
	public:
		int titletoNumber(string s)
		{
			int r = 0;
			for (int i = 0; i < s.length(); i++)
			{
				r = r * 26 + s[i] - 64;
			}
			return r;
		}
};

int main()
{
	fstream file;

	string filename;
	cout << "Please enter the input file name: ";
	getline(cin, filename);
	file.open(filename.c_str());
}
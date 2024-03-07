#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    void twoSum(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[i] != nums[j] && nums[i] + nums[j] == target)
                {
                    cout << "[" << i << "," << j << "]" << endl;
                }
            }
        }
    }
};

int main()
{
    Solution solve;
    vector<int> values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int input;
    cout << "Enter a value you want array to add up to: ";
    cin >> input;

    solve.twoSum(values, input);
}
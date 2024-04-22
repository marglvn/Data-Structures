/*

A palindrome is any word, phrase, or sentence that reads the same forward and backward.
Design a function that uses recursion to determine if a string argument is a palindrome.The function should return true
if the argument reads the same forward and backward.Demonstrate that the function works in a program.For this
exercise, the solution is case sensitive(A is not equal to a).

*/

#include <iostream>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    // Base case: when start index is greater than or equal to end index
    if (start >= end) {
        return true;
    }

    // Check if characters at start and end indices are equal
    if (str[start] != str[end]) {
        return false;
    }

    // Recursively check characters from start+1 to end-1
    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
	string value = "abba";

    bool table = isPalindrome(value, 0, 3);

    cout << table << endl;

}
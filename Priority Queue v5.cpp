//Priority Queue
//Written by: Cyril Harris
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PriorityQueue
{
private:
    vector<int> data;

public:
    // Returns the number of elements in the priority queue
    int size()
    {
        return data.size();
    }

    // Returns true if the priority queue is empty, false otherwise
    bool empty()
    {
        return data.empty();
    }

    // Inserts an element into the priority queue
    void push(int element)
    {
        data.push_back(element);
        sort(data.begin(), data.end());
    }

    // Removes and returns the element with the highest priority (lowest value)
    int pop()
    {
        int element = data.front();
        data.erase(data.begin());
        return element;
    }

    int top()
    {
        return data.front();
    }
};

int main()
{
    PriorityQueue pq;

    pq.push(5);
    pq.push(1);
    pq.push(0);
    pq.push(-2);
    pq.push(4);
    pq.push(10);
    pq.push(-10);

    cout << "Size: " << pq.size() << endl;

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}

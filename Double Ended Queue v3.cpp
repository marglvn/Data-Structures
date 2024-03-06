//Double ended queue example
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Deque {
private:
    vector<T> data;

public:
    // Returns the number of elements in the deque
    int size() {
        return data.size();
    }

    // Returns true if the deque is empty, false otherwise
    bool empty() {
        return data.empty();
    }

    // Inserts an element at the front of the deque
    void push_front(T element) {
        data.insert(data.begin(), element);
    }

    // Inserts an element at the back of the deque
    void push_back(T element) {
        data.push_back(element);
    }

    // Removes and returns the element at the front of the deque
    T pop_front() {
        T element = data.front();
        data.erase(data.begin());
        return element;
    }

    // Removes and returns the element at the back of the deque
    T pop_back() {
        T element = data.back();
        data.pop_back();
        return element;
    }

    // Returns the element at the front of the deque
    T front() {
        return data.front();
    }

    // Returns the element at the back of the deque
    T back() {
        return data.back();
    }
};

int main() {
    Deque<int> dq;

    // Insert some elements into the deque
    dq.push_back(5);
    dq.push_back(1);
    dq.push_back(3);
    dq.push_front(2);
    dq.push_front(4);

    // Print the size of the deque
    cout << "Size: " << dq.size() << endl;

    // Print the elements in the deque (should be in the order 4, 2, 5, 1, 3)
    while (!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    return 0;
}

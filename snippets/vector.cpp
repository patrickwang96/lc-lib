#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printVector(vector<T> v) {
    for (int i = 0; i < v.size(); i++) 
        cout << i << '\t' ;
    cout << endl;
}

int main() {
    vector<int> v1(5, 0); // declare a vector with length 5 and initialize all element to value 0;
    printVector(v1);

    for (int i = 0; i < v1.size(); i++) 
        v1[i] = i;
    printVector(v1);

    for (auto i: v1) 
        cout << i << '\t';
    cout << endl;

    auto iter = v1.begin();
    while (iter != v1.end()) {
        cout << *iter++ << '\t';
    }
    cout << endl;

    auto reverse_iter = v1.rbegin();
    while (reverse_iter != v1.rend()) {
        cout << *reverse_iter++ << '\t';
    }
    cout << endl;

    v1.push_back(5);
    printVector(v1);

    v1.pop_back();
    printVector(v1);

    return 0;
}
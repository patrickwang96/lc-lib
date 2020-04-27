#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " ;
    }
    cout << endl;
    return;
}

template <typename T>
void bubble_sort(vector<T>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - 1 - i; j++) {
            if (v[j] > v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}

template<typename T>
void selection_sort(vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        int k = i;
        for (int j = k + 1; j < v.size(); j++) {
            if (v[j] < v[k]) k = j;
        }
        swap(v[i], v[k]);
    }
}

template<typename T>
void insertion_sort(vector<T>& v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i-1]) {
            int wait = v[i];
            int j = i;
            while (j > 0 && v[j-1] > wait) {
                v[j] = v[j-1];
                j--;
            }
            v[j] = wait;
        }
    }
}

template <typename T>
void quick_sort(vector<t>& v) {
}

int main() {

    vector<int> v = {3,1,5,7,4};

    insertion_sort(v);
    printVector(v);




    return 0;
}
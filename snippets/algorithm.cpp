#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printVector(vector<T> v) {
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << ' ' ;
    cout << endl;
}

int main() {
    cout << max(1, 2) << endl;

    cout << min(1,2) << endl;

    vector<int> v1 = {1,5,3,7,9,3,7,6};
    printVector(v1);
    sort(v1.begin(), v1.end());
    printVector(v1);
    
    if (binary_search(v1.begin(), v1.end(), 5))
        cout << "element 5 exists in v1 vector\n";
    if (!binary_search(v1.begin(), v1.end(), 4))
        cout << "element 4 doesn't exist in v1 vector\n";
    
    


    return 0;
}
#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    unordered_map<int, int> map;

    map[1] = 10;
    map[2] = 20;

    if (map.count(3) == 0) {
        cout << "map doesn't contain key 3" << endl;
    }
    if (map.count(2) == 1) {
        cout << "map contains key 2" << endl;
    }

    cout << "key 1 maps to value " << map[1] << endl;

    return 0;
}
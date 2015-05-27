#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> test;
    int i;
    for(i = 0; i < 10; i++) {
        test.push_back(i);
    }
    for(i = 0; i < 10; i++) {
        cout << test[i] << endl;
    }
    cout << test[-2];
    return 0;
}

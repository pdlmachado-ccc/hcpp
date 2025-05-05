#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    char n, m;
    vector<char> translate = {'a', 'b', 'c'};
    cin >> n;
    if(find(translate.begin(), translate.end(), n) == translate.end()){
        cout << "Is in the vector" << endl;
    }
    else{
        cout << "Is not in the vecotr" << endl;
    }
    return 0;
}
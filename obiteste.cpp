#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void buildArray(vector<vector<int>> &arrayTwo, int size){
    int value;
    vector<int> lanes;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cin >> value;
            lanes.push_back(value);
        }
        arrayTwo.push_back(lanes);
    }
}


void showArray(vector<vector<int>> &array, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
           cout << array[i][j];
        }
        cout << endl;
    }
}

int* findNeighbours(vector<vector<int>> &arrayTwo, int current_i, int current_j){
    int neighbours [8];
    for (int i = 0; i < 8; i++){
        
    }
}



int main(){
    int size, trials, value;
    cin >> size >> trials;
    vector<vector<int>> arrayTwo;
    


    buildArray(arrayTwo, size);
    showArray(arrayTwo, size);

    return 0;
}
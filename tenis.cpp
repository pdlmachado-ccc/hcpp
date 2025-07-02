#include <iostream>
#include <vector>
using namespace std;


int main(){

    int players[4];
    int rest[2];
    int biggest, smallest, middle;
    middle = 0;

    for (int i = 0; i < 4; i++){
        cin >> players[i];
    }


    
    biggest = 0;
    for (int i = 0; i < 4; i++){
        if (players[i] > biggest){
            biggest = players[i];
        }
        
    }

    smallest = biggest;
    for (int i = 0; i < 4; i++){
        if (players[i] < smallest){
            smallest = players[i];
        }
        
    }


    for (int i = 0; i < 4; i++){
        if(players[i] != biggest && players[i] != smallest){
            middle = middle + players[i];
        }
    }

    cout << (biggest + smallest) - middle << endl;
}
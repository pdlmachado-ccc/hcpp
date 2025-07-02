#include <iostream>
#include <vector>
using namespace std;


int main(){

    int players[4];
    int ordered[4];
    int temp;


    for (int i = 0; i < 4; i++){
        cin >> players[i];
    }


    
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (players[i] > players[j]) {
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    cout << abs((players[0] + players[3]) - (players[1] + players[2])) << endl;


}
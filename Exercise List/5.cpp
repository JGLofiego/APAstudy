#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int cases, num_heights, aux;
    cin >> cases;

    for(int i = 0; i < cases; i++){
        cin >> num_heights;
        vector<int> vect(num_heights);

        for (int j = 0; j < num_heights; j++){
            cin >> vect[j];
        }

        stable_sort(vect.begin(), vect.end());

        for (int j = 0; j < num_heights - 1; j++){
            cout << vect[j] << " ";
        } cout << vect[num_heights - 1] << endl;
    }
}
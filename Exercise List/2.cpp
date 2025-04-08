#include <iostream>
using namespace std;

int bubble_sort(int trains[50], int num){
    int temp;
    int swaps = 0;
    for(int i = 0; i < num; i++) {
        for(int j = num-1; j > i; j--) {
            if(trains[j] < trains[j-1]) {
                temp = trains[j];
                trains[j] = trains[j-1];
                trains[j-1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}

int main() {
    int num_cases, num_trains, trains[50];
    cin>>num_cases;
    for(int _ = 0; _ < num_cases; _++) {
        
        cin>>num_trains;
        
        for(int i = 0; i < num_trains; i++)
           cin>>trains[i];
        
       cout<<"Optimal train swapping takes "<<bubble_sort(trains, num_trains)<<" swaps." <<endl;
    }
}
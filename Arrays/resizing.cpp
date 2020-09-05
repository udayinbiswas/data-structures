// Resizing an array in heap
// Author : Udayin Biswas, Date : 05/09/2020
#include <iostream>
using namespace std;

void printArray(int array[],int length){
    for (int i=0;i<length;i++){
        cout<<array[i]<<",";
    }
    cout<<endl;
    return;
}

int main(){
    // Declare + Initialise an array in heap
    int* p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[3] = 3;
    p[4] = 4;
    p[5] = 5;
    printArray(p,5);
    // Declare + Initialise a bigger size array in heap
    int* q = new int[10];
    for (int i=0;i<5;i++){
        q[i] = p[i];
    }
    // Delete smaller array from heap
    delete []p;
    // Point p to array pointer by q
    p=q;
    q=NULL;
    printArray(p,10);
    // Delete bigger array from heap
    delete []p;
    return 0;
}
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
    // Declare + Initialise a 2d array in stack
    // Visualise as 2d table but memory allocated will be in a linear manner
    int A[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};

    // Create an array of pointers and each pointer pointing to array in heap
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[5];
    B[2] = new int[6];

    // Creating double pointer which points to array of pointers in heap, each pointer in turns point to another array in heap
    int **C[3];
    C[0] = new int*[4];
    C[1] = new int*[4];
    C[2] = new int*[4];

    return 0;
}
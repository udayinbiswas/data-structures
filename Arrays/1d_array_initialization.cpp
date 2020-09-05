// Different ways of declaring and initialising an array
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

void printArrayAddresses(int array[],int length){
    for (int i=0;i<length;i++){
        cout<<&array[i]<<",";
    }
    cout<<endl;
    return;
}

int main(){
    // Array method 1 
    int a[5];
    printArray(a,5); // Will print garbage values
    // Array method 2
    int b[5] = {1,2,3,4,5};
    printArray(b,5);
    // Array method 3
    int c[5] = {1,2};
    printArray(c,5);
    // Array method 4
    int d[5] = {0};
    printArray(c,5);
    // Array method 5
    int e[] = {1,2,3,4,5,6};
    printArray(e,6);

    return 0;
}
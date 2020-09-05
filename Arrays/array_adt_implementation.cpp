// Different ways of declaring and initialising an array
// Author : Udayin Biswas, Date : 05/09/2020
#include <iostream>
using namespace std;

class Array {
    private:
        int A[20];
        int size;
        int length;
    public:
        // Constructor
        Array(int array[],int size,int length){
            for (int i=0;i<length;i++){
                this->A[i] = array[i];
            }
            this->size = size;
            this->length = length;
        }
        // Display the elements of the array
        void printArray(){
            for (int i=0;i<length;i++){
                cout<<A[i]<<endl;
            }
        }
        
        void appendElement(int x){}
        void insertElementAtIndex(int x, int index){}
        void removeElement(int index){}
        bool searchElement(int x){return true;}
        int getElementAtIndex(int index){return 0;}
        void setElementAtIndex(int index,int x){}
        int maxElement(){return 0;}
        int minElement(){return 0;}
        void reverseArray(){}
        void shiftArray(int x){}
};

int main(){
    int a[10] = {2,3,4,5};
    Array array = Array(a,10,4);
    array.printArray();

    return 0;
}
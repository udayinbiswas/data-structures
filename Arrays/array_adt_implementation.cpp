// Array ADT implementation
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
        // Append an element to the array
        void appendElement(int x){
            if (length==size){
                cout<<"Cannot insert element, array is full"<<endl;
                return;
            }
            A[length-1] = x;
            length++;
            return;
        }
        // Inserting an element at a given index
        void insertElementAtIndex(int x, int index){
            if (length==size){
                cout<<"Cannot insert element, array is full"<<endl;
                return;
            }
            if (index<0 || index>length){
                cout<<"Invalid index"<<endl;
                return;
            }
            // Start from back and copy element from previous index to it
            for (int i=length;i>index;i--){
                A[i] = A[i-1];
            }
            // When we reach the index, simply put the element we need to insert since all values have been shifted
            // to the right of index
            A[index] = x;
            length++;
            return;
        }
        // Remove an element at index
        void removeElement(int index){

        }
        // Search an element in array
        bool searchElement(int x){
            return true;
        }
        // Get the element in array by index 
        int getElementAtIndex(int index){
            return 0;
        }
        // Set the element in array at index
        void setElementAtIndex(int index,int x){

        }
        // Get the max element in array
        int maxElement(){
            return 0;
        }
        // Get the min element in array
        int minElement(){
            return 0;
        }
        // Reverse the array
        void reverseArray(){

        }
        // Shift the array
        void shiftArray(int x){
            
        }
};

int main(){
    int a[10] = {2,3,4,5};
    Array array = Array(a,20,4);
    array.printArray();

    return 0;
}
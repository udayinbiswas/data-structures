// Array ADT template class implementation
// Author : Udayin Biswas, Date : 06/09/2020

#include <iostream>
using namespace std;

template<class T> 
class Array {
    private:
        T *A;
        int size;
        int length;
    public:
        // Constructors
        Array(){
            size = 10;
            length = 0;
            // Declaring array in heap so that it can be accessed by class accessing construtor
            A = new T[size]; 
        }
        Array(int size){
            this->size = size;
            length = 0;
            A = new T[this->size];
        }
        //Destructor
        ~Array(){
            delete []A;
        }
        void Display();
        void Insert(int index,T x);
        T Delete(int index);

};

template<class T>
void Array<T>::Display(){
    for (int i=0;i<length;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void Array<T>::Insert(int index, T x){
    if (index>=0 && index<=length){
        for (int i=length-1;i>index;i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        length++; 
    }
}

template<class T>
T Array<T>::Delete(int index){
    T x = 0;
    if (index>=0 && index<=length){
        x = A[index];
        for (int i=index;i<length;i++){
            A[i] = A[i+1];
        }
        length--;
    }
    return x;
}

int main()
{
    Array<char> arr(10);

    arr.Insert(0,'a');
    arr.Insert(1,'c');
    arr.Insert(2,'d');
    arr.Display();
    cout<<arr.Delete(0)<<endl;
    arr.Display();
    return 0;
}
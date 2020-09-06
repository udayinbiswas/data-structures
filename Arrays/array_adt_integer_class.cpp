// Array ADT integer class implementation
// Author : Udayin Biswas, Date : 06/09/2020

#include <iostream>
using namespace std;

class Array {
    private:
        int *A;
        int size;
        int length;
        void swap(int &x,int &y){
            int temp = x;
            x = y;
            y = temp;
        }
    public:
        // Constructors
        Array(){
            size = 10;
            length = 0;
            // Declaring array in heap so that it can be accessed by class accessing construtor
            A = new int[size]; 
        }
        Array(int size){
            this->size = size;
            length = 0;
            A = new int[this->size];
        }
        //Destructor
        ~Array(){
            delete []A;
        }
        void Display();
        void Append(int x);
        void Insert(int index,int x);
        int Delete(int index);
        int LinearSearch(int key);
        int BinarySearch(int key);
        int Get(int index);
        void Set(int index,int x);
        int Max();
        int Min();
        int Sum();
        float Avg();
        void Reverse();
        void Reverse2();
        void InsertSort(int x);
        bool isSorted();
        Array* Merge(Array *arr2);
        Array* Union(Array *arr2);
        Array* Diff(Array *arr2);
        Array* Inter(Array *arr2);
                
};

void Array::Display(){
    for (int i=0;i<length;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Array::Append(int x){
    if (length<size){
        A[length++] = x;
    }
}

void Array::Insert(int index, int x){
    if (index>=0 && index<=length){
        for (int i=length-1;i>index;i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        length++; 
    }
}

int Array::Delete(int index){
    int x = 0;
    if (index>=0 && index<=length){
        x = A[index];
        for (int i=index;i<length;i++){
            A[i] = A[i+1];
        }
        length--;
    }
    return x;
}

int Array::LinearSearch(int key){
    for (int i=0;i<length;i++){
        if (A[i]==key) return i;
    }
    return -1;
}

int Array::BinarySearch(int key){
    int l = 0, r = length-1;
    while (l<=r){
        int mid = (l+r)/2;
        if (A[mid]==key){
            return mid;
        } else if (A[mid]<key){
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return -1;
}

int Array::Get(int index){
    if(index>=0 && index<length){
        return A[index];
    }
    return -1;
}

void Array::Set(int index,int x){
    if(index>=0 && index< length){
        A[index]=x;
    }
}

int Array::Max(){
    int max=A[0];
    for(int i=1;i<length;i++){
        if(A[i]>max){
            max=A[i];
        }    
    }
    return max;
}

int Array::Min(){
    int min=A[0];
    for(int i=1;i<length;i++){
        if(A[i]<min){
            min=A[i];
        }
    }
    return min;
}

int Array::Sum(){
    int s=0;
    int i;
    for(i=0;i<length;i++){
        s+=A[i];
    }
    return s;
}

float Array::Avg(){
    return (float)Sum()/length;
}

void Array::Reverse(){
    for (int i=0,j=length-1;i<j;i++,j--){
        swap(A[i],A[j]);
    }
}

void Array::InsertSort(int x){
    if (length==size) return;
    int i = length-1;
    while (A[i]>x){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    return;
}

bool Array::isSorted(){
    for(int i=0;i<length-1;i++){
        if(A[i]>A[i+1])  return false;
    }
    return true;
}

Array* Array::Merge(Array *arr2){
    int p1 = 0,p2 = 0;
    // Declaring in heap, not stack so that we can return it
    Array *array = new Array(length+arr2->length);
    int i = 0;
    while (p1<length && p2<arr2->length){
        if (A[p1]<A[p2]){
            array->A[i++] = A[p1++];
        } else {
            array->A[i++] = arr2->A[p2++];
        }
    }
    while (p1<length){
        array->A[i++] = A[p1++];
    }
    while (p2<arr2->length){
        array->A[i++] = arr2->A[p2++];
    }
    return array;
}

Array* Array::Union(Array *arr2){
    int p1 = 0,p2 = 0;
    // Declaring in heap, not stack so that we can return it
    Array *array = new Array(length+arr2->length);
    int i = 0;
    while (p1<length && p2<arr2->length){
        if (A[p1]==A[p2]){
            array->A[i++] = A[p1++];
            p2++;
        } else if (A[p1]<A[p2]){
            array->A[i++] = A[p1++];
        } else {
            array->A[i++] = arr2->A[p2++];
        }
    }
    while (p1<length){
        array->A[i++] = A[p1++];
    }
    while (p2<arr2->length){
        array->A[i++] = arr2->A[p2++];
    }
    array->length = i;
    return array;
}

Array* Array::Diff(Array *arr2){
    int p1 = 0,p2 = 0;
    // Declaring in heap, not stack so that we can return it
    Array *array = new Array(length+arr2->length);
    int i = 0;
    while (p1<length && p2<arr2->length){
        if (A[p1]==A[p2]){
            p1++;
            p2++;
        } else if (A[p1]<A[p2]){
            array->A[i++] = A[p1++];
        } else {
            p2++;
        }
    }
    while (p1<length){
        array->A[i++] = A[p1++];
    }
    array->length = i;
    return array;
}

Array* Array::Inter(Array *arr2){
    int p1 = 0,p2 = 0;
    
    // Declaring in heap, not stack so that we can return it by its pointer
    // If we had done 'Array *array = &Array(length+arr2->length)' and then return by pointer of type 'Array*'
    // this array variable will be local to this Inter method and cannot be accessed by its pointer outside this method
    // So accessing it by address will return error/warning.
    Array *array = new Array(length+arr2->length);
    // Instead if we declare it by stack we should return it by its type and not pointer
    // Array array = Array(length+arr2->length) and then return by its type 'Array' so that copy is created of array
    
    int i = 0;
    while (p1<length && p2<arr2->length){
        if (A[p1]==A[p2]){
            array->A[i++] = A[p1++];
            p2++;
        } else if (A[p1]<A[p2]){
            p1++;
        } else {
            p2++;
        }
    }
    array->length = i;
    return array;
}
#include <iostream>
#include <vector>

using namespace std;

// Max heap implementation
void Insert(vector<int> &v,int key,int index){
    int p = index;
    while (p>0 && v[p/2]<key){
        v[p] = v[p/2];
        v[p/2] = key;
        p = p/2;
    }
}

void CreateHeap(vector<int> &v){
    for (int i=1;i<v.size();i++){
        Insert(v,v[i],i);
    }
}

void PrintHeap(vector<int> &v){
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int DeleteFromHeap(vector<int> &v,int n){
    int val = v[0];
    v[0] = v[n];
    v[n] = val;
    int i = 0;
    int j = 1;
    while (j<n-1){
        if (v[j]<v[j+1]) j=j+1;
        if (v[i]<v[j]){
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
            i = j;
            j = 2*j;
        } else {
            break;
        }
    }
    return val;
}

int main(){
    cout<<"Create Heap:"<<endl;
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(25);
    v.push_back(5);
    v.push_back(40);
    v.push_back(35);
    PrintHeap(v);
    CreateHeap(v);
    PrintHeap(v);
    for (int i=v.size()-1;i>=0;i--){
        // i will denote the last element of the heap. After every delete, we assume the array size reduces by 1
        int x = DeleteFromHeap(v,i);
        cout<<"Deleting element:"<<x<<endl;
        cout<<"Array:";
        PrintHeap(v);
    }
    // Note the final sorted order -> this is heap sort i.e. instead of deleting we are just shifting the max elements to
    // the end of the array
    PrintHeap(v);
    return 0;
}
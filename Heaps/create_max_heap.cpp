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
    return 0;
}
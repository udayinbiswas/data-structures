// Finding string permutations
// Author : Udayin Biswas, Date : 06/09/2020
#include <iostream>
#include <string>
using namespace std;

// To check if duplicate characters are present in string using bit operations
void permutations(string s,int flag[],int l,string p){ // this flag array argument is basically a pointer
    if (l==s.length()){
        cout<<p<<endl;
        return;
    }
    for (int i=0;i<s.length();i++){
        if (flag[i]==0){
            // Proceed ahead after setting the flag
            flag[i]=1;
            permutations(s,flag,l+1,p+s[i]);
            // Unset the flag
            flag[i]=0;
        }
    }
}


int main(){
    string p = "goku";
    int flag[6] = {0};
    permutations(p,flag,0,"");
    return 0;
}
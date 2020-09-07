// Finding duplicates in a string using bit operation
// Author : Udayin Biswas, Date : 05/09/2020
#include <iostream>
#include <string>
using namespace std;

// To check if duplicate characters are present in string using bit operations
bool duplicatesPresent(string s){
    // x is for checking at each iteration; H will store the bits corresponding to the characters in the string till that point
    int H = 0, x = 0;
    for (int i=0;i<s.length();i++){
        x = 1;
        // Left shift the bit to the intended position of character 
        x = x<<(s[i]-'a');
        // And is for masking and seeing whether the bit at that position is already on or not, 
        // If on then it means its duplicate is present before in string
        if ((x&H) > 0){
            return true;
        } else {
            // Turn on the bit corr to character position in array
            H = x|H;
        }
    }
    return false;
}


int main(){
    // Array method 1 
    string s = "messi";
    cout<<s<<",duplicates:"<<duplicatesPresent(s)<<endl;
    string p = "udayin";
    cout<<p<<",duplicates:"<<duplicatesPresent(p)<<endl;
    return 0;
}
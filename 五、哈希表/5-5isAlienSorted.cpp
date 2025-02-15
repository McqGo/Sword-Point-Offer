#include <iostream>
#include <string>
#include <vector>
using namespace std;

int order_array[26] = {};

bool sorted(string& s1, string& s2){
    int i=0;
    for(;i<s1.size() && i<s2.size(); i++){
        if(order_array[s1[i]-'a']<order_array[s2[i]-'a'])
            return true;
        if(order_array[s1[i]-'a']>order_array[s2[i]-'a'])
            return false;
    }

    return i==s1.size();
}

bool isAlienSorted(vector<string>& words, string& order){
    for(int i=0; i<order.size(); i++){
        order_array[order[i]-'a'] = i; 
    }

    for(int i=0; i<words.size()-1; i++){
        if(!sorted(words[i], words[i+1])){
            return false;
        }
    }

    return true;
}

int main(){
    string order = "zyxwvutsrqponmlkjihgfedcba";
    vector<string> words ={"often", "bs", "b"};
    cout<<boolalpha<<isAlienSorted(words, order)<<endl;
    return 0;
}
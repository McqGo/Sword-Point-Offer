#include <iostream>
#include <unordered_map>
using namespace std;


bool isAnagram26(string& s1, string& s2){
    if(s1.size()!=s2.size() || s1==s2)
        return false;

    int hash[26] = {};
    for(auto& ch:s1){
        hash[ch-'a']++;
    }

    for(auto& ch: s2){
        if(hash[ch-'a']==0)
            return false;

        hash[ch-'a']--;
    }

    return true;
}

bool isAnagram(string& s1, string&s2){
    if(s1.size()!=s2.size() || s1==s2)
        return false;
    
    unordered_map<char, int>hash;
    for(auto& ch:s1){
        hash[ch]++;
    }

    for(auto& ch:s2){
        if(hash[ch]==0)
            return false;

        hash[ch]--;
    }

    return true;

}

int main(){
    string s1 = "sa&d*";
    string s2 = "d&s*a";
    //cout<<boolalpha<<isAnagram26(s1, s2)<<endl;
    cout<<boolalpha<<isAnagram(s1, s2)<<endl;
    return 0;
}
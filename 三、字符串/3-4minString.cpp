#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

#define MAX_LEN 0x7ffffff

string minString(string &str1, string &str2){
    unordered_map<char, int> hash;
    for(const auto &ch: str1){
        hash[ch]+=1;
    }

    int count = hash.size();
    int len = str2.size();
    int min_start = 0, min_end = 0, min_len = MAX_LEN;
    int start = 0, end = 0;

    while(end<len){
        if(count>0){
            char end_ch = str2[end];
            if(hash.count(end_ch)>0){
                hash[end_ch]-=1;
                if(hash[end_ch]==0)
                    count--;
            }
            end++;
        }
        else{
            if(end-start<min_len){
                min_len = end-start;
                min_start = start;
                min_end = end;                
            }

            char start_ch = str2[start];
            if(hash.count(start_ch)>0){
                hash[start_ch]+=1;
                if(hash[start_ch]==1){
                    count++;
                }
            }

            start++;

        }
    }

    return min_len<MAX_LEN? str2.substr(min_start, min_len): "";

}


int main(){
    string str1 = "ABBC";
    string str2 = "ADDBANCABD";
    cout<<minString(str1, str2)<<endl;
    return 0;
}
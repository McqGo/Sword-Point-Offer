#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxProduct1(vector<string>& str){
    int len = str.size();
    int result = 0;
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            bool flag = true;
            for(const auto &ch1: str[i]){
                for(const auto &ch2: str[j]){
                    if(ch1==ch2){
                        flag = false;
                        break;
                    }
               }
            }
            if(flag){
                int temp = str[i].size() * str[j].size();
                if(result<temp) result = temp;
            }
        }
    }

    return result;
}

int maxProduct_hash(vector<string>& str){
    int len = str.size();
    int result = 0;
    vector<vector<bool>> flags(len, vector<bool>(26, false));

    for(int i=0; i<len; i++){
        for(const auto &ch: str[i]){
            flags[i][ch-'a'] = true;
        }
    }

    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            int k = 0;
            for(; k<26; k++){
                if(flags[i][k] && flags[j][k])
                    break;
            }
            if(k==26){
                int temp = str[i].size() * str[j].size();
                if(result<temp) result = temp;
            }
        }
    }

    return result;
}


int maxProduct_binary(vector<string>& str){
    int len = str.size();
    int result = 0;
    vector<int> flags(len, 0);

    for(int i=0; i<len; i++){
        for(const auto &ch: str[i]){
            flags[i]|=1<<(ch-'a');
        }
    }

    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if((flags[i]&flags[j])==0){
                int temp = str[i].size() * str[j].size();
                if(result<temp) result = temp;
            }
        }
    }

    return result;
}

int main(){
    vector<string> str = {"abcw", "foo", "bar", "fxyz", "abcdef"};
    cout<<maxProduct1(str)<<endl;
    cout<<maxProduct_hash(str)<<endl;
    cout<<maxProduct_binary(str)<<endl;
    return 0;
}
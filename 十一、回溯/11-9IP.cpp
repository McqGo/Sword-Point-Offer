#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(string& seg){
    if(seg=="") return false;
    
    return stoi(seg)<=255 
    && stoi(seg)>=0 
    && (seg=="0" || seg[0]!='0');
}

void dfs(string& str, int i, int seg_i, string& seg, string& ip, vector<string>& res){
    if(i==str.size() && seg_i==3 && isValid(seg)){
        res.emplace_back(ip+seg);
    }

    else if(i<str.size() && seg_i<=3){
        char ch = str[i];
        string temp = seg+ch;
        if(isValid(temp)){
            string tmp_1 = seg+ch;
            dfs(str, i+1, seg_i, tmp_1, ip, res);
        }
        if(seg.size()>0 && seg_i<3){
            string tmp_1(1, ch);
            string tmp_2 = ip+seg+".";
            dfs(str, i+1, seg_i+1, tmp_1, tmp_2, res);
        }
    }
}

vector<string> getIps(string& str){
    vector<string> res;
    string seg;
    string ip;
    dfs(str, 0, 0, seg, ip, res);
    return res;
}

int main(){
    string str = "10203040";
    vector<string> res = getIps(str);
    for(auto ip: res)
        cout<<ip<<endl;
    return 0;
}
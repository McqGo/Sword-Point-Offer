#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& tem){
    vector<int> res(tem.size());
    stack<int> sta;
    for(int i=0; i<tem.size(); i++){
        while(!sta.empty()
              && tem[i]>tem[sta.top()]){
            int prev = sta.top();
            sta.pop();
            res[prev] = i-prev;
        }

        sta.push(i);
    }

    return res;
}

int main(){
    vector<int> tem = {35, 31, 33, 36, 34};
    vector<int> res = dailyTemperatures(tem);
    for(auto i: res)
        cout<<i<<" "<<flush;
    cout<<endl;
    return 0;
}
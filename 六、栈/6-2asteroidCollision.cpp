#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids){
    vector<int> res;
    stack<int> sta;
    for(const auto& as: asteroids){
        while(!sta.empty() && sta.top()>0 && sta.top()<-as){
            sta.pop();
        }

        if(!sta.empty() && sta.top()>0 && sta.top()==-as){
            sta.pop();
        }

        else if(sta.empty() || sta.top()<0 || as>0){
            sta.push(as);
        }
    }

    while(!sta.empty()){
        auto as = sta.top();
        sta.pop();
        res.emplace_back(as);
    }

    reverse(res.begin(), res.end());
    return res;
}

int main(){
    vector<int> asteroids = {4, 5, -6, 4, 8, -5};
    vector<int> res = asteroidCollision(asteroids);
    for(const auto& i: res)
        cout<<i<<" "<<flush;
    cout<<endl;
    return 0;
}
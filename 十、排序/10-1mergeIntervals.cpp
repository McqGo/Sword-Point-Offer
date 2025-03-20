#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vector<int>> res;
    res.reserve(intervals.size());
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0]<b[0];
    });

    int i = 0;
    while(i<intervals.size()){
        vector<int> temp = {intervals[i][0], intervals[i][1]};
        int j = i+1;
        while(j<intervals.size() && intervals[j][0]<=temp[1]){
            temp[1] = max(temp[1], intervals[j][1]);
            j++;
        }

        res.emplace_back(temp);
        i = j;
    }

    return res;
}


int main(){
    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {8, 10}, {2, 6}, {9, 12}, {15, 18}};
    intervals = merge(intervals);
    for(auto i: intervals)
        cout<<"["<<i[0]<<" "<<i[1]<<"]"<<" "<<flush;
    cout<<endl;
    return 0;
}
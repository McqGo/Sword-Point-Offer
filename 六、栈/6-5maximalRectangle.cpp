#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleAreaMS(vector<int>& heights){
    stack<int> sta;
    sta.push(-1);
    int max_area = 0;
    for(int i=0; i<heights.size(); i++){
        while(sta.top()!=-1 && heights[sta.top()]>heights[i]){
            int height = heights[sta.top()];
            sta.pop();
            int width = i-sta.top()-1;
            max_area = max(max_area, height*width);
        }

        sta.push(i);
    }

    while(sta.top()!=-1){
        int height = heights[sta.top()];
        sta.pop();
        int width = heights.size()-sta.top()-1;
        max_area = max(max_area, height*width);
    }

    return max_area;
}

int maximalRectangle(vector<vector<int>>& matrix){
    if(matrix.size()==0 || matrix[0].size()==0)
        return 0;
    
    vector<int> heights(matrix[0].size(), 0);
    int max_area = 0;
    for(const auto& row:matrix){
        for(int i=0; i<row.size(); i++){
            if(row[i]==0)
                heights[i]=0;
            else 
                heights[i]++;
        }

        max_area = max(max_area, largestRectangleAreaMS(heights));
    }

    return max_area;
}

int main(){
    vector<vector<int>> matrix = {{1, 0, 1, 0, 0},
                                  {0, 0, 1, 1, 1},
                                  {1, 1, 1, 1, 1},
                                  {1, 0, 0, 1, 0}};

    cout<<maximalRectangle(matrix)<<endl;
    return 0;
}
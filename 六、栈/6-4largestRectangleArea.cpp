#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleAreaBF(vector<int>& heights){
    int max_area = 0;
    for(int i=0; i<heights.size(); i++){
        int min_height = heights[i];
        for(int j=i; j<heights.size(); j++){
            min_height = min(min_height, heights[j]);
            int area = min_height*(j-i+1);
            max_area = max(max_area, area);
        }
    }

    return max_area;
}

int helper(vector<int>& heights, int start, int end){
    if(start==end)  return 0;
    if(start+1==end) return heights[start];

    int min_index = start;
    for(int i=start+1; i<end; i++){
        if(heights[i]<heights[min_index])
            min_index = i;
    }

    int area = heights[min_index]*(end-start);
    int left = helper(heights, start, min_index);
    int right = helper(heights, min_index+1, end);

    area = max(area, left);
    return max(area, right);

}

int largestRectangleAreaDC(vector<int>& heights){
    return helper(heights, 0, heights.size());
}

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

int main(){
    vector<int> heights = {3, 2, 5, 4, 6, 1, 4, 2};
    cout<<largestRectangleAreaBF(heights)<<endl;
    cout<<largestRectangleAreaDC(heights)<<endl;
    cout<<largestRectangleAreaMS(heights)<<endl;
    return 0;
}
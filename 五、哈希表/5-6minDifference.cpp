#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool minuteFlags[1440] = {};

int helper(){
    int minDiff = 1439;
    int prev = -1;
    int first = 1439;
    int last = 0;
    for(int i=0; i<1440; i++){
        if(minuteFlags[i]){
            if(prev>-1){
                minDiff = min(i-prev, minDiff);
            }

            prev = i;
            first = min(i, first);
            last = max(i, last);
        }
    }

    minDiff = min(first+1440-last, minDiff);
    return minDiff;
}

int findMinDifference(vector<string>& times){
    if(times.size()>1440)
        return 0;
    
    for(auto& time:times){
        int hour = (time[0]-'0')*10+(time[1]-'0');
        int minute = (time[3]-'0')*10+(time[4]-'0');
        int time_value = hour*60+minute;
        if(minuteFlags[time_value])
            return 0;

        minuteFlags[time_value] = true;
    }

    return helper();
}

int main(){
    vector<string> times = {"20:20", "00:11", "10:20","00:00", "23:59", "23:50"};
    cout<<findMinDifference(times)<<endl;
    return 0;

}
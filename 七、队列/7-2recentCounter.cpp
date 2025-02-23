#include <iostream>
#include <queue>

using namespace std;

class RecentCount{
    private:
        int window_size;
        queue<int> times;

    public:  
        RecentCount(){
            window_size = 3000;
        }

        int ping(int time){
            times.push(time);
            while(times.front()+window_size<time){
                times.pop();
            }

            return times.size();
        }

};


int main(){
    RecentCount rc;
    cout<<rc.ping(1)<<endl;
    cout<<rc.ping(10)<<endl;
    cout<<rc.ping(3001)<<endl;
    cout<<rc.ping(3002)<<endl;

    return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;

void process(vector<int> &data) {
    //first
    int first = 0;
    int second = 0;
    for(int i=1; i<data.size(); i++) {
        int prev = data[i-1], cur = data[i];
        int diff = 0;
        if(cur < prev) {
            diff = (prev - cur);
            first += diff;
            second = max(second, diff);
        }
    }
    cout<<first<<" ";

    int re=0;
    for(int i=0; i<data.size()-1; i++) {
        if(data[i] < second)
            re += data[i];
        else
            re += second;
    }
    cout<<re;
}

int main() {
    int T;
    cin>>T;
    for(int tcas=1; tcas<=T; tcas++) {
        int n, temp;
        cin>>n;
        vector<int> data;
        for(int i=0; i<n; i++) {
            cin>>temp;
            data.push_back(temp);
        }
        cout<<"Case #"<<tcas<<": ";
        process(data);
        cout<<endl;
    }
}
        

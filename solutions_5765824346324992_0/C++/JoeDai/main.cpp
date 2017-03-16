
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;
typedef long long int ll;
typedef pair<int, ll> PII;

class Compare
{
public:
    bool operator() (const pair<int, ll> &a, const pair<int, ll> &b)
    {
        if(a.second == b.second) return (a.first>b.first);
        return a.second > b.second;
    }
};

int product(int m, int n) {
    int s = m * n;
    while(n != 0) { 
        int r = m % n; 
        m = n; 
        n = r; 
    } 
    return s/m;
}

void process(vector<int> &data, int n) {
    int a=data[0];
    for(int i=1; i<data.size(); i++) {
        a = product(a, data[i]);
    }
    int r=0;
    for(int i=0; i<data.size(); i++) {
        r += a/data[i];
    }
    n = n%r;
    if(n==0) n = r;
    priority_queue<PII, vector<PII>, Compare> time;
    for(int i=0; i<data.size(); i++) {
        time.push(PII(i, 0));
    }
    int mark = 0;
    for(int i=0; i<n-1; i++) {
        PII cur = time.top();
        time.pop();
        time.push(PII(cur.first, cur.second + data[cur.first]));
    }
    cout<<time.top().first+1;
}

int main() {
    int T;
    cin>>T;
    for(int tcas=1; tcas<=T; tcas++) {
        int b, n;
        cin>>b>>n;
        vector<int> data;
        int temp;
        for(int i=0; i<b; i++) {
            cin>>temp;
            data.push_back(temp);
        }
        cout<<"Case #"<<tcas<<": ";
        process(data, n);
        cout<<endl;
    }
}

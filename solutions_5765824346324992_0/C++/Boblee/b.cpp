#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const int maxm = 1000+20;
int m[maxm];
int b,n;

struct node {
    
    int id;
    long long time;

    friend bool operator < (node x, node y) {
        if(x.time != y.time)
            return x.time > y.time;
        return x.id > y.id;
    }

};


int gcd(int a, int b) {
    return b?gcd(b,a%b):a;
}

int lcm(int a, int b) {
    return a/gcd(a,b)*b;
}


int main() {
    
    int T;
    cin>>T;
    int cas = 1;
    while( T-- ) {
        cin>>b>>n;
        priority_queue<node> q;
        for(int i=1; i<=b; i++) {
            cin>>m[i];
            node tmp;
            tmp.id = i;
            tmp.time = 0;
            q.push(tmp); 
        }
        
        int zuixiaogongbei = 1;

        for(int i=1;i<=b;i++) {
            zuixiaogongbei = lcm(zuixiaogongbei,m[i]);
        }
        
        int pre = 0;        

        for(int i=1;i<=b;i++)
            pre += zuixiaogongbei / m[i];
        
        int start = 1;
        
        if(pre <= n-1) {
            pre = (n-1)/pre*pre;
            start = pre+1;
        }
        for(int i=start; i<=n-1; i++) {
            node tmp = q.top();
            q.pop();
            tmp.time += m[tmp.id];
            q.push(tmp);
        }
        
        node tmp = q.top();
        printf("Case #%d: %d\n",cas++,tmp.id);
    }

    return 0;
}



#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

long check(long t,long long mid, long time[]) {
    long tot=t;
    for (int i=1;i<=t;i++) {
        tot+=mid/time[i];
    }
    return tot;
}

int main() {
    freopen("B-large.in","r",stdin);
    freopen("output2L.txt","w",stdout);
    int totcase;
    long time[1001];

    cin >> totcase;
    for (long nowcase=0;nowcase<totcase;nowcase++) {
        long t,n;
        long max = 0;
        cin >> t >> n;
        for (int i=1;i<=t;i++) {
            cin >> time[i];
            if (max<time[i]) max=time[i];
        }
        
        long long r=max*n;
        long long l=1;
        long long mid=(l+r)/2;
        long res1=check(t,mid,time),res2=check(t,mid-1,time);
        while (!((res1<n)&&(res2>=n))) {
            if (res2<n) l=mid+1; else r=mid-1;
            mid=(l+r)/2;
            res1=check(t,mid-1,time);
            res2=check(t,mid,time);
        }
        
        long k=n-res1,tot=0,i=0;
        do {
            i++;
            if (mid%time[i]==0) tot++;
        } while (tot!=k);
        
        cout << "Case #" << nowcase+1 << ": " << i<< endl;
        
    }
    
}
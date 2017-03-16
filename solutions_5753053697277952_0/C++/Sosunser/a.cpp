#include <bits/stdc++.h>
using namespace std;

int t,n;
int a[50];
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    for(int k = 0; k < t; k++){
        scanf("%d",&n);
        int count = 0;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
            pq.push({a[i],i});
            count += a[i];
        }
        cout << "Case #" << k+1 << ":";
        while(!pq.empty()){
            auto j = pq.top();
            pq.pop();
            a[j.second]--;
            cout << " " << (char)(j.second+'A');
            count--;
            if(a[j.second] != 0){
                pq.push({a[j.second],j.second});
            }
            if(!pq.empty()){
                if(pq.top().first > (double)count/2){
                    cout << (char)(pq.top().second+'A');
                    auto j2 = pq.top();
                    pq.pop();
                    a[j2.second]--;
                    count--;
                    if(a[j2.second] != 0){
                        pq.push({a[j2.second],j2.second});
                    }
                }
            }
        }
        cout << endl;
    }
}
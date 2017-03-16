#include<bits/stdc++.h>
#define ii pair<int,int>
using namespace std;

main() {

    int te;
    cin>>te;
    for (int t=1; t<=te; t++) {

        priority_queue <ii, vector<ii > > pq;

        int n;
        cin>>n;
        for (int i=0; i<n; i++) {
            int x;
            cin>>x;
            pq.push(make_pair(x, i));
        }

        cout<<"Case #"<<t<<": ";

        while (pq.size() > 2) {
            ii m1 = pq.top();
            pq.pop();
            cout<<char(m1.second + 'A')<<" ";
            if (m1.first > 1) {
                pq.push(make_pair(m1.first-1, m1.second));
            }
        }

        ii top1 = pq.top();
        pq.pop();
        ii top2 = pq.top();
        for (int i=1; i<=top1.first; i++) cout<<char(top1.second+'A')<<char(top2.second+'A')<<" ";
        cout<<endl;
    }
}

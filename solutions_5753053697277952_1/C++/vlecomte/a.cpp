#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,char> ic;

int main()
{
    int nt;
    cin >> nt;
    for (int t=1; t<=nt; t++) {
        printf("Case #%d:", t);
        priority_queue<ic> pq;
        int n,sp=0;
        cin >> n;
        for (int i=0; i<n; i++) {
            int p;
            cin >> p;
            sp += p;
            pq.push(ic(p, 'A'+i));
        }
        for (int i=0; i<sp; i++) {
            ic pa = pq.top();
            pq.pop();
            ic pb = pq.top();
            if (pa.first == pb.first && i != sp-3) {
                pq.pop();
                cout << ' ' << pa.second << pb.second;
                pq.push(ic(pb.first-1, pb.second));
                i++;
            } else {
                cout << ' ' << pa.second;
            }
            pq.push(ic(pa.first-1, pa.second));
        }
        cout << endl;
    }
}

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 2000000000


bool cmp(int a,int b){return a>b;}


priority_queue<ii, vector<ii>, less<ii> > pq;

//printf("Case #%d:", z);
int main () {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen ("ofile.txt", "w", stdout);
    int t;
    cin >> t;
    for (int z=1; z<=t; z++){
        int n;
        cin >> n;
        int P[n+1];
        int total = 0;
        for (int i=1; i<=n; i++){
            cin >> P[i];
            total = total+ P[i];
            pq.push(make_pair(P[i],i));
        }
        vector<char> steps(1002);
        char dictionary[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        printf("Case #%d: ", z);
        while (total>0){
          
            ii u = pq.top();
            pq.pop();
            if (total%2 == 1){
                total--;
                pq.push(make_pair(u.first-1,u.second));
                cout << dictionary[u.second-1];
            }
            else {
                ii v = pq.top();

                if (v.first > (total-2)/2){
                    total = total-2;
                    pq.pop();
                    pq.push(make_pair(u.first-1,u.second));
                    pq.push(make_pair(v.first-1,v.second));
                    cout << dictionary[u.second-1] << dictionary[v.second-1];
                }
                else {
                    total = total-2;
                    pq.push(make_pair(u.first-2, u.second));
                    cout << dictionary[u.second-1]<< dictionary[u.second-1];
                }
            }
            cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
#include <cstring>

#define MAX
#define INF
#define MOD
#define MP make_pair
#define AA first
#define BB second
#define IS(X) cout << #X << " = " << X << endl;
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef queue<int> QI;
typedef priority_queue<int> PQI;
int n;
struct E{
    int id;
    int num;
    friend bool operator < (E e1,E e2) {
        return e1.num > e2.num;
    }
}p[27];
vector<pair<int,int> > v;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;cin >> t;
    int cc = 0;
    while(t--) {
        cin >> n;
        memset(p,0,sizeof p);
        int tot = 0;
        for(int i = 0;i < n;i++) {
            cin >> p[i].num;p[i].id = i;
            tot += p[i].num;
        }
        sort(p,p+n);
        v.clear();
        int top = 0;
        int e = n-1;
        while(tot) {
            while(!p[top].num) top++;
            while(!p[e].num) e--;
            if(top != e) {
                p[top].num--;p[e].num--;tot-=2;
                v.push_back(make_pair(p[top].id,p[e].id));
            } else {
                p[top].num--;tot--;
                v.push_back(make_pair(p[top].id,-1));
            }
        }
        printf("Case #%d: ",++cc);
        for(int i = v.size()-1;i >= 0;i--) {
            printf("%c",v[i].first + 'A');
            if(v[i].second != -1)
                printf("%c",v[i].second + 'A');
            if(i)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}

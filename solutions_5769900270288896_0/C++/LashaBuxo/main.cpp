#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<time.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<set>
#define Pi 3.14159265358
#define mod9 %1000000009
#define INF 1000000000LL
#define mod7 %1000000007
#define LL long long
#define time clock()/(double)CLOCKS_PER_SEC
using namespace std;
 int i,n,j,r,c,T;
 vector<int> a[1001],last[1001];
 struct name{
    int x;
    int y;
    int z;
    int k;
 } p;
 vector<name> heap;
 bool how(name A,name B){
    return A.z<B.z;
 }
 int f(int x,int y){

    return a[x-1][y]+a[x+1][y]+a[x][y+1]+a[x][y-1];
 }
 void add_in_heap(name e){
    heap.push_back(e);
    push_heap(heap.begin(),heap.end(),how);
 }
 void del(){
    pop_heap(heap.begin(),heap.end(),how);
    heap.pop_back();
 }
int main(){
 #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
    cin>>T;
    int u=0;
    while (T--){
            u++;
        cin>>r>>c>>n;
        for (i=0;i<=r+1;i++)
            last[i].clear(),last[i].resize(c+2,0),a[i].clear(),a[i].resize(c+2,0);
        for (i=1;i<=r;i++)
            for (j=1;j<=c;j++)
                last[i][j]=1,a[i][j]=1,a[i+1][j]=a[i][j+1]=0;
        heap.clear();
        make_heap(heap.begin(),heap.end(),how);
        for (i=1;i<=r;i++)
            for (j=1;j<=c;j++){
                p.x=i; p.y=j; p.z=f(i,j); p.k=1;
                add_in_heap(p);

                heap.push_back(p);
            }
            int cnt=0;
        for (i=1;cnt<r*c-n;i++){
            p=heap.front();
            del();

            if (p.k!=last[p.x][p.y] || a[p.x][p.y]==0) continue;

            cnt++;
            a[p.x][p.y]=0;

            if (p.x>1) last[p.x-1][p.y]++;
            if (p.x<r) last[p.x+1][p.y]++;
            if (p.y>1) last[p.x][p.y-1]++;
            if (p.y<c) last[p.x][p.y+1]++;

            name q;
            if (p.x>1) q.x=p.x-1,q.y=p.y,q.z=f(p.x-1,p.y),q.k=last[p.x-1][p.y];
            if (p.x>1) add_in_heap(q);

            //name q;
            if (p.x<r) q.x=p.x+1,q.y=p.y,q.z=f(p.x+1,p.y),q.k=last[p.x+1][p.y];
            if (p.x<r) add_in_heap(q);

            //name q;
            if (p.y>1) q.x=p.x,q.y=p.y-1,q.z=f(p.x,p.y-1),q.k=last[p.x][p.y-1];
            if (p.y>1) add_in_heap(q);

            //name q;
            if (p.y<c) q.x=p.x,q.y=p.y+1,q.z=f(p.x,p.y+1),q.k=last[p.x][p.y+1];
            if (p.y<c) add_in_heap(q);

        }
        int ans=0;

        for (i=1;i<=r;i++)
            for (j=1;j<=c;j++)
                if (a[i][j] && a[i][j+1] && j<c) ans++;
        for (i=1;i<=r;i++)
            for (j=1;j<=c;j++)
                if (a[i][j] && a[i+1][j] && i<r) ans++;

            cout<<"Case #"<<u<<": "<<ans<<endl;

    }
  return 0;
}

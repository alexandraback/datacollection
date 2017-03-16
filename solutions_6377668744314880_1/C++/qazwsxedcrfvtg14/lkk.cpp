#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/rope>
#include<cmath>
#pragma GCC optimize ("O3")
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef __gnu_pbds::priority_queue<int> heap;
typedef tree<int,null_type,less<int>,splay_tree_tag,tree_order_statistics_node_update> tre;
typedef pair<int,int> par;
typedef pair<int,long long int> pr1;
typedef pair<long long int,par> pr2;
par ar[3005],br[6005];
inline long long int crs(par &o,par &a,par &b){
    return 1ll*(a.f-o.f)*(b.s-o.s)-1ll*(b.f-o.f)*(a.s-o.s);
    }
int main(){
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&ar[i].f,&ar[i].s);
        int ans=0;
        printf("Case #%d:\n",T);
        for(int i=0;i<n;i++){
            int bp=0;
            for(int j=0;j<n;j++)
                if(i!=j)
                    br[bp++]=ar[j];
            sort(br,br+n-1,[&](par a,par b){
                return atan2(a.s-ar[i].s,a.f-ar[i].f)<atan2(b.s-ar[i].s,b.f-ar[i].f);
                });
            for(int j=0;j<n-1;j++)
                br[bp++]=br[j];
            int now=0;
            while(now<bp-1&&crs(ar[i],br[0],br[now+1])>=0)
                now++;
            int nans=n-1-(now-0+1);
            for(int j=1;j<n-1;j++){
                while(now<bp-1&&crs(ar[i],br[j],br[now+1])>=0)
                    now++;
                nans=min(n-1-(now-j+1),nans);
                }
            printf("%d\n",max(nans,0));
            }
        }
	return 0;
    }

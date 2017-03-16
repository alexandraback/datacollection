#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/rope>
#pragma GCC optimize ("O3")
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef __gnu_pbds::priority_queue<int> heap;
typedef tree<int,null_type,less<int>,splay_tree_tag,tree_order_statistics_node_update> tre;
typedef pair<long long int,long long int> par;
typedef pair<int,long long int> pr1;
typedef pair<long long int,par> pr2;
int ar[1005];
int b,n;
long long cnt(long long int k){
    long long int ret=0;
    for(int i=0;i<b;i++)
        ret+=k/ar[i]+1;
    return ret;
    }
int main(){
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        scanf("%d%d",&b,&n);
        for(int i=0;i<b;i++)
            scanf("%d",&ar[i]);
        long long int l=0,r=1e15;
        while(l<=r){
            long long int mid=l+r>>1;
            if(cnt(mid)>=n)r=mid-1;
            else l=mid+1;
            }
        long long prt=n-cnt(r);
        int ans=0;
        int nd=0;
        for(int i=0;i<b;i++)
            if(!(l%ar[i])){
                ans=i+1;
                if((++nd)==prt)
                    break;
                }
        printf("Case #%d: %d\n",T,ans);
        }
	return 0;
    }

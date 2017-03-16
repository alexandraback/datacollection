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
int main(){
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&ar[i]);
        int ans=0,now=ar[0];
        for(int i=1;i<n;i++){
            if(now>ar[i])ans+=now-ar[i];
            now=ar[i];
            }
        printf("Case #%d: %d",T,ans);
        int ma=0;
        for(int i=1;i<n;i++)
            ma=max(ma,ar[i-1]-ar[i]);
        ans=ma*(n-1);
        now=0;
        for(int i=0;i<n-1;i++)
            if(ar[i]<ma)ans-=ma-ar[i];
        printf(" %d\n",ans);
        }
	return 0;
    }


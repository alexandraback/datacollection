#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
//#include<ext/rope>
#pragma GCC optimize ("O3")
#define f first
#define s second
//#define mkptr make_shared<nod>
//#define mkptr new nod
//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC diagnostic error "-m64"
//-wl,--stack=2147483647
//int main() __attribute__((optimize("-O3")));
using namespace std;
typedef pair<int,int> par;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//int ar[26005];
int mp[30];
int main(){
    int t,T=0;
    scanf("%d",&t);
    while(t--){T++;
        int n;
        scanf("%d",&n);
        int tot=0;
        for(int i=0;i<n;i++)
            scanf("%d",&mp[i]),tot+=mp[i];
        printf("Case #%d:",T);
        for(int i=0;i<tot;i++){
            int ma=0,p=-1;
            for(int j=0;j<n;j++)
                if(ma<mp[j])
                    ma=mp[j],p=j;
            mp[p]--;
            putchar(' ');
            putchar(p+'A');
            ma=0,p=-1;
            for(int j=0;j<n;j++)
                if(ma<mp[j])
                    ma=mp[j],p=j;
            if(ma*2>(tot-i-1))
                putchar(p+'A'),i++;
            }
        puts("");
        }
    return 0;
    }

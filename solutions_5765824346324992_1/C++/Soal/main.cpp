#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <climits>
using namespace std;
typedef long long LL;
LL a[1100];

int main(){
    //getResult("jijiji");
    //getResult("");
    freopen("/Users/jiangzefan/code/C/C/input.txt","r",stdin);
    freopen("/Users/jiangzefan/code/C/C/output.txt","w",stdout);
    int _,__;
    scanf("%d",&_);
    for (__=1;__<=_;__++){
        int n,num;
        scanf("%d%d",&n,&num);
        for (int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        LL l=0,r=1e14;
        while (l<r){
            LL mid=l+r>>1;
            LL s=0;
            for (int i=0;i<n;i++){
                s+=mid/a[i]+1;
            }
            // cout << mid << ' ' << s << endl;
            if (s<num){
                l=mid+1;
            }else{
                r=mid;
            }

        }
        // cout << r << endl;
        int ans=0;
        vector<int> t;
        for (int i=0;i<n;i++){
            num-=r/a[i]+1;
            if (r%a[i]==0){
                t.push_back(i+1);
                ++num;
            }
        }
        // cout << num << endl;
        printf("Case #%d: %d\n",__,t[num-1]);
    }
    
}
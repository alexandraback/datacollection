using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
typedef long long LL;

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    cin>>t;
    for (int time=1;time<=t;time++){
        int n;
        cin>>n;
        int cnt[100];
        memset(cnt,0,sizeof cnt);
        for (int i=0;i<n;i++)
            cin>>cnt[i];
        cout<<"case #"<<time<<":";
        int sum=0;
        for (int i=0;i<n;i++) sum+=cnt[i];
        while(sum>0){
            int maxm=-1;
            int maxi=-1;
            int maxm2=-1;
            int maxi2=-1;
            for (int j=0;j<n;j++)
            if (cnt[j]>maxm){maxm2=maxm;maxi2=maxi;maxm=cnt[j];maxi=j;}
            else if (cnt[j]==maxm&&cnt[j]>maxm2){maxm2=cnt[j];maxi2=j;}

            if (maxm2==maxm){
                int tmp=0;
                for (int t=0;t<n;t++)
                if (cnt[t]==maxm2) tmp++;
                if (tmp>2){
                                    char out=maxi+'A';
                cout<<" "<<out;
                cnt[maxi]--;
                sum--;

                }else{
                char out=maxi+'A';
                cout<<" "<<out;
                out=maxi2+'A';
                cout<<out;
                cnt[maxi]--;
                cnt[maxi2]--;
                sum-=2;
                }
            }else{
                char out=maxi+'A';
                cout<<" "<<out;
                cnt[maxi]--;
                sum--;
            }
        }
        cout<<endl;

    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

#define xx first
#define yy second
#define ll long long
#define pb push_back
#define pp pop_back
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
using namespace std;
const int maxn=20;
int a[maxn][maxn];
int cnt[maxn];
int t,ans1,ans2;
int main(){
    ifstream cin("1.in");
    ofstream cout("1.out");
    cin>>t;
    for(int l=1;l<=t;l++){
        memset(cnt,0,sizeof(cnt));
        memset(a,0,sizeof(a));
        ans1=ans2=0;
        cin>>ans1;
        for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)cin>>a[i][j];
        for(int j=1;j<=4;j++)cnt[a[ans1][j]]++;
        memset(a,0,sizeof(a));
        cin>>ans2;
        for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)cin>>a[i][j];
        for(int j=1;j<=4;j++)cnt[a[ans2][j]]++;
        int sum1=0;
        int sum0=0;
        int sum2=0;
        for(int i=1;i<=16;i++){
            if(cnt[i]==0)sum0++;
            else if(cnt[i]==1)sum1++;
            else sum2++;
        }
        cout<<"Case #"<<l<<": ";
        if(sum2>1)cout<<"Bad magician!";
        else if(sum2==1){
            int pos;
            for(int i=1;i<=16;i++)if(cnt[i]==2)pos=i;
            cout<<pos;
        }
        else cout<<"Volunteer cheated!";
        cout<<endl;
    }
}

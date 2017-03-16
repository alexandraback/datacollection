#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include <queue>
using namespace std;
typedef long long ll;
int n;
int m[1001];
typedef pair<ll,int> pii;
int main(){
    //freopen("input1.txt","r",stdin);
    freopen("A-small-attempt0.in","r",stdin);
   //freopen("A-large.in","r",stdin);
    freopen("output1.txt","w",stdout);
    
    int t;
    cin >> t;
    
    for(int ti=1;ti<=t;ti++){
		cout << "Case #"<<ti<<": ";
        cin>>n;
		for(int i=0;i<n;i++) cin>>m[i];
		int ans1=0, ans2=0;
		int tmp = 0;
        for(int i=1;i<n;i++){
            if(m[i]-m[i-1]<0)
                ans1+=(m[i-1]-m[i]);            
            tmp = max(tmp,m[i-1]-m[i]);
        }
        for(int i=0;i<n-1;i++){
            if(m[i]>=tmp)
				ans2 += tmp;
            else ans2 += m[i];
        }
		cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}

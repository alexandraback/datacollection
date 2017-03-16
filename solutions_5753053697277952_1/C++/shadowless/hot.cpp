#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define si(X) scanf("%d", &(X))
#define sll(X) scanf("%lld",&(X))
#define INFL 0x3f3f3f3f3f3f3f3fLL
ll gcd(ll a,ll b){
	if(b==0)
	return a;
	return gcd(b,a%b);
}
string toBin(ll a) {
	string res = "";
	while (a) {
		res += char((a & 1) + '0');
		a >>= 1;
	}
	reverse(res.begin(), res.end());
	return res;
}
const int mod = 1e9+7;
ll expo(ll base,ll pow){
    ll ans = 1;
    while(pow!=0){
        if(pow&1==1){
            ans = ans*base;
            ans = ans%mod;
        }
        base *= base;
        base%=mod;
        pow/=2;
    }
    return ans;
}
double pi = 3.141592653589793238462643;
double error = 0.0000001;
/* -------Template ends here-------- */

const int M = 100001;

int main(){

	int t;
	si(t);

	for(int alp = 1;alp<=t;alp++){
		int ans = 0;
		cout<<"Case #"<<alp<<": ";
		int n;
		si(n);
		int arr[30];
		memset(arr,0,sizeof(arr));

		for(int i = 0;i<n;i++){
            int num;
            si(num);
            arr[i] = num;
		}

		while(true){
            int nonz = 0,maind = 0,ma = 0;
            for(int i = 0;i<n;i++){
                if(arr[i]>ma){
                    ma = arr[i];
                    maind = i;
                }
                if(arr[i]>0){
                    nonz++;
                }
            }
            if(nonz==0)
                break;

            if(nonz==2){
                int ind1 = -1,ind2 = -1;
                for(int i = 0;i<n;i++){
                    if(arr[i]>0&&ind1==-1){
                        ind1 = i;
                    }
                    else if(arr[i]>0&&ind2==-1){
                        ind2 = i;
                    }
                }
                char c1 = ind1+65;
                char c2 = ind2+65;
                cout<<c1<<c2<<" ";
                arr[ind1]--;
                arr[ind2]--;
                continue;
            }
            char c1 = maind+65;
            cout<<c1<<" ";
            arr[maind]--;

		}
		cout<<endl;















		//cout<<"Case #"<<alp<<": "<<ans<<endl;

	}











}
























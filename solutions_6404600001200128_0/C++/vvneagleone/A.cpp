#include<cstdio>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<utility>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long LL;
#define MOD 1000000007LL

#ifdef __WIN32
#define gx getchar
#define px putchar
#define ps putchar(' ')
#define pn putchar('\n')
#else
#define gx getchar_unlocked
#define px putchar_unlocked
#define ps putchar_unlocked(' ')
#define pn putchar_unlocked('\n')
#endif // __WIN32

void scan(int &n){int sign=1;n=0;char c=gx();while(c<'0'||c>'9'){if(c=='-')sign=-1;c=gx();}while(c>='0'&&c<='9')n=(n<<3)+(n<<1)+c-'0',c=gx();n=n*sign;}
void lscan(LL &n){int sign=1;n=0;char c=gx();while(c<'0'||c>'9'){if(c=='-')sign=-1;c=gx();}while(c>='0'&&c<='9')n=(n<<3)+(n<<1)+c-'0',c=gx();n=n*(LL)(sign);}
int sscan(char a[]){char c=gx();while(c==' '||c=='\n')c=gx();int i=0;while(c!='\n')a[i++]=c,c=gx();a[i]=0;return i;}
int wscan(char a[]){char c=gx();while(c==' '||c=='\n')c=gx();int i=0;while(c!='\n'&&c!=' ')a[i++]=c,c=gx();a[i]=0;return i;}
void print(int n){if(n<0){n=-n;px('-');}int i=10;char o[10];do{o[--i]=(n%10)+'0';n/=10;}while(n);do{px(o[i]);}while(++i<10);}
void lprint(LL n){if(n<0LL){n=-n;px('-');}int i=21;char o[21];do{o[--i]=(n%10LL)+'0';n/=10LL;}while(n);do{px(o[i]);}while(++i<21);}
void sprint(const char*a){const char*p=a;while(*p)px(*p++);}
LL power(LL b,LL e,LL m=MOD){LL r=1;while(e){if(e&1)r=(r*b)%m;b=(b*b)%m;e>>=1;}return r;}
LL minv(LL a,LL m=MOD){LL c,t,q,x,y;c=m;x=0;y=1;while(a>1){q=a/c;t=c;c=a%c;a=t;t=x;x=y-q*x;y=t;}if(y<0)y+=m;return y;}
LL absll(LL x){if(x<0)return -x;return x;}

int main() {
    LL t, tt, i, j, k, n, sum1, sum2, mx;
    LL m[1002];
    cin >> t;
    for( tt = 1; tt <= t; ++tt ) {
        cin >> n;
        for( i = 0; i < n; ++i ) {
            cin >> m[i];
        }
        cout << "Case #" << tt << ": ";
        sum1 = sum2 = 0;
        for( i = 0; i < n-1; ++i ) {
            if( (m[i] - m[i+1]) > 0 ) sum1 += m[i] - m[i+1];
        }
        cout << sum1 << " ";
        mx = 0;
        for( i = 0; i < n-1; ++i ) {
            if( m[i] - m[i+1] > mx ) mx = m[i] - m[i+1];
        }
        if( mx == 0 ) {
            cout << 0 << endl;
        }
        else {
            k = sum2 = 0;
            for( i = 0; i < n-1; ++i ) {
                //k += m[i];
                //LL x = min(mx,k);
                sum2 += min(m[i],mx);//x;
                //k -= x;
                //cout << sum2 << endl;
            }
            cout << sum2 << endl;
        }
    }
	return 0;
}

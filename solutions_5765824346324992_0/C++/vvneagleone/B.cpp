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
#include<climits>
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

LL primes[9] = {2,3,5,7,11,13,17,19,23};

LL e[9];

void fac( int x ) {
    LL ct;
    for( int j = 0; j < 9; ++j ) {
        ct = 0;
        if( x % primes[j] == 0 ) {
            while( x % primes[j] == 0 ) {
                x /= primes[j];
                ++ct;
            }
        }
        e[j] = max(e[j],ct);
    }
}

LL m[1002], i, j, n, b;
LL lcm() {
    LL prod = 1;
    for( i = 0; i < 9; ++i )
        if( e[i] != 0 ) prod *= power( primes[i], e[i], LLONG_MAX );
    return prod;
}

int main() {
    LL t, tt, i, j, k, n, sum, sum1, sum2, mx, b, lc;
    LL x[10];
    cin >> t;
    for( tt = 1; tt <= t; ++tt ) {
        cin >> b >> n;
        for( i = 0; i < 9; ++i ) e[i] = 0;

        for( i = 0; i < b; ++i ) {
            cin >> m[i];
            fac( m[i] );
        }

        lc = lcm();
        sum1 = 0;
        for( i = 0; i < b; ++i ) {
            sum1 += lc / m[i];
        }

        cout << "Case #" << tt << ": ";
        n = n % sum1;
        if( n == 0 ) n = sum1;

        for( i = 0; i < b; ++i ) x[i] = 0;
        j = 0;
        LL last = 0;
        while( j < n ) {
            LL minn = x[0];
            for( i = 1; i < b; ++i ) {
                minn = min(minn, x[i]);
            }
            if( minn == 0 ) {
                for( i = 0; i < b; ++i ) {
                    if(x[i] == 0) {
                        x[i] = m[i];
                        last = i;
                        break;
                    }
                }
                ++j;
            }
            else {
                for( i = 0; i < b; ++i ) {
                    x[i] -= minn;
                }
            }
        }
        cout << last + 1 << endl;
    }
	return 0;
}

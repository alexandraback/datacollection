//Akhilesh Gulati, NSIT
#include<bits/stdc++.h>
void printmat(int rs, int re, int cs, int ce, int ncol, int* a) {
    printf("   ");
    for(int j=cs; j<=ce; j++) {
        printf("%3d", j);
    }
    printf("\n");
    for(int i=rs; i<=re; i++) {
        printf("%3d", i);
        for(int j=cs; j<=ce; j++) {
            printf("%3d", a[i*ncol+j]);
        }
        printf("\n");
    }
}
#define ll long long int
#define gc getchar
void scan(int &x) { register int c = gc(); x = 0; for(;(c<48 || c>57);c = gc()); for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} }
void scanll(ll &x) { register ll c = gc(); x = 0; for(;(c<48 || c>57);c = gc()); for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} }
#define pii pair<int,int>
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define foreach(it, t) for(auto it = t.begin(); it!=t.end(); it++)  //it: pointer
#define vi vector<int>
#define pb push_back
#define in(n) scan(n)
#define inll(n) scanll(n)
#define out(n) printf("%d", n)
#define outll(n) printf("%lld", n)
#define outs(n) printf("%d ",n)   //with space
#define outsll(n) printf("%lld ",n)   //with space
#define newl printf("\n")
#define chk(a) cout << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl

using namespace std;

int r,c,n;
int a[16][16];

int nOnes(int n) {
    int i=0;
    int p=0;
    for(; i<r*c; i++) {
        if(n&(1<<i)) p++;
    }
    return p;
}

int checkconf() {
    int p=0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c-1; j++) {
            if(a[i][j]==1 && a[i][j+1]==1) {
                p++;
            }
        }
    }
    for(int j=0; j<c; j++) {
        for(int i=0; i<r-1; i++) {
            if(a[i][j]==1 && a[i+1][j]==1) {
                p++;
            }
        }
    }
    return p;
}

int minVal() {
    int m = pow(2,r*c);
    int ans = INT_MAX;
    for(int i=0; i<m; i++) {
//        chk(1);
//        chk(nOnes(i));
        memset(a,0,sizeof(a));
//        chk(n);
        if(nOnes(i)==n) {
//            chk(2);
            for(int j=0; j<(r*c); j++) {
                if(i & (1<<j)) {
//                    chk(3);
                    a[j/c][j%c] = 1;
                }
            }
//            newl;
//            for(int x=0; x<r; x++) {
//                for(int y=0; y<c; y++) {
//                    outs(a[x][y]);
//                }
//                newl;
//            }
//            printmat(0,r-1,0,c-1,c,(int*)a); newl;
//            chk(c);

            ans = min(ans, checkconf());
        }
    }
    return ans;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int t,k;
	in(t);
	for(k=1; k<=t; k++) {
        in(r);
        in(c);
        in(n);
        printf("Case #%d: ",k);
        out(minVal()); newl;
	}
}

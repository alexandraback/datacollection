#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define pii pair<int, int>
using namespace std;
const int N = int(1e5);
int n, un, dn, an,bn;
ll A,B,C;
int ans[N];

       
struct point{
        int x,y;
        point(){
            x = y = 0;
        }
        point(int _x,int _y){
            x = _x;
            y = _y;
        }
        void read(){
            scanf("%d%d",&x,&y);
        }
        point operator + (point a){
            return point(x + a.x,y + a.y);
        }
        point operator - (point a){
            return point(x - a.x,y - a.y);
        }
        ll operator * (point a){
            return (1ll*x*a.y - 1ll*y*a.x);
        }
        ll scalar(point a){
            return(1ll*x*a.x + 1ll*y*a.y);
        }
        double sdist(){
        return (1ll*x*x + 1ll*y*y);
    }
        double dist(){
            return sqrt(1ll*x*x + 1ll*y*y + 0.0);
    }
} a[3111],up[3111],down[3111],t[3111],b[3111];
 
 
bool cmp(point a, point b){
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

void get(point a,point b){
	A = b.y - a.y;
	B = a.x - b.x;
	C = 1ll*a.y * b.x - 1ll*b.y*a.x;
}
 
int main () {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++){
		scanf("%d",&n);	
		printf("Case #%d:\n",tt);
		for(int i=1;i<=n;i++){
		    a[i].read();
		    b[i] = a[i];
		}
		sort(a+1,a+n+1,cmp);
		up[1] = a[1], up[2] = a[n];
		un = 2;
		down[1] = a[1] , down[2] = a[n];
		dn = 2;
		for(int i=2;i<=n;i++){
		    if((a[1] - a[n])*(a[1] - a[i]) >= 0){
		        while(un > 1 && (up[un-1] - up[un])*(up[un-1] - a[i]) >= 0) un--;
		        up[++un] = a[i];
		    }
		    if((a[1] - a[n])*(a[1] - a[i]) <= 0){
		        while(dn > 1 && (down[dn-1] - down[dn])*(down[dn-1] - a[i]) <= 0) dn--;
		        down[++dn] = a[i];
		    }
		}
		int k = 0;
		for(int i=1;i<=un;i++){
		    t[++k] = up[i];
		}
		
		for(int i=dn-1;i>1;i--){
		    t[++k] = down[i];
		}

		for(int i=1;i<=n;i++){
			ans[i] = n - 1;
			for(int j=1;j<=k;j++){
				if(b[i].x == t[j].x && b[i].y == t[j].y){
					ans[i] = 0;
					break;
				}
				get(b[i],t[j]);
				an = 0,bn = 0;
				for(int s=1;s<=n;s++){
					if(A * b[s].x + B * b[s].y + C > 0) an++;
					if(A * b[s].x + B * b[s].y + C < 0) bn++;		
				}
				an = min(an,bn);
				ans[i] = min(ans[i],an);
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}

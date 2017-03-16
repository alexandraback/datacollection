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
} a[1111],up[1111],down[1111],t[1111],b[1111];
 
void get(point a,point b){
	A = b.y - a.y;
	B = a.x - b.x;
	C = 1ll*b.x * a.y - 1ll*a.x*b.y;
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
		}
		for(int i=1;i<=n;i++){
			ans[i] = n - 1;
			for(int j=1;j<=n;j++) if(i != j){
				get(a[i],a[j]);
				an = 0,bn = 0;
				for(int s=1;s<=n;s++){
					if(A * a[s].x + B * a[s].y + C > 0) an++;
					if(A * a[s].x + B * a[s].y + C < 0) bn++;		
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

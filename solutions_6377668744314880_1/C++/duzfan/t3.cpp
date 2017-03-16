#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;

const int N = 3005;
const double Pi = acos(-1.0);
const double eps = 1e-10;

#define fo(i , st , en) for (int i = st; i <= en; i++)
#define Me(x , y) memset(x , y , sizeof(x))

struct _node{
	double p; int x;
}b[N + N];

bool operator < (const _node &x , const _node &y){
	return x.p < y.p;
}

int t , n;
pi a[N];

bool cmp(const int &x , const int &y){
	if (a[x].first != a[y].first)	return a[x].first < a[y].first;
	return a[x].second > a[y].second;
}

int main(){
	freopen("t3.in" , "r" , stdin);
	freopen("t3.out" , "w" , stdout);
	scanf("%d" , &t);
	fo (p , 1 , t){
		scanf("%d" , &n);
		printf("Case #%d:\n" , p);
		fo (i , 1 , n) scanf("%d%d" , &a[i].first , &a[i].second);
		fo (i , 1 , n){
			int tot = 0;
			fo (j , 1 , n)
				if (j != i) b[++tot] = (_node){atan2(a[i].first - a[j].first , a[i].second - a[j].second) , j};
			sort(b + 1 , b + tot + 1);
			fo (j , 1 , tot){
				b[tot + j] = b[j]; b[tot + j].p += Pi * 2;
			}
			int num = n - 1 , t1 = 1 , t2 = 2;
			fo (j , 1 , tot){
				while (t1 < tot + j && b[j].p + Pi > b[t1].p + eps) t1++;
				while (t2 < tot + j && b[j].p + Pi + eps > b[t2].p) t2++;
				num = min(num , min(tot + j - t2 , t1 - j - 1));
			}
			printf("%d\n" , num);
		}
	}
	return 0;
}

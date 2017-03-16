// Bismillahirrahmanirrahim
#include <bits/stdc++.h>
using namespace std;

typedef long long int Lint;
typedef pair < int , int > pii;
typedef pair < int , pii > piii;

#define foreach(_i,x)  for(__typeof(x.begin()) _i=x.begin() ; _i != x.end() ; _i++)
#define yeral() (struct node *)calloc(1,sizeof(struct node))
#define bug printf("#NOOOOO#\n")
#define all(x) x.begin(),x.end()
#define mid ((l+r)/2)
#define pb push_back
#define mp make_pair
#define sc second
#define ft first

inline int read(){ int _x; scanf("%d",&_x); return _x; }

const int INF  = (int) 1e9;
const int mod  = (int) 1e9+7;
const int maxn = (int) 1e5+5;
const int logn = 20;

int N;

void islem(){
	priority_queue < pii > pq;
	scanf("%d",&N);
	
	int a,top = 0;
	for ( int i = 1 ; i <= N ; i++ ){
		scanf("%d",&a);
		pq.push ( pii ( a , i ) );
		top += a;
	}
	
	while ( pq.size() ){
		pii cur = pq.top();
		pq.pop();
		if ( top > 3 && cur.ft == pq.top().ft  ){
			pii cur2 = pq.top();
			pq.pop();
			printf("%c%c ",'A'-1+cur.sc,'A'-1+cur2.sc);
			pq.push(pii(cur.ft-1,cur.sc));
			pq.push(pii(cur2.ft-1,cur2.sc));
			top -= 2;
			continue;
		}
		if ( top == 3 ){
			printf("%c ",'A'+cur.sc-1);
			pq.push(pii(cur.ft-1,cur.sc));
			top--;
			continue;			
		}
		if ( top == 2 ){
			printf("%c%c\n",'A'+cur.sc-1,'A'+pq.top().sc-1);
			return ;
		}
		printf("%c ",'A'+cur.sc-1);
		pq.push(pii(cur.ft-1,cur.sc));
		top--;
	}
	
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("cikti.out","w",stdout);
	
	int T;
	cin >> T;
	
	for ( int test = 1 ; test <= T ; test++ ){
		printf("Case #%d: ",test);
		islem();
	}
	
	return 0;
}

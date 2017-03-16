//============================================================================
// Author      : Prateek Agarwal
// Institution : NITJ
//============================================================================

#include <bits/stdc++.h>

#define ll long long

#define TEST int t;scan(t);while(t--)
#define scan(n) scanf("%d",&n)
#define set(x,y) memset(x,y,sizeof(x))
#define loop(i,l,r,x) for (int i=l;i<=r;i+=x)
#define printl(n) printf("%d\n",n)
#define print(n) printf("%d ",n)
#define pb push_back

#define INF 1000000000
#define M 1000000009
#define MAX 100000000
#define LIM 10

using namespace std;

ofstream of("out.txt");
ifstream in("inp.txt");

struct node{
	int x;
	char c;
};

node a[100];

bool operator <(node a,node b){
	return a.x>b.x;
}

int init(){
	int t;
	in>>t;
	int cs = 1;
	while(t--){
		int n;
		in>>n;
		int tot = 0;
		for (int i=0;i<n;i++){
			a[i].c = char(i+65);
			in>>a[i].x;
			tot+=a[i].x;
		}

		cout << "Case #" << cs++ << ": ";

		while(tot){
			sort(a,a+n);
			if (tot==1||tot==2){
				for (int i=0;i<n;i++){
					for (int j=0;j<a[i].x;j++){
						cout << a[i].c;
						a[i].x--;
						tot--;
					}
				}
				break;
			}

			int temp = max(a[0].x-1,a[1].x);

			if (2*temp<=tot-1){
				tot--;
				a[0].x--;
				cout << a[0].c;
			}
			else{
				tot-=2;
				a[0].x--;
				a[1].x--;
				cout << a[0].c << a[1].c;
			}

			cout << " ";
		}
		cout << endl;
	}
	return 0;
}

int main(){
	//clock_t start = clock();
	init();
	//printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}


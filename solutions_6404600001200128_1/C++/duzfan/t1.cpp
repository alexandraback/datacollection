#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1005;

#define fo(i , st , en) for (int i = st; i <= en; i++)
#define Me(x , y) memset(x , y , sizeof(x))

int t , n;
int a[N];

int main(){
	freopen("t1.in" , "r" , stdin);
	freopen("t1.out" , "w" , stdout);
	scanf("%d" , &t);
	fo (i , 1 , t){
		scanf("%d" , &n);
		fo (j , 1 , n) scanf("%d" , a + j);
		int sum1 = 0 , sum2 = 0;
		fo (j , 1 , n - 1)
			if (a[j] > a[j + 1]) sum1 += a[j] - a[j + 1];
		int max2 = 0;
		fo (j , 1 , n - 1)
			if (a[j] > a[j + 1]) max2 = max(max2 , a[j] - a[j + 1]);
		int num2 = (max2 + 9) / 10;
		fo (j , 1 , n - 1) sum2 += min(max2 , a[j]);
		printf("Case #%d: %d %d\n" , i , sum1 , sum2);
	}
	return 0;
}

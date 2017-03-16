#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<math.h>
#include <algorithm>

using namespace std;

#define LL long long
#define LD long double
#define FM(i,a,b) for(int i=a;i<b;i++) //(b-a) times a ~ b-1
#define P_T "A"
#define I_T "large"
#define FILE_OPEN() char name1[50],name2[50];\
sprintf(name1, "%s-%s.in", P_T,I_T );\
sprintf(name2,"%s-%s.out" , P_T,I_T );\
freopen(name1,"r", stdin);freopen(name2, "w" ,stdout) // open file

#define D_INPUT_A(x) int x;scanf( "%d",&x)
#define D_INPUT_B(x,y) int x;int y;scanf( "%d%d",&x,&y)
#define D_INPUT_C(x,y,z) int x;int y;int z;scanf( "%d%d%d",&x,&y,&z)
#define INPUT_A(x) scanf("%d",&x)
#define INPUT_B(x,y) scanf("%d%d",&x,&y)
#define INPUT_C(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define INPUT_STR(x) scanf("%s",x)
#define OUTPUT(x) printf("Case #%d: %d\n",n+1,x)
#define OUTPUT_B(x,y) printf("Case #%d: %d %d\n",n+1,x,y)
#define OUTPUT_STR(x) printf("Case #%d: %s\n",n+1,x)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

const LD EPS = 1e-10;
const LD PI = acos(-1.0);

int N;
int input[26];
int sum; 

int find_max_index() {
	int output = 0;
	FM(i, 1, N) {
		if (input[i] > input[output])
			output = i;
	}
	return output;
}

void evacuation() {
	int s1 = find_max_index();
	input[s1]--;
	int s2 = find_max_index();
	if (input[s1] + 1 == input[s2] && sum % 2 == 0) {
		input[s2]--;
		sum -= 2;
		printf(" %c%c", s1 + 'A', s2 + 'A');
	}
	else {
		sum--;
		printf(" %c", s1 + 'A');
	}

}

int main() {
	FILE_OPEN();

	D_INPUT_A(T);
	FM(n, 0, T) {
		sum = 0;
		INPUT_A(N);
		FM(i, 0, N) {
			INPUT_A(input[i]);
			sum += input[i];
		}
			//
		printf("Case #%d:", n + 1);
		while (sum != 0) {
			evacuation();
		}
		printf("\n");
	}
	return 0;
}

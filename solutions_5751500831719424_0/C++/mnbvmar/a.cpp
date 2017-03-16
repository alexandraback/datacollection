#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#define MP make_pair
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define ALL(container) (container).begin(), (container).end()
#define FORI(i,from,to) for(int i = (from); i <= (to); i++)
#define FORD(i,from,to) for(int i = (from); i >= (to); i--)
#define REP(i,num) for(int i = 0; i < (num); i++)


using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
const LD Eps = 1e-8;
inline bool is_zero(LD x){ return (x >= -Eps) && (x <= Eps); }



/**********************************************************************/
/**********************************************************************/

int N;
char str[100][105];
int len[105];
char patt[105];
vector<int> lens[105];

void cleanup(){
	for(int i=  0; i < 105; i++) lens[i].clear();
}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s", str[i]);
		len[i] = strlen(str[i]);
	}
	
	//printf("[%d]\n", N);
}

void output(int res){
	if(res != -1)
		printf("%d\n", res);
	else
		printf("Fegla won\n");
}


void process_test(){
	cleanup();
	input();
	
	copy(str[0], str[0]+len[0], patt);
	int siz = unique(patt, patt+len[0]) - patt;
	patt[siz] = 0;
	//printf("%s\n", patt);
	
	for(int i = 0; i < N; i++){
		int ptr = 0;
		char last = -1;
		int num = 0;
		
		for(int pos = 0; pos < len[i]; pos++){
			//printf("i=%d pos=%d last=%c new=%c\n", i, pos, last, patt[ptr]);
			if(str[i][pos] == last){
				num++;
			} else if(str[i][pos] == patt[ptr]){
				if(ptr) lens[ptr-1].push_back(num);
				num = 1;
				last = patt[ptr];
				ptr++;
				
			} else {
				output(-1);
				return;
			}
		}
		if(ptr != siz){
			output(-1);
			return;
		}
		
		lens[ptr-1].push_back(num);
	}
	//printf("Y\n");
	
	int result = 0;
	for(int i = 0; i < siz; i++){
		sort(lens[i].begin(), lens[i].end());
		//printf("A\n");
		
		int what = lens[i][N/2];
		for(int j = 0; j < N; j++)
			result += abs(lens[i][j]-what);
	}
	
	output(result);
}


int main(){
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		process_test();
	}
}

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

#define INF 2000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int TC;

int main(){
	scanf("%d", &TC);
	for(int Tn = 1; Tn <= TC; Tn++){
		printf("Case #%d: ", Tn);
		
		int N;
		int num = 0;
		vii P;

		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			int a;
			scanf("%d", &a);
			num+=a;
			P.push_back(make_pair(a, i));
		}

		sort(P.begin(),P.end());
		reverse(P.begin(), P.end());
		int evacuated = 0;

		while(evacuated < num){
			if(P[1].first <= (num - evacuated - 2)/2){
				printf("%c%c ", 65 + P[0].second, 65 + P[0].second);
				evacuated+=2;
				P[0].first = P[0].first - 2;

			}else if(P[1].first <= (num - evacuated - 1)/2){
				printf("%c ", 65 + P[0].second);
				evacuated+=1;
				P[0].first = P[0].first - 1;
			}else{
				printf("%c%c ", 65 + P[0].second, 65 + P[1].second);
				evacuated += 2;
				P[0].first = P[0].first - 1;
				P[1].first = P[1].first - 1;
			}
			sort(P.begin(), P.end());
		reverse(P.begin(), P.end());
		}
		printf("\n");
	}
}
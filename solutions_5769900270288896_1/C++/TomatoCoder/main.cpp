#include<iostream>
#include<algorithm>
#include<cstdio>

#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)

using namespace std;
int cnt[1 << 18];
int R, C, N;
int compute(int i){
	int ans = 0;
	for (int r = 0; r < R; r++){
		for (int c = 0; c < C; c++){
			if (c > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - 1))))
				ans++;
			if (r > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - C))))
				ans++;
		}
	}
	return ans;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    CASET{
        cin >> R >> C >> N;
		int best = R * C * N * 100;
		for (int i = 1; i < (1 << (R * C)); i++){
			cnt[i] = cnt[i - (i & -i)] + 1;
			if (cnt[i] == N)
				best = min(best, compute(i));
		}
		if(best < 0)
          best = 0;
        cout<<"Case #"<<case_n<<": "<< best<<endl;
        case_n++;
    }
}

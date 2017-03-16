#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int T, N;
int P[50];
void solve(int testi){
    scanf("%d",&N);
    int cnt = 0;
    for(int i=0; i<N; i++){
        scanf("%d",P+i);
        cnt += P[i];
    }
    printf("Case #%d: ",testi);
    while(cnt){
        int xi = 0,yi = -1;
        for(int i=1; i<N; i++){
            if (P[i]>P[xi]){
                xi = i;
            }
        }
        for(int i=0; i<N; i++){
            if ((yi == -1 || P[i]>P[yi]) && i!=xi ){
                yi = i;
            }
        }
        if (yi>=0 && P[xi]==P[yi] && P[xi]+P[yi]==cnt){
            P[xi]--;
            P[yi]--;
            cnt-=2;
            printf("%c%c ", 'A'+xi, 'A'+yi);
        }
        else{
            P[xi]--;
            cnt--;
            printf("%c ", 'A'+xi);
        }
    }
    printf("\n");
}

int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
		freopen("d:\\src\\CppProjects\\stdout","w",stdout);
	#endif

	scanf("%d\n",&T);
    for(int i=1; i<=T; i++){
        cerr << i << endl;
        solve(i);
    }
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int main(){
    #ifndef ONLINE_JUDGE
	//	freopen("A-large .in", "r", stdin);
	//	freopen("A-large .out", "w", stdout);
    #endif
    int T, n, cas = 1;
    scanf ("%d", &T);
    while (T--){
		scanf ("%d", &n);
		priority_queue <pii> Q;
        for (int i = 0; i < n; i++){
            int x;
            scanf ("%d", &x);
            Q.push(make_pair(x, i));
        }
        printf("Case #%d:", cas++);
        while (!Q.empty()){
            if (Q.size() == 1){
                printf(" %c", Q.top().second + 'A');
                Q.pop();
            }else{
                pii a = Q.top();
                if (a.first == 1 && Q.size() == 3){
					printf(" %c", a.second + 'A');
					Q.pop();
					continue;
                }
                Q.pop();
                if (a.first > 1){
                    Q.push(make_pair(a.first-1, a.second));
                }
                pii b = Q.top();
                Q.pop();
				if (b.first > 1){
                    Q.push(make_pair(b.first-1, b.second));
                }
                printf(" %c%c", a.second+'A', b.second+'A');
            }
        }
		printf("\n");
    }
    return 0;
}

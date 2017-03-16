#include <cstdio>
#include <algorithm>

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int main(){
    int T;
    scanf("%d", &T);
    
    for(int i=0;i<T;i++){
        int R, C, N;
        scanf("%d %d %d", &R, &C, &N);

        int minScore = 252521, state;
        for(int j=0;j<1<<(R*C);j++){
            if(__builtin_popcount(j) != N){continue;}
            
            int score = 0;
            bool used[100][100];
            std::fill(&used[0][0], &used[0][0]+100*100, false);
            for(int k=0;k<R;k++){
                for(int l=0;l<C;l++){
                    if(!(j >> (k*C + l) & 1)){continue;}
                    
                    for(int m=0;m<4;m++){
                        int nr = k + dy[m],
                            nc = l + dx[m];

                        if(nr < 0 || nr >= R || nc < 0 || nc >= C){continue;}
                        // printf("%d, %d, %d, %d, %d\n", k, l, nr, nc, (j >> (nr*C + nc) & 1));
                        if(!(j >> (nr*C + nc) & 1)){
                            continue;
                        }

                        if(m < 2 && !used[k*2+1][l+(m==1)]){
                            // printf("%d, %d, %d, %d, %d\n", k, l, nr, nc, m);
                            score += 1;
                            used[k*2+1][l+(m==1)] = true;
                        }
                        if(m >= 2 && !used[(k+(m==3))*2][l]){
                            // printf("%d, %d, %d, %d, %d\n", k, l, nr, nc, m);
                            score += 1;
                            used[(k+(m==3))*2][l] = true;
                        }
                    }
                }
            }

            // if(minScore > score){state = j;}
            minScore = std::min(minScore, score);
        }

        printf("Case #%d: %d\n", i+1, minScore);
    }
}

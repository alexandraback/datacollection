#include <bits/stdc++.h>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
priority_queue<pair<pair<int, int>, pair<int, int> > > Q;
int R, C, N, t;

int main() {
    srand(time(0));
    scanf("%d", &t);
    for(int test = 1; test <= t; test++) {
        while(!Q.empty()) Q.pop();
        printf("Case #%d: ", test);
        scanf("%d %d %d", &R, &C, &N);
        int tab[R + 5][C + 5];
        int zrob[R + 5][C + 5];
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {
                tab[i][j] = 0;
                zrob[i][j] = 0;
//                 for(int k = 0; k < 4; k++) {
//                     int xx = i + dx[k];
//                     int yy = j + dy[k];
//                     if(xx >= 1 && xx <= R && yy >= 1 && yy <= C) {
//                         tab[i][j]++;
//                     }
//                 }
                Q.push({{-tab[i][j], 0}, {i, j}});
            }
        }
        int toFree = N;
        while(!Q.empty() && toFree > 0) {
            int x = Q.top().second.first;
            int y = Q.top().second.second;
            int h = -Q.top().first.first;
            Q.pop();
            if(zrob[x][y] || tab[x][y] != h) {
                continue;
            }
            toFree--;
            zrob[x][y] = true;
            for(int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx >= 1 && xx <= R && yy >= 1 && yy <= C && zrob[xx][yy] == 0) {
                    tab[xx][yy]++;
                    Q.push({{-tab[xx][yy], 0}, {xx, yy}});                    
                }
            }
        }
        int wynik = 0;
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {
                if(zrob[i][j] == 0) continue;
                if(j + 1 <= C && zrob[i][j + 1] == 1) wynik++;
                if(i + 1 <= R && zrob[i + 1][j] == 1) wynik++;
            }
        }
        while(!Q.empty()) Q.pop();
        
        
        
        
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {
                tab[i][j] = 0;
                zrob[i][j] = 0;
                for(int k = 0; k < 4; k++) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if(xx >= 1 && xx <= R && yy >= 1 && yy <= C) {
                        tab[i][j]++;
                    }
                }
                Q.push({{tab[i][j], 0}, {i, j}});
            }
        }
    
        toFree = R * C - N;
        while(!Q.empty() && toFree > 0) {
            int x = Q.top().second.first;
            int y = Q.top().second.second;
            int h = Q.top().first.first;
            Q.pop();
            if(zrob[x][y] || tab[x][y] != h) {
                continue;
            }
            toFree--;
            zrob[x][y] = true;
            for(int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx >= 1 && xx <= R && yy >= 1 && yy <= C && zrob[xx][yy] == 0) {
                    tab[xx][yy]--;
                    Q.push({{tab[xx][yy], 0}, {xx, yy}});                    
                }
            }
        }
        int wynik2 = 0;
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {
                if(zrob[i][j] == 1) continue;
                if(j + 1 <= C && zrob[i][j + 1] == 0) wynik2++;
                if(i + 1 <= R && zrob[i + 1][j] == 0) wynik2++;
            }
        }
        
        
        
        
        printf("%d\n", min(wynik, wynik2));
        
        
        
        
        
        
        
        
        
        
        
        
    }
    return 0;
}
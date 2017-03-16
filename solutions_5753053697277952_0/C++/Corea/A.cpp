#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int T;
    scanf( "%d", &T );
    for (int test = 1; test <= T; test ++) {
        int N;
        vector< pair<int, int> > data;
        
        scanf( "%d", &N );
        for (int i = 0; i < N; i ++) {
            int a;
            scanf( "%d", &a );
            data.emplace_back(a, i);
        }

        sort(data.begin(), data.end());

        printf( "Case #%d: ", test );
        for (int i = data[N-2].first; i < data[N-1].first; i ++) {
            printf( "%c ", 'A' + data[N-1].second);
        }

        for (int i = 0; i < N - 2; i ++) {
            for (int j = 0; j < data[i].first; j ++) {
                printf( "%c ", 'A' + data[i].second);
            }
        }
        for (int i = 0; i < data[N-2].first; i ++) {
            printf( "%c%c ", 'A' + data[N-1].second, 'A' + data[N-2].second);
        }
        printf( "\n" );
    }

    return 0;
}

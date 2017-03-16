#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int m[1002];

int max(int a, int b){
    return a > b ? a : b;
}

int main(int argc, char *argv[]){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int N;
        cin >> N;
        for(int j = 0; j < N; j++)
            cin >> m[j];

        int case1 = 0, case2 = 0;
        int maxDelta = 0;
        for(int j = 0; j < N-1; j++){
            int delta = m[j] - m[j+1];
            if(delta > 0)
                case1 += delta;
            if(delta > maxDelta)
                maxDelta = delta;
        }
        for(int j = 0; j < N-1; j++){
            int after = max(m[j] - maxDelta, 0);
            if(m[j+1] > after)
                case2 += (m[j+1] - after);
        }
        case2 += (m[0] - m[N-1]);
        cout << "Case #" << i+1 << ": " << case1 << " " << case2 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

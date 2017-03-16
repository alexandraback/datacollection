#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int m[1002];

int main(int argc, char *argv[]){
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int B, N;
        int maxB = 0;
        cin >> B >> N;
        for(int j = 0; j < B; j++){
            cin >> m[j];
            if(m[j] > maxB)
                maxB = m[j];
        }

        long long maxTime = (long long)maxB * N;
        long long left = 0, right = maxTime, mid;
        while(left < right){
            mid = (left + right) / 2;
            long long guests = 0;
            for(int j = 0; j < B; j++){
                guests += (mid / m[j]);
                if(mid % m[j] != 0)
                    guests++;
            }
            if(guests < N)
                left = mid + 1;
            else
                right = mid;
        }

        long long now = 0;
        long long time = left - 1;
        for(int j = 0; j < B; j++){
            now += (time / m[j]);
            if(time % m[j] != 0)
                now++;
        }

        int cutter;
        for(int j = 0; j < B; j++){
            if(time % m[j] == 0)
                now++;
            if(now == N){
                cutter = j;
                break;
            }
        }

        cout << "Case #" << i+1 << ": " << cutter+1 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <climits>
#include <set>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;
typedef std::pair<double, double> pdd;

#define PI 3.1415926535897932384626433
#define INF ((1<<30)-1)*2+1
#define mp(a, b) make_pair((a), (b))
#define pb push_back
#define MOD 1000000007
#define MAX_N 26
using namespace std;

void solve(int n, int arr[MAX_N]){
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    while(sum > 0){
        int changed = 0;
        for(int i = 0; i < n; i++){
            if(sum == 0)
                break;
            if((double)arr[i]/sum >= 0.5 && arr[i] > 0 && changed < 1){
                arr[i]--;
                cout << (char)(i+'A');
                sum--;
                changed++;
                if(sum == 0)
                    break;
                for(int j = 0; j < n; j++){
                    if(arr[j] > 0 && (double)arr[j]/sum >= 0.5){
                        arr[j]--;
                        cout << (char)(j+'A');
                        sum--;
                        changed++;
                        break;
                    }
                }
            }
        }

        if(changed == 0){
            int mx = 100000, mxInd;
            for(int i = 0; i < n; i++){
                if(arr[i] > mx){
                    mx = arr[i];
                    mxInd = i;
                }
            }
            arr[mxInd]--;
            sum--;
            cout << (char)(mxInd+'A');
        }

        /*if(changed < 2){
            for(int i = 0; i < n; i++){
                if(arr[i] >= mx && arr[i] > 0 && changed < 1){
                    arr[i]--;
                    cout << (char)(i+'A');
                    sum--;
                    mx = (double)sum/n;
                    changed++;
                }
            }
        }*/
        cout << " ";
    }
}

int main()
{
    freopen("../A-large.in","r",stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N, a[MAX_N];
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> a[i];
        cout << "Case #" << t << ": ";
        solve(N, a);
        cout << endl;
    }
    return 0;
}

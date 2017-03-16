#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int n; scanf("%d", &n);
        int arr[1000];
        int c1 = 0, c2 = 0;
        for(int lx = 0;lx < n;lx++)
            scanf("%d", arr+lx);

        //case1

        for(int lx = 1;lx < n;lx++)
            c1 += max(0, arr[lx-1]-arr[lx]);

        //case2

        int det = 0;
        for(int lx = 1;lx < n;lx++)
            det = max(det, arr[lx-1] - arr[lx]);

        for(int lx = 1;lx < n;lx++){
            if(arr[lx-1] - det >= 0) c2 += det;
            else c2 += arr[lx-1];
        }

        printf("Case #%d: %d %d\n", lt, c1, c2);
    }
    return 0;
}


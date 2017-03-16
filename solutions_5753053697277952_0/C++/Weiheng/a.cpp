#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int maxnum(int num[], int n) {
    int max = -1;
    int ind = -1;
    int i;
    for (i=0; i<n; i++) {
        if (num[i] > max) {
            max = num[i];
            ind = i;
        }
    }
    return ind;
}

int no(int num[], int n, int sum) {
    int i;
    for (i=0; i<n; i++) {
        if (num[i] > sum)
            return 1;
    }
    return 0;
}

int main() {
    int t, n ;
    int ca = 1;
    int num[30];
    int i, j, sum;
    scanf("%d", &t);
    while (ca <= t) {
        scanf("%d", &n);
        sum = 0;
        for (i=0; i<n; i++) {
            scanf("%d", &num[i]);
            sum += num[i];
        }
        cout<<"Case #"<<ca<<":";
        while (1) {
            int k = maxnum(num, n);
            num[k]--;
            sum--;
            cout<<" "<<char(k+'A');
            if (sum == 0) break;
            k = maxnum(num, n);
            num[k]--;
            if (no(num, n, (sum-1)/2)) {
                num[k]++;
            } else {
                cout<<char(k+'A');
                sum--;
            }
            if (sum == 0) break;
        }
        cout<<endl;
        ca++;
    }
    return 0;
}


#include<stdio.h>
int arr[1000];
int st[1000];
int b;

int gcd(int a, int b)
{
    int t;
    while (b) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    return (a*b)/gcd(a,b);
}

int find(int n) {
    int i, j;

    if(n == 0) {
        for(i=b-1;i>=0;i--) {
            if(arr[i] == 1) {
                return i+1;
            }
        }
        return b;
    }

    while(1) {
        for(i=0;i<b;i++) {
            if(!st[i]) {
                st[i] = arr[i];
                n--;
                if(!n)goto end;
            }
        }

        j = st[0];
        for(i=1;i<b;i++) {
            if(st[i] < j) j = st[i];
        }
        for(i=0;i<b;i++) {
            st[i]-=j;
        }
    }
end:
    return i+1;
}

int main() {
    int cases, n, i, j, p = 1, L, rate;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d %d", &b, &n);

        for(i=0;i<b;i++) {
            scanf("%d", &arr[i]);
            st[i] = 0;
        }

        //printf("brute->%d\n", find(n));
        //for(i=0;i<b;i++)st[i]=0;

        L = arr[0];
        for(i=1;i<b;i++) {
            L = lcm(L, arr[i]);
        }

        //printf("LCM+>%d\n", L);
        rate = 0;
        for(i=0;i<b;i++) {
            rate += L/arr[i];
        }

        //printf("RATE->%d\n", rate);

        //n = n - ((n/rate) * rate);
        n = n % rate;

        //printf("n becomes->%d\n", n);

        printf("Case #%d: %d\n", p++, find(n));

    }
}

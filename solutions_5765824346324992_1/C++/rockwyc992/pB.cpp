#include <stdio.h>

int T;
int n;
int b;
int num[1100];

int test(long long x)
{
    x++;
    long long now = n;
    for (int i = 0; i < b; i++) {
        now -= x / num[i];
        if (x % num[i]) {
            now --;
        }
    }

    if (now <= 0) {
        return 1;
    }

    return 0;
}

long long bs() 
{
    long long min = 0;
    long long max = 100000;
    max *= 100000;
    max *= 10000;

    while (min < max) {
        long long mid = min + max;
        mid /= 2;
        if (test(mid)) {
            max = mid;
        } else {
            min = mid+1;
        }
    }

    return min;
}

long long align(long long x) {
    int min = 101000;
    for (int i = 0; i < b; i++) {
        if ((x % num[i]) == 0) {
            return x;
        }
        int temp = x % num[i];
        if (num[i] - temp < min) {
            min = num[i] - temp;
        }
    }
    return x + min;
}

int ans()
{
    long long time = bs();
    //time = align(time);

    for (int i = 0; i < b; i++) {
        if ((time % num[i]) == 0) {
            n -= time / num[i];
        } else {
            n -= time / num[i];
            n--;
        }
    }
    for (int i = 0; i < b; i++) {
        if ((time % num[i]) == 0) {
            n--;
            if (n == 0) {
                return i+1;
            }
        }
    }
    for (int i = 0; i < b; i++) {
        if ((time % num[i]) == 0) {
            return i+1;
        }
    }
    return 1;
}

int main()
{
    scanf("%d", &T);
    for (int z = 1; z <= T; z++) {
        scanf("%d%d", &b, &n);
        for (int i = 0; i < b; i++) {
            scanf("%d", num + i);
        }
        printf("Case #%d: %d\n", z, ans());
    }
    return 0;
}

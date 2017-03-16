#include <cstdio>

int arr[20];

int main() {
    int t;
    scanf("%d", &t);
    for(int _i=1; _i<=t; _i++) {
        for(int i=0; i<20; i++) arr[i]=0;
        int r; scanf("%d", &r);
        for(int i=0; i<16; i++) {
            int x; scanf("%d", &x);
            if(i/4 == r-1) arr[x] = 1;
        }
        scanf("%d", &r);
        for(int i=0; i<16; i++) {
            int x; scanf("%d", &x);
            if(i/4 == r-1 and arr[x] == 1) arr[x] = 2;
        }
        r=0;
        for(int i=0; i<20; i++) {
            if(arr[i] == 2) {
                if(r == 0) {
                    r = i;
                } else {
                    r = -1;
                }
            }
        }
        printf("Case #%d: ", _i);
        if(r == 0) {
            printf("Volunteer cheated!\n");
        } else if(r == -1) {
            printf("Bad magician!\n");
        } else {
            printf("%d\n", r);
        }
    }
}
            

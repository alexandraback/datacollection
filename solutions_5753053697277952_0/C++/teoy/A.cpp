#include "iostream"
#include "cstring"
#include "cstdio"
#include "algorithm"
using namespace std;
struct T
{
    int x, y;
}a[30];
bool cmp(T a, T b)
{
    return a.y > b.y;
}
int main(void)
{
    int T;
    scanf("%d", &T);
    int g = 0, n;
    while(T--){
        printf("Case #%d:", ++g);
        scanf("%d", &n);
        int sum = 0;
        for(int i = 0; i < n; ++ i){
            scanf("%d", &a[i].y);
            a[i].x = i;
            sum += a[i].y;
        }
        while(true){
            sort(a, a + n, cmp);
            if (a[0].y * 2 > sum) {
                return 0;
            }
            if (a[0].y == 0) break;

            if (sum % 2 == 1){
                printf(" %c", 'A' + a[0].x);
                a[0].y --;
                sum -= 1;
            }else if (a[0].y >= a[1].y + 2 || a[1].y == 0){
                printf(" %c%c",'A' + a[0].x, 'A' + a[0].x);
                a[0].y -= 2;
            }else{
                printf(" %c%c", 'A' + a[0].x, 'A' + a[1].x);
                a[0].y --;
                a[1].y --;
            }
        }    
        printf("\n");
    }
    return 0;
}
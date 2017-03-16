#include <cstdio>
#include <algorithm>

using namespace std;

int data[1010];
int main() {
    int tt;
    scanf("%d", &tt);
    for(int t=0 ; t<tt ; t++) {
        int n;
        scanf("%d", &n);
        for(int i=0 ; i<n ; i++) {
            scanf("%d", &data[i]);
        }
        int first_method = 0;
        int second_method = 0;
        for(int i=1 ; i<n ; i++) {
            if(data[i] < data[i-1]) {
                int delta = data[i-1] - data[i];
                first_method += delta;

                if(delta > second_method) {
                    second_method = delta;
                }
            }
        }

        int ans_second = 0;
        for(int i=0 ; i<n-1 ; i++) {
            if(data[i] < second_method) {
                ans_second += data[i];
            }
            else ans_second += second_method;
        }
        printf("Case #%d: %d %d\n", t+1, first_method, ans_second);
    }
}

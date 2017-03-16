#include <cstdio>
#include <bitset>
using namespace std;

int T, x;
bitset<17> v1, v2, v;

void ReadRow(bitset<17>& v);

int main()
{
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);

    scanf("%d", &T);
    for (int i=0; i<T; ++i){
        printf("Case #%d: ", i+1);
        ReadRow(v1);
        ReadRow(v2);
        v = v1&v2;
        switch (v.count()){
            case 0:
                puts("Volunteer cheated!");
                break;
            case 1:
                x = 1;
                while (!v[x])
                    ++x;
                printf("%d\n", x);
                break;
            default:
                puts("Bad magician!");
        }
    }
    return 0;
}

void ReadRow(bitset<17>& v){
    int r, x;

    v.reset();
    scanf("%d", &r);
    for (int i=1; i<r; ++i){
        for (int j=0; j<4; ++j)
            scanf("%*d");
    }
    for (int j=0; j<4; ++j){
        scanf("%d", &x);
        v[x] = 1;
    }
    for (int i=r+1; i<=4; ++i){
        for (int j=0; j<4; ++j)
            scanf("%*d");
    }
}

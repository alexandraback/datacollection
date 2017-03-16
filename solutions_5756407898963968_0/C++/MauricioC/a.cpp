#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++) {
        int masks[2] = {0, 0};

        for(int i = 0; i < 2; i++) {
            int row;
            scanf("%d", &row);

            for(int j = 0; j < 4; j++)
                for(int k = 0; k < 4; k++) {
                    int tmp;
                    scanf("%d", &tmp);

                    if(j+1 == row)
                        masks[i] |= (1<<tmp);
                }
        }

        int mask = masks[0] & masks[1];

        printf("Case #%d: ", z);
        if(mask == 0)
            printf("Volunteer cheated!\n");
        else if((mask & (mask-1)) == 0)
            printf("%d\n", 31 - __builtin_clz(mask));
        else
            printf("Bad magician!\n");
    }
}

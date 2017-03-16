#include <stdio.h>
#include <string.h>

int list[20];

void update() {
    int row;
    int i, j;
    int t;
    scanf("%d", &row);
    for (i = 1; i <= 4; ++i) {
        for (j = 1; j <= 4; ++j) {
            scanf("%d", &t);
            if (i == row) 
                list[t]++;
        }
    }
}

void run() {
    memset(list, 0, sizeof(list));
    update();
    update();
    int ans = 0;
    for (int i = 1; i <= 16; ++i) {
        if (list[i] == 2) {
            if (ans == 0)
                ans = i;
            else 
                ans = -1;
        }
    }
    if (ans == 0)
        puts("Volunteer cheated!");
    else if (ans == -1)
        puts("Bad magician!");
    else
        printf("%d\n", ans);
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    for (int t = 1; t <= num_cases; ++t) {
        printf("Case #%d: ", t);
        run();
    }
    return 0;
}

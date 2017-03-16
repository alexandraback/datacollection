#include <cstdio>

bool ok[17];

void question()
{
    int answer;
    scanf("%d", &answer);
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            int tmp;
            scanf("%d", &tmp);
            if (i != answer)
                ok[tmp] = false;
        }
    }
}

int testCase()
{
    for (int i = 1; i <= 16; ++i)
        ok[i] = true;
    question();
    question();
    int result = 0;
    for (int i = 1; i <= 16; ++i) {
        if (ok[i]) {
            if (result != 0)
                result = -1;
            else
                result = i;
        }
    }
    return result;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        int q = testCase();
        printf("Case #%d: ", i);
        if (q == -1)
            printf("Bad magician!\n");
        else if (q == 0)
            printf("Volunteer cheated!\n");
        else
            printf("%d\n", q);
    }
}
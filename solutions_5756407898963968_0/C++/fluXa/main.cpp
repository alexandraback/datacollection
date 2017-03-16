#include <cstdio>

using namespace std;


int main(int argc, const char * argv[])
{
    int numCases = 0;
    scanf("%d\n", &numCases);
    int row1, row2, d;
    int a[4], b[4];

    for (int count = 1; count <= numCases; ++count) {
        scanf("%d\n", &row1);
        for (int j = 1; j <= 4; ++j) {
            if (j == row1) {
                scanf("%d %d %d %d\n", &a[0], &a[1], &a[2], &a[3]);
            } else {
                scanf("%d %d %d %d\n", &d, &d, &d, &d);
            }
        }
        
        scanf("%d\n", &row2);
        for (int j = 1; j <= 4; ++j) {
            if (j == row2) {
                scanf("%d %d %d %d\n", &b[0], &b[1], &b[2], &b[3]);
            } else {
                scanf("%d %d %d %d\n", &d, &d, &d, &d);
            }
        }
        
        printf("Case #%d: ", count);
        
        int numMatches = 0;
        int match = 0;
        for (int j = 0; j < 4; ++j) {
             for (int k = 0; k < 4; ++k) {
                 if (a[j] == b[k]) {
                    numMatches++;
                     match = a[j];
                }
            }
        }
        
        if (numMatches == 1) {
            printf("%d\n", match);
        } else if (numMatches == 0) {
            printf("Volunteer cheated!\n");
        } else {
            printf("Bad magician!\n");
        }
    }
    return 0;
}


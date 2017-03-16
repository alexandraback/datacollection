#include <stdio.h>

int main(int argc, char *argv[])
{
    int t, t_index;
    FILE *ifp, *ofp;

    ifp = fopen("in.txt", "r");
    ofp = fopen("out.txt", "w");

    fscanf(ifp, "%d", &t);
    for (t_index = 1; t_index <= t; t_index++)
    {
        fprintf(ofp, "Case #%d: ", t_index);

        // Turn START
        int n, b[1001], i, j, q, min;
        int b2[1001];
        int sum, sum2;
        fscanf(ifp, "%d %d", &n, &q);

        sum = 0;
        for (i = 0; i < n; i++)
        {
            fscanf(ifp, "%d", &(b[i]));
            b2[i] = b[i];
            sum += b[i];
        }
        if (q > n) {
            sum2 = sum;
            for (i = 0; i < q - n; i++)
            {
                min = b2[0];
                for (j = 1; j < n; j++)
                {
                    if (min == 0)
                        break;

                    if (min > b2[j]) {
                        min = b2[j];
                    }
                }

                if (min > 0) {
                    for (j = 0; j < n; j++)
                    {
                        b2[j] -= min;
                    }
                    sum2 -= n * min;
                }

                for (j = 0; j < n; ++j)
                {
                    if (b2[j] == 0)
                    {
                        b2[j] = b[j];
                        break;
                    }
                }

                sum2 += b[j];
                if (sum == sum2) {
                    q = (q - n) % (i + 1) + n;
                    i = -1;
                }
            }
            fprintf(ofp, "%d\n", j + 1);
        } else {
            fprintf(ofp, "%d\n", q);
        }

        // Turn END
    }
    fclose(ofp);
    fclose(ifp);
	return 0;
}

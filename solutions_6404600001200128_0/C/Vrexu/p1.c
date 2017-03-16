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
        int n, m[1001], i;
        int sum = 0, max_diff, diff;
        fscanf(ifp, "%d", &n);

        for (i = 0; i < n; i++)
        {
            fscanf(ifp, "%d", &(m[i]));
        }

        max_diff = 0;

        for (i = 1; i < n; i++)
        {
            diff = m[i - 1] - m[i];
            if (diff > 0) {
                sum += diff;
                if (diff > max_diff)
                {
                    max_diff = diff;
                }
            }
        }
        
        int sum2 = 0;

        for (i = 0; i < n - 1; i++)
        {
            sum2 += (max_diff < m[i] ? max_diff : m[i]);
        }

        fprintf(ofp, "%d %d\n", sum, sum2);
        // Turn END
    }
    fclose(ofp);
    fclose(ifp);
	return 0;
}

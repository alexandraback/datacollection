#include<cstdio>
int main()
{
    int t, n;
    int m[1010];
    FILE *in, *out;
    in = fopen("A-large.in", "r");
    out = fopen("A.out", "w");
    fscanf(in, "%d", &t);
    for(int i = 1; i <= t; i++)
    {
        int diff, ans1 = 0, ans2 = 0, max = 0;
        fscanf(in, "%d", &n);
        for(int j = 0; j < n; j++)
        {
            fscanf(in, "%d", &m[j]);
            if(j > 0 && (diff = m[j - 1] - m[j]) > 0)
            {
                ans1 += diff;
                if(diff > max) max = diff;
            }
        }
        for(int j = 1; j < n; j++)
        {
            if(m[j - 1] < max) ans2 += m[j - 1];
            else ans2 += max;
        }
        fprintf(out, "Case #%d: %d %d\n", i, ans1, ans2);
    }
    fclose(in);
    fclose(out);
    return 0;
}

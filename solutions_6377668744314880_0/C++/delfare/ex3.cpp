#include <stdio.h>
#include <vector>

int main()
{
    int num;
    scanf("%d\n", &num);
    for(int i = 0; i < num; i++)
    {
        long N;
        scanf("%ld\n", &N);
        std::vector<int> x(N), y(N);
        for(int j = 0; j < N; j++)
            scanf("%d %d", &x[j], &y[j]);
        printf("Case #%d:\n", i+1);
        for(int j = 0; j < N; j++)
        {
            int minVal = 2*N;
            for(int k = 0; k < N; k++)
            {
		if(k == j)
		    continue;
                float a,b,c;
                if(x[j]==x[k])
                {
                    a = 1;
                    b = 0;
                }
                else
                {
                    a = (y[k]-y[j])/(x[j]-x[k]);
                    b = 1;
                }
		c = -(a*x[j]+b*y[j]);
                int count1 = 0, count2 = 0;
                for(int l = 0; l < N; l++)
                {
                    if(l != k && l != j)
                    {
                        if(a*x[l]+b*y[l]+c < 0)
                            count1++;
                        else if(a*x[l]+b*y[l]+c > 0)
                            count2++;
                    }
                }
                minVal = std::min(minVal, std::min(count1, count2));
            }
            printf("%d\n", minVal);
        }
    }
    return 0;
}

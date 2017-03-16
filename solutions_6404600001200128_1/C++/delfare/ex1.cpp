#include <stdio.h>
#include <vector>

int main()
{
    int num;
    char line[1024];
    scanf("%d\n", &num);
    for(int i = 0; i < num; i++)
    {
	int N;
        scanf("%d\n", &N);
	std::vector<int> tab(N);
	for(int j = 0; j < N; j++)
	    scanf("%d", &tab[j]);
	int count1 = 0, count2 = 0, maxEat = 0;
	for(int j = 1; j < N; j++)
	    if(tab[j] < tab[j-1])
	    {
		count1 += tab[j-1]-tab[j];
		maxEat = std::max(maxEat, tab[j-1]-tab[j]);
	    }
	for(int j = 1; j < N; j++)
	{
	    count2 += std::min(tab[j-1], maxEat);
	}
        printf("Case #%d: %d %d\n", i+1, count1, count2);
    }
    return 0;
}

#include <stdio.h>
#include <vector>

long capacity(const std::vector<long>& M, long t)
{
    if(t < 0)
	return 0;
    long count = M.size();
    for(int i = 0; i < M.size(); i++)
	count += t/M[i];
    return count;
}

long findTime(const std::vector<long>& M, long N)
{
    long minT = 0;
    long maxT = 200000000000000;
    while(maxT > minT)
    {
	long midT = (minT+maxT)/2;
	long c = capacity(M, midT);
	if(c < N)
	    minT = midT+1;
	else maxT = midT;
    }
    return minT;
}

long findId(const std::vector<long>& M, long t, long N)
{
    N -= capacity(M, t-1);
    for(int i = 0; i < M.size(); i++)
    {
	if(t % M[i] == 0)
	{
	    N--;
	    if(N == 0)
		return i;
	}
    }
    return -1;
}

int main()
{
    int num;
    scanf("%d\n", &num);
    for(int i = 0; i < num; i++)
    {
	long B, N;
        scanf("%ld %ld\n", &B, &N);
	std::vector<long> M(B);
	for(int j = 0; j < B; j++)
	    scanf("%ld", &M[j]);
	long t = findTime(M, N);
        printf("Case #%d: %ld\n", i+1, findId(M, t, N)+1);
    }
    return 0;
}

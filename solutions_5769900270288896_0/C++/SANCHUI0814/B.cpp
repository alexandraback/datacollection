#include<cstdio>
#include<algorithm>

using namespace std;

// R >= C
int compute(int R, int C, int N)
{
    int quiet = (R*C+1)/2;

    if(N <= quiet)
        return 0;

    int noisy = (R-1)*C + (C-1)*R;
    if(R*C - N <= ((R-2)*(C-2)+1)/2)
        return noisy - (R*C - N)*4;

    N -= quiet;

    if(C == 1)
    {
        if(N == 1)
            return 1;
        else
            return 2*(N-1)+1;
    }

    if(R*C % 2 != 0)
    {
        int r = (R-1)/2*2;
        int c = (C-1)/2*2;

        if(N <= r+c)
            return N*3;

        int res = (r+c)*3;

        N -= r+c;

        return res + N*4;
    }
    else
    {
        if(N <= 2)
            return N*2;

        int res = 4;

        N -= 2;
        if(N <= R+C - 4)
            return res + N*3;

        N -= R+C - 4;

        res += (R+C-4)*3;

        return res + N*4;

    }
}

int main(int argc, char* argv[])
{
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        int R, C, N;
        scanf("%d %d %d", &R, &C, &N); 

        if(R < C)
            swap(R, C); 

        int ret = compute(R, C, N);

        printf("Case #%d: %d\n", i+1, ret);
    }

    return 0;
}


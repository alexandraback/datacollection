#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MaxN = 110;
const int InfMin = 10000;


// convert A to B
int minopt(char* A, char* B)
{
    int lenA = strlen(A);
    int lenB = strlen(B);

    static int f[MaxN][MaxN];
    memset(f, 0x6f, sizeof(f));

    for(int i=0; i<lenA; i++)
    {
        for(int j=0; j<lenB; j++)
        {
            if(i == 0 && j == 0)
                f[0][0] = 0;
            else
            {
                if(i > 0 && j > 0 && A[i] == B[j])
                    f[i][j] = min(f[i][j], f[i-1][j-1]);
                if(j > 0 && A[i] == B[j]) // copy
                    f[i][j] = min(f[i][j], f[i][j-1] + 1);
                if(i > 0 && A[i] == B[j] && A[i] == A[i-1]) // del
                    f[i][j] = min(f[i][j], f[i-1][j] + 1);
            }
        }
    }

    return f[lenA-1][lenB-1];
}

char words[MaxN][MaxN];

int main()
{
    int T;
    cin >> T;

    for(int c=0; c<T; c++)
    {
        int N;
        cin >> N;
        
        for(int i=0; i<N; i++)
        {
            words[i][0] = '>';
            cin >> (words[i]+1);
        }

        bool orz = false;
        int minsum = InfMin;
        for(int i=0; i<N; i++)
        {
            int sum = 0;
            for(int j=0; j<N; j++)
            {
                if(i != j)
                {
                    int opt = minopt(words[j], words[i]);
                    //printf("str%d->str%d: %d\n", i, j, opt);
                    if(opt > InfMin)
                    {
                        orz = true;
                        break;
                    }

                    sum += opt;
                }
            }

            if(orz) break;
            minsum = min(minsum, sum);
        }
        
        int result = minsum;
        if(result < InfMin)
            printf("Case #%d: %d\n", c+1, result);
        else
            printf("Case #%d: Fegla Won\n", c+1);
    }

    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MaxN = 110;
const int InfMin = 10000;

char words[MaxN][MaxN];
int nxt[MaxN], dlen[MaxN], cur[MaxN];

int main()
{
    int T;
    cin >> T;

    for(int c=0; c<T; c++)
    {
        int N;
        cin >> N;
        
        for(int i=0; i<N; i++)
            cin >> words[i];

        memset(cur, 0, sizeof(cur));

        bool bad = false;
        int result = 0;
        while(true)
        {
            char ch = words[0][cur[0]];
            for(int i=0; i<N; i++)
            {
                if(words[i][cur[i]] != ch)
                {
                    bad = true;
                    break;
                }

                int j = cur[i];
                while(words[i][j+1] == words[i][j]) j++;
                nxt[i] = j + 1;
                dlen[i] = j - cur[i] + 1;
            }
            if(bad) break;
            if(ch == '\0') break;

            sort(dlen, dlen+N);

            int mid = dlen[N/2];
            int sum = 0;
            for(int i=0; i<N; i++)
                if(dlen[i] < mid)
                    sum += mid - dlen[i];
                else
                    sum += dlen[i] - mid;

            result += sum;

            for(int i=0; i<N; i++)
                cur[i] = nxt[i];
        }

        if(!bad)
            printf("Case #%d: %d\n", c+1, result);
        else
            printf("Case #%d: Fegla Won\n", c+1);
    }

    return 0;
}

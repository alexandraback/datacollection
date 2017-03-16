#include <bits/stdc++.h>
using namespace std;

int A[27];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("output3.txt", "w", stdout);

    int T;
    cin >> T;

    for(int test=1; test<=T; test++)
    {
        int N;
        cin >> N;

        for(int i=1; i<=N; i++)
            cin >> A[i];

        printf("Case #%d: ", test);

        while(1)
        {
            int k = 0, ans1 = -1, ans2 = -1, flag = 0;

            for(int i=1; i<=N; i++)
            {
                if(A[i]>k)
                {
                    k = A[i];
                    ans1 = i;
                    ans2 = -1;
                }
                else if(A[i]==k)
                {
                    if(ans2==-1)
                        ans2 = i;
                    else
                        flag = 1;
                }
            }

            if(ans1==-1)
                break;

            if(ans2==-1 || (ans2!=-1 && flag==1))
            {
                A[ans1]--;
                printf("%c ", (char)'A'+ans1-1);
            }
            else
            {
                A[ans1]--, A[ans2]--;
                printf("%c%c ", (char)'A'+ans1-1, 'A'+ans2-1);
            }
        }

        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

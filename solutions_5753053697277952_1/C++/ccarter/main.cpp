#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    for (int t=1;t<=tt;t++)
    {
        int n;
        cin >> n;
        int arr[26],m=0,s=0,mi=0;
        for (int i=0;i<n;i++)
        {
            cin >>arr[i];
            if (arr[i] > m) {
                m = arr[i];
                mi = i;
            }
            s+=arr[i];
        }
        printf("Case #%d:",t);
        if (s%2)
        {
            printf(" %c",mi+'A');
            arr[mi]--;
            s--;
        }


        while (s>0) {
            int m1=-1,m2=-1,mi1,mi2;
            for (int i=0;i<n;i++)
            {
                if (arr[i] > m1)
                {
                    m1 = arr[i];
                    mi1 = i;
                }
            }
            arr[mi1]--;
            for (int i=0; i<n; i++)
            {
                if (arr[i] > m2)
                {
                    m2=arr[i];
                    mi2=i;
                }
            }
            arr[mi2]--;
            printf(" %c%c",mi1+'A',mi2+'A');
            s-=2;
        }
        printf("\n");
    }
    return 0;
}

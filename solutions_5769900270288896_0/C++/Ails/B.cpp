#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(void)
{
    int ca,cases;
    int i,j,k;
    int r,c,n;
    int four,three,two;
    int ans;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("Bs.txt","w",stdout);
    scanf("%d",&cases);
    for (ca=1;ca<=cases;ca++)
    {
        scanf("%d%d%d",&r,&c,&n);
        printf("Case #%d: ",ca);
        if (r*c/2+r*c%2>=n)
            printf("%d\n",0);
        else
        {
            i=r*c-n;
            four=((r-1)/2)*((c-1)/2)+((r-2)/2)*((c-2)/2);
            if (r==1||c==1)
                three=0;
            else
            if (r==2)
                three=(c-2)/2+(c-1)/2;
            else
            if (c==2)
                three=(r-2)/2+(r-1)/2;
            else
                three=(c-2)/2+(c-r%2-1)/2+(r-2)/2+(r-c%2-1)/2;
            if (r==1)
                two=(c+1)/2;
            else
            if (c==1)
                two=(r+1)/2;
            else
                two=1+r%2+c%2+(r+c+1)%2;
           // printf("%d %d %d\n",four,three,two);
            j=(c-1)*r+(r-1)*c;
            if (i>four)
            {
                j-=four*4;
                i=i-four;
            }
            else
            {
                j-=i*4;
                i=0;
            }

            if (i>three)
            {
                j-=three*3;
                i=i-three;
            }
            else
            {
                j-=i*3;
                i=0;
            }

            if (i>two)
            {
                printf("Wrong!\n");
            }
            else
            {
                j-=i*2;
                i=0;
            }

            i=r*c-n;
            four=((r-1)/2)*((c-2)/2)+((r-2)/2)*((c-1)/2);

            if (r==1||c==1)
                three=0;
            else
            if (r==2)
                three=(c-2)/2+(c-1)/2;
            else
            if (c==2)
                three=(r-2)/2+(r-1)/2;
            else
                three=(c-1)/2+(c+r%2-2)/2+(r-1)/2+(r+c%2-2)/2;

            if (r==1)
                two=c/2;
            else
            if (c==1)
                two=r/2;
            else
                two=(r+1)%2+(c+1)%2+(r+c)%2;
           // printf("%d %d %d\n",four,three,two);
            k=(c-1)*r+(r-1)*c;
            if (i>four)
            {
                k-=four*4;
                i=i-four;
            }
            else
            {
                k-=i*4;
                i=0;
            }

            if (i>three)
            {
                k-=three*3;
                i=i-three;
            }
            else
            {
                k-=i*3;
                i=0;
            }

            if (i>two)
            {
                printf("Wrong!\n");
            }
            else
            {
                k-=i*2;
                i=0;
            }
            printf("%d\n",min(j,k));
        }
    }
    return 0;
}

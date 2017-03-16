#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int odd(int a)
{
    return a & 1;
}

int getAns1(int r,int c ,int n)
{
    int ans = 0;
    if ( odd(r) && odd(c) )
    {

        if ( n <= (r * c) / 2 + 1 )
        {
            return ans;

        }
        n -= (r * c / 2 + 1);
        if ( n  <= r + c - 2 )
        {
            return n * 3;

        }
        ans = (r + c - 2) * 3;
        n -= (r + c - 2);
        return ans + n * 4;
    }
    else if ( odd(r) && !odd(c) )
    {
        if ( n <= (r * c) / 2  )
        {
            return ans;

        }
        n -= (r * c / 2 );
        if ( n <= 2)
        {
            return n * 2;

        }
        ans += 2 * 2;
        n -= 2;
        if ( n  <= r + c - 4 )
        {
            return ans + n * 3;

        }
        ans += (r + c - 4) * 3;
        n -= (r + c - 4);
        return ans + n * 4;
    }
    else if ( odd(c) && !odd(r) )
    {
        //cout << n << r << c << endl;
        if ( n <= (r * c) / 2  )
        {
            return ans;

        }
        n -= (r * c / 2 );
        if ( n <= 2)
        {
            return ans + n * 2;

        }
        ans += 2 * 2;
        n -= 2;
        if ( n  <= r + c - 4 )
        {
            return ans + n * 3;

        }
        ans += (r + c - 4) * 3;
        n -= (r + c - 4);
        return ans + n * 4;
    }
    else if ( !odd(r) && !odd(c) )
    {
        if ( n <= (r * c) / 2  )
        {
            return ans ;

        }
        n -= (r * c / 2 );
        if ( n <= 2)
        {
            return ans + n * 2;

        }
        ans += 2 * 2;
        n -= 2;
        if ( n  <= r + c - 4 )
        {
            return ans + n*3;

        }
        ans += (r + c - 4) * 3;
        n -= (r + c - 4);
        return ans + n * 4;
    }
}
int getAns2(int r,int c,int n)
{
    int ans = 0;
    if ( odd(r) && odd(c) )
    {

        if ( n <= (r * c) / 2  )
        {
            return ans;
        }
        n -= (r * c / 2 );
        if ( n <= 4 )
        {
            return n * 2;
        }
        ans += 4 * 2;
        n -= 4;
        if ( n  <= r + c - 6 )
        {
            return n * 3;
        }
        ans += (r + c - 6) * 3;
        n -= (r + c - 6);
        return ans + n * 4;
    }
    else if ( odd(r) && !odd(c) )
    {
        if ( n <= (r * c) / 2  )
        {
            return ans;

        }
        n -= (r * c / 2 );
        if ( n <= 2)
        {
            return n * 2;

        }
        ans += 2 * 2;
        n -= 2;
        if ( n  <= r + c - 4 )
        {
            return ans + n * 3;

        }
        ans += (r + c - 4) * 3;
        n -= (r + c - 4);
        return ans + n * 4;
    }
    else if ( odd(c) && !odd(r) )
    {
        //cout << n << r << c << endl;
        if ( n <= (r * c) / 2  )
        {
            return ans;

        }
        n -= (r * c / 2 );
        if ( n <= 2)
        {
            return ans + n * 2;

        }
        ans += 2 * 2;
        n -= 2;
        if ( n  <= r + c - 4 )
        {
            return ans + n * 3;

        }
        ans += (r + c - 4) * 3;
        n -= (r + c - 4);
        return ans + n * 4;
    }
    else if ( !odd(r) && !odd(c) )
    {
        if ( n <= (r * c) / 2  )
        {
            return ans ;

        }
        n -= (r * c / 2 );
        if ( n <= 2)
        {
            return ans + n * 2;

        }
        ans += 2 * 2;
        n -= 2;
        if ( n  <= r + c - 4 )
        {
            return ans + n*3;
        }

        ans += (r + c - 4) * 3;

        n -= (r + c - 4);
        return ans + n * 4;
    }
}
int getAns3(int r,int n)
{
    if (odd(r))
    {
        if ( n <= r / 2 + 1) return 0;
        n -= r / 2 + 1 ;
        return n * 2;
    }
    else
    {
        if ( n <= r / 2 )return  0;
        n -= r/2;
        if ( n <= 1 ) return 1;
        n --;
        return n * 2 + 1;
    }
}
int getAns4(int r,int n)
{
    int ans = 0;
    if (odd(r))
    {
        if ( n <= r / 2 ) return 0;
        n -= r / 2 ;
        if (n <= 2) return n ;
        n -= 2;
        return n * 2 + 2;
    }
    else
    {
        if ( n <= r / 2 )return  0;
        n -= r/2;
        if ( n <= 1 ) return 1;
        n --;
        return n * 2 + 1;
    }
}
int main()
{
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    int caseTest;
    scanf("%d",&caseTest);
    for (int _ = 1 ; _ <= caseTest ; _ ++)
    {
        int r , c , n;
        scanf("%d%d%d",&r,&c,&n);
        if ( r > c ) swap(r,c);
        if (r == 1)
        printf("Case #%d: %d\n",_,min(getAns3(c,n),getAns4(c,n)));
        else
        printf("Case #%d: %d\n",_,min(getAns1(r,c,n),getAns2(r,c,n)));
    }
    fclose(stdin);
    fclose(stdout);
}

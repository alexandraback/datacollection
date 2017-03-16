#include <stdio.h>
#include <stdlib.h>

int m_K[1000];
int t_K[1000];

int gcd( int a, int b )
{
    if( a < b )
    {
        return gcd( b, a );
    }
    else if( a % b == 0 )
    {
        return b;
    }
    else
    {
        return gcd( b, a%b );
    }
}

int lcm( int a, int b )
{
    return a * b / gcd( a, b );
}

int lcm_find(int a)
{
    if( a == 1 )
        return lcm(m_K[a],m_K[a-1]);

    return lcm(m_K[a],lcm_find(a-1));
}

int main()
{
    int cases, num, max_num_B, max_num_C, res, lcm_num, lcm_cut;
    int min_val, min_i;
    int i, j, k;

    freopen("1.in","r",stdin);
    freopen("1.out","w+",stdout);

    scanf("%d ",&cases);

    for(i = 0;i<cases;i++){
        res = 0;
        lcm_num = 0;
        lcm_cut = 0;
        min_i = -1;
        min_val = 10000;

        scanf("%d ",&max_num_B);
        scanf("%d ",&max_num_C);

        for(j=0;j<max_num_B;j++){
            scanf("%d",&m_K[j]);
            if( m_K[j] <= min_val ){
                min_i = j;
                min_val = m_K[j];
            }
            t_K[j] = 0;
        }
        lcm_num = lcm_find(max_num_B-1);
        for(j=0;j<max_num_B;j++){
            lcm_cut += lcm_num/m_K[j];
        }

        max_num_C = max_num_C%lcm_cut;
        if(max_num_C == 0 )
        {
            res = min_i;
        }
        else
        {
            while(max_num_C > 0){
                for(j=0;j<max_num_B;j++){
                    if(t_K[j] == 0){
                        t_K[j] = m_K[j];
                        max_num_C--;
                        if( max_num_C == 0)
                        {
                            res = j;
                            break;
                        }
                    }
                }

                for(j = 0;j<max_num_B;j++)
                {
                    t_K[j]--;
                }

            }
        }

       // res = (max_num-res)>0?max_num-res:0;
        printf("Case #%d: %d\n",i+1,res+1);
    }

    return 0;
}

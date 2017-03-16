#include<stdio.h>
int main()
{
    int i,t,r,c,n,tot,tmp,out,maxedge,removal,tomake,x,y,z,removal2;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&r,&c,&n);
        tot=r*c;
        tmp = (tot+1)/2;
        //tmp stores max possible apartments;
        if(n<=tmp)
        {
            out=0;
        }
        else
        {
            tomake=r*c - n; // the number of apartments to be removed
            maxedge=(r-1)*c + (c-1)*r; // total edges
            removal=0; // edges to be removed due to unoccupied
            //Finding maximum 4s
            tmp=(r-2)*(c-2);
            tmp=(tmp+1)/2; // Number of max 4s
            if(r<3 || c<3)
                tmp=0;

            if(tmp>=tomake)
            {
                removal+=tomake*4;
            }
            else
            {
                tomake=tomake-tmp;
                removal+=tmp*4;
                //Finding max 3s
                tmp=0;
                tmp+=(r-2)/2;
                tmp+=(c-2)/2;
                tmp+= (r%2==0)? (c-1)/2 : (c-2)/2;
                tmp+= (c%2==0) ? (r-1)/2 : (r-2)/2;

                if(r<2 || c<2)
                    tmp=0;

                if(tmp>=tomake)
                {
                    removal+=tomake*3;
                }
                else
                {
                    tomake=tomake-tmp;
                    removal+=tmp*3;
                    //Addind 2s
                    removal+=tomake*2;
                }
            }


            //Alternate start
            tomake=r*c - n; // the number of apartments to be removed
            maxedge=(r-1)*c + (c-1)*r; // total edges
            removal2=0; // edges to be removed due to unoccupied
            //Finding maximum 4s
            tmp=(r-2)*(c-2);
            tmp=(tmp)/2; // Number of max 4s
            if(r<3 || c<3)
                tmp=0;

            if(tmp>=tomake)
            {
                removal2+=tomake*4;
            }
            else
            {
                tomake=tomake-tmp;
                removal2+=tmp*4;
                //Finding max 3s
                tmp=0;
                tmp+=(r-1)/2;
                tmp+=(c-1)/2;
                tmp+= (r%2==0)? (c-2)/2 : (c-1)/2;
                tmp+= (c%2==0) ? (r-2)/2 : (r-1)/2;

                if(r<2 || c<2)
                    tmp=0;

                if(tmp>=tomake)
                {
                    removal2+=tomake*3;
                }
                else
                {
                    tomake=tomake-tmp;
                    removal2+=tmp*3;
                    //Addind 2s
                    removal2+=tomake*2;
                }
            }
            //Alternate end
            if(removal2<removal)
                out=maxedge-removal;
            else
                out=maxedge-removal2;
        }
        printf("Case #%d: %d\n",i,out);
    }
    return 0;
}

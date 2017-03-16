#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream f2("f5.out");
    int T;
    cin>>T;
    int R,C,N;
    int y=0;
    int count0,b0,j0,l0;
    int y1,y2;
    for(int i=0;i<T;i++)
    {
        y=0;y1=0;y2=0;
        cin>>R>>C>>N;
        if(R==1||C==1)
        {
            if((R*C)%2==0)
            {
                count0=R*C/2;
                j0=1;
                b0=R*C-count0-j0;
                if(N<count0+1)
                {
                    y=0;
                }
                else
                {
                    y=1+(N-count0-1)*2;
                }
            }
            else
            {
                count0=R*C/2;
                j0=2;
                b0=R*C-count0-j0;
                if(N<count0+1)
                {
                    y1=0;
                }
                else
                {
                    if(N-count0<j0+1)
                    {
                        y1=(N-count0);
                    }
                    else
                    {
                        y1=2+(N-count0-j0)*2;
                    }
                }
                count0=R*C/2+1;
                j0=0;
                b0=R*C-count0-j0;
                if(N<count0+1)
                {
                    y2=0;
                }
                else
                {
                    y2=(N-count0)*2;
                }
                y=y1>y2?y2:y1;
            }

        }
        else{ if((R*C)%2==0)
        {
            count0=R*C/2;
            j0=2;
            b0=(R/2+C/2+(R+1)/2+(C+1)/2)-4;
            l0=R*C-count0-j0-b0;
            if(N<count0+1)
            {
                y=0;
            }
            else
            {
                if(N-count0<j0+1)
                {
                    y=(N-count0)*2;
                }
                else
                {
                    if(N-count0-j0<b0+1)
                    {
                        y=j0*2+(N-count0-j0)*3;
                    }
                    else
                    {
                        y=j0*2+b0*3+(N-count0-j0-b0)*4;
                    }
                }
            }

        }
        else
        {
            count0=R*C/2;
            j0=4;
            b0=((R+1)/2+(C+1)/2)*2-8;
            l0=R*C-count0-j0-b0;
            if(N<count0+1)
            {
                y1=0;
            }
            else
            {
                if(N-count0<j0+1)
                {
                    y1=(N-count0)*2;
                }
                else
                {
                    if(N-count0-j0<b0+1)
                    {
                        y1=j0*2+(N-count0-j0)*3;
                    }
                    else
                    {
                        y1=j0*2+b0*3+(N-count0-j0-b0)*4;
                    }
                }
            }
            count0=R*C/2+1;
            j0=0;
            b0=(R/2+C/2)*2;
            l0=R*C-count0-j0-b0;
            if(N<count0+1)
            {
                y2=0;
            }
            else
            {
                if(N-count0<j0+1)
                {
                    y2=(N-count0)*2;
                }
                else
                {
                    if(N-count0-j0<b0+1)
                    {
                        y2=j0*2+(N-count0-j0)*3;
                    }
                    else
                    {
                        y2=j0*2+b0*3+(N-count0-j0-b0)*4;
                    }
                }
            }
            y=y1>y2?y2:y1;
            }


        }
        f2<<"Case #"<<i+1<<": "<<y<<endl;



    }
    return 0;
}

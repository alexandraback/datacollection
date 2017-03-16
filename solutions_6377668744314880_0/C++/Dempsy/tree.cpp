#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

typedef struct
{
    long x;
    long y;
}POINT;

POINT b[1001],a[1001],res[1001];

long Distance(POINT p1,POINT p2)//两点间的距离
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

long mul(POINT p1,POINT p2,POINT p3)//叉积
{
    return((p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x));
}

int Compare(const void*p1,const void*p2)//根据p0->p1的极值和p0->p2的极值进行比较，如果极值相同则用距离长度比较
{
    POINT *p3,*p4;
    double m;
    p3=(POINT*)p1;
    p4=(POINT*)p2;
    m=mul(a[0],*p3,*p4);
    if(m<0)return 1;
    else if(m==0&&(Distance(a[0],*p3)<Distance(a[0],*p4)))
    return 1;
    else return-1;
}

int main() {
    freopen("C-small-attempt1.in","r",stdin);
    freopen("output31.txt","w",stdout);
    int  totcase,top;
 
    cin >> totcase;
    for (int nowcase=0;nowcase<totcase;nowcase++) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> a[i].x >> a[i].y;
            b[i].x=a[i].x;b[i].y=a[i].y;
        }
        
        long px = 0,py=-1;
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(py==-1||a[i].y<py)
            {
                px=a[i].x;
                py=a[i].y;
                p=i;
            }
            else if(a[i].y==py&&a[i].x<px)
            {
                px=a[i].x;
                py=a[i].y;
                p=i;
            }
        }
        std::swap(a[0].x,a[p].x);
        std::swap(a[0].y,a[p].y);
        
        qsort(&a[1],n-1,sizeof(double)*2,Compare);
        
        
        a[n].x=a[0].x;
        a[n].y=a[0].y;
        
        res[0].x=a[0].x;res[0].y=a[0].y;
        res[1].x=a[1].x;res[1].y=a[1].y;
        res[2].x=a[2].x;res[2].y=a[2].y;

        top=2;
        for (int i=3;i<=n;i++) {
            while (mul(res[top-1],res[top],a[i])<=0&&top>2)
                top--;
            res[top+1].x=a[i].x;
            res[top+1].y=a[i].y;
            top++;
        }

        
        cout << "Case #"<<nowcase+1<<":"<<endl;
        
        for (int i=0;i<n;i++) {
            int min=3000;
            for (int j=0;j<top;j++) {
                int resx=0;
                int resy=0;
                if (min!=0) {
                    if ((b[i].x==res[j].x)&&(b[i].y==res[j].y)) {
                        min=0;
                    } else {
                        for (int k=0;k<n;k++) {
                            double xx=mul(b[i],res[j],b[k]);
                            if (xx>0) {
                                resx++;
                            } else if (xx<0) {
                                resy++;
                            }
                        }
                    }
                }
                if (resx<min) min=resx;
                if (resy<min) min=resy;
            }
            cout << min << endl;
        }
        
    }
}

#include <bits/stdc++.h>
#define pi 2*acos(0)
#define ll long long
using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};


struct point{
    int x,y,id;
    double a;
}p[100000];

int turn(point p1,point p2,point p3)
{
    ll k= (( (p2.x-p1.x)*1LL)*(p3.y-p1.y)-((p3.x-p1.x)*1LL)*(p2.y-p1.y));

    if(k>0) return 1;
    if(k<0) return -1;
    return 0;
}

double dist(point p1,point p2)
{
    ll r;

    r=(1LL*(p1.x-p2.x))*(p1.x-p2.x)+(1LL*(p1.y-p2.y))*(p1.y-p2.y);

    return sqrt(r);
}

bool mycomp(point p1,point p2)
{
    int k=turn(p[0],p1,p2);

    if(k==1) return 1;
    if(k==-1) return 0;

    return (dist(p[0],p1)>dist(p[0],p2));

}

bool left_com(point p1,point p2)
{
    if(p1.x!=p2.x) return (p1.x<p2.x);

    if(p1.y!=p2.y) return (p1.y<p2.y);

    return (p1.id<p2.id);
}

vector <PT> input,process;
map <pair<int,int>,bool> mymap;
int x[20],y[20],n;
int hull[100];


bool convex(int self){

    int i,j,k,n,h;

    n=input.size();
    h=0;

    for(i=0;i<n;i++){

        p[i].x=(int)(input[i].x+0.5);
        p[i].y=(int)(input[i].y+0.5);

    }

    sort(p,p+n,left_com);  //Its not essential to sort the whole array

    sort(p+1,p+n,mycomp);


    for(i=2;i<n;i++)
    {
        if(turn(p[i],p[i-1],p[0])==0) continue;

        break;
    }


        if(i>2) sort(p,p+i,left_com);

        for(i=0;i<n;i++)
        {
            while(h>1)
            {
                if(turn(p[hull[h-2]],p[hull[h-1]],p[i])==1) break;

                else   h--;

            }

            hull[h++]=i;
        }

        while(h>2)
        {
            if(turn(p[hull[h-2]],p[hull[h-1]],p[0])==1) break;

            else   h--;

        }

        //peri=0.0;

        point pn;

        pn.x=x[self];
        pn.y=y[self];

        for(i=0;i<h;i++) if(turn(p[hull[i]],pn,p[hull[(i+1)%h]])==0) return 1;


        return 0;
}

bool found;

void work(int self,int now,int sz){

    if(found) return;

    if(process.size()>sz) return;

    if(now==self){
        work(self,now+1,sz);
        return ;
    }

    if(now>n && process.size()==sz){

        //cout<<"process size "<<process.size()<<endl;

        input = process;



        if(convex(self)){
            found=1;
        }

        return;

    }


    if(process.size()+(n-now+1)<sz) return;

    if(process.size()+(n-now+1) == sz){

        process.push_back(PT(x[now],y[now]));
        work(self,now+1,sz);
        process.pop_back();
        return ;
    }

     if(process.size()+(n-now+1) > sz){

        //input.push_back(PT(x[now],y[now]));
        work(self,now+1,sz);

        process.push_back(PT(x[now],y[now]));
        work(self,now+1,sz);
        process.pop_back();
        return ;
    }
}


int main()
{
    int i,j,k,t,T,ret=0,mx,my,sz;

    //freopen("in.txt","r",stdin);

    freopen("C-small-attempt1.in","r",stdin);
    freopen("CSmall2.txt","w",stdout);

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {

        scanf("%d",&n);

        mx=my=0;

        for(i=1;i<=n;i++){

            scanf("%d %d",&x[i],&y[i]);

            mx=min(mx,x[i]);
            my=min(my,y[i]);

        }

        for(i=1;i<=n;i++){

            x[i]-=mx;
            x[i]++;
            y[i]-=my;
            y[i]++;
        }

        printf("Case #%d:\n",t);

        for(i=1;i<=n;i++){

            found=0;
            process.clear();

            process.push_back(PT(x[i],y[i]));

            for(sz=n;sz>=4;sz--){

               // cout<<" Now work for "<<sz<<endl;

                work(i,1,sz);

                if(found) break;

            }

            //cout<<"FINAL SZ "<<sz<<endl;

            printf("%d\n",n-sz);
        }
    }

    return 0;
}

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1005;
const int MOD = 100007;
#define mp make_pair
#define pb push_back
namespace Geometry{
    #define typec double
    const typec eps=1e-8;
    const typec pi=acos(-1.0);
    const typec inf=1e20;
    const int maxp=100001;
    int dblcmp(double d){
        if (fabs(d)<eps)return 0;
        return d>eps?1:-1;
    }
    int sgn(double a) {return a<-eps?-1:a>eps;}
    inline double sqr(double x){return x*x;}
    struct Point2D{
        typec x,y;
        Point2D(){}
        Point2D(typec _x,typec _y):x(_x),y(_y){};
        void input(){
            scanf("%lf%lf",&x,&y);
        }
        void output(){
            printf("%.2f %.2f\n",x,y);
        }
        bool operator==(Point2D a)const{
            return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
        }
        bool operator<(Point2D a)const{
            return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
        }
        typec len(){
            return hypot(x,y);
        }
        typec len2(){
            return x*x+y*y;
        }
        Point2D operator + (const Point2D &A) const{
            return Point2D(x + A.x , y + A.y);
        }
        Point2D operator - (const Point2D &A) const{
            return Point2D(x - A.x , y - A.y);
        }
        Point2D operator * (const typec _x) const{
            return Point2D(x * _x , y * _x);
        }
        typec operator * (const Point2D &A) const{
            return x * A.x + y * A.y;
        }
        typec operator ^ (const Point2D &A) const{
            return x * A.y - y * A.x;
        }
        Point2D operator / (const typec _p) const{
            return Point2D(x / _p , y / _p);
        }
        typec distance(Point2D p){
            return hypot(x-p.x,y-p.y);
        }
        Point2D add(Point2D p){
            return Point2D(x+p.x,y+p.y);
        }
        Point2D sub(Point2D p){
            return Point2D(x-p.x,y-p.y);
        }
        Point2D mul(typec b){
            return Point2D(x*b,y*b);
        }
        Point2D div(typec b){
            return Point2D(x/b,y/b);
        }
        typec dot(Point2D p){
            return x*p.x+y*p.y;
        }
        typec det(Point2D p){
            return x*p.y-y*p.x;
        }
        typec rad(Point2D a,Point2D b){
            Point2D p=*this;
            return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
        }
        Point2D trunc(typec r){
            typec l=len();
            if (!dblcmp(l))return *this;
            r/=l;
            return Point2D(x*r,y*r);
        }
        Point2D rotleft(){
            return Point2D(-y,x);
        }
        Point2D rotright(){
            return Point2D(y,-x);
        }
        Point2D rotate(Point2D p,typec angle)//ÈÆµãpÄæÊ±ÕëÐý×ªangle½Ç¶È
        {
            Point2D v=this->sub(p);
            typec c=cos(angle),s=sin(angle);
            return Point2D(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
        }
    };

    typec cross(Point2D a,Point2D b,Point2D c){
        return (b.sub(a)).det(c.sub(a));
    }

    struct Line2D{
        Point2D a,b;
        double at;
        Line2D(){}
        Line2D(Point2D _a,Point2D _b){
            a=_a;
            b=_b;
        }
        bool operator==(Line2D v){
            return (a==v.a)&&(b==v.b);
        }
        bool operator < (const Line2D &t) const {
            return sgn(at-t.at)<0||
                    (sgn(at-t.at)==0&&sgn(cross(a,b,t.a))<0);
        }

        Point2D operator &(Line2D &A)const
        {
            Point2D res = a;
            //×¢Òâ£ºÓÐÐ©ÌâÄ¿¿ÉÄÜ»áÓÐÖ±ÏßÏà½»»òÕßÖØºÏÇé¿ö
            //¿ÉÒÔ°Ñ·µ»ØÖµ¸Ä³É`pair<Point,int>`À´·µ»ØÁ½Ö±ÏßµÄ×´Ì¬¡£
            double t = ((a - A.a) ^ (A.a - A.b)) / ((a - b) ^ (A.a - A.b));
            res.x += (b.x - a.x) * t;
            res.y += (b.y - a.y) * t;
            return res;
        }
        //ÇãÐ±½Çangle
        Line2D(Point2D p,double angle)
        {
            a=p;
            if (dblcmp(angle-pi/2)==0)
            {
                b=a.add(Point2D(0,1));
            }
            else
            {
                b=a.add(Point2D(1,tan(angle)));
            }
        }

        //Ê¸Á¿VÒÔPÎª¶¥µãÄæÊ±ÕëÐý×ªangle²¢·Å´óscale±¶
        Point2D rotate(Point2D v,Point2D p,double angle,double scale){
            Point2D ret=p;
            v.x-=p.x,v.y-=p.y;
            p.x=scale*cos(angle);
            p.y=scale*sin(angle);
            ret.x+=v.x*p.x-v.y*p.y;
            ret.y+=v.x*p.y+v.y*p.x;
            return ret;
        }

        //ax+by+c=0
        Line2D(typec _a,typec _b,typec _c){
            if (dblcmp(_a)==0)
            {
                a=Point2D(0,-_c/_b);
                b=Point2D(1,-_c/_b);
            }
            else if (dblcmp(_b)==0)
            {
                a=Point2D(-_c/_a,0);
                b=Point2D(-_c/_a,1);
            }
            else
            {
                a=Point2D(0,-_c/_b);
                b=Point2D(1,(-_c-_a)/_b);
            }
        }
        void input()
        {
            a.input();
            b.input();
            angle();
        }
        void adjust()
        {
            if (b<a)swap(a,b);
        }
        double length()
        {
            return a.distance(b);
        }
        double angle()//Ö±ÏßÇãÐ±½Ç 0<=angle<180
        {
            double k=atan2(b.y-a.y,b.x-a.x);
            if (dblcmp(k)<0)k+=pi;
            if (dblcmp(k-pi)==0)k-=pi;
            at = k;
            return k;
        }
        //µãºÍÏß¶Î¹ØÏµ
        //1 ÔÚÄæÊ±Õë
        //2 ÔÚË³Ê±Õë
        //3 Æ½ÐÐ
        int relation(Point2D p)
        {
            int c=dblcmp(p.sub(a).det(b.sub(a)));
            if (c<0)return 1;
            if (c>0)return 2;
            return 3;
        }
        bool pointonseg(Point2D p)
        {
            return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
        }
        bool parallel(Line2D v)
        {
            return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
        }
        //2 ¹æ·¶Ïà½»
        //1 ·Ç¹æ·¶Ïà½»
        //0 ²»Ïà½»
        int segcrossseg(Line2D v)
        {
            int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
            int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
            int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
            int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
            if ((d1^d2)==-2&&(d3^d4)==-2)return 2;
            return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
                    d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
                    d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
                    d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);
        }

        int linecrossseg(Line2D v)//*this seg v line
        {
            int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
            int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
            if ((d1^d2)==-2)return 2;
            return (d1==0||d2==0);
        }
        //0 Æ½ÐÐ
        //1 ÖØºÏ
        //2 Ïà½»
        int linecrossline(Line2D v)
        {
            if ((*this).parallel(v))
            {
                return v.relation(a)==3;
            }
            return 2;
        }
        Point2D crosspoint(Line2D v)
        {
            double a1=v.b.sub(v.a).det(a.sub(v.a));
            double a2=v.b.sub(v.a).det(b.sub(v.a));
            return Point2D((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
        }
        double dispointtoline(Point2D p)
        {
            return fabs(p.sub(a).det(b.sub(a)))/length();
        }
        double dispointtoseg(Point2D p)
        {
            if (dblcmp(p.sub(b).dot(a.sub(b)))<0||dblcmp(p.sub(a).dot(b.sub(a)))<0)
            {
                return min(p.distance(a),p.distance(b));
            }
            return dispointtoline(p);
        }
        Point2D lineprog(Point2D p)
        {
            return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
        }
        Point2D symmetrypoint(Point2D p)    //¶Ô³Æµã
        {
            Point2D q=lineprog(p);
            return Point2D(2*q.x-p.x,2*q.y-p.y);
        }
    };
    struct Polygon2D{
        int n;
        Point2D p[maxp];
        Line2D l[maxp];
        void copy(Polygon2D & A){
            A.n=n;
            for (int i=0;i<n;++i){
                A.p[i]=p[i];
                A.l[i]=l[i];
            }
        }
        void input()
        {
            for (int i=0;i<n;i++)
            {
                p[i].input();
            }
        }
        void add(Point2D q)
        {
            p[n++]=q;
        }
        void getline()
        {
            for (int i=0;i<n;i++)
            {
                l[i]=Line2D(p[i],p[(i+1)%n]);
            }
        }
        struct cmp
        {
            Point2D p;
            cmp(const Point2D &p0){p=p0;}
            bool operator()(const Point2D &aa,const Point2D &bb)
            {
                Point2D a=aa,b=bb;
                int d=dblcmp(a.sub(p).det(b.sub(p)));
                if (d==0)
                {
                    return dblcmp(a.distance(p)-b.distance(p))<0;
                }
                return d>0;
            }
        };
        void norm()
        {
            Point2D mi=p[0];
            for (int i=1;i<n;i++)mi=min(mi,p[i]);
            sort(p,p+n,cmp(mi));
        }
        void getconvex(Polygon2D &convex)
        {
            int i,j,k;
            sort(p,p+n);
            convex.n=n;
            for (i=0;i<min(n,2);i++)
            {
                convex.p[i]=p[i];
            }
            if (n<=2)return;
            int &top=convex.n;
            top=1;
            for (i=2;i<n;i++)
            {
                while (top&&dblcmp(convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i])))<0)
                    top--;
                convex.p[++top]=p[i];
            }
            int temp=top;
            convex.p[++top]=p[n-2];
            for (i=n-3;i>=0;i--)
            {
                while (top!=temp&& dblcmp(convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i])))<0)
                    top--;
                convex.p[++top]=p[i];
            }
        }
        bool isconvex()
        {
            bool s[3];
            memset(s,0,sizeof(s));
            int i,j,k;
            for (i=0;i<n;i++)
            {
                j=(i+1)%n;
                k=(j+1)%n;
                s[dblcmp(p[j].sub(p[i]).det(p[k].sub(p[i])))+1]=1;
                if (s[0]&&s[2])return 0;
            }
            return 1;
        }
        //3 µãÉÏ
        //2 ±ßÉÏ
        //1 ÄÚ²¿
        //0 Íâ²¿
        int relationpoint(Point2D q)
        {
            int i,j;
            for (i=0;i<n;i++)
            {
                if (p[i]==q)return 3;
            }
            getline();
            for (i=0;i<n;i++)
            {
                if (l[i].pointonseg(q))return 2;
            }
            int cnt=0;
            for (i=0;i<n;i++)
            {
                j=(i+1)%n;
                int k=dblcmp(q.sub(p[j]).det(p[i].sub(p[j])));
                int u=dblcmp(p[i].y-q.y);
                int v=dblcmp(p[j].y-q.y);
                if (k>0&&u<0&&v>=0)cnt++;
                if (k<0&&v<0&&u>=0)cnt--;
            }
            return cnt!=0;
        }
        //1 ÔÚ¶à±ßÐÎÄÚ³¤¶ÈÎªÕý
        //2 Ïà½»»òÓë±ßÆ½ÐÐ
        //0 ÎÞÈÎºÎ½»µã
        int relationline(Line2D u)
        {
            int i,j,k=0;
            getline();
            for (i=0;i<n;i++)
            {
                if (l[i].segcrossseg(u)==2)return 1;
                if (l[i].segcrossseg(u)==1)k=1;
            }
            if (!k)return 0;
            vector<Point2D>vp;
            for (i=0;i<n;i++)
            {
                if (l[i].segcrossseg(u))
                {
                    if (l[i].parallel(u))
                    {
                        vp.pb(u.a);
                        vp.pb(u.b);
                        vp.pb(l[i].a);
                        vp.pb(l[i].b);
                        continue;
                    }
                    vp.pb(l[i].crosspoint(u));
                }
            }
            sort(vp.begin(),vp.end());
            int sz=vp.size();
            for (i=0;i<sz-1;i++)
            {
                Point2D mid=vp[i].add(vp[i+1]).div(2);
                if (relationpoint(mid)==1)return 1;
            }
            return 2;
        }
        //Ö±ÏßuÇÐ¸îÍ¹¶à±ßÐÎ×ó²à
        //×¢ÒâÖ±Ïß·½Ïò
        void convexcut(Line2D u,Polygon2D &po)
        {
            int i,j,k;
            int &top=po.n;
            top=0;
            for (i=0;i<n;i++)
            {
                int d1=dblcmp(p[i].sub(u.a).det(u.b.sub(u.a)));
                int d2=dblcmp(p[(i+1)%n].sub(u.a).det(u.b.sub(u.a)));
                if (d1>=0)po.p[top++]=p[i];
                if (d1*d2<0)po.p[top++]=u.crosspoint(Line2D(p[i],p[(i+1)%n]));
            }
        }


        double getcircumference()
        {
            double sum=0;
            int i;
            for (i=0;i<n;i++)
            {
                sum+=p[i].distance(p[(i+1)%n]);
            }
            return sum;
        }
        double getarea()
        {
            double sum=0;
            int i;
            for (i=0;i<n;i++)
            {
                sum+=p[i].det(p[(i+1)%n]);
            }
            return fabs(sum)/2;
        }
        bool getdir()//1´ú±íÄæÊ±Õë 0´ú±íË³Ê±Õë
        {
            double sum=0;
            int i;
            for (i=0;i<n;i++)
            {
                sum+=p[i].det(p[(i+1)%n]);
            }
            if (dblcmp(sum)>0)return 1;
            return 0;
        }
        Point2D getbarycentre()
        {
            Point2D ret(0,0);
            double area=0;
            int i;
            for (i=1;i<n-1;i++)
            {
                double tmp=p[i].sub(p[0]).det(p[i+1].sub(p[0]));
                if (dblcmp(tmp)==0)continue;
                area+=tmp;
                ret.x+=(p[0].x+p[i].x+p[i+1].x)/3*tmp;
                ret.y+=(p[0].y+p[i].y+p[i+1].y)/3*tmp;
            }
            if (dblcmp(area))ret=ret.div(area);
            return ret;
        }
        double areaintersection(Polygon2D po)
        {
        }
        double areaunion(Polygon2D po)
        {
            return getarea()+po.getarea()-areaintersection(po);
        }
        void cg()
        {
            if (getdir())reverse(p,p+n);
        }
        int pointinpolygon(Point2D q)//µãÔÚÍ¹¶à±ßÐÎÄÚ²¿µÄÅÐ¶¨
        {
            if (dblcmp(q.sub(p[0]).det(p[n-1].sub(p[0])))==0)
            {
                //if (line(p[n-1],p[0]).pointonseg(q))return n-1;
                return -1;
            }
            if (dblcmp(q.sub(p[0]).det(p[1].sub(p[0])))==0)
            {
                //if (line(p[n-1],p[0]).pointonseg(q))return n-1;
                return -1;
            }
            int low=1,high=n-2,mid;
            static Polygon2D c;
            while (low<=high)
            {
                mid=(low+high)>>1;
                if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0])))>=0&&dblcmp(q.sub(p[0]).det(p[mid+1].sub(p[0])))<0)
                {
                    c.p[0]=p[mid];
                    c.p[1]=p[mid+1];
                    c.p[2]=p[0];
                    c.n=3;
                    if (Line2D(p[mid],p[mid+1]).pointonseg(q))return -1;
                    if (c.relationpoint(q))return mid;
                    return -1;
                }
                if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0])))>0)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            return -1;
        }
        /**
        \subsection{°ëÆ½Ãæ½»}
            Ö±Ïß×ó±ß´ú±íÓÐÐ§ÇøÓò¡£
            \begin{lstlisting}[language=c++
            */
        /*
        bool HPIcmp(Line2D A, Line2D B)
        {
            if (fabs(A.at - B.at) > eps)    return A.at < B.at;
            return ((A.a - B.a) * (B.b-B.a)) < 0;
        }
        */
        void HPI(Line2D line[], int m)
        {
            int tot = m;
            Line2D Q[10000];
            sort(line, line + m );//, HPIcmp); // HPIcmp
            tot = 1;
            for (int i = 1; i < m; i++)
                if (fabs(line[i].at - line[i - 1].at) > eps)
                    line[tot++] = line[i];
            int head = 0, tail = 1;
            Q[0] = line[0];
            Q[1] = line[1];
            n = 0;
            for (int i = 2; i < tot; i++)
            {
                if (fabs((Q[tail].b-Q[tail].a) ^ (Q[tail - 1].b-Q[tail - 1].a)) < eps ||
                        fabs((Q[head].b-Q[head].a) ^ (Q[head + 1].b-Q[head + 1].a)) < eps){
                    return;
                }
                while (head < tail && (((Q[tail]&Q[tail - 1]) - line[i].a) ^ (line[i].b-line[i].a)) > eps)
                    tail--;
                while (head < tail && (((Q[head]&Q[head + 1]) - line[i].a) ^ (line[i].b-line[i].a)) > eps)
                    head++;
                Q[++tail] = line[i];
            }
            while (head < tail && (((Q[tail]&Q[tail - 1]) - Q[head].a) ^ (Q[head].b-Q[head].a)) > eps)
                tail--;
            while (head < tail && (((Q[head]&Q[head + 1]) - Q[tail].a) ^ (Q[tail].b-Q[tail].a)) > eps)
                head++;
            if (tail <= head + 1) return;
            for (int i = head; i < tail; i++)
                p[n++] = Q[i] & Q[i + 1];
            if (head < tail + 1)
                p[n++] = Q[head] & Q[tail];
        }
        /*
        \subsection{Ö±ÏßÓëÍ¹°üÇó½»µã}
            ¸´ÔÓ¶È$O(\log{n})$¡£\\
            ÐèÒªÏÈÔ¤´¦Àí¼¸¸ö¶«Î÷¡£\\
            \begin{lstlisting}[language=c++]
        */
        //`¶þ·Ö[la,lb]Õâ¶ÎÇø¼äÄÇÌõ±ßÓëLine2DÏà½»`
        int Gao(int la,int lb,Line2D line)
        {
            if (la > lb)
                lb += n;
            int l = la,r = lb,mid;
            while (l < r)
            {
                mid = l+r+1>>1;
                if (dblcmp((line.b-line.a)^(p[la]-line.a))*dblcmp((line.b-line.a)^(p[mid]-line.a)) >= 0)
                    l = mid;
                else
                    r = mid-1;
            }
            return l%n;
        }
        //`ÇólÓëÍ¹°üµÄ½»µã`

        //`ÏÈµ÷ÓÃGetthetaÔ¤´¦Àí³öÍ¹°üÃ¿Ìõ±ßµÄÐ±ÂÊ£¬È»ºó´¦Àí³ÉÉýÐòÅÅÁÐ`
        double theta[maxp];

        void Gettheta()
        {
            for (int i = 0;i < n;i++)
            {
                Point2D v = p[(i+1)%n]-p[i];
                theta[i] = atan2(v.y,v.x);
            }
            for (int i = 1;i < n;i++)
                if (theta[i-1] > theta[i]+eps)
                    theta[i] += 2*pi;
        }

        double lineInterConvexHull(Line2D l , Point2D & pa , Point2D & pb)
        {
            double tnow;
            Point2D v = l.b-l.a;
            tnow = atan2(v.y,v.x);
            if (dblcmp(tnow-theta[0]) < 0)    tnow += 2*pi;
            int pl = lower_bound(theta,theta+n,tnow)-theta;
            tnow = atan2(-v.y,-v.x);
            if (dblcmp(tnow-theta[0]) < 0)    tnow += 2*pi;
            int pr = lower_bound(theta,theta+n,tnow)-theta;
            //`plºÍprÊÇÔÚl·½ÏòÉÏ¾àÀë×îÔ¶µÄµã¶Ô`
            pl = pl%n;
            pr = pr%n;

            if (dblcmp(v^(p[pl]-l.a))*dblcmp(v^(p[pr]-l.a)) >= 0)
                return 0.0;

            int xa = Gao(pl,pr,l);
            int xb = Gao(pr,pl,l);

            if (xa > xb)    swap(xa,xb);
            //`Óë[xa,xa+1]ºÍ[xb,xb+1]`ÕâÁ½ÌõÏß¶ÎÏà½»

            if (dblcmp(v^(p[xa+1]-p[xa])) == 0)  return 0.0;
            if (dblcmp(v^(p[xb+1]-p[xb])) == 0)  return 0.0;

            pa = Line2D(p[xa],p[xa+1])&l;
            pb = Line2D(p[xb],p[xb+1])&l;
            //return MP(pa , pb);
            //`ÌâÄ¿£ºÇóÖ±ÏßÇÐÍ¹°üµÃµ½µÄÁ½²¿·ÖµÄÃæ»ý`
            //double area0 = sum[xb]-sum[xa+1]+(pa*p[xa+1])/2.0+(p[xb]*pb)/2.0+(pb*pa)/2.0;
            //double area1 = sum[xa+n]-sum[xb+1]+(pb*p[xb+1])/2.0+(p[xa]*pa)/2.0+(pa*pb)/2.0;

            //return min(area0,area1);
        }
    };
}using namespace Geometry;
Point2D p[N];
Polygon2D q , con;
int ans[N] , n;
int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);  
    int t , cas = 0;scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            p[i].input ();
            ans[i] = n - 1;
        }
        for (int i = 1 ; i < 1 << n ; i ++) {
            int cnt = 0;
            q.n = 0;
            for (int j = 0 ; j < n ; j ++) {
                if (i & (1 << j)) {
                    q.add (p[j]);
                }
                else cnt ++;
            }
            q.getconvex (con);
            for (int j = 0 ; j < con.n ; j ++) {
                for (int i = 0 ; i < n ; i ++) {
                    if (p[i] == con.p[j]) {
                        ans[i] = min (ans[i] , cnt);
                    }
                }
            }

        }
        printf ("Case #%d:\n" , ++ cas);
        for (int i = 0 ; i < n ; i ++) {
            printf ("%d\n" , ans[i]);
        }
    }
    return 0;
}
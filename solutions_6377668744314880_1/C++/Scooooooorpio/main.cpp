#include <QCoreApplication>

#include <iostream>
#include <string>
#include <QDebug>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <algorithm>
using namespace std;


void prework() {

}

int x[4000], y[4000];
int re[4000];
int N;

double PI = acos(-1.0);
double degree0(qint64 x, qint64 y) {
    if (y ==0) {
        if (x>0)  return 0;
        else return PI;
    }

    double l =  x*x+ y*y;
    l = sqrt(l);
   // qDebug()<<x<<' '<<l;
    double d = acos(x/l);
    if (y<0) {
        d = 2*PI - d;
    }
//    qDebug()<<x<<' '<<y<<' '<<d;

    return d;
}

double degree(int x1, int y1, int x2, int y2) {
    int x = x2-x1;
    int y = y2 - y1;
    return degree0(x,y);
}
void check(int i, int r) {
    if ( r< re[i]) re[i] = r;
}
double roundAngle(double a) {
    if (a<0) a+=2*PI;
    if (a>=2*PI) a-= 2*PI;
    return a;
}

void work(int order) {
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>x[i]>>y[i];
        re[i] = 4000;
    }
    if (N<=3) {
        for (int i=0; i<N; i++) {
            cout<<endl<<0;
        }
        return;
    }

    for (int i=0; i<N; i++) {
        double dd[4000];
        int acc = 0;
        for (int j = 0; j<N; j++) {
            if (i==j) continue;
            dd[acc] = degree(x[i],y[i], x[j],y[j]);
            acc++;
        }

        sort(dd,dd+acc);

//        for (int j=0; j<N; j++) {
//            cout<<dd[j]<<' ';
//        }
//        cout<<endl;
        for (int j=0; j<acc; j++) {
            double angle = dd[j];

            int a = lower_bound(dd,dd+acc, roundAngle(angle-1e-8)) - dd;
            int b = upper_bound(dd,dd+acc, roundAngle(angle+1e-8)) - dd;



            double angle2 = angle + PI;

            int c = lower_bound(dd,dd+acc, roundAngle(angle2-1e-8)) - dd;
            int d = upper_bound(dd,dd+acc, roundAngle(angle2+1e-8)) - dd;
      //     qDebug()<<a<<' '<<b<<' '<<c<<' '<<d;
            if (b<=c) check(i,c-b);
            else check(i, c+acc -b);

            if (d<=a) check(i,a-d);
            else check(i, a+acc -d);

        }
    }

    for (int i=0; i<N; i++) {
        assert(re[i] <= N-3);
        cout<<endl<<re[i];
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<degree0(1,1);
    qDebug()<<degree0(1,0);
qDebug()<<degree0(0,1);
qDebug()<<degree0(-1,0);
qDebug()<<degree0(0,-1);
qDebug()<<degree0(-1,-1);
     if(freopen("D:\\temp\\output.txt", "w", stdout) == NULL)
         fprintf(stderr,"error redirecting stdout\n");
     if(freopen("D:\\temp\\input.txt", "r", stdin) == NULL)
         fprintf(stderr,"error redirecting stdin\n");
    int t;
    cin >>t;
    prework();
    for (int i=0; i<t;i++) {
        cout<<"Case #"<<i+1<<": ";

        work(i+1);
        cout<<endl;
    }

return 0;
    return a.exec();
}

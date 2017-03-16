#include <QCoreApplication>

#include <iostream>
#include <string>
#include <QDebug>
#include <cstdio>
#include <cassert>
using namespace std;


void prework() {

}


void work(int order) {
     int n;
     int re1,re2;
     cin>>n;
     int z[2000];
     re1 = 0;
     re2 = 0;
     int maxRate = 0;
     for (int i=0; i<n; i++) {
        cin>>z[i];
        if (i==0) continue;
        int x = z[i-1] - z[i];
        if (x<=0) continue;
        if (x>= maxRate) {
            maxRate = x;
        }
        re1 += x;
     }

     for (int i=0; i<n-1; i++) {
        if (z[i]< maxRate) {
            re2+= z[i];
        }
        else {
            re2+= maxRate;
        }
     }
     cout<<re1<<' '<<re2;
     qDebug()<<re1<<' '<<re2;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


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

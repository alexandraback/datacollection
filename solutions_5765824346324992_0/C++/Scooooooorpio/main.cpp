#include <QCoreApplication>

#include <iostream>
#include <string>
#include <QDebug>
#include <cstdio>
#include <cassert>
using namespace std;


void prework() {

}

int B,N;
int M[2000];

bool ifok(qint64 time) {
    qint64 count = 0;
    for (int i=0; i<B; i++) {
        count += time / M[i] +1;
    //    qDebug()<<count;
    }
 //   qDebug()<<count;
    if (count>=N) return true;
    return false;
}

void work(int order) {


    qDebug()<<" case "<<order;
    cin>>B>>N;

    for (int i=0; i<B; i++) {
        cin>>M[i];
    }

    qint64 bot, top;
    bot = -1;
    top = 1e16;

    while( bot +1 < top) {

        qint64 mid = (bot+top)/2;
    //    qDebug()<< bot<<' '<<top<<' '<<mid;
        if (ifok(mid)) {
            top = mid;
        }
        else {
            bot = mid;
        }
    }
    qDebug()<<top;
    qint64 count = 0;
    for (int i=0; i<B; i++) {
        count += top / M[i];
        if (top%M[i]!=0) count++;
    }
    qint64 x = N - count;
    qDebug()<<x;
    for (int i=0; i<B; i++) {
        if (top%M[i] == 0) {
            x--;
        }
        if (x==0) {
            cout<<i+1;
            return;
        }
    }
    assert(false);
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

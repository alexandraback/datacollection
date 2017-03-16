//
//  main.cpp
//  Codejam2015
//
//  Created by stoness on 15/4/11.
//  Copyright (c) 2015年 sts. All rights reserved.
//

#include <iostream>
using namespace std;

int q1() {
    int s(0),i(0),j(0),cnt(0),res(0);
    char c(0);
    cin>>s;
    cin.ignore();
    do {
        cin>>c;
        j=c-'0';
        if (i>cnt) { res+=i-cnt;cnt=i;}
        cnt+=j;
    } while (++i<=s);
    return res;
}

bool q4()  {
    int x(0),r(0),c(0);
    cin>>x>>r>>c;
    if (x>=7) return true;
    else if (r*c%x!=0) return true;
    else if (r<x && c<x) return true;
    else if (x==1) return false;
    else if (x==3)  {
        if (r==1 || c==1) return true;
    } else if (x==4)  {
        if (r<=2 || c<=2) return true;
    } else if (x==5)  {
        if (r<=2 || c<=2) return true;
        if (r*c==15) return true;
    } else if (x==6) {
        if (r<=3 || c<=3) return true;
    }
    return false;
}

int q2()  {
    int d(0),p(0),m(0),n(0),i(0),m1(0);
    cin>>d;
    for (i=0; i<d; ++i) {
        cin>>p;
        n+=p;
        m=max(m,p);
    }
    m1=(n+d+1)/(d+2);
    i=0;
    while (m>m1)  {
        ++i; m=m1;
        d+=2;
        m1=(n+d-1)/d;
    }
    return m+i;
}

void t1(int &r1, int &r2)  {
    int n(0);
    int m[10008]={0};
    int i(0),j(0),k(0);
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>m[i];
        j=m[i-1]-m[i];
        if (j>0) {
            r1+=j;
            k=max(k,j);
        }
    }
    for (i=0;i<n;++i) {
        if (m[i]>k) r2+=k;
        else r2+=m[i];
    }
}

int main(int argc, const char * argv[]) {
    int T(0);
    cin>>T;
    for (int i=0;i<T;++i) {
        int r1(0),r2(0);
        t1(r1,r2);
        cout<<"Case #"<<i+1<<": "<<r1<<' '<<r2<<endl;
    }
    return 0;
}

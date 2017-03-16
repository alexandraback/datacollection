#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>





using namespace std;



int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}




struct Time {
    unsigned long long h; // >= 0
    unsigned long long m; // 0-59
    unsigned long long x;
};

class CompareTime {
public:
    bool operator()(Time& t1, Time& t2)
    {
       if (t1.h > t2.h) return true;
       if (t1.h == t2.h && t1.m > t2.m) return true;
       return false;
    }
};



long long solve(string n,string s){
    long long res=0;
    return res;
}




int main(){

    long long res;
    ifstream myfile;
    myfile.open("B-small-attempt1.in.txt");
    ofstream outfile;
    outfile.open("output.txt");

    string line;
    getline(myfile,line);
    const int t=atoi(line.c_str());
    for(int i=0;i<t;i++){
        priority_queue<Time, vector<Time>, CompareTime> pq;
        getline(myfile,line);
        istringstream iss(line);
        string num;
        iss>> num;
        int n=atoi(num.c_str());
        iss>> num;
        int ith=atoi(num.c_str());
        getline(myfile,line);
        istringstream iss2(line);
        int arr[n];
        for(int i=0;i<n;i++){
            string v;
            iss2>>v;
            int vv=atoi(v.c_str());
            Time t;
            t.h=0;
            t.m=i;
            t.x=vv;
            arr[i]=vv;
            pq.push(t);
            cout<<vv<<" ";
        }
    int result = std::accumulate(arr, arr+n, 1, lcm);
    int pp=0;
    for(int i=0;i<n;i++){
        pp+=result/arr[i];
    }
    cout<<endl<<ith<<"%%"<<pp;
//cout<<endl<<"~"<<ith;        
cout<<endl;

        for(int i=0;i<ith%pp+pp-1;i++){
            Time temp = pq.top();
            pq.pop();
            temp.h += temp.x;
            pq.push(temp);
        }
        outfile<<"Case #"<<(i+1)<<": "<<pq.top().m+1<<endl;
        cout<<pq.top().m+1<<endl;
    }

    outfile.close();
    myfile.close();
    return 1;
}















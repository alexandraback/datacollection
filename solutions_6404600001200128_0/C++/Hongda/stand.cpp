#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

long long solve(string n,string s){
    long long res=0;
    return res;
}

long long s1(vector<int> input){
    int n = input.size();
    long long res=0;
    for(int i=1;i<n;i++){
        if(input[i-1]-input[i]>0){
            res+=input[i-1]-input[i];
        }
    }
    return res;
}


long long s2(vector<int> input){
    int d = 0;
    int n = input.size();
    long long res=0;
    for(int i=1;i<n;i++){
        if(input[i-1]-input[i]>0)  d=max(d,input[i-1]-input[i]);
    }
    for(int i=0;i<n-1;i++){
        int td=input[i];
            td = min(td,d);
            res+=td;
    }
    return res;
}






int main(){
    long long res;
    ifstream myfile;
    myfile.open("A-small-attempt0.in.txt");
    ofstream outfile;
    outfile.open("output.txt");

    string line;
    getline(myfile,line);
    const int t=atoi(line.c_str());
    for(int i=0;i<t;i++){
        getline(myfile,line);
        istringstream iss(line);
        string num;
        iss>> num;
        int n=atoi(num.c_str());
        vector<int> array;
        getline(myfile,line);
        istringstream iss2(line);
        for(int i=0;i<n;i++){
            string v;
            iss2>>v;
            int vv=atoi(v.c_str());
            cout<<vv<<" ";
            array.push_back(vv);
        }
cout<<endl;

        outfile<<"Case #"<<(i+1)<<": "<<s1(array)<<" "<<s2(array)<<endl;
    }

    outfile.close();
    myfile.close();
    return 1;
}















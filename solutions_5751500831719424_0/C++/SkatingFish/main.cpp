//
//  main.cpp
//  test1
//
//  Created by Liubing Yu on 5/3/14.
//  Copyright (c) 2014 Liubing Yu. All rights reserved.
//
//
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

int main(int argc, const char * argv[])
{
     int T,j,R,C,M,i,p,q,itar,t_tar,problem,sum;
    int l[100][100];
    ifstream fin;    // Input file stream
    ofstream fout;   //Output file stream
    string a,tempS;
    char tempc,m[100][100];
    char tar[100];///mark the character without repeat
    char *k;
    vector<int> Fl;
    fin.open ("/Users/liubingyu/Desktop/A-small-attempt0.in");
    fout.open("/Users/liubingyu/Desktop/A-small-attempt0.out.txt");
    fin>>T;
    //  std::cout << T<<"Hello, World!\n";
    
    for(j=0;j<T;j++){
        fin>>R;
        for(i=0;i<100;i++){
            tar[i]=0;
            for(p=0;p<100;p++){
                m[i][p]=0;
                l[i][p]=0;
            }
        }
        
        fin.getline(m[0], 200);
        for (i=0;i<R;i++){
            fin.getline(m[i], 200);
        }
        tempc=m[0][0];
        itar=0;
        tar[0]=m[0][0];
        for(p=1;p<100;p++){
            if(m[0][p]==0){
                break;
            }
            if(m[0][p]!=tempc){
                tempc=m[0][p];
                itar++;
                tar[itar]=m[0][p];
            }
        }
        t_tar=itar;
        ///caculate the target string
     //   cout<<tar<<endl;
        problem=0;
        for(i=0;i<R;i++){
            itar=0;
            problem=0;
            for(p=0;p<100;p++){
                if(m[i][p]==0){
                    break;
                }
                if(m[i][p]!=tar[itar]){
                    if(l[i][itar]==0){//no match target char
                        problem=1;
                        break;
                    }
                    itar++;
                    if(m[i][p]!=tar[itar]){
                        
                        problem=1;
                        break;
                    }
                    l[i][itar]++;
                }
                else{
                  l[i][itar]++;
                }
            }
            if(itar!=t_tar||problem==1){
                problem=1;
                break;
            }
        }
        if(problem==1){
            fout<<"Case #"<<j+1<<": Fegla Won\n";
            cout<<"Case #"<<j+1<<": Fegla Won\n";
            continue;
        }
        sum=0;
        for(p=0;p<100;p++){
            Fl.clear();
            for(i=0;i<R;i++){
                Fl.push_back(l[i][p]);
                //sum=sum+l[i][p];
            }
            sort(Fl.begin(),Fl.end());
            for(i=0;i<R;i++){
                sum=sum+abs(l[i][p]-Fl[R/2]);
            }
        }
        
                
        fout<<"Case #"<<j+1<<": "<<sum<<"\n";
        cout<<"Case #"<<j+1<<": "<<sum<<"\n";

    }
    fin.close();
    fout.close();
    // insert code here...
   // std::cout << "Hello, World!\n";
    return 1;
}


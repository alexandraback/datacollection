#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
#include<iomanip>

int main(int argc,char* argv[]){
    if(argc!=2){
        std::cerr<<"filename missing\n";
        return 1;
    }
    std::ifstream ifs(argv[1]);
    std::ofstream ofs("output.txt");
    std::string str;
    int T;
    ifs>>T;
    for(int CASE=0;CASE++<T;){
        int n;
        std::cout<<"Solving Case "<<CASE<<"...\n";
        std::vector<char> map;
        std::vector< std::vector<int> > counts;
        ifs>>n;

        ifs>>str;

        int counter=1;
        std::vector<int> firstcount;
        map.push_back(str[0]);
        for(int i=1;i<str.size();i++){

            if(str[i]==map[map.size()-1]) counter++;
            else{
                firstcount.push_back(counter);
                map.push_back(str[i]);
                counter=1;
            }
        }
        firstcount.push_back(counter);
        counts.push_back(firstcount);
        std::cout<<firstcount.size()<<" "<<map.size()<<"\n";
        bool flag=false;
        
        for(int i=1;i<n;i++){
            ifs>>str;
            counter=0;
            std::vector<int> newcount;
            int pointer=0;
            for(int j=0;j<str.size();j++){
                if(str[j]==map[pointer]) counter++;
                else if(counter==0 || str[j]!=map[pointer+1]){
                    std::cout<<j<<" aa\n";
                    flag=true;
                    break;
                }else{
                    pointer++;
                    newcount.push_back(counter);
                    counter=1;
                }
            }
            if(pointer!=map.size()-1) flag=true;
            newcount.push_back(counter);
            counts.push_back(newcount);
        }
        if(flag){
            ofs<<"Case #"<<CASE<<": "<< "Fegla Won"<<"\n";
        }else{
            int ret=0;
            for(int i=0;i<map.size();i++){
                int maxx=0,minn=10000;
                std::cout<<n<<"\n";
                for(int j=0;j<n;j++){
                    std::cout<<counts[j][i]<<" ";
                    maxx=(maxx>counts[j][i]?maxx:counts[j][i]);
                    minn=(minn<counts[j][i]?minn:counts[j][i]);
                }
                std::cout<<maxx<<" "<<minn<<"\n";
                int tmpmin=1000000;
                for(int j=minn;j<=maxx;j++){
                    int tmp=0;
                    for(int k=0;k<n;k++){
                        tmp+=abs(counts[k][i]-j);
                    }
                    tmpmin=(tmpmin<tmp?tmpmin:tmp);
                }
                ret+=tmpmin;
            }
            ofs<<"Case #"<<CASE<<": "<< ret<<"\n";
        }
    }
    
    
    
    return 0;
}
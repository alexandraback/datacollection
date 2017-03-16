#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;

int main(){

    int tests;
    cin>>tests;
    for(int i=1;i<=tests;i++){
        int sum1=0;
        int sum2=0;
        int plates;
        cin>>plates;
        int * p= new int[plates];
        for(int j=0;j<plates;j++){
            cin>>p[j];
        }
        int max=0;
        //finding the sum of all downfall;
        for(int j=0;j<plates-1;j++){
            if(p[j]>p[j+1]){
                sum1+=p[j]-p[j+1];
                if(p[j]-p[j+1]>max){
                    max=p[j]-p[j+1];
                }
            }
        }
        for(int j=0;j<plates-2;j++){
            if(p[j]>=max)
                sum2+=max;
            else
                sum2+=p[j];
        }
        if(p[plates-2]>p[plates-1])
            sum2+=abs(p[plates-2]-p[plates-1]);
        cout<<"Case #"<<i<<": "<<sum1<<" "<<sum2<<endl;
    
    }

    return 0;

}

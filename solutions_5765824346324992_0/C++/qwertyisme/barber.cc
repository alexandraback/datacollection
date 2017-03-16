#include <vector>
#include <iostream>
using namespace std;

int gcd (int a, int b){
    int c;
    while (a!=0){
        c=a; 
        a=b%a;
        b=c;
  }
  return b;
}

int lcm(int a, int b){
    return (a/gcd(a,b))*b;
}

int lcmvec(vector<int> v){
    int i;
    int ret=1;
    for(unsigned int i=0;i<v.size();i++){
        ret=lcm(ret, v[i]);
    }
    return ret;
}

int main(){
    int t, bcount,place,temp;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> bcount >> place;
        int barbers[5]={0,0,0,0,0};
        vector<int> barbersvec;
        for(int ii=0;ii<bcount;ii++){
            cin >> temp;
            barbers[ii]=temp;
            barbersvec.push_back(temp);
        }

        //do lcm stuff
        int lcm=lcmvec(barbersvec);
        int group=0;
        
        for(unsigned int iit=0;iit<barbersvec.size();iit++){
            group=group+lcm/barbersvec[iit];
        }
        place=place%group;
        if(place==0){
            place=group;
        }
        //finish lcm stuff

        //initialized barbers array, now brute force lol
        int time=0;
        int position;

        //cout << "arryay is " << barbers[0] << "," << barbers[1];
        //cout  << "," << barbers[2];
        //cout << "," << barbers[3] << "," << barbers[4] << endl;    
        

        while(place>0){
            for(int j=0;j<5;j++){
                if(barbers[j]!=0 and time%barbers[j]==0){
                    place--;
                }
                if(place==0){
                    position=j+1;
          //          cout << "pos is " << position << endl;
                    break;
                }
            }
            time++;
        }
        cout << "Case #" << i+1 << ": " << position << endl;
    }
}

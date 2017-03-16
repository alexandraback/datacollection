//
//  main.cpp
//  B
//
//  Created by Zhou Sun on 4/11/14.
//  Copyright (c) 2014 Zhou Sun. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, const char * argv[])
{
    freopen("myfile1.txt","r",stdin);
    
    freopen("myfile.txt","w",stdout);
    int ts;
    cin>>ts;
    int k,x;

    for (int tt=0; tt<ts; tt++) {
        int a[20];
        memset(a, 0,sizeof(a));
        cin>>k;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                cin>>x;
                if (i+1==k) {
                    a[x]++;
                }
            }
        }
        cin>>k;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                cin>>x;
                if (i+1==k) {
                    a[x]++;
                }
            }
        }
        int r=0;
        for (int i=1;i<=16;i++) {
            if (a[i]==2) {
                if (!r) {
                    r=i;
                }
                else
                    r=-1;
            }
        }
        
        printf("Case #%d: ",tt+1);
        if (r==-1) {
            cout<<"Bad magician!\n";
        }
        else if(r==0){
            cout<<"Volunteer cheated!\n";
        }
        else
            cout<<r<<endl;
        
    }
    return 0;
}


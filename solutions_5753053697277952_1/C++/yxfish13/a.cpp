#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
int P[100];
int N;
char getMax(){
    int ans=0;
    for (int i=0;i<N;i++){
        if (P[i]>P[ans]) ans=i;
    }
    P[ans]--;
    return 'A'+ans;
}
void Sol(){
    cin>>N;
    int total=0;
    for (int i=0;i<N;i++) {scanf("%d",&P[i]);total+=P[i];}
    while (total!=0){
        printf(" ");
        if (total==3){
            total-=3;
            printf("%c",getMax());
            printf(" ");
            printf("%c",getMax());
            printf("%c",getMax());
        }else{
            total-=2;
            printf("%c",getMax());
            printf("%c",getMax());
        }
    }
    printf("\n");
}
int main(){
    int T;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    for (int datanum=1;datanum<=T;datanum++){
        printf("Case #%d:",datanum);
        Sol();
    }
    return 0;
}

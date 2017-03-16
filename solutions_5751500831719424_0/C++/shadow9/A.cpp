#include<cstdio>
#include<cstring>
#define ms(a,b) memset(a,b,sizeof(a))
int N;
char str[110][110];
char uni[110][110];

const int OO = 1000000000;

int getLen(int seg, int st);
int myAbs(int x){
    return (x>0)?x:-x;
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out", "w", stdout);
    int T, cnt = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        ms(uni, 0);
        for(int i = 0; i < N; i++){
            scanf("%s", str[i]);
            int len = strlen(str[i]);
            uni[i][0] = str[i][0];
            for(int j = 1, pt = 1; j < len; j++){
                if(uni[i][pt-1] != str[i][j]) uni[i][pt++] = str[i][j];
            }
        }
        bool sol = true;
        for(int i = 1; i < N && sol; i++){
            if(strcmp(uni[i], uni[0]) != 0) sol = false;
        }
        printf("Case #%d: ", ++cnt);
        if(!sol) printf("Fegla Won\n");
        else{
            int ans[110], mmin, curr;
            ms(ans,0);
            int seg = strlen(uni[0]);
            for(int i = 0; i < seg; i++){
                mmin = OO;
                for(int j = 0; j < N; j++){
                    curr = 0;
                    int tar = getLen(i,j);
//                    printf("len of seg %d from str %d = %d\n", i, j, tar);
                    for(int k = 0; k < N; k++){
                        int my = getLen(i,k);
                        curr += myAbs(tar-my);
                    }
                    if(curr < mmin) mmin = curr;
                }
                ans[i] = mmin;
            }
            int sum = 0;
            for(int i = 0; i < seg; i++) sum += ans[i];
            printf("%d\n", sum);
        }
    }
    return 0;
}

int getLen(int seg, int st){
    int currp = 1;
    int currs = 0;
    char currc = str[st][0];
    int len = 1;
    while(1){
        if(str[st][currp] != currc){
            currs++;
            currc = str[st][currp];
            if(currs > seg) break;
            len = 1;
        }
        else len++;
        currp++;
    }
    return len;
}

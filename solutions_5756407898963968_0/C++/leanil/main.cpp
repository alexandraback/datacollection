#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int t;
    FILE* fp(fopen("input.txt","r"));
    fscanf(fp,"%d",&t);
    FILE* out(fopen("output.txt","w"));
    for(int i=1;i<=t;i++) {
        int row;
        fscanf(fp,"%d",&row);
        int tmp;
        set<int> num1;
        for(int j=1;j<=4;j++) {
            for(int k=0;k<4;k++) {
                fscanf(fp,"%d",&tmp);
                if(j == row) {
                    num1.insert(tmp);
                }
            }
        }
        fscanf(fp,"%d",&row);
        set<int> num2;
        for(int j=1;j<=4;j++) {
            for(int k=0;k<4;k++) {
                fscanf(fp,"%d",&tmp);
                if(j == row) {
                    num2.insert(tmp);
                }
            }
        }
        set<int>::iterator it1 = num1.begin();
        set<int>::iterator it2 = num2.begin();
        int ki, db = 0;
        while(it1 != num1.end() && it2 != num2.end()) {
            if(*it1 < *it2) {
                it1++;
            }
            else if(*it1 > *it2) {
                it2++;
            }
            else if(*it1 == *it2) {
                ki = *it1;
                db++;
                it1++;
                it2++;
            }
        }
        fprintf(out,"Case #%d: ",i);
        if(db == 0) {
            fprintf(out,"Volunteer cheated!\n");
        }
        else if(db == 1) {
            fprintf(out,"%d\n",ki);
        }
        else {
            fprintf(out,"Bad magician!\n");
        }
    }
    return 0;
}

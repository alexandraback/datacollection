#include<fstream>
#include<set>
using namespace std;

ifstream fin("repeater.in");
ofstream fout("repeater.out");

int N, L;
string str[105];
string col[105];
int ct[105][105];

int main(){
    int T;
    fin >> T;
    for(int t=0; t<T; t++){
        fin >> N;
        
        memset(ct, 0, sizeof(ct));
        for(int i = 0; i<100; i++)
            col[i] = "";
        
        for(int i=0; i<N; i++){
            fin >> str[i];
            int idx = -1;
            for(int j=0; j<str[i].length(); j++){
                if(!j || str[i][j]!=str[i][j-1]){
                    col[i] += str[i][j];
                    idx++;
                }
                ct[i][idx]++;
            }
        }
        
        bool good = true;
        for(int i=1; i<N; i++)
            if(col[i] != col[0])
                good = false;
                
        int ans = 0;
        for(int i=0; i<col[0].length(); i++){
            int low = 1 << 25;
            for(int x = 1; x<=100; x++){
                int myc = 0;
                for(int j=0; j<N; j++)
                    myc += abs(x - ct[j][i]);
                low = min(low, myc);
            }
            ans += low;
        }

        fout << "Case #" << t+1 << ": ";
        if(!good) fout << "Fegla Won" << endl;
        else fout << ans << endl;
    }
}

#include <iostream>
#include <queue>
int M[10000][10000];
int MB[10000][10000];
using namespace std;


int mX[4] = {1, 0, -1, 0};
int mY[4] = {0, 1, 0, -1};

int dX[4] = {1, 1, -1, -1};
int dY[4] = {1, -1, 1, -1};
vector< pair<int, pair<int,int> > > max;
int y, x, n;

void printTable(){
    for(int i=0;i<y;++i){
        for(int j=0;j<x;++j)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

int MIN (int a, int b){
    return a<b?a:b;
}
//
//int run(int off){
//    for(int i=0;i<y;++i)
//        for(int j=0;j<x;++j){
//            M[i][j] = 0;
//            for(int moveC = 0;moveC<4;++moveC){
//                int ny = i + mY[moveC];
//                int nx = j + mX[moveC];
//                if(nx < 0 || ny < 0 || nx >= x || ny >=y)
//                    continue;
//                M[i][j]++;
//            }
//        }
//    
//    
//    // 1 i ayri handle et
//    queue< pair<int, int> > Q;
//    for(int i=1;i<x;i+=2){
//        int Y = y/2;
//        int X = i;
//        if(n == 0)
//            continue;
//        M[Y][X] = -1;
//        Q.push(make_pair(y/2, i));
//        for(int m = 0;m<4;++m){
//            int ny = Y + mY[m];
//            int nx = X + mX[m];
//            if(nx < 0 || ny < 0 || nx >= x || ny >=y)
//                continue;
//            M[ny][nx]--;
//        }
//        n--;
//    }
//    
//    while(!Q.empty()){
//        pair<int, int> p = Q.front();
//        cout << p .first << " " << p.second << endl;
//        Q.pop();
//        
//        if(n == 0)
//            continue;
//        
//        int Y = p.first;
//        int X = p.second;
//        
//        
//        
//        
//        int count = 0;
//        for(int m = 0;m<4;++m){
//            
//            max[m].first = -1;
//            int ny = Y + dY[m];
//            int nx = X + dX[m];
//            max[m].second.first = ny;
//            max[m].second.second = nx;
//            if(nx < 0 || ny < 0 || nx >= x || ny >=y || M[ny][nx] == -1)
//                continue;
//            max[m].first = M[ny][nx];
//        }
//        sort(max.begin(), max.end(), greater< pair<int,pair<int,int> > >());
//        
//        for(int i=0;i<4 && max[i].first!=-1 && n>0; ++i){
//            Q.push(max[i].second);
//            int Y =max[i].second.first;
//            int X =max[i].second.second;
//            M[Y][X] = -1;
//            n--;
//            for(int m = 0;m<4;++m){
//                int ny = Y + mY[m];
//                int nx = X + mX[m];
//                if(nx < 0 || ny < 0 || nx >= x || ny >=y)
//                    continue;
//                M[ny][nx]--;
//            }
//        }
//    }
//    
//    int total = 0;
//    for(int i=0;i<y;++i){
//        for(int j=0;j<x;++j){
//            if(M[i][j] >0)
//                total += M[i][j];
////            cout << M[i][j] << " ";
//        }
////        cout << endl;
//    }
//}

bool fill(int Y, int X){
    if(Y < 0 || X < 0 || Y >= y || X>=x)
        return false;
    if(M[Y][X] == -1)
        return false;
    M[Y][X] = -1;
    for(int m = 0;m<4;++m){
        int ny = Y + mY[m];
        int nx = X + mX[m];
        if(nx < 0 || ny < 0 || nx >= x || ny >=y)
            continue;
        M[ny][nx]--;
    }
    return true;
}


int run(int row, int off, int n){
    if(n == 0)
        return 0;
    if(row <0 || row >= y)
        return n;
    int center = x/2;
    for(int i=0;i<=x/2 && n!=0;i+=2){
        if(fill(row, center + off + i))
            n--;
        if(n!=0)
            if(fill(row, center - off - i))
                n--;
    }
    return n;
}



int main(){
    int T;
    cin >> T;
    
    
    

//    for(int i=0;i<4;++i)
//        max.push_back(make_pair(-1, make_pair(i, i)));
//    
    for(int t=1;t<=T;++t){

        cin >> y >> x >> n;
        n = y*x-n;
        

        
        if(y>x){
            int t = y;
            y = x;
            x = t;
        }
        for(int i=0;i<y;++i)
            for(int j=0;j<x;++j){
                M[i][j] = 0;
                for(int moveC = 0;moveC<4;++moveC){
                    int ny = i + mY[moveC];
                    int nx = j + mX[moveC];
                    if(nx < 0 || ny < 0 || nx >= x || ny >=y)
                        continue;
                    M[i][j]++;
                    MB[i][j]++;
                }
            }
        
        int total1 = 0, total2=0;
        int nn = n;
        int cen = y/2;
        nn = run (cen, 0, n);
        for(int i=1;i<=y/2;++i){
            nn = run(cen+i,(0+i)%2, nn );
            nn = run(cen-i,(0-i+2*y)%2,nn);
        }

        for(int i=0;i<y;++i)
            for(int j=0;j<x;++j){
                if(M[i][j] != -1)
                total1 += M[i][j];
                M[i][j] = MB[i][j];
            }


        nn = run(cen, 1, n);
        for(int i=1;i<=y/2;++i){
            nn = run(cen+i, (1+i)%2, nn);
            nn = run(cen-i,(1-i+2*y)%2,nn);
        }
        
        for(int i=0;i<y;++i)
            for(int j=0;j<x;++j){
                if(M[i][j] != -1)
                total2 += M[i][j];
            }
        
        cout <<"Case #" << t << ": "<< MIN(total1, total2)/2 << endl;
    }
    return 0;
}
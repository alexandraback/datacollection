#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>

#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define fl(a) fr( l, ( a ) )

using namespace std;
int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

int main()
{
    int i, j, k, l;
    int nbTestCases = 0;
    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("A-small-attempt0.out","w",stdout);
    cin >> nbTestCases;

    fi(nbTestCases) {
        int result = -1;
        int firstAnswer = ni();
        vector<int> answers1;
        fj(4) {
            if (j+1 == firstAnswer) {
                fk(4)
                    answers1.push_back(ni());
            }
            else {
                fk(4)
                    ni();
            }
        }
        int secondAnswer = ni();
        fj(4) {
            if (j+1 == secondAnswer) {
                int answCount = 0;
                fk(4) {
                    int answ = ni();
                    fl(4) {
                        if (answers1[l] == answ) {
                            result = answ;
                            answCount++;
                        }
                    }
                    if (answCount > 1)
                        result = -2;
                }
            }
            else {
                fk(4)
                    ni();
            }
        }

        cout << "Case #" << i+1 << ": ";
        if (result == -2)
            cout << "Bad magician!" << endl;
        else if (result == -1)
            cout << "Volunteer cheated!" << endl;
        else
            cout << result << endl;

    }
    return 0;
}

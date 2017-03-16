#include <cstdio>
#include <cstring>

using namespace std;

const int COLS = 4;
const int ROWS = 4;
const int QUESTIONS = 2;
const int MAX_CARD = COLS*ROWS;
bool used[MAX_CARD+1];


int main(){

    freopen ( "A-small-attempt0.in", "r", stdin );
    freopen ( "A-small-attempt0.out", "w", stdout );

    int t;
    scanf ( "%d ", &t );
    for ( int testcase = 1; testcase <= t; ++testcase ){
        memset ( used+1, true, sizeof ( bool ) * MAX_CARD );
        for ( int question = 0; question < QUESTIONS; ++question ){
            int chosen_row;
            scanf ( "%d ", &chosen_row );
            for ( int row = 1; row <= ROWS; ++row ){
                for ( int col = 1; col <= COLS; ++col ){
                    int card;
                    scanf ( "%d ", &card );
                    if ( row != chosen_row ){
                        used[card] = false;
                    }
                }
            }
        }

        int chosen_card = false;
        bool bad_magician = false;
        for ( int card = 1; card <= MAX_CARD && !bad_magician; ++card ){
            if ( used[card] ){
                if ( chosen_card ){
                    bad_magician = true;
                } else {
                    chosen_card = card;
                }
            }
        }

        if ( !chosen_card ){
            printf ( "Case #%d: Volunteer cheated!\n", testcase );
            continue;
        }
        if ( bad_magician ){
            printf ( "Case #%d: Bad magician!\n", testcase );
            continue;
        }
        printf ( "Case #%d: %d\n", testcase, chosen_card );
    }


    return 0;
}

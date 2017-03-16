#include <cstdio>

int findMajority(int a[], int n ) {
    int x = -1 ;
    int s = 0 ;
    for ( int i = 0 ; i < n ; ++i ) {
        s += a[i];
    }
    for ( int i = 0 ; i < n ; ++i ) {
        if ( a[i]*2 > s) {
            return i;
        }
    }
    return -1;
}

void work() {
    int n  ;
    int a[26] = {0};

    scanf("%d",&n);

    int s = 0 ;
    for ( int i = 0 ; i < n ; ++i )  {
        scanf("%d",&a[i]);
        s += a[i] ;
    }

    for ( int i = 0 ; i < s ; ++i ) {
        int maxj = 0 ;
        for ( int j = 0 ; j < n ; ++j ) {
            if ( a[j] > a[maxj] )
                maxj = j ;
        }

        a[maxj] -- ;
        if ( i )
            printf(" ");

        printf("%c",'A'+maxj);

        int t = findMajority(a,n);
        if ( t != -1 ) {
            ++i;
            printf("%c",'A'+t);
            a[t]--;
        }

    }
    printf("\n");
}
int main() {
    int T ;
    scanf("%d",&T);
    for ( int i = 0 ; i < T ; ++i ) {
        printf("Case #%d: ",i+1);
        work();
    }
    return 0;
}

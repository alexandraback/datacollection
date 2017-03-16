#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int memoria[65536][16][257];

int R, C;

bool __ocupado[16][16];

bool ocupado(int r, int c) {
    if (r<0)
        return false;
    if (c<0)
        return false;
    if (r>=R)
        return false;
    if (c>=C)
        return false;
    return __ocupado[r][c];
}

int cuenta(int anterior, int col, int faltan);

int busca(int anterior, int actual, int col, int row, int faltan) {
    if (faltan==0)
    return 0;
    if (row==R)
        return cuenta(actual, col+1, faltan);
    int opcion = busca(anterior, actual, col, row+1, faltan);
    __ocupado[row][col] = true;
    int opcion2 = busca(anterior, actual | (1<<row), col, row+1, faltan-1);
    if (ocupado(row-1,col))
        opcion2++;
    if (ocupado(row,col-1))
        opcion2++;
    __ocupado[row][col] = false;
    if (opcion<opcion2)
        return opcion;
    return opcion2;
}

int cuenta(int anterior, int col, int faltan)
{
    if (faltan==0)
        return 0;
    if (((C-col)*R)<faltan) {
        return (R*(C+1)) + ((R+1)*C) + 10;
    }
    if (memoria[anterior][col][faltan]<0)
        memoria[anterior][col][faltan] = busca(anterior,0,col,0,faltan);
    return memoria[anterior][col][faltan];
}

int main()
{
    int T;
    int N;
    cin >> T;
    for (int t=1;t<=T;t++) {
        cin >> R;
        cin >> C;
        cin >> N;
        memset(memoria,-1,sizeof(memoria));
        printf("Case #%d: %d\n", t, cuenta(0,0,N));
    }
    return 0;
}

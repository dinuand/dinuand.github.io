#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAX_D 2000001

using namespace std;

unsigned long long d[2], w[MAX_D];

/** atentie la long long
 * daca trebuie sa facem operatii pe nr mari
 * exemplU: avem de inmultit 2*10^6 cu 2 * 10^6 =>
 * e mai ok decat sa facem cast, sa declaram toate variabilele
 * ce intra in calculul rezultatului de tipul long long
 */

int main()
{
    unsigned long long n, l, m;
    unsigned long long s, x, y, z, v;
    FILE *fdin = fopen("toys.in", "r");
    FILE *fdout = fopen("toys.out", "w");
    fscanf(fdin, "%llu%llu%llu", &n, &l, &m);
    fscanf(fdin, "%llu%llu%llu%llu%llu", &s, &x, &y, &z, &v);
    d[0] = s;
    w[1] = d[0] + l;
    int i;
    int lin = 0;
    for (i = 2; i <= n; i++, lin = 1 - lin) {
        d[1 - lin] = ( x * d[lin] + y * ( i - 1 ) ) % ( l - 1 ) + 1;
        int t = ( z * d[lin] + v * ( i - 1 ) ) % 2;
        if (t) w[i] = d[1 - lin] + l;
        else w[i] = l - d[1 - lin];
    }
    int mod = m % n;
    unsigned long long sol;
    if (mod == 0) {
        nth_element(w + 1, w + n, w + n + 1);
        sol = w[n] + (m / n) * 2 * l - l;
    } else {
        nth_element(w + 1, w + mod, w + n + 1);
        sol = w[mod] + (m / n) * 2 * l + l;
    }
    fprintf(fdout, "%llu\n", sol);
    fclose(fdin);
    fclose(fdout);
    return 0;
}
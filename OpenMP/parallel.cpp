#include <algorithm>
#include <omp.h>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <assert.h>

using namespace std;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ", ++ks);

#define mx 1002

int a[mx][mx];
int b[mx][mx];
int c[mx][mx];
int d[mx][mx];
void generate_matrix(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = rand() % 100;
            b[i][j] = rand() % 100;
        }
    }
}
void check(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            assert(c[i][j] == d[i][j]);
    }
}
void matrix_mult_serial(int n)
{
    int i, j, k;
    double st = omp_get_wtime();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    double en = omp_get_wtime();
    printf("Serial: %lf\n", en - st);
}
void matrix_mult_parallel(int n)
{
    // Static Scheduler
    memset(d, 0, sizeof d);
    int i, j, k;
    double st = omp_get_wtime();
#pragma omp parallel for schedule(static, 50) collapse(2) private(i, j, k) shared(a, b, c)
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                d[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    double en = omp_get_wtime();
    printf("Parallel-1(Static Scheduler) %lf\n", en - st);
    check(n);
}
int main()
{
    // READ("in");
    // WRITE("out2");
    int n = 500;
    generate_matrix(n);
    matrix_mult_serial(n);

    matrix_mult_parallel(n);

    return 0;
}


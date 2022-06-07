#include <cmath>
#include <ctime>
#include <iostream>
#define MAXN 101
#define MAXK 1e7
clock_t start, stop;
double duration;

double f1(int n, double a[], double x) {
    int i;
    double p = a[0];
    for (i = 1; i <= n; i++)
        p += a[i] * pow(x, i);
    return p;
}

double f2(int n, double a[], double x) {
    int i;
    double p = a[n];
    for (i = n; i > 0; i--)
        p += a[n - 1] + x * p;
    return p;
}

void fun_test(double fun(int n, double a[], double x), double a[]) {
    int i;
    start = clock();
    for (i = 0; i < MAXK; i++)
        fun(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start) / CLK_TCK) / MAXK;
    printf("tickes = %.2f\tduration = %6.2le\n", (double)(stop - start), duration);
}

int main() {
    double a[MAXN] = {(double)1};
    int i;
    for (i = 1; i < MAXN; i++)
        a[i] = (double)1 / (double)i;
    fun_test(f1, a);
    fun_test(f2, a);
    return 0;
}

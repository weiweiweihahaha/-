#include <iostream>
#include <ctime>
using namespace std;
const int n=524288;
float a[n];
void recursion(int x)
{
    if(x==1)
        return;
    else
    {
        for(int i=0;i<x/2;i++)
        {
            a[i]+=a[x-i-1];
        }
        x=x/2;
        recursion(x);
    }
}

int main() {
    double sum = 0.0;
    struct timespec start, end;

    // Initial setup
    for (int j = 0; j < n; j++) {
        a[j] = 1.3 * (n + 1);
    }

    long long time_ns = 0;

    for (int count = 0; count < 100; count++) {
        sum = 0.0;
        clock_gettime(CLOCK_MONOTONIC, &start); // Start time

        recursion(n);

        clock_gettime(CLOCK_MONOTONIC, &end); // End time

        // Calculate elapsed time in nanoseconds
        long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);

        time_ns += elapsed_ns;
    }

    // Convert total time to milliseconds and average
    double time_ms = static_cast<double>(time_ns) / 1000000.0 / 100.0;

    cout << "time: " << time_ms << " ms" << endl;

    return 0;
}

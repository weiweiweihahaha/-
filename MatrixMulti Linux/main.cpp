#include <iostream>
#include<sys/time.h>
using namespace std;

const int n = 4000;
double a[n];
double b[n][n];
double sum[n];

int main() {
    // Initialize
    struct timeval start, end;
    long long seconds, useconds;
    for (int k = 0; k < n; k++) {
        a[k] = k + 2.0;
        for (int r = 0; r < n; r++) {
            b[k][r] = (k + 1.1) + 2.0 * (r + 1.1);
        }
    }

    gettimeofday(&start, NULL);

    for (int i = 0; i < n; i++) {
        sum[i] = 0.0;
        for (int j = 0; j < n; j++) {
            sum[i] += b[j][i] * a[j];
        }
    }
    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    // 处理微秒部分可能产生的负数情况  
    if (useconds < 0) {
        --seconds;
        useconds += 1000000;
    }
    //double time_taken = double(end - start) / double(CLOCKS_PER_SEC) * 1000000;
    cout << "Time: " << seconds*1000000+useconds << " us" << endl;

    return 0;
}

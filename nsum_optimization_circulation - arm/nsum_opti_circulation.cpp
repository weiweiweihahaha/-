#include <iostream>
#include <ctime>
#include<cmath>
//#include <unistd.h> // For sleep function
using namespace std;
const int N = 524288;
float a[N];

int main() {
    float sum = 0.0;
    struct timespec start, end;

    // Initial setup
    for (int j = 0; j < N; j++) {
        a[j] = 1.3 * (j+ 1);
    }

    for(int cou=0;cou<11;cou++)
    {
         long long time_ns = 0;
         int times=pow(2,cou);

         int n=512*times;
      for (int count = 0; count < 100; count++) {
       // sum = 0.0;
        clock_gettime(CLOCK_MONOTONIC, &start); // Start time

       for (int m = n; m > 1; m /= 2) {
    int half_m = m / 2; // 计算一次 m/2 并重用结果
    for (int i = 0; i < half_m; ++i) {
        int index1 = i * 2;
        int index2 = index1 + 1;
        a[i] = a[index1] + a[index2]; // 直接使用计算好的索引
    }
}
        clock_gettime(CLOCK_MONOTONIC, &end); // End time

        // Calculate elapsed time in nanoseconds
        long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);

        time_ns += elapsed_ns;
    }

    // Convert total time to milliseconds and average
    double time_ms = static_cast<double>(time_ns) / 1000000.0 / 100.0;

    cout << n<<"  time: " << time_ms << " ms" << endl;

    }

    return 0;
}







//#include <iostream>
//#include <ctime>
//using namespace std;
//const int n=524288
//;
//float a[n];
//
//int main() {
//    float sum = 0.0;
//    struct timespec start, end;
//
//    // Initial setup
//    for (int j = 0; j < n; j++) {
//        a[j] = 1.3 * (n + 1);
//    }
//
//    long long time_ns = 0;
//
//    for (int count = 0; count < 100; count++) {
//        sum = 0.0;
//
//        clock_gettime(CLOCK_MONOTONIC, &start); // Start time
//
//       for(int m=n;m>1;m/=2)
//        {
//            for(int i=0;i<m/2;i++)
//            {
//                a[i]=a[i*2]+a[i*2+1];
//            }
//        }
//
//        clock_gettime(CLOCK_MONOTONIC, &end); // End time
//
//        // Calculate elapsed time in nanoseconds
//        long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
//
//        time_ns += elapsed_ns;
//    }
//
//    // Convert total time to milliseconds and average
//    double time_ms = static_cast<double>(time_ns) / 1000000.0 / 100.0;
//
//    cout << "time: " << time_ms << " ms" << endl;
//
//    return 0;
//}

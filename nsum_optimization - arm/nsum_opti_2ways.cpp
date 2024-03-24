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
       double sum1 = 0.0,sum2 = 0.0;//sum3 = 0.0,sum4 = 0.0,sum5 = 0.0,sum6 = 0.0,sum7 = 0.0,sum8 = 0.0;
        //double sum9 = 0.0,sum10 = 0.0,sum11 = 0.0,sum12 = 0.0,sum13 = 0.0,sum14 = 0.0,sum15 = 0.0,sum16 = 0.0;
       sum=0.0;
        clock_gettime(CLOCK_MONOTONIC, &start); // Start time

       for (int i = 0;i < n; i += 16)
         {
            sum1 += a[i];
            sum2 += a[i + 1];
//            sum3+=a[i+2];
//            sum4+=a[i+3];
//            sum5 += a[i+4];
//            sum6 += a[i + 5];
//            sum7+=a[i+6];
//            sum8+=a[i+7];
//            sum9 += a[i+8];
//            sum10 += a[i + 9];
//            sum11+=a[i+10];
//            sum12+=a[i+11];
//            sum13 += a[i+12];
//            sum14+= a[i + 13];
//            sum15+=a[i+14];
//            sum16+=a[i+15];
        }
         sum = sum1 + sum2;//+sum3+sum4+sum5 + sum6+sum7+sum8+sum9 + sum10+sum11+sum12+sum13 + sum14+sum15+sum16;

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


//int main() {
//    double sum = 0.0;
//    struct timespec start, end;
//
//     Initial setup
//    for (int j = 0; j < n; j++) {
//        a[j] = 1.3 * (n + 1);
//    }
//
//    long long time_ns = 0;
//
//    for (int count = 0; count < 100; count++) {
//       double sum1 = 0.0,sum2 = 0.0;
//       sum=0.0;
//        clock_gettime(CLOCK_MONOTONIC, &start); // Start time
//
//       for (int i = 0;i < n; i += 2)
//         {
//            sum1 += a[i];
//            sum2 += a[i + 1];
//        }
//         sum = sum1 + sum2;
//
//        clock_gettime(CLOCK_MONOTONIC, &end); // End time
//
//         Calculate elapsed time in nanoseconds
//        long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
//
//        time_ns += elapsed_ns;
//    }
//
//     Convert total time to milliseconds and average
//    double time_ms = static_cast<double>(time_ns) / 1000000.0 / 100.0;
//
//    cout << "time: " << time_ms << " ms" << endl;
//
//    return 0;
//}
//

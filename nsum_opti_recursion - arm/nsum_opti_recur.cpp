#include <iostream>
#include <ctime>
#include<cmath>
//#include <unistd.h> // For sleep function
using namespace std;
const int N = 524288;
float a[N];

  void recursion(int n){
 if (n == 1)return;
 else {
 for (int i = 0; i < (n / 2); i+=2) {
 a[i] += a[n - i - 1];
 a[i + 1] += a[n - i - 2 ];
 }
 n = (n+1) / 2;
 recursion(n);
 }
 }

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
        //sum = 0.0;
        clock_gettime(CLOCK_MONOTONIC, &start); // Start time

       recursion(n);

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
//#include <windows.h>
//using namespace std;
//const int n=524288;
//float a[n];
//void recursion(int x)
//{
//    if(x==1)
//        return;
//    else
//    {
//        for(int i=0;i<x/2;i++)
//        {
//            a[i]+=a[x-i-1];
//        }
//        x=x/2;
//        recursion(x);
//    }
//}
//
//int main()
//{
//
//    long long head=0.0, tail=0.0 , freq=0.0;// timers
//    long long time=0.0;
//    QueryPerformanceFrequency((LARGE_INTEGER *)&freq );
//    //initial
//    for(int j=0;j<n;j++)
//    {
//        a[j]=1.3*(n+1);
//    }
//
//    for(int count=0;count<100;count++)
//    {
//         head=0.0, tail=0.0;
//        // float sum1 = 0.0,sum2 = 0.0,sum=0.0;
//
//        QueryPerformanceCounter((LARGE_INTEGER *)&head);// start time
//
//       recursion(n);
//
//        QueryPerformanceCounter((LARGE_INTEGER *)&tail );// end time
//
//        time+=tail-head;
//    }
//
//
//
//   cout<<"time:"<<time*1000.0*0.01/(freq)<<"  ms"<<endl;
//
//    return 0;
//}
//
//

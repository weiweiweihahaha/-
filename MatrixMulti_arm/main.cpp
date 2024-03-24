#include <iostream>
#include <ctime>
using namespace std;
  const int N=10000;
  double a[N];
    double b[N][N];
    double sum[N];
int main()
{
    //float temp[100][100];
    //初始化
    for(int k=0;k<N;k++)
    {
        a[k]=k+2.0;
        for(int r=0;r<N;r++)
        {
            b[k][r]=(k+1.1)+2.0*(r+1.1);
        }
    }
 struct timespec start, end;

  //for(int cou=0;cou<10;cou++)
    //{
         long long time_ns = 0;
      //   int times=1000*cou;

         int n=7000;
      for (int count = 0; count < 20; count++)
        {

        clock_gettime(CLOCK_MONOTONIC, &start); // Start time

        for (int i = 0; i < n ;i++)
    {
        sum[i]=0.0;
        for (int j = 0; j < n; j++)
           {

            sum[i]+=b[j][i]*a[j] ;

           }




clock_gettime(CLOCK_MONOTONIC, &end); // End time

        // Calculate elapsed time in nanoseconds
        long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);

        time_ns += elapsed_ns;
    } }

    // Convert total time to milliseconds and average
    double time_ms = static_cast<double>(time_ns) / 1000000.0 / 100.0;

    cout << n<<"  time: " << time_ms << " ms" << endl;




//    long long head=0.0, tail=0.0 , freq=0.0; // timers
// QueryPerformanceFrequency((LARGE_INTEGER *)&freq );
// // start time
//
//QueryPerformanceCounter((LARGE_INTEGER *)&head);
//
//{
//    for (int i = 0; i < n ;i++)
//    {
//        sum[i]=0.0;
//        for (int j = 0; j < n; j++)
//           {
//
//            sum[i]+=b[j][i]*a[j] ;
//
//           }
//}
//
// }
//
//
// QueryPerformanceCounter((LARGE_INTEGER *)&tail );
// // end time
//
// cout<<"time:"<<(tail-head)*1000000.0/freq<<"  us"<<endl;

//    计时部分
//  LARGE_INTEGER start, end, freq;
//  QueryPerformanceFrequency(&freq); // 获取计数器的频率
//  QueryPerformanceCounter(&start); // 获取开始时的计数器值
//
//  for(int i=0;i<n;i++)
//  {
//      sum[i]=0;
//      for(int j=0;j<n;j++)
//      {
//
//          sum[i]+=b[j][i]*a[j];
//      }
//  }
//  QueryPerformanceCounter(&end); // 获取结束时的计数器值
//
// long double Time = (long double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
//  cout<<"该函数运行时间为："<<Time<<endl;
//  cout<<endl;
return 0;

}

#include <iostream>
#include <windows.h>
using namespace std;
  const int n=4000;
  double a[n];
    double b[n][n];
    double sum[n];
int main()
{
    //float temp[100][100];
    //初始化
    for(int k=0;k<n;k++)
    {
        a[k]=k+2.0;
        for(int r=0;r<n;r++)
        {
            b[k][r]=(k+1.1)+2.0*(r+1.1);
        }
    }



    long long head=0.0, tail=0.0 , freq=0.0; // timers
 QueryPerformanceFrequency((LARGE_INTEGER *)&freq );
 // start time

QueryPerformanceCounter((LARGE_INTEGER *)&head);

{
    for (int i = 0; i < n ;i++)
    {
        sum[i]=0.0;
        for (int j = 0; j < n; j++)
           {

            sum[i]+=b[j][i]*a[j] ;

           }
}

 }


 QueryPerformanceCounter((LARGE_INTEGER *)&tail );
 // end time

 cout<<"time:"<<(tail-head)*1000000.0/freq<<"  us"<<endl;

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

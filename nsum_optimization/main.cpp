#include <iostream>
#include <windows.h>
using namespace std;
const int n=524288;
float a[n];

int main()
{

    long long head=0.0, tail=0.0 , freq=0.0;// timers
    long long time=0.0;
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq );
    //initial
    for(int j=0;j<n;j++)
    {
        a[j]=1.3*(n+1);
    }

    for(int count=0;count<100;count++)
    {
         head=0.0, tail=0.0;
         float sum1 = 0.0,sum2 = 0.0,sum=0.0;

        QueryPerformanceCounter((LARGE_INTEGER *)&head);// start time

        for (int i = 0;i < n; i += 2)
         {
            sum1 += a[i];
            sum2 += a[i + 1];
        }
         sum = sum1 + sum2;
        QueryPerformanceCounter((LARGE_INTEGER *)&tail );// end time

        time+=tail-head;
    }



   cout<<"time:"<<time*1000.0*0.01/(freq)<<"  ms"<<endl;

    return 0;
}


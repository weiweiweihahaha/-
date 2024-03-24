#include <iostream>
#include <windows.h>
using namespace std;
const int n=524288;
float a[n];
void recursion(int x)
{
    if(x == 1)
        return;
    else if(x == 2)
    {
        a[0] += a[1];
        recursion(1);
    }
    else if(x == 3)
    {
        a[0] += a[2];
        a[1] += a[2];
        recursion(1);
    }
    else if(x == 4)
    {
        a[0] += a[3];
        a[1] += a[2];
        recursion(2); // 在这里，x被减半为2，我们可以直接调用处理x=2的情况
    }
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
        // float sum1 = 0.0,sum2 = 0.0,sum=0.0;

        QueryPerformanceCounter((LARGE_INTEGER *)&head);// start time

       recursion(n);

        QueryPerformanceCounter((LARGE_INTEGER *)&tail );// end time

        time+=tail-head;
    }



   cout<<"time:"<<time*1000.0*0.01/(freq)<<"  ms"<<endl;

    return 0;
}



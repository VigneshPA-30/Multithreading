#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Write a program with two worker classes that prints 1 to 100 and 100 to 1 concurrently without data corruption,
    when notified from the main.
    
    two worker classes are created and locked using unique lock, then conditional variable is used to make the threads 
    work on command.
    
*/

mutex mtx;
condition_variable cv;
bool ready = false;

void worker1(){
    unique_lock<mutex> lock(mtx);
    cv.wait(lock,[](){return true;});
   for(int i=1;i<=100;i++){cout<<i<<" ";}
   mtx.unlock();
}

void worker2(){
    unique_lock<mutex> lock(mtx);
    cv.wait(lock,[](){return true;});
    for(int i=100;i>=1;i--){cout<<i<<" ";}
    mtx.unlock();
}

int main()
{

     this_thread::sleep_for(chrono::milliseconds(2000));
      thread T1(worker1);
       thread T2(worker2);
     ready=true;
     cv.notify_all();

    return 0;
}

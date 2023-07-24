#include <iostream>
#include<bits/stdc++.h>
using namespace std;


/*
  Write a program to toggle a variable (0-1) for at frequency of 2Hz.

  calling a togglefunc in futureobject.
  */

bool toggleFunc(){
    bool toggle=false;
    this_thread::sleep_for(chrono::milliseconds(500));

    return toggle?false:true;
}
int main()
{

    int n;
    cout<<"enter no of times"<<endl;
    cin>>n;
    while(n!=0){
            n--;
    future<bool> fut=async(toggleFunc);

  
    cout<<endl;

    bool x=fut.get();
    cout<<x<<endl;

    }
}

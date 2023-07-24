#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Write a program that does ascending and descending of given vector concurrently using Mutex.
    
    calling functions for ascending and descending using thread function and locking the critical
    sections using uniquelock mutex.

*/


mutex m;
 vector<int> vec{9,4,2,7,8,3};

 void ascendingorder(){

unique_lock<mutex> guard (m);
cout<<"ascending:"<<endl;
    for(int i=0;i<vec.size()-1;i++){

        for(int j=i+1;j<vec.size();j++){
            if(vec[j]<vec[i]){

                    int temp=vec[i];
                vec[i]=vec[j];
            vec[j]=temp;
            }
        }
    }

    for(auto i:vec){
        cout<<i<<" ";
    }
m.unlock();
}


void descendingorder(){

  unique_lock<mutex> guard (m);
  cout<<"descending:"<<endl;
        for(int i=0;i<vec.size()-1;i++){

        for(int j=i+1;j<vec.size();j++){
            if(vec[j]>vec[i]){
                    int temp=vec[i];
                vec[i]=vec[j];
            vec[j]=temp;
            }
        }
    }

    for(auto i:vec){
        cout<<i<<" ";
    }
   // this_thread::sleep_for(chrono::seconds(1));
   m.unlock();
}



int main()
{

   thread th1(ascendingorder);
   thread th2(descendingorder);




   th1.join();
  th2.join();



    return 0;
}

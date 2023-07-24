#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    find factorial for two inputs concurrently while doing matrix multiplication concurrently.
    
    factorial of two inputs are called using future object and matrix multiplication is also done concurrently.
*/

mutex m;
int factorial(int n){
    //this_thread::sleep_for(chrono::milliseconds(100));
    return (n<=1)?1:n*factorial(n-1);

}

int main()
{
    future<int> fut1=async(factorial,5);
    future<int> fut2=async(factorial,6);



     vector<vector<int>> matrix_1={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix_2={{1,2,3},{4,5,6},{7,8,9}};
 vector<vector<int>> res_matrix(matrix_1.size(),vector<int>(matrix_2[0].size(),0));


      if(matrix_1[0].size() != matrix_2.size()){
         cout<<"Matrix cannot be multiplied";
         return 0;
      }






  for(int l1=0;l1<matrix_1.size();l1++){
      for(int l2=0;l2<matrix_2[0].size();l2++){
          for(int c=0;c<matrix_2.size();c++){

              res_matrix[l1][l2]+=(matrix_1[l1][c]*matrix_2[c][l2]);
          }
      }
  }


     for(auto &r:res_matrix){
      for(int c:r){
          cout<<c<<" ";
      }
      cout<<endl;
  }



    int x= fut1.get();
    int y= fut2.get();
    cout<<"factorial 1 is "<<x<<endl;
    cout<<"factorial 2 is "<<y;
    return 0;
}

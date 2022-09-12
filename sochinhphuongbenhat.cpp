/*
Số chính phương là số có thể biểu diễn bằng bình phương của một số. Ví dụ: 9=3^2, 16=4^2.

Cho số tự nhiên k (1 ≤ k ≤18). Hãy tìm số chính phương nhỏ nhất có k chữ số và mỗi chữ số của nó cũng là số chính phương.

Note: Số 0 là số chính phương.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

     int Square(int n) // hàm kiểm tra số chính phương
     {
          if ( n == 0) return 1;
          int square = sqrt(n);
          if (square * square == n) return 1;
          return 0;
     }
     ll Solve(int k)
     {
          ll first = pow(10, k - 1);
          ll last = pow(10, k) - 1;
          ll square;
          if (Square(first) == 1)
          {
               square = (ll)sqrt(first);
          }
          else
          {
               square = (ll)sqrt(first) + 1;
          }
          // square = sqrt(first) hoặc sqrt(first) + 1
          /*
               -----ví dụ-----
               first = 1000, last = 9999
               square = sqrt(first) + 1 = 32;
               32*32 <= 9999, chấp nhận vòng lặp
               tmp = 32*32 = 1024
               "2" không phải số chính phương -> check = false;
               square ++  = 32+1 = 33
               square * square = 33 * 33 <= 9999, tiếp tục vòng lặp đến khi nào tìm được check = true;
          */
          while(square * square <= last)
          {
               bool check = true;
               ll tmp = square * square;
               while(tmp > 0)
               {
                    if (!Square(tmp%10))
                    {
                         check = false;
                         break;
                    }
                    tmp/=10;
               }
               if (check == true)       return square*square;
               else                     square++;
          }
          return -1; 
     }
     int main()
     {
          int testcase;
          cin>>testcase;
          while(testcase--)
          {
               int k;
               cin>>k;
               if (k < 0 || k > 18)     cout<<"-1"<<endl;
               else if ( k == 1)        cout<<"0"<<endl;
               else if (k % 2 == 1)     cout<<(ll)pow(10,k-1)<<endl;
               else                     cout<<Solve(k)<<endl;    
          }
     }
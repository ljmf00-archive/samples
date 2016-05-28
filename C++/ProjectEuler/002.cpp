#include <iostream>
using namespace std;

int fibonacci(int n);

int main()
{
    int n=4000000, i = 0, c, num = 0;
    for ( c = 1 ; c <= n ; c++ )
   {
      if (fibonacci(i) >= 4000000) {
        break;
      }
      else
      {
          if(fibonacci(i)%2==0){
            num=num+fibonacci(i);
          }
      }
      i++;
   }
   cout << num;
    return 0;
}

int fibonacci(int n)
{
    if ( n == 0 )
        return 0;
    else if ( n == 1 )
        return 1;
    else
        return ( fibonacci(n-1) + fibonacci(n-2) );
}

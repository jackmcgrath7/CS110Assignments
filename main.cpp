#include <iostream>
#include <math.h>
#include <limits>
#include <sstream>
#include <string>
using namespace std;
int upperLimit;
int kthBack;
int validate(int &upperLimit, int &kthBack);
int findPrimes(int &upperLimit, int &kthBack);
int main()
{
    string strInput = " ";
    cout<<"Hello. Please enter an upper limit.\n";
     getline(cin, strInput);
     stringstream myStream(strInput);
     if ( (myStream >> upperLimit) ){
         cout<<"Please enter  an integer that is less than the upperLimit for the kth back.\n";
         getline(cin, strInput);
         stringstream myStream(strInput);
         if ( (myStream >> kthBack) ){
            int val = validate(upperLimit, kthBack);

            if (val){
                kthBack=findPrimes(upperLimit, kthBack);

            }
    cout<<"the answer is "<<kthBack<<".\nPress Enter.";
         }
     }
    return 0;
}
int validate (int &upperLimit, int &kthBack)
  {
    if (kthBack<upperLimit){
        return true;
    }
    else{
        return false;
    }
  }
int findPrimes (int &upperLimit, int &kthBack)
  {

  int primes [upperLimit]; //the first array, all numbers in the sequence are labelled true or false. true=prime, false=non-prime
  int i; //for the for loop
  int k; // for the second for loop, to find non-primes
  int d=0; //used to find which prime number the user requested
  int trueprimes[upperLimit]; //the array the primes are sent to
  primes[0]=false; // 0 and 1 are not primes, but the algorithm will treat them as such
  primes[1]=false;
        for (i = 2; i <= upperLimit; i++)
        {

          if (primes[i]!=1) {
              for (k = i * i; k <= upperLimit; k = k + i ) { //i*i so that the prime # itself is not counted as nonprime
                    primes[k] = 0;                       // k=k+i so add
                  }
                }
          if(primes[i]!=0){
                    primes[i]=1;
                    trueprimes[d]=i;
                    d++;
            }
        }
        d=d-kthBack;
  kthBack=trueprimes[d];
  return kthBack;
  }

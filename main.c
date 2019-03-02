/* mathStuff_xxxxxx.c

Roger Priebe and (Osaid Kadim)
cs1428 10/15/2007 (updated 3/24/09)
EE312  10/3/2018

Finish comments here
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number);



//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes (int n);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int  findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);
void RecursiveModFactor ( int number, int divisor);
bool RecursiveModCounter( int number, int divisor );
void Counter (int *count);
//******************  MAIN  *****************************
int Count=0;
int counter=1;


int main () {


    int testNum;

    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);

    if (isPrime(testNum))
        printf("%d is prime\n",testNum);
    else
        printf("%d is not prime.\n", testNum);

    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);

    printPrimes(testNum);

    printf("\n");

    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d",&testNum);

    printf("The %d Fibonacci number is : %d \n", testNum, findFibo(testNum));

    printf("\n");

    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);

    findFactors(testNum);

    return 0;
}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number) {
    int START_DIVISOR = 2; //HINT: You may want a helper function
    int count=0;
    if (number==2){ return true;}
    if (number==1){ return false;}
    int Remainder = number % START_DIVISOR;
    if (Remainder !=0) { count = RecursiveModCounter(number, START_DIVISOR);}
    else return false;
    if (count==true) {
      Count=0;
      return true;
    }
    Count=0;
    return false;


}


//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes (int n) {
    if (counter <= n) {
        if (isPrime(counter)) {
          if (counter>2) { printf(",%d", counter);}
          else  printf("%d", counter);
        }
        Counter(&counter);
        printPrimes(n);
    }
}





//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {
    if (n==0||n==1) {
        return n; }
    else {
        return (findFibo(n-1)+findFibo(n-2));
    }
}




//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) {
    const int START_DIVISOR = 2;
    if (isPrime(number)) {
        printf("%d=prime", number);
        return;
    }
    printf("%d=1", number);
    RecursiveModFactor(number,START_DIVISOR);
}


bool RecursiveModCounter ( int number, int divisor) {
    int remainder;
    divisor++;
    remainder=number%divisor;
    if (remainder==0) {
        Count++;}
    if (divisor < number){
        RecursiveModCounter(number,divisor);}
    if (Count > 1) {
        return false;
    }
    else return true;

}


void RecursiveModFactor ( int number, int divisor) {
    int remainder;
    if (divisor <= number) {
        remainder=number%divisor;
        if (remainder == 0) {
            printf("*%d", divisor);
             }
        else divisor++;
      if (remainder==0) RecursiveModFactor(number/divisor,divisor);
      else RecursiveModFactor(number,divisor);
    }
}


void Counter (int *count){
  (*count)++;
}
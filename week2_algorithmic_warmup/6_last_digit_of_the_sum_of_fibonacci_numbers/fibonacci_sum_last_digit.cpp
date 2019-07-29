#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int last_digit_fibonacci_fast(int n) {
    if( n <= 1)
        return n;
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2; i<=n; ++i){
        fib[i] = (fib[i-1] + fib[i-2]) % 10; //find the last digit of nth fib numbers = n mod 10 
    }
    return fib[n] % 10;
}

long long sum_fib_fast(long long n){
    if( n <= 1)
        return n;
    const int PisanoPeriod = 60;
    // sum of 1st Fib numbers up to nth is equal to F(n+2) - 1
    long long r = (n + 2) % PisanoPeriod;
    long long last = last_digit_fibonacci_fast(r);
    if(last == 0)
        return 9;
    else{
        return last%10 - 1;
    }
}


int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n);
    std::cout << sum_fib_fast(n);
}

//reference 
//http://thisthread.blogspot.com/2018/02/last-digit-of-sum-of-fibonacci-numbers.html
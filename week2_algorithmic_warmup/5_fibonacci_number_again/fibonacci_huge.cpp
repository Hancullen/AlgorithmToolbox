#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    }

    return current ;
}
long long find_period(long long m){
    long long pre=0, cur=1;
    for (int i = 0; i < m * m; i++)
    {
        long long tmp = pre;
        pre = cur;
        cur = (tmp + cur) % m;

        if (pre == 0 && cur == 1)
            return i + 1;
    }
    return 0;
}

long long get_fib_fast(long long n, long long m){
    if( n <= 1)
        return n;
    // find remainder when n is devided by period 
    long long r = n % find_period(m);
    return get_fibonacci_huge_naive(r, m);
 
}
int main() {
    long long n, m;
    std::cin >> n >> m;

    // // testing find period
    // for(int i=0; i<= 48; ++i){
    //     std::cout << find_period(i) << '\n';
    // }
    
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fib_fast(n, m) << '\n';

}

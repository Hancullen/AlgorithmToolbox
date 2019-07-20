#include <iostream>
#include <cassert>
#include <cstdlib>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

long long get_last_digit_fast(int n){
    if(n <= 1)
        return n;
    //for saving memory space, dont necessary need an array
    long long pre = 0, current = 1, i;
    long long result; 
    for (i = 0; i < n-1; i++){
        long long tmp_pre = pre % 10;
        pre = current % 10;
        current = tmp_pre + current % 10;
        result = current % 10;
    }
    return result;
}

void test_solution() {
    int n = rand() % 100; 
    for (int i = 0; i < n; ++n)
        assert(get_fibonacci_last_digit_naive(i) == get_last_digit_fast(i) && "Oops bug needs to be fixed");
}

int main() {
    // test_solution();
    int n;
    std::cin >> n;
    int c = get_last_digit_fast(n);
    std::cout << c << '\n';
    }

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
// Optimal sequence from 1 to n.
// You are given a primitive calculator that can perform the following three
//     operations with the current number x:
//     * multiply x by 2
//     * multiply x by 3
//     * add 1 to x
//     Your goal is given a positive integer n, find the minimum number of
//     operations needed to obtain the number n starting from the number 1.

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;

  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dp_sequence(int n){
  std::vector<int> sequence;
  std::vector<int> a(n + 1); //store the minimum number of steps to reduce n to 1
  for (int i = 1; i < a.size(); i++){
    a[i] = a[i - 1] + 1;
    if (i % 2 == 0)
      a[i] = std::min(1 + a[i / 2], a[i]);
    if (i % 3 == 0)
      a[i] = std::min(1 + a[i / 3], a[i]);
  }
  std::cout << a[n] << '\n';

  // backtracking the number leading to n
  int i = n;
  while (i > 1){
    sequence.push_back(i);
    if (a[i - 1] == a[i] - 1)
      i = i - 1;
    else if (i % 2 == 0 && (a[i / 2] == a[i] - 1))
      i = i / 2;
    else if (i % 3 == 0 && (a[i / 3] == a[i] - 1))
      i = i / 3;
  }

  sequence.push_back(1);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = dp_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  // const clock_t begin_time = clock();
  // dp_sequence(n);
  // const clock_t end_time = clock();
  // std::cout << "\n Time used: " << (float)(end_time - begin_time) / CLOCKS_PER_SEC << '\n';
}

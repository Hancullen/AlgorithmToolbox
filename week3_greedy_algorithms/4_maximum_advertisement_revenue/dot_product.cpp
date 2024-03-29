#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;
  std::sort(a.begin(), a.end(), std::greater<int>());
  // for(int i=0; i< a.size(); i++){
  //   std::cout << a[i]  << '\t';
  // }
  // std::cout << '\n';
  std::sort(b.begin(), b.end(), std::greater<int>());
  // for(int i=0; i< b.size(); i++){
  //   std::cout << b[i] << '\t';
  // }
  // std::cout << '\n';
  for (size_t i = 0; i < a.size(); i++) { //be carefull when to use operator " < " or " <="
      result += ((long long) a[i]) * b[i];
    }

  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
  return 0;
}

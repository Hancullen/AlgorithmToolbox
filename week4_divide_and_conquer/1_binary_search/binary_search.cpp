#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0;
  int  right = (int)a.size() - 1; //right or high need to be initialized as (array size -1)  
  while(left <= right){
    int mid = left + (right - left)/2;
      if(x == a[mid])
        return mid;
      else if(x < a[mid])
        right = mid - 1;
      else
        left = mid + 1;
  }
  return -1;
}



int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

void stress_test(){
  int n = rand() % 20 + 1;
  int m = rand() % 20 + 1;
  
  vector<int> a;
  for(int i=0; i<= n; i++){
    a.push_back(rand() % 100);
  }

  vector<int> b;
    for(int i=0; i<= m; i++){
      b.push_back(rand() % 100);
    }
  for(int i=0; i < m; i++){
    assert(linear_search(a, b[i]) == binary_search(a, b[i]) && "Oops bugs");
  }
}

int main() {
  // stress_test();
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  sort(a.begin(), a.end()); // sort a[] if it's not sorted 

  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(a, b[i]) << ' ';
    // std::cout << linear_search(a, b[i]) << ' ';
  }
}

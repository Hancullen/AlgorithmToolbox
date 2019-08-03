#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cout;
//The naive algorithm will take O(n*n) time
//The second divide and conquer algorithm will take O(nlogn) time
//This problem still have another solution which will take O(n) time

int get_majority_element_naive(vector<int> &a, int left, int right) {
  right = (int)a.size() - 1;
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  int max_count = 0;
  for(int i = left; i < right; ++i){
    int count = 0;
    for(int j = left; j < right; j++){
      if(a[i] == a[j])
        count++;
    }
    if(count > max_count){
      max_count = count;
    }
  }
  if(max_count > right/2)
    return 1;
  return -1;
}

int get_majority_fast(vector<int> &a, int left, int right){
  if(left == right)
    return -1;
  if(left+1 == right)
    return a[left];
  cout << "left: " << left << "\t - right: " << right << '\n';
  int k = (left + right - 1) /2 + 1;
  cout << "k is: " << k << '\n';
  int left_major = get_majority_fast(a, left, k);
  int right_major = get_majority_fast(a, k, right);
  cout <<" Left major " << left_major << '\n';
  cout <<" Right major " << right_major << '\n';
  if(left_major == right_major)
    return left_major;
  //find occurences of majority element on the left side
  int left_count = 0;
  for(int i=left; i < right; i++){
    if(a[i] == left_major){
      left_count += 1;
      cout <<" left major " << a[i] << '\n';
      cout <<" left count " << left_count << '\n';
    }
      
    cout <<" a[" << i << "]" << "\tLeft count: " << left_count << '\n';

  }
  cout << "(right - left)/2 = "<< (right-left)/2 << '\n';
  if(left_count > (right-left)/2)
    return left_major;
  
  //find occurences of majority element on the right side
  int right_count = 0;
  for(int i=left; i < right; i++){
    if(a[i] == right_major){
      right_count += 1;
      cout <<" right major " << a[i] << '\n';
      cout <<" right count " << right_count << '\n';
    }
      
  }
  if (right_count > (right-left)/2)
    return right_major;
  
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // cout << (get_majority_element_naive(a, 0, a.size()) != -1) << '\n';
  cout << (get_majority_fast(a, 0, a.size()) != -1) << '\n';
}

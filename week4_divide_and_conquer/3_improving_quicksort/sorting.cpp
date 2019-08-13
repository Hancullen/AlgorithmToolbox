#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

//This 2-way partition will take O(n*n) time 
int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      // std::cout << "j: " << j << '\n';
      // std::cout << "a[" << i << "]: "<< a[i] <<'\n'; 
      swap(a[i], a[j]);
      // std::cout << "after swapping a[" << i << "]: " << a[i] << '\n';
      // std::cout << "after swapping a[" << j << "]: " << a[j] << '\n';
    }
  }
  swap(a[l], a[j]);
  return j;
}

//This new 3-way partition will take O(nlogn) time
int partition_new(vector<int> &a, int left, int right){
  // int start = a[left];
  // for(int i=start; i<right; i++){
  //   if(a[i] <= pivot){
  //     swap(a[i], a[left]);
  //     left++;
  //   } 
  // }
  // swap(a[left], pivot);
  int x = a[left];
  int i = left;
  int j = right;
  std::cout <<" i = " << i << '\n';
  while(1){
    //pivot is poiting at left 
    while(a[i] <= a[right] && i != right){
      right--;
    }
    if(i == j) //both left and right point at the same element
      break;

    else if(a[i] > a[j]) //pivot >= right element, swap pivot and that right element
      swap(a[j], a[i]);

    //pivot is now pointing at right
    while(a[i] >= a[left] && i != left){
      left++;
    }

    if(i == j){
      break;
    }

    else if(a[i] < a[j])
      swap(a[i], a[j]);
  }
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1); //pick pivot randomly
  swap(a[l], a[k]); //place random pivot at the beginning
  // int m = partition2(a, l, r);
  int m = partition_new(a, l, r);
  // std::cout << "m = " << m << '\n';

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // partition_new(a, 0, a.size()-1);
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}


//ref 
//https://www.dyclassroom.com/sorting-algorithm/quick-sort
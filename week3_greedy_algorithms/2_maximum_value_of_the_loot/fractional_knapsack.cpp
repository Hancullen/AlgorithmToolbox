#include <iostream>
#include <vector>
#include <algorithm>
// #include <iomanip>

using std::vector;

// get index of the item in the list whose value is the highest
int get_max_value(vector<int> w, vector<int> v){
  int max_index = 0;
  double max_value = 0.0;
  for(int i=0; i<= w.size(); ++i){
    if(w[i] > 0 && ((double)v[i]/w[i] > max_value)){
      max_value = (double) v[i]/w[i];
      max_index = i;
    } 
  }
  return max_index; //return index = position of items
}

double get_optimal_value(int capacity, vector<int>& weights, vector<int>& values) {
  double value = 0.0;

  for(int i=0; i <= weights.size(); ++i){
      if(capacity == 0) 
        return value;
      else{
        int index = get_max_value(weights, values); // get the position of item
        //check if the weight of that item is still within capacity and take allowance kg of that item
        int amount = std::min(capacity, weights[index]);
        value += amount * (double) values[index]/weights[index];
        capacity -= amount; //remaining of the capacity
        weights[index] -= amount; //remaining of the item
      }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10); //std::cout << std::setprecision(5) << optimal_value << '\n';
  std::cout << optimal_value << std::endl;
  return 0;
}

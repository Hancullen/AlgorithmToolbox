#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::vector;

double get_optimal_value(int capacity, vector<int>& weights, vector<int>& values) {
  int v = values.size();
  int w = weights.size();
  double value_per_unit = 0.0;
  int backpack[v][w];
  for(int i=0; i <= v; ++i){
    // value_per_unit = values[i]/weights[i];
    for(int j=0; j <= capacity; ++j){

      if((i == 0) || j == 0) //base case(when backpack is full)
        return 0;
      else if(weights[i] <= j){
        backpack[i][j] = std::max(values[i]+backpack[i-1][j-weights[i]], backpack[i-1][j]);
      }
      else{
        backpack[i][j] = backpack[i+1][j];
      }
      return backpack[i][j];
    }
  }
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

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
const int INF = 100000;

using std::vector;

int get_change(int m) {
  int denominations[] = {0, 1, 3, 4};
  int min_coins[m+1]; //stored minimum number of coins needed for each value
  min_coins[0] = 0; //0 euro needs 0 coin

  for(int i=1; i <= m; i++){
    int min = INF;

    for(int j=1; j < sizeof(denominations)/sizeof(denominations[1]); j++){
      if(i >= denominations[j]) //if the value to be made is greater than the denomiantions, then we can use this coin of denominations
        min = std::min(min, 1 + min_coins[i-denominations[j]]); 
    }
    min_coins[i] = min; // save the minimum coins needed for each value 
  }

  return min_coins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}


//ref
//https://www.codesdope.com/course/algorithms-coin-change/
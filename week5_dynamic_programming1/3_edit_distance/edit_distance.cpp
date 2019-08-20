#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

// Given 2 strings and edit operations, write an algorithm to find minimum 
// number operations to convert str1 to str2.
// Allowed operations: - Insert 
//                     - Delete 
//                     - Replace/Modify

//naive approach, time complexity: O(3^n)
int naive_distance(const string &str1, const string &str2, int m, int n){
  // int m = str1.size();
  // int n = str2.size();
  int cost = 0;

  //base case
  if(m == 0)
    return n;
  if(n == 0)
    return m;
  
  if(str1[m-1] == str2[n-1])
    cost = 0;
  else
    cost = 1;
  return std::min(std::min(naive_distance(str1,str2, m, n-1), naive_distance(str1,str2, m-1, n)) + 1, naive_distance(str1, str2, m-1, n-1)+cost);
}

//Time complexity: O(mn)
int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int m = str1.size();
  int n = str2.size();
  
  //store solutions into an array to make sure each sub-problem will be solved only once
  vector<vector<int> > dp(m + 1, vector<int>(n + 1)); // plus 1 in case of insertion
  
  //base case. If one of the strings is empty then number of operations needed is 
  //equal to the length of other string.
  //either all character will be removed or inserted
  for(int i=0; i <= m; i++){
    dp[0][i] = i; //all elements will be inserted
  }

  for(int i=0; i <= n; i++){
    dp[i][0] = i; // all elements will be removed
  }
  int cost = 0;
  //solving bottom-up
  for(int i=1; i <= m; i++){
    for(int j=1; j <= n; j++){
      //if last characters are matching, ignore them
      //and the solution will be the same as without those last characters
      if(str1[i-1] == str2[j-1])
        cost = 0;
      else
        cost = 1;
      dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]) + 1, dp[i-1][j-1] + cost); 
            // deletetion: dp[i-1][j] + 1;
            // insertion: dp[i][j+1] + 1;
            // substitution: dp[i-1][j-1] + cost;
      
    }
  }
  return dp[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  
  //check time consumed
  const clock_t begin_time = clock();
  // edit_distance(str1, str2);
  naive_distance(str1, str2, str1.size(), str2.size());
  const clock_t end_time = clock();
  std::cout << "\n Time used: " << (float)(end_time - begin_time) / CLOCKS_PER_SEC << '\n';
  return 0;
}


//ref
//https://en.wikipedia.org/wiki/Levenshtein_distance
//https://medium.com/@ethannam/understanding-the-levenshtein-distance-equation-for-beginners-c4285a5604f0
//https://algorithms.tutorialhorizon.com/dynamic-programming-edit-distance-problem/
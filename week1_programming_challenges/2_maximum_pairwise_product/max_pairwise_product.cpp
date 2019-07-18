#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                ((long long)numbers[first]) * numbers[second]);
        }
    }
    return max_product;
}

long long MaxProductFaster(const vector<int>& numbers){
    int n = numbers.size();
    //find first max number
    int max = -1;
    for(int i=0; i<n; ++i){
        if((max == -1) || (numbers[i] > numbers[max]))
            max = i;
    }
    //find the second one
    int max2 = -1;
    for(int j=0; j<n; ++j){
        if((j != max) && ((max2 == -1) || numbers[j] > numbers[max2]))
            max2 = j;
    }
    // cout<< numbers[max] << '\t' << numbers[max2]<< '\n';
    return ((long long)numbers[max])*numbers[max2]; 
}

int main() {
    //doing stress test
    // while (true)
    // {
    //     int n = rand() % 100 + 2; // generate a random number, then add 2 to it
    //     cout << "Size of array: "<< n << '\n'; 
    //     vector<int> a;
    //     for(int i=0; i<n; ++i){
    //         a.push_back(rand() % 10000); // inset value at the end of vector
    //     }
    //     for(int i=0; i<n; ++i){
    //         cout << a[i] << ' '; 
    //     }
    //     cout<< '\n';
    //     long long res1 = MaxPairwiseProduct(a);
    //     long long res2 = MaxProductFaster(a);
    //     if(res1 != res2)
    //     {
    //         cout<<"Wrong answer: "<< res1 << " is not equal to " << res2 << '\n';
    //         break;
    //     }
    //     else
    //     {
    //         cout<<"Testing passed\n";
    //     }
    // }
    
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    cout << MaxProductFaster(numbers) << "\n";
    
    //try with an array size 10000 of number 0
    // long long result = MaxProductFaster(vector<int>(10000, 0));
    // cout << result << "\n";

    return 0;
}

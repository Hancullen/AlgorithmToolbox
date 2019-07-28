#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
// using std::max;

int compute_min_refills(int dist, int miles_with_fulltank, vector<int> & stops) {
    int num_refill = 0;
    int current_refill = 0;
    int pre_refill=0;
    int n = stops.size();

    // No need to refill the tank if d between A and B is less than the miles that car can travel with full tank 
    if(dist <= miles_with_fulltank) return 0;

    while(current_refill < (n - 1)){
        pre_refill = current_refill; 
        while((current_refill < n) && (stops[current_refill + 1] - stops[pre_refill]) <= miles_with_fulltank){
            // pre_refill = current_refill;

            current_refill ++;
            if(current_refill == (n - 1))
                break;

            // cout << " Inner loop: previous refill " << pre_refill << '\n';  
            // cout << " Inner loop: current refill " << current_refill << '\n';  
           
        }

        if((dist - stops[current_refill]) > miles_with_fulltank) //check if the next station is too far away to reach even with full tank
            return -1; 
        // if(current_refill == pre_refill) 
        //     return -1;

        if(current_refill <= (n-1))
            num_refill ++;        
        
        // cout << " Outer loop: current refill "<< current_refill << '\n';
        // cout << " num refill: " << num_refill << '\n';
    }

    return num_refill;
}


int main() {
    int d = 0; //distance between A and B
    cin >> d;
    int m = 0; //number of miles that car can travel with full tank of fuel
    cin >> m;
    int n = 0; //number of gas stations on the way
    cin >> n;

    vector<int> stops(n); //get the position of each gas station
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

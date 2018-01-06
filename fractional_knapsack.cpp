
// Fractional Napsack Problem
//
// This program returns the most valuable combination 
// of items assuming that any fraction of a loot item
// can be put into the bag.



#include <iostream>
#include <vector>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  //loop through whole set of items or until capacity reaches zero
  for(int i = 0; i < weights.size();i++) {
  	if(capacity == 0) {
  		return value;
  	}
  	//initialize index of best value/weight ratio item
  	int best_index = 0; 
  	double best_ratio = 0;
  	//find best value/weight ratio item
  	for(int i = 0; i < weights.size();i++) {
  		double ratio = values[i]/((double)weights[i]);
  		if(weights[i] > 0 && ratio > best_ratio) {
  			best_index = i;
  			best_ratio = ratio;
  		}
  	}
  	//take all of best item if there is enough room, or
  	//take enough to fill bag
  	int take_amt = min(weights[best_index],capacity);
  	//increment total value, available weight of item, and bag capacity
  	value += (take_amt*best_ratio);
  	weights[best_index] -= take_amt;
  	capacity -= take_amt;
  }
  return value;
}

int main() {
  int n;          //number of loot items
  int capacity;   //weight capacity of bag
  cin >> n >> capacity;
  vector<int> values(n); //vector of item values
  vector<int> weights(n);  //vector of item weights
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}

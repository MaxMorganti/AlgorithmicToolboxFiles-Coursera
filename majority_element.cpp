#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



// Algorithm to check for a majority element. A naive 
// alg. doing linear scans for each element runs in time
// O(n^2); this one recursively divides the array in half
// and tests candidate elements on the smaller subarrays by
// using the concept that if the full sequence contains a
// majority element, one of the halves will as well. Poor
// candidates can be ruled out early and the algorithm can
// run in time O(n*log(n)).

// Returns 1 if a majority is present, and 0 otherwise.


int get_majority_element(vector<int> &a, int left, int right) {

	//return if subarray is size 1 or 2
	if (left == right) {
		return a[left];
	}
	if (left + 1 == right) {
		return a[left];
	}  
	
	//divide the array in two and make recursive calls
	//on each half
	//these will return two candidate values to check
	//on whole subarray
	int mid = left + ((right-left)/2);
	int check_one = get_majority_element(a, left, mid-1);
	int check_two = get_majority_element(a, mid, right);
	
	
	int count_one = 0;
	int count_two = 0;
	for(int i = left; i <= right; i++) {
		if(a[i]==check_one) {
			count_one++;
		}
		else if(a[i]==check_two) {
			count_two++;
		}
	}
	
	//If a majority is found in either element, and the 
	//full array is being checked, a 1 is returned.
	//The element is returned if only a subarray is
	//being checked.
	if(count_one > ((right-left+1)/2)) {
		if((right-left)==(a.size()-1)) {
			return 1;
		}
		return check_one;
	}
	if(count_two > ((right-left+1)/2)) {
		if((right-left)==(a.size()-1)) {
			return 1;
		}
		return check_two;
	}
    return 0;
}


int main() {
  int n;
  cin >> n; //size of array
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  
  //special cases for a small arrays
  if(a.size() == 1) {
  	//not defined for this length
  	cout << -1;
  	return 0;
  }
  if(a.size() == 2) {
  	if(a[0]==a[1]) {
  		cout << 1;
  		return 0;
  	}
  	cout << 0;
  	return 0;
  }
  
  
  cout << get_majority_element(a, 0, (a.size()-1)) << '\n';
}

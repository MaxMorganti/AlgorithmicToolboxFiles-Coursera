#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


//a binary search on a sorted array
//runs faster than linear, as every element does not need to be checked
int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  while(left <= right) {
  	int mid = left + ((right - left)/2);
  	if(x == a[mid]) {
  		return mid;
  	}
  	else if(x < a[mid]) {
  		right = mid - 1;
  	}
  	else {
  		left = mid + 1;
  	}
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    cout << binary_search(a, b[i]) << ' ';
  }
}

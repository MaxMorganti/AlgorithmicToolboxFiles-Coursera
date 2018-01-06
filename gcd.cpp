#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

// gcd_fast able to find common denominators quickly
// for large (up to 2e9) numbers

// utilizes fact that gcd(a, b) = gcd(a', b),
// where a' is remainder of a/b 

long long gcd_naive(long long a, long long b) {
  long long current_gcd = 1;
  for (long long d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long gcd_fast(long long a, long long b) {
	if(b == 0){
		return a;
	}
	long long remainder = a%b;
	gcd_fast(b, remainder);
}

void test_solution(){
	int i = 0;
	while(true) {
		cout << "Test " << i << "\n";
		i++;
		int a = rand() %1000;
		int b = rand() %1000;
		cout << a << " " << b << "\n";
		assert(gcd_fast(a, b) == gcd_naive(a, b));
	}
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout << gcd_fast(a, b);
  //test_solution();
  return 0;
}

#include <iostream>
#include <cassert>
#include <vector>

// Last Digit of a Fibonacci Number
// N can now be very large (up to 10^7)


using namespace std;


int fibonacci_last_num(int n) {
	
	// in case where n = 0, vector needs to be 2-long
	// to accomodate first two elements
	vector<int> fib_list(n+2);
	fib_list[0] = 0;
	fib_list[1] = 1;
	
	for(int i = 2; i <= n; i++) {
		//only last number is stored
		fib_list[i] = (fib_list[i-1] + fib_list[i-2])%10;
	}
    return fib_list[n];
}

void test_solution() {
    assert(fibonacci_last_num(3) == 2);
    assert(fibonacci_last_num(331) == 9);
    assert(fibonacci_last_num(327305) == 5);
}

int main() {
    int n = 0;
    cin >> n;
	//test_solution();
    cout << fibonacci_last_num(n);
    
    return 0;
}


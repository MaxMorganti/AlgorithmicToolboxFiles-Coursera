#include <iostream>

using namespace std;

int get_change(int m) {
	
	//number of coins
	int coins = 0;
	//integer division will round answer down
	coins += m/10; 
	//redefine m as the remainder
	m %= 10;
	coins += m/5;
	m %= 5;
	coins += m;
	
    return coins;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}

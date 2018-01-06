#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence2(int n) {
	vector<int> A(n+1);
	vector<int> sequence;
	
	
	A[0] = 0; 
	A[1] = 0;
	
	//fill dynamic array A
	for(int i=2;i<= n;i++) {
		int a, b, c = 0;
		
		//checks all possible previous operations to see
		//which requires the least steps
		a = A[i-1];
		if (i%2==0) {
			b = A[i/2];
		} 
		else {
		//arbitrarily high no.
		b = 1000000; 
		}
		
		if (i%3==0) {
			c = A[i/3];
		}
		else {
		c=1000000;
		}
		//adds one to number of operations from previous
		//optimum number in sequence
		int my_min = min(a, min(b, c));
		A[i] = my_min + 1;
	}	
	
	//find what optimal sequence is
	sequence.push_back(n);
	int index_check = n;
	while(index_check > 1) {
		
		//starting with last index, check which of possible
		//previous indices has lowest number of operations
		int a_index, b_index, c_index = 0;
		a_index = (index_check)-1;
		if (index_check%2==0) {
			b_index = (index_check)/2;
		} 
		else {
		b_index = index_check;
		}
		
		if (index_check%3==0) {
			c_index = (index_check)/3;
		}
		else {
		c_index=index_check;
		}
		
		int a = A[a_index];
		int b = A[b_index];
		int c = A[c_index];
		int my_min = min(a, min(b,c));
		
		//add previous optimum number to sequence
		if(my_min == a) {
			sequence.push_back(a_index);
			index_check = a_index;
		}
		else if (my_min == b) {
			sequence.push_back(b_index);
			index_check = b_index;
		}
		else {
			sequence.push_back(c_index);
			index_check = c_index;
		}
			
	}
	reverse(sequence.begin(), sequence.end());
    return sequence;
	
}

//naive and incorrect greedy alg.
vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  cin >> n;
  vector<int> sequence = optimal_sequence2(n);
  cout << sequence.size() - 1 << endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    cout << sequence[i] << " ";
  }
}

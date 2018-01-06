#include <iostream>
#include <vector>

using namespace std;

//uses dynamic programming to find optimum weight of a discrete
//knapsack problem
//assume weight = value


int optimal_weight_new(int W, const vector<int> &w) {
  
  int **mat, rows = w.size(), cols = W + 1;
   // dynamically allocate memory for a matrix 
   
   mat = new int*[rows];
   for (int i = 0; i < rows; i++) {
      mat[i] = new int[cols];
   }
   
   // initialize matrix elements 
   // form : A[row][col]
   for(int i = 0; i < rows; i++) {
   		mat[i][0] = 0;
   }
   for(int j = 0; j < cols; j++) {
   		mat[0][j] = 0;
   }
   
   
   for(int i = 1; i < rows;i++) {
   		for(int j = 1;j<cols;j++) {
   			mat[i][j] = mat[i-1][j];
   			if(w[i] <= j) {
   				//this is value from best that can 
   				//be done w/out adding, plus value from adding
   				int value = mat[i-1][j-w[i]] + w[i];
   				if(value > mat[i][j]) {
   					mat[i][j] = value;
   				}
   			}
   		}
   }
   
   //display matrix for debugging
   /*for(int i = 0;i<rows;i++) {
   		for(int j = 0;j<cols;j++) {
   			cout << mat[i][j] << " ";
   		}
   		cout << endl;
   }*/
   
   int answer = mat[rows-1][cols-1];
   
   // deallocate (free) the memory
   for (int i = 0; i < rows; i++ ) {
      delete mat[i];
   }
   delete mat;
   return answer;
  }




//greedy and incorrect
int optimal_weight(int W, const vector<int> &w) {
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main() {
  int n, W;
  cin >> W >> n;
  //enter vector starting from index 1
  vector<int> w(n+1);
  for (int i = 1; i < n+1; i++) {
    cin >> w[i];
  }
  cout << optimal_weight_new(W, w) << '\n';
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Countsort(vector<int>& A) {
    int n = A.size();
    int max_val = *max_element(A.begin(), A.end()) + 1; // Get the maximum value in A and add 1 for array size
    vector<int> C(max_val, 0); // Create a counting array of size max_val

    // Count the occurrences of each element in A and store in C
    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }

    int j = 0;
    for (int i = 0; i < max_val; i++) {
        while (C[i] > 0) {
            A[j++] = i; // Update the original vector A with sorted values
            C[i]--;
        }
    }
}

int main() {
    vector<int> A = {6, 8, 5, 9, 4, 2, 3, 4};
    Countsort(A);
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    
    return 0;
}

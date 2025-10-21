// Program: knapsack_dp.cpp
// Purpose: To solve the 0/1 Knapsack problem using Dynamic Programming.
// Author: [Your Name]
// Description:
//   The 0/1 Knapsack problem is a classic optimization problem in which we have
//   'n' items, each with a certain value and weight. The goal is to determine
//   the maximum total value we can obtain by selecting items such that their
//   combined weight does not exceed a given capacity (maxW).
//   This program uses a bottom-up dynamic programming approach to solve it efficiently.

#include <bits/stdc++.h> // Includes all standard libraries (iostream, vector, etc.)
using namespace std;

// A simple function to return the maximum of two integers
int max1(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n; // Input total number of items

    int va[n], wt[n]; // Arrays to store values and weights of items
    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> va[i] >> wt[i]; // Input value and weight for item i
    }

    int maxW;
    cout << "Enter maximum capacity of knapsack: ";
    cin >> maxW; // Input maximum weight capacity of knapsack

    // Create a DP table Knap[n+1][maxW+1]
    // Knap[i][j] will store the maximum value achievable with i items and capacity j
    int Knap[n + 1][maxW + 1];

    // Build the table in a bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= maxW; j++) {
            if (i == 0 || j == 0)
                // Base case: if no items or capacity 0, value = 0
                Knap[i][j] = 0;
            else {
                // If weight of current item is less than or equal to remaining capacity
                if (wt[i - 1] <= j)
                    // Choose maximum of:
                    // 1) Including current item
                    // 2) Excluding current item
                    Knap[i][j] = max1(Knap[i - 1][j], Knap[i - 1][j - wt[i - 1]] + va[i - 1]);
                else
                    // Cannot include the item if it exceeds capacity
                    Knap[i][j] = Knap[i - 1][j];
            }
        }
    }

    int maxv = Knap[n][maxW]; // The bottom-right cell holds the maximum value
    cout << "\nMaximum value achievable: " << maxv << endl;

    return 0;
}

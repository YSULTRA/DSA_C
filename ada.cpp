#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Function to calculate the maximum profit
int cost_finder(int m, int n, const vector<vector<int>> &spot_prices, vector<vector<int>> &memo)
{
  // Base case: if any of the dimensions becomes 0
  if (m == 0 || n == 0)
  {
    return 0;
  }

  // Initialize the maximum profit
  int max_profit = INT_MIN;

  // fecth prev max
  if (m <= spot_prices.size() && n <= spot_prices[0].size())
  {
    max_profit = spot_prices[m - 1][n - 1];
  }

  // vertical cut
  for (int i = 1; i < m; i++)
  {
    int above_cut = cost_finder(i, n, spot_prices, memo);
    int below_cut = cost_finder(m - i, n, spot_prices, memo);
    max_profit = max(max_profit, above_cut + below_cut);
  }

  // horizontal
  for (int i = 1; i < n; i++)
  {
    int left_cut = cost_finder(m, i, spot_prices, memo);
    int right_cut = cost_finder(m, n - i, spot_prices, memo);
    max_profit = max(max_profit, left_cut + right_cut);
  }

  // Memoize the result
  memo[m][n] = max_profit;
  return max_profit;
}

int main()
{
  int m, n;
  // cout << "Enter dimensions of the marble slab (m x n): ";
  cin >> m >> n;

  vector<vector<int>> spot_prices(m, vector<int>(n));
  // cout << "Enter the costs for each combination:" << endl;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> spot_prices[i][j];
    }
  }

  // Initialize memoization table with -1
  vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

  int max_profit = cost_finder(m, n, spot_prices, memo);
  cout << "Maximum profit: " << max_profit << endl;

  return 0;
}
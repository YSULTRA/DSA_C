#include <iostream>
#include <vector>
using namespace std;

long long int binarySearchMaxPlates(const string &recipe, int requiredBread, int requiredSalmon, int requiredCorn, int priceBread, int priceSalmon, int priceCorn, long long int budget, vector<int> &ingredientCount, long long int low, long long int high)
{
  if (low > high)
    return -1;

  long long int mid = low + (high - low) / 2;
  long long int breadNeeded = max(0LL, mid * ingredientCount[0] - requiredBread);
  long long int salmonNeeded = max(0LL, mid * ingredientCount[1] - requiredSalmon);
  long long int cornNeeded = max(0LL, mid * ingredientCount[2] - requiredCorn);
  long long int cost = priceBread * breadNeeded + priceSalmon * salmonNeeded + priceCorn * cornNeeded;

  if (cost <= budget)
  {
    long long int nextPossible = binarySearchMaxPlates(recipe, requiredBread, requiredSalmon, requiredCorn, priceBread, priceSalmon, priceCorn, budget, ingredientCount, mid + 1, high);
    return max(mid, nextPossible);
  }
  else
  {
    return binarySearchMaxPlates(recipe, requiredBread, requiredSalmon, requiredCorn, priceBread, priceSalmon, priceCorn, budget, ingredientCount, low, mid - 1);
  }
}

long long int findMaxPlates(const string &recipe, int requiredBread, int requiredSalmon, int requiredCorn, int priceBread, int priceSalmon, int priceCorn, long long int budget)
{
  vector<int> ingredientCount(3, 0);
  for (char c : recipe)
  {
    if (c == 'B')
      ingredientCount[0]++;
    else if (c == 'S')
      ingredientCount[1]++;
    else if (c == 'C')
      ingredientCount[2]++;
  }

  return binarySearchMaxPlates(recipe, requiredBread, requiredSalmon, requiredCorn, priceBread, priceSalmon, priceCorn, budget, ingredientCount, 0, 1e15);
}

int main()
{
  string recipe;
  cout << "Enter recipe: ";
  cin >> recipe;

  int requiredBread, requiredSalmon, requiredCorn;
  cout << "Enter required bread, salmon, and corn: ";
  cin >> requiredBread >> requiredSalmon >> requiredCorn;

  int priceBread, priceSalmon, priceCorn;
  cout << "Enter price for bread, salmon, and corn: ";
  cin >> priceBread >> priceSalmon >> priceCorn;

  long long int budget;
  cout << "Enter budget: ";
  cin >> budget;

  long long int maxPlates = findMaxPlates(recipe, requiredBread, requiredSalmon, requiredCorn, priceBread, priceSalmon, priceCorn, budget);
  cout << "Maximum plates possible: " << maxPlates << endl;

  return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int knapSack(int n, vector<int>& wt, vector<int>& val, int MAX) {
    vector<vector<int>> dp(n + 1, vector<int>(MAX + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= MAX; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][MAX];
}

int main() {
    int cases, time, n_pizzas;
    cin >> cases;

    while (cases != 0) {
        int MAX;
        cin >> MAX;
        vector<int> times(cases);
        vector<int> pizzas(cases);

        for (int i = 0; i < cases; i++) {
            cin >> time >> n_pizzas;
            times[i] = time;
            pizzas[i] = n_pizzas;
        }

        cout << knapSack(cases, pizzas, times, MAX) <<" min."<< endl;

        cin >> cases;
    }

}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int M,N;
        cin >> N >> M;
        
        int total = 0;
        
        vector<vector<int>> prices;
        for (int n = 0; n < N; n++) {

            vector<int> line;
            int min, value;
            int min_i = 0;

            cin >> min;
            line.push_back(min);
            for (int m = 1; m < M; m++) {
                cin >> value;
                line.push_back(value);
                if (min > value) { min = value; min_i = m; }
            }

            prices.push_back(line);
            
            if (n==0) {
                total += min + 1;
                prices[n].erase(prices[n].begin() + min_i); // remove min element
            }
            else {
                min = min + 1; // add tax of today
                int min_d = n;

                // min is least this day

                for (int d = 0; d < n; d++) {

                    // day d, update min?
                    if (prices[d].size() > 0) {
                        int v = 0;
                        for (int i = 0; i < prices[d].size(); i++) {
                            v = prices[d][i] > prices[d][v] ? v : i;
                        }
                        int bout = M-prices[d].size();
                        int tax = (bout+1)*(bout+1) - (bout*bout);
                        int cost_d = tax + prices[d][v];
                        if (cost_d < min) {
                            min = cost_d;
                            min_d = d;
                            min_i = v;
                        }
                    }
                }

                total += min;
                prices[min_d].erase(prices[min_d].begin() + min_i); // remove the pastry
            }
        }

	cout << "Case #" << t+1 << ": " << total << endl;
    }
    
    return 0;
}

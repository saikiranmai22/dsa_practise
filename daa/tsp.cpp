#include <iostream>
#include <vector>
// #include <cmath>
using namespace std;
#define V 4  
#define INF 1e9  

int dp[V][1 << V];
int tsp(int i, int mask, int dist[][V]) {
    // mask is the set of cities already visited 
    // if all the cities have been visited then return to the distance of the starting city
    if (mask == (1 << V) - 1) {
        return dist[i][0];  
    }
    if (dp[i][mask] != -1) { // to avoid redundant calculations
        return dp[i][mask];
    }
    int res = INF;

    for (int j = 0; j < V; j++) {
        // If city j is not visited in the current mask
        if (!(mask & (1 << j))) {
            // Recur for the next state: city j and updated mask to include city j as visited
            int newRes = dist[i][j] + tsp(j, mask | (1 << j), dist);
            res = min(res, newRes);
        }
    }

    // Save the result and return
    dp[i][mask] = res;
    return res;
}

int main() {
    int dist[V][V] = {
        { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 }
    };

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < (1 << V); j++) {
            dp[i][j] = -1;
        }
    }

    // Start the TSP from vertex 0 and initial mask is 1 (only vertex 0 is visited)
    int result = tsp(0, 1, dist);

    // Output the minimum cost to complete the tour
    cout << "Minimum path cost: " << result << endl;

    return 0;
}

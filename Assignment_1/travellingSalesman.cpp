#include <iostream>
#include <climits>
using namespace std;

int tsp(int cost[n][], int n, int vis[], int path[n][], int dp[n][], int visit, int currCity){
    if(visit == n){
        return cost[currCity][0];
    }

    if(dp[currCity][visit] != -1){
        return dp[currCity][visit];
    }

    int minCost = INT_MAX;
    for(int next=0; next<n; next++){
        if(!vis[next]){
            vis[next] = true;
            int newCost = cost[currCity][next] + tsp(next, visit+1, vis);
            if(newCost < minCost){
                minCost = newCost;
                path[currCity][visit] = next; 
            }
            vis[next] = false;

        }

        dp[currCity][visit] = minCost;
        return minCost;
    }

}

void printPath(int start, int path[][], int n){
    int curr = start;
    int visit = 1;
    bool vis[n];
    for(int i=0; i<n; i++){
        vis[i] = false;
    }
    vis[0] = true;

    cout<<"Path: "<<curr ;

    while(visit < n){
        int nextCity = path[curr][visit];

        if(nextCity == -1){
            break;
        }

        cout<<" -> " <<nextCity;
        vis[nextCity] = true;
        curr = nextCity;
        visit++;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int cost[][] = {{0, 10, 15, 20},
                    {10, 0, 35, 25},
                    {15, 35, 0, 30},
                    {20, 25, 30, 0}};

    bool vis[];
    for(int i=0; i<n; i++){
        vis[i] = false;
    }

    int dp[n][n+1];
    int path[n][n+1];

    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = -1;
            path[i][j] = -1;
        }
    }

    int minCost = tsp(cost, n ,vis, path, dp, 1, 0);
    cout<<"Minimum Cost: " <<minCost <<"\n";
    printPath(0, path, n);

    vis[0] = true;

}
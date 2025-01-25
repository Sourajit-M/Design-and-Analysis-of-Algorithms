#include <iostream>
#include <algorithm>  // For next_permutation
#include <climits>    // For INT_MAX

int route[4];  // Array to store the route

// Function to calculate the distance of a given route
int calcDist(int graph[4][4], int route[4]) {
    int dist = 0;

    // Calculate the distance of the route by summing up the edges
    for (int i = 0; i < 4 - 1; i++) {
        dist += graph[route[i]][route[i + 1]];
    }

    // Adding the distance from the last city back to the starting city
    dist += graph[route[3]][route[0]];

    return dist;
}

// Function to solve TSP using brute force (all permutations)
int tsp(int graph[4][4], int source) {
    // Initialize the route with the cities
    for (int i = 0; i < 4; i++) {
        route[i] = i;
    }

    // Variable to store the minimum distance
    int minDist = INT_MAX;

    // Generate all permutations of the cities
    do {
        // Calculate the distance for the current permutation of cities
        int currDist = calcDist(graph, route);

        // Update the minimum distance if the current one is smaller
        if (currDist < minDist) {
            minDist = currDist;
        }
    } while (std::next_permutation(route + 1, route + 4));  // Start from the second city to avoid redundant starting city

    return minDist;
}

int main() {
    int graph[4][4] = {{0, 3, 6, 8},
                       {3, 0, 6, 8},
                       {6, 0, 9, 4},
                       {8, 4, 2, 0}};  // Example graph with distances

    // Call tsp to find the minimum route starting from city 0
    int res = tsp(graph, 0);

    // Output the result
    std::cout << "The minimum distance is: " << res << std::endl;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define V 4  //  number of vertices = 4


#define INF 99999 // INF -> infinte , when vertices are not connected with each other

void printSolution(int dist[][V]);

void floydWarshall(int graph[][V]) // Floyd warshall algorithm
{
	
	int dist[V][V];   // Matrix that will finally have shortest distance between every pair of vertices
        int i, j, k;

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];  // intialize with graph matrix

	
	for (k = 0; k < V; k++) {  // Adding vertices individually
		for (i = 0; i < V; i++) {
			
			for (j = 0; j < V; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))  // vertex k is on shortest path from i to j
					dist[i][j] = dist[i][k] + dist[k][j];  
			}
		}
	}

	printSolution(dist);
}

void printSolution(int dist[][V])
{
	cout << "The following matrix shows the shortest "
			"distances"
			" between every pair of vertices \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
					<< "	 ";
			else
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
}

int main()
{
	
	int graph[V][V] = { { 0, 5, INF, 10 },
						{ INF, 0, 3, INF },
						{ INF, INF, 0, 1 },
						{ INF, INF, INF, 0 } };

	// Function call
	floydWarshall(graph);
	return 0;
}

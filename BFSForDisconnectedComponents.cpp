#include<bits/stdc++.h>
using namespace std;

void printBFS(int **edges, int n, int sv) {
	queue<int> pendingVertices;
	bool *visited = new bool[n];
	for(int i=0;i<n;i++) {
		visited[i] = false;
	}
	pendingVertices.push(sv);
	visited[sv] = true;
	while(!pendingVertices.empty()) {
		int currentVertex = pendingVertices.front();
		cout<<currentVertex<<" ";
		pendingVertices.pop();
		for(int i=0;i<n;i++) {
			if(i == sv) {
				continue;
			}
			if(edges[currentVertex][i] == 1 && !visited[i]) {
				pendingVertices.push(i);
				visited[i] = true;
			}
		}
	}
	delete[] visited;
}

int main() {
	int n, e;
	cout<<"Enter number of vertices: ";
	cin>>n;
	cout<<"Enter number of edges: ";
	cin>>e;
	int **edges = new int*[n];
	for(int i=0;i<n;i++) {
		edges[i] = new int[n];
		for(int j=0;j<n;j++) {
			edges[i][j] = 0;
		}
	}
	for(int i=0;i<e;i++) {
		int f, s;
		cout<<"Enter the first and the second edge: ";
		cin>>f>>s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	printBFS(edges, n, 0);
	for(int i=0;i<n;i++) {
		delete []edges[i];
	}
	delete []edges;
	return 0;
}

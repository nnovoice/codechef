#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_VERTICES = 100001;
int vStack[MAX_VERTICES];
bool visited[MAX_VERTICES];
int idx;

void PrintGraph(map<int, vector<int> >& graph, int nVerts, int mEdges)
{
	for (int i = 1; i <= nVerts; ++i) {
		cout << "Size of nodes(" << i << ") is= " << graph[i].size() << ": nodes are: ";
		for (size_t j = 0; j < graph[i].size(); ++j)
			cout << graph[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void DijkstraShortestPath(map<int, vector<int> >& graph, int startVert, int endVert)
{
	
}

void BFS(map<int, vector<int> >& graph, int nVerts, int mEdges)
{
	memset(visited, false, (nVerts + 1) * sizeof(bool));
	cout << "Debug: " << "Performing a BFS now...\n";
	int curVert = 0;
	vStack[idx++] = 1;
	
	while(idx != 0) {
		curVert = vStack[--idx];
		if (visited[curVert] == true) continue;
		
		cout << curVert << " ";
		visited[curVert] = true;
		
		for (size_t i = 0; i < graph[curVert].size(); ++i) {
				vStack[idx++] = graph[curVert][i];
			//cout << graph[curVert][i] << " ";
		}
	}
	cout << "Debug " << "BFS done.\n";
}

int main()
{
	map<int, vector<int> > directedGraph;
	map<int, vector<int> > undirectedGraph;
	
	int node1 = 0, node2 = 0;
	int nVerts = 0, mEdges = 0;
	
	cin >> nVerts >> mEdges;

	for (int i = 0; i < mEdges; ++i) {
		cin >> node1 >> node2;
		
		directedGraph[node1].push_back(node2);
		
		undirectedGraph[node1].push_back(node2);
		undirectedGraph[node2].push_back(node1);
	}
	
	PrintGraph(directedGraph, nVerts, mEdges);
	cout << "Debug: " << "performing BFS on directed graph:\n";
	BFS(directedGraph, nVerts, mEdges);
	
	PrintGraph(undirectedGraph, nVerts, mEdges);
	cout << "Debug: " << "performing BFS on undirected graph:\n";
	BFS(undirectedGraph, nVerts, mEdges);

	return 0;
}

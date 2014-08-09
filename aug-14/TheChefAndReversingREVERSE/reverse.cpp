#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_VERTICES = 100001;
int vStack[MAX_VERTICES];
int pred[MAX_VERTICES];
int costs[MAX_VERTICES];
bool visited[MAX_VERTICES];
int idx;

void PrintGraph(map<int, map<int, int> >& graph, int nVerts, int mEdges)
{
	map<int, int>::iterator iter, iter_end;
	for (int i = 1; i <= nVerts; ++i) {
		cout << "Size of nodes(" << i << ") is= " << graph[i].size() << ": nodes are: ";
		iter = graph[i].begin();
		iter_end = graph[i].end();
		for (; iter != iter_end; ++iter)
			cout << iter->first << "," << iter->second << " ";
		cout << endl;
	}
	cout << endl;
}

void DijkstraShortestPath(map<int, map<int, int> >& graph, int startVert, int endVert)
{

}

int BFS(map<int, map<int, int> >& graph, int sourceVert, int targetVert, int nVerts, int mEdges)
{
	bool reachedDestination =  false;
	map<int, int>::iterator iter, iter_end;
	int minEdgesReversed = INT_MAX;
	int curMinEdgesReversed = 0;
	
	memset(visited, false, (nVerts + 1) * sizeof(bool));
	int curVert = sourceVert;
	vStack[idx++] = sourceVert;
	pred[sourceVert] = sourceVert;
	costs[sourceVert] = 0;

	while(idx != 0) {
		curVert = vStack[--idx]; 
		if (curVert == targetVert) {
			reachedDestination = true;
			cout << "reached destination: cur min edges= " << curMinEdgesReversed << endl;
			if (curMinEdgesReversed < minEdgesReversed) {
				minEdgesReversed = curMinEdgesReversed;
				curMinEdgesReversed = 0;
			}
		}

		if (visited[curVert] == true) continue;
		cout << curVert << " ";
		visited[curVert] = true;
		
		if (graph[pred[curVert]][curVert] == 2)  {
			curMinEdgesReversed = costs[pred[curVert]] + 1;
			costs[curVert] = curMinEdgesReversed;
		}

		iter = graph[curVert].begin();
		iter_end = graph[curVert].end();
		for (; iter != iter_end; ++iter) {
			vStack[idx++] = iter->first;
			pred[iter->first] = curVert;
		}
	}
	
	return (reachedDestination == true) ? minEdgesReversed : -1;
}

int main()
{
	map<int, map<int, int> > directedGraph;
	map<int, map<int, int> > undirectedGraph;

	int node1 = 0, node2 = 0;
	int nVerts = 0, mEdges = 0;

	cin >> nVerts >> mEdges;

	for (int i = 0; i < mEdges; ++i) {
		cin >> node1 >> node2;
		if (node1 == node2) continue; // ignore loops

		directedGraph[node1][node2] = 1;

		undirectedGraph[node1][node2] = 1;
		if (undirectedGraph[node2][node1] == 0)
			undirectedGraph[node2][node1] = 2;
	}

	PrintGraph(directedGraph, nVerts, mEdges);
	cout << "Debug: " << "performing BFS on directed graph:\n";
	cout << "Debug: min edges reversed= " << BFS(directedGraph, 1, nVerts, nVerts, mEdges) << endl;

	PrintGraph(undirectedGraph, nVerts, mEdges);
	cout << "Debug: " << "performing BFS on undirected graph:\n";
	cout << "Debug: min edges reversed= " << BFS(undirectedGraph, 1, nVerts, nVerts, mEdges) << endl;

	return 0;
}

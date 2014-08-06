#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

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
	PrintGraph(undirectedGraph, nVerts, mEdges);

	return 0;
}

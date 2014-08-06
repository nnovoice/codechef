#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void PrintGraph(map<int, vector<int> >& graph)
{
	size_t n = graph.size();
	for (size_t i = 1; i <= n; ++i) {
		nodes = graph[i];
		cout << "Size of nodes(" << i << ") is= " << nodes.size() << ": nodes are: ";
		for (size_t j = 0; j < nodes.size(); ++j)
			cout << nodes[j] << " ";
		cout << endl;
	}
}

int main()
{
	map<int, vector<int> > graph;
	int node1 = 0, node2 = 0;
	int nVerts = 0, mEdges = 0;
	cint >> nVerts >> mEdges;

	for (int i = 0; i < mEdges; ++i) {
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
	}

	return 0;
}

int main0()
{
	map<int, vector<int> > graph;

	vector<int> nodes;
	nodes.push_back(2);
	graph[1].push_back(3);
	graph[2].push_back(4);
	graph[2].push_back(5);
	graph[3].push_back(3);

	for (int i = 1; i < 5; ++i) {
		nodes = graph[i];
		cout << "Size of nodes(" << i << ") is= " << nodes.size() << ": nodes are: ";
		for (size_t j = 0; j < nodes.size(); ++j)
			cout << nodes[j] << " ";
		cout << endl;
	}
	return 0;
}
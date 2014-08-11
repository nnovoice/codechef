#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define NOT_EXISTS -1

void PrintGraph(vector<vii>& adjList, int nVerts, int mEdges)
{
	printf("Printing Graph:\n");
	for (int i = 1; i < adjList.size(); ++i) {
		printf("Edges for %d= ", i);
		for (int j = 0; j < adjList[i].size(); ++j) {
			printf("%d,%d ", adjList[i][j].first, adjList[i][j].second);
		}
		printf("\n");
	}
}

int main() {
  int V, E, s, u, v, w;
  vector<vii> AdjList;

  scanf("%d %d", &V, &E);
  //printf("%d %d\n", V, E);
  s = 1; // source

  AdjList.assign(V + 1, vii()); // assign blank vectors of pair<int, int>s to AdjList
  //printf("size of adj list=%u\n", AdjList.size());
  for (int i = 1; i <= E; ++i) {
    scanf("%d %d", &u, &v);
    //printf("%d %d\n", u, v);
    //w = 1;
    if (u == v) continue;
    AdjList[u].push_back(ii(v, 0));                              // directed graph
    AdjList[v].push_back(ii(u, 1));
  }
  
  //PrintGraph(AdjList, V, E);  

  // Dijkstra routine
  vi dist(V + 1, NOT_EXISTS); dist[s] = 0;                    // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; 
  pq.push(ii(0, s));
                             // ^to sort the pairs by increasing distance from s
  while (!pq.empty()) {                                             // main loop
    ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;   // this check is important, see the explanation
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];                       // all outgoing edges from u
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;                 // relax operation
        pq.push(ii(dist[v.first], v.first));
  } } }  // note: this variant can cause duplicate items in the priority queue

  //for (int i = 1; i <= V; ++i) // index + 1 for final answer
  //  printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);
  
  printf("%d\n", dist[V]);

  return 0;
}


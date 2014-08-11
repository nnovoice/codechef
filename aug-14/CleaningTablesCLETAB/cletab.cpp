#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int MAX_CUSTOMERS = 401;
int orders[MAX_CUSTOMERS];


int main()
{
  map<int, int> priorities;
  map<int, int> allottedTables;
  priority_queue< ii, vector<ii>, less<ii> > pq;
  int nCases, n, m, c, minTablesToClean = 0;

  scanf("%d", &nCases);
  printf("Debug: cases=%d\n", nCases);

  while (nCases--) {
	  scanf("%d %d", &n, &m);
	  //printf("Debug: n=%d m=%d\n", n, m);

	  pq = priority_queue< ii, vector<ii>, less<ii> >();
	  priorities.clear();
	  allottedTables.clear();
	  minTablesToClean = 0;

	  for (int i = 0; i < m; ++i) {
	    scanf("%d", &c);
	    //printf("%d ", c);
	    orders[i] = c;
	    priorities[c] += 1;
	  }
	  //printf("Debug: \n");

//	  map<int, int>::iterator iter = priorities.begin();
//	  map<int, int>::iterator iter_end = priorities.end();
//	  while (iter != iter_end) {
//		  pq.push(ii(iter->first, iter->second));
//		  ++iter;
//	  }

//	  while (!pq.empty()) {
//		  ii front = pq.top(); pq.pop();
//		  printf("top=%d,%d\n", front.first, front.second);
//	  }

	  for (int i = 0; i < m; ++i) {
	    c = orders[i];
	    //printf("Debug: processing request for a table by: %d\n", c);
	    if (allottedTables[c] == 1) continue;
	    if (pq.size() == n) {
	    	ii front = pq.top(); pq.pop();
	    	allottedTables.erase(front.first);
	    	//printf("Debug: %d was politely asked to leave\n", front.first);
	    }
	    //printf("Debug: allotted table for %d\n", c);
	    pq.push(ii(c, priorities[c]));
	    allottedTables[c] = 1;
	    ++minTablesToClean;
	  }
	  printf("%d\n", minTablesToClean);
  }
  return 0;
}


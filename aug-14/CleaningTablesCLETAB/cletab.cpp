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
  int nCases, n, m, c;

  scanf("%d", &nCases);
  printf("Debug: cases=%d\n", nCases);

  while (nCases--) {
	  scanf("%d %d", &n, &m);
	  printf("Debug: n=%d m=%d\n", n, m);

	  pq = priority_queue< ii, vector<ii>, less<ii> >();
	  priorities.clear();

	  for (int i = 0; i < m; ++i) {
	    scanf("%d", &c);
	    printf("%d ", c);
	    orders[i] = c;
	    priorities[c] += 1;
	  }
	  printf("Debug: \n");

	  map<int, int>::iterator iter = priorities.begin();
	  map<int, int>::iterator iter_end = priorities.end();
	  while (iter != iter_end) {
		  pq.push(ii(iter->first, iter->second));
		  ++iter;
	  }

	  while (!pq.empty()) {
		  ii front = pq.top(); pq.pop();
		  printf("top=%d,%d\n", front.first, front.second);
	  }

//	  for (int i = 0; i < m; ++i) {
//	    c = orders[i];
//	    if (pq.size() == n) {
//
//	    }
//
//	  }

  }


  return 0;
}


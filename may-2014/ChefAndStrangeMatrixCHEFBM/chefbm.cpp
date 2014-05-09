#include <stdio.h>
#include <map>

using namespace std;

void PrintMatrix(map<int, map<int, int> >& strangeMatrix, int n, int m)
{
    map<int, int>::iterator iter;
    map<int, int>::iterator iter_end;
    for (int i = 1; i <= n; ++i) {
        if (strangeMatrix.find(i) != strangeMatrix.end()) {
            iter = strangeMatrix[i].begin();
            iter_end = strangeMatrix[i].end();
            for (;iter != iter_end; ++iter) {
                printf("%d,%d ", iter->first, iter->second);
            }
        }
        else {
            for (int j = 1; j <= m; ++j) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}
// row cost if valid is always MaxVal - MinVal
int GetRowCost(map<int, int>& smRow, int n, int m)
{
    if (m == 1) return -1;

    map<int, int>::iterator iter     = smRow.begin();
    map<int, int>::iterator iter_end = smRow.end();
    map<int, int>::reverse_iterator rev_iter;

    int curIdx  = 0, curVal  = 0;
    int prevIdx = 1, prevVal = 1;
    int minVal  = 1, maxVal  = m;

    while (iter != iter_end) {
        curIdx = iter->first;
        curVal = iter->second;

        if (((curIdx - prevIdx) == 1) && (curVal - prevVal < 0))
            return -1;

        prevIdx = curIdx;
        prevVal = curVal;

        ++iter;
    }

    if ((prevIdx < m) && (prevVal > (prevIdx + 1))) return -1;

    iter = smRow.begin();
    minVal = (minVal < iter->second) ? minVal : iter->second;

    rev_iter = smRow.rbegin();
    maxVal = (maxVal > rev_iter->second) ? maxVal : rev_iter->second;

    return maxVal - minVal;
}

void PrintCosts(map<int, map<int, int> >& strangeMatrix, int n, int m)
{
    int rowCost = 0;
    for (int i = 1; i <= n; ++i) {
        if (strangeMatrix.find(i) != strangeMatrix.end()) {
            rowCost = GetRowCost(strangeMatrix[i], n, m);
        }
        else {
            rowCost = m - 1;
        }
        //printf("debug row=%d ", i);
        printf("%d\n", rowCost);
    }
}

// This method builds a sparse matrix using a map of maps
void ReadMatrix(map<int, map<int, int> >& strangeMatrix, int& n, int& m, int& p)
{
    int row = 0, col = 0;
    scanf ("%d %d %d", &n, &m, &p);
    for (int i = 0; i < p; ++i) {
        scanf ("%d %d", &row, &col);
        if (strangeMatrix[row][col] == 0) {
            strangeMatrix[row][col] = col;
        }
        //printf("row=%d col=%d was %d,", row, col, strangeMatrix[row][col]);
        strangeMatrix[row][col] += 1;
        //printf(" changed to %d\n", strangeMatrix[row][col]);
    }
}

int main()
{
    map<int, map<int, int> > strangeMatrix;
    int n = 0, m = 0, p = 0;

    ReadMatrix(strangeMatrix, n, m, p);
    //PrintMatrix(strangeMatrix, n, m);
    PrintCosts(strangeMatrix, n, m);

    return 0;
}

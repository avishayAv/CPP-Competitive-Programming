#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;

int main() {
    ll x;
    while (cin >> x)    {
        ll temp;
        ll rows_yellow=0, rows_red=0, rows_white=0;
        ll cols_yellow=0, cols_red=0, cols_white=0;
        for (ll i=1; i<=x; i++)    {
            cin >> temp;
            if (i%3 == 0) rows_yellow += (temp);
            else if (i%3 == 1) rows_red += (temp);
            else rows_white += (temp);
        }
        for (ll i=1; i<=x; i++)    {
            cin >> temp;
            if (i%3 == 0) cols_yellow += (temp);
            else if (i%3 == 1) cols_red += (temp);
            else cols_white += (temp);
        }
        ll yellow = (rows_red * cols_white) + (cols_red * rows_white) + (rows_yellow * cols_yellow);
        ll red = (rows_yellow * cols_red) + (cols_yellow * rows_red) + (rows_white * cols_white);
        ll white = (rows_red * cols_red) + (rows_yellow * cols_white) + (cols_yellow * rows_white);
        cout << yellow << " " << red << " " << white << endl;
    }
    return 0;
}
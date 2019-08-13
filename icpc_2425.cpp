
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

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< vector< pair<int,int> > > vvii; // weighted graph

const int INF = 1e9;

/********** Bellman-Ford **********/

// input: weighted directed graph (g), source node (s)
// output: is there a negative cycle in g? (return value), the distances from s (d)
// comment: the values in d are valid only if there is no negative cycle
bool BellmanFord(const vvii& g, int s, vi& d) {
    d.assign(g.size(), INF);
    d[s] = 0;
    bool changed = false;
    // V times
    for (int i = 0; i < g.size(); ++i) {
        changed = false;
        // go over all edges u->v with weight w
        for (int u = 0; u < g.size(); ++u) for (auto e = g[u].begin(); e!= g[u].end(); e++) {
                int v = e->first;
                int w = e->second;
                // relax the edge
                if (d[u] < INF && d[u]+w < d[v]) {
                    d[v] = d[u]+w;
                    changed = true;
                }
            }
    }
    // there is a negative cycle if there were changes in the last iteration
    return changed;
}

int main()  {
    int test_cases;
    cin >> test_cases;
    while (test_cases--)    {
        int n, exit, timer, connections;
        string str;
        getline(cin, str);
        cin >> n >> exit >> timer >> connections;
        vvii maze_reversed;
        for (int i=0; i<n; i++) {
            maze_reversed.push_back(vector<pair<int, int>>());
        }
        while (connections--)   {
            int a,b, weight;
            cin >> a >> b >> weight;
            maze_reversed[(b-1)].push_back(make_pair((a-1), weight));
        }
        vi distances;
        BellmanFord(maze_reversed, exit-1, distances);
        int countMouse = 0;
        for (auto i=distances.begin(); i!=distances.end(); i++) {
            if ((*i) <= timer) countMouse++;
        }
        cout << countMouse;
        if (test_cases == 0) {
            cout << endl;
        }
        else cout << endl << endl;
    }
    return 0;
}
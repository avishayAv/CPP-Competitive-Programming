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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;

const int INF = 1e9;

const int UNSEEN = -1;
const int SEEN = 1;

// DFS on digraph g from node u:
// visit a node only if it is mapped to the color UNSEEN,
// Mark all visited nodes in the color map using the given color.
// input: digraph (g), node (v), mapping:node->color (colorMap), color (color).
// output: DFS post-order (S), node coloring (colorMap).
void KosarajuDFS(const vvi& g, int u, vi& S, vi& colorMap, int color) {
    colorMap[u] = color;
    for (auto& v : g[u])
        if (colorMap[v] == UNSEEN)
            KosarajuDFS(g, v, S, colorMap, color);
    S.push_back(u);
}

// Compute the number of SCCs and maps nodes to their corresponding SCCs
// input: directed graph (g)
// output: the number of SCCs (return value), a mapping from node to SCC color (components)
int findSCC(const vvi& g, vi& components) {
    // first pass: record the `post-order' of original graph
    vi postOrder, seen;
    seen.assign(g.size(), UNSEEN);
    for (int i = 0; i < g.size(); ++i)
        if (seen[i] == UNSEEN)
            KosarajuDFS(g, i, postOrder, seen, SEEN);
    // second pass: explore the SCCs based on first pass result
    vvi reverse_g(g.size(),vi());
    for (int u=0; u<g.size(); u++)  {
        if (g[u].size() > 0)    {
            for (int num=0; num<g[u].size(); num++) {
                reverse_g[g[u][num]].push_back(u);
            }
        }
    }
    vi dummy;
    components.assign(g.size(), UNSEEN);
    int numSCC = 0;
    for (int i = (int)g.size()-1; i >= 0; --i)
        if (components[postOrder[i]] == UNSEEN)
            KosarajuDFS(reverse_g, postOrder[i], dummy, components, numSCC++);
    return numSCC;
}

// Computes the SCC graph of a given digraph
// input: directed graph (g)
// output: strongly connected components graph of g (sccg)
void findSCCgraph(const vvi& g, vsi& sccg) {
    vi component;
    int n = findSCC(g, component);
    sccg.assign(n, si());
    for (int u=0; u<g.size(); u++) for (int v: g[u]) // for every edge u->v
            if (component[u] != component[v])
                sccg[component[u]].insert(component[v]);
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int a,b, tempA, tempB;
        cin >> a >> b;
        vvi graph;
        for (int i=0; i<a; i++)  {
            graph.push_back(vector<int>());
        }
        while (b>0) {
            cin >> tempA >> tempB;
            graph[tempA-1].push_back(tempB-1);
            b--;
        }
        vsi scc;
        findSCCgraph(graph, scc);

        if (scc.size() == 1)    {
            cout  << "0" << endl;
        }
        else    {
            //Find holes and sources and calc the maximum between them
            int holes = 0;
            for (int i=0; i<scc.size(); i++)  {
                if (scc[i].size() == 0) holes++;
            }

            vsi scc_reverse;
            for (int i=0; i<scc.size(); i++)  {
                scc_reverse.push_back(set<int>());
            }

            for (int u=0; u<scc.size(); u++)  {
                if (scc[u].size() > 0)    {
                    for (auto num=scc[u].begin(); num!=scc[u].end(); num++) {
                        scc_reverse[(*num)].insert(u);
                    }
                }
            }

            int sources = 0;
            for (int i=0; i<scc_reverse.size(); i++)  {
                if (scc_reverse[i].size() == 0) sources++;
            }

            cout  << max(holes, sources) << endl;
        }
    }
    return 0;
}
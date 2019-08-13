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

void bfs(const vvi& g, int s, vector<int>& d ) {
    queue<int> q;
    q.push(s);
    vector<bool> visible (g.size(),false);
    visible[s]=true;
    d.assign(g.size(),INF);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (!visible[v]) {
                visible[v] = true;
                d[v] = d[u]+1;
                q.push(v);
            }
    }
}

int isEqual (vvi translate, char a, char b)   {
    vector<int> distances;
    bfs(translate, toascii(a)-toascii('a'), distances);
    return (distances[toascii(b)-toascii('a')]);
}

int main()  {
    int dict, words;
    while (cin >> dict >> words)    {
        vvi translate;
        for (int i=0; i<26; i++)    {
            translate.push_back(vector<int>());
        }
        char a,b;
        while (dict--)  {
            cin >> a >> b;
            int index = toascii(a) - toascii('a');
            translate[index].push_back(toascii(b)-toascii('a'));
        }
        string c,d;
        while (words--) {
            cin >> c >> d;
            if (c.length() != d.length())   {
                cout << "no" << endl;
                continue;
            }
            else    {
                int i=0;
                while (i<c.length())    {
                    if (isEqual(translate, c[i], d[i]) < 100)    {
                        i++;
                    }
                    else break;
                }
                if (i==c.length()) cout << "yes" << endl;
                else cout << "no" << endl;
            }
        }
    }
    return 0;
}


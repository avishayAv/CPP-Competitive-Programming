
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

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;

/********** topological sort **********/

// input: a graph (g)
// output: is g a DAG (return value), a topological ordering of g (order)
// comment: order is valid only if g is a DAG
bool topological_sort(const vvi& g, vi& order) {
    // compute indegree of all nodes
    vi indegree (g.size(), 0);
    for (int v=0; v<g.size(); v++) for (int u : g[v]) indegree[u]++;
    // order sources first
    order = vector<int>();
    for (int v=0; v<g.size(); v++) if (indegree[v] == 0) order.push_back(v);
    // go over the ordered nodes and remove outgoing edges,
    // add new sources to the ordering
    for (int i=0; i<order.size(); i++) for (int u : g[order[i]]) {
            indegree[u]--;
            if (indegree[u]==0) order.push_back(u);
        }
    return order.size()==g.size();
}


int main()  {
    vvi graph;
    map<char, int> charToInt;
    map<int, char> intToChar;
    vector<string> dictionary;
    int countChars = 0;
    string str;
    cin >> str;
    //Add vertex
    while (str != "#")  {
        dictionary.push_back(str);
        for (int i=0; i<str.size(); i++)    {
            if (charToInt.find(str[i]) == charToInt.end())  {
                charToInt.insert(make_pair(str[i], countChars));
                intToChar.insert(make_pair(countChars, str[i]));
                countChars++;
                graph.push_back(vector<int>());
            }
        }
        cin >> str;
    }
    //Add edges
    for (int i=0; i<(dictionary.size()-1); i++) {
        string str1 = dictionary[i];
        string str2 = dictionary[i+1];
        int iterator = 0;
        char letter1 = str1[iterator];
        char letter2 = str2[iterator];
        while (iterator < min(str1.size(), str2.size()) && letter1 == letter2)    {
            iterator++;
            letter1 = str1[iterator];
            letter2 = str2[iterator];
        }
        if (iterator >= min(str1.size(), str2.size())) continue;
        //letter 1 is prio comparing to letter 2
        graph[charToInt.find(letter1)->second].push_back(charToInt.find(letter2)->second);
    }
    //sort graph
    vi order;
    topological_sort(graph, order);
    for (int i=0; i<order.size(); i++)  {
        cout << intToChar.find(order[i])->second;
    }
    cout << endl;
    return 0;
}

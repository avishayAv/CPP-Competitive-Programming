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

int main()  {
    int test;
    cin >> test;
    while (test--)  {
        int n;
        int m;
        int temp;
        cin >> n;
        cin >> m;
        int size = 1<<n;
        bitset<1025> players;
        players.set();
        for (int i=1; i<=m; i++)    {
            cin >> temp;
            players.reset(temp);
        }
        int walkovers = 0;
        while (size > 1)    {
            for (int i = 1; i<=size-1; i = i+2)    {
                if (players[i] ^ players[i+1] == 1) walkovers++;
                if (players[i] | players[i+1] == 1) players[(i+1)/2] = 1;
                else players[(i+1)/2] = 0;
            }
            size = size/2;
        }
        cout << walkovers << endl;
    }

    return 0;
}


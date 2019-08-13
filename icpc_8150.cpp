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

int main() {
    int width;
    int pieces;
    int a,b;
    int area;
    while (scanf("%d", &width) == 1)    {
        cin >> pieces;
        area=0;
        while (pieces--)    {
            cin >> a >> b;
            area += (a*b);
        }
        cout << area / width << endl;
    }
    return 0;
}
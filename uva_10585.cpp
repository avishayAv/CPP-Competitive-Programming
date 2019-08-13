
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

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        ll count, x, y;
        ll avg_x = 0, avg_y = 0;
        cin >> count;
        vector<pair<ll, ll>> coors;
        while (count--) {
            cin >> x >> y;
            coors.push_back(make_pair(x,y));
            avg_x += x;
            avg_y += y;
        }
        //if there is a symmetry point, its (avg_x, avg_y)
        int size = coors.size();
        avg_x = (avg_x * 2) / size;
        avg_y = (avg_y * 2) / size;
        pair<ll, ll> candidate= make_pair(avg_x, avg_y);
        bool isSymmetry = true;
        sort(coors.begin(), coors.end());
        for (int i=0; i<size/2; i++)   {
            ll x_both = coors[size-i-1].first + coors[i].first;
            ll y_both = coors[size-i-1].second + coors[i].second;
            if ((x_both != avg_x) || (y_both != avg_y)) {
                isSymmetry = false;
                break;
            }
        }
        if (isSymmetry) cout << "yes" << endl;
        else cout << "no" << endl;

    }
    return 0;
}
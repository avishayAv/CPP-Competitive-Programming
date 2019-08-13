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
typedef vector<pair<int, string>> v_ex2;
typedef pair<int, int> pii;
typedef pair<double, double> coors;

int main()  {
    int island, radius, number=0;
    string str;
    vector<coors> islands;
    vector<coors> positions;    //min and max positions for each island
    vector<coors> radars;
    double x, y;
    while (cin >> island && cin >> radius) {
        if (island == 0 && radius == 0) break;
        number++;
        bool isDone = false;
        islands.clear();
        positions.clear();
        while (island--)    {
            cin >> x >> y;
            if (y > radius) {
                isDone = true;
            }
            islands.push_back(make_pair(x, y));
            double distance = sqrt((radius*radius)-(y*y));
            double min = x - distance;
            double max = x + distance;
            positions.push_back(make_pair(min, max));
        }
        if (isDone) {
            cout << "Case ";
            cout << number;
            cout << ": ";
            cout << "-1";
            cout << endl;
            getline(cin, str);
            continue;
        }
        sort(positions.begin(), positions.end());
        int count = 0;
        double radar = -32000;
        int i=0;
        while (i<positions.size())  {
            while (i<positions.size() && positions[i].first <= radar) {
                if (radar>=positions[i].second) radar=positions[i].second;
                i++;
            }
            count++;
            radar=positions[i].second;
        }
        count--;
        cout << "Case ";
        cout << number;
        cout << ": ";
        cout << count;
        cout << endl;
        getline(cin, str);
    }
}
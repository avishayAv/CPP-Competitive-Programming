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
#include<fstream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

ll GCD(ll a, ll b) {
    ll modulu;
    while (b > 0) {
        modulu = a % b;
        a = b;
        b = modulu;
    }
    return a;
}

ll fillDetails (ll* max)  {
    ll temp;
    ll sum = 0;
    for (int i = 1; i<=9; i++)  {
        cin >> temp;
        sum += temp;
    }
    cin >> temp;
    sum -= temp;
    if (temp > *max) *max = temp;
    return sum;
}

int main()  {
    ll cases, lines;
    cin >> cases;
    while (cases--) {
        ll max=0;
        cin >> lines;
        vector<ll> results;
        while (lines--) {
            results.push_back(fillDetails(&max));
        }
        ll gcd = 0;
        for (ll i=0; i<results.size(); i++) {
            gcd = GCD(results[i], gcd);
        }
        if (gcd <= 1 || gcd <= max) cout << "impossible" << endl;
        else cout << gcd << endl;
    }
    return 0;
}


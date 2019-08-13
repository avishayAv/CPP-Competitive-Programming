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

bool isEnoughKlapis(vector<int> population, int pplPerKalpi, int kalpi) {
    int needed = 0;
    for (auto it = population.begin(); it!= population.end(); it++) {
        int neededCity = ((*it) / pplPerKalpi);
        if ((*it) % pplPerKalpi > 0) neededCity++;
        needed += neededCity;
        if (needed > kalpi) return false;
    }
    if (needed <= kalpi) return true;
    return false;
}

int main() {
    int cities, kalpi, temp;
    string str;
    while (cin >> cities &&  cin >> kalpi)   {
        if (cities == -1 && kalpi == -1) break;
        vector<int> population;
        int sum=0, count=0, max=0;
        while(cities--) {
            cin >> temp;
            sum+=temp;
            count++;
            if (temp > max) max=temp;
            population.push_back(temp);
        }
        int middle;
        int start = sum / kalpi;
        int end = max;
        while (end - start > 0) {
            middle = (start + end) / 2;
            if (isEnoughKlapis(population, middle, kalpi)) end=middle;
            else start = middle+1;
        }
        if (isEnoughKlapis(population, start, kalpi)) cout << start << endl;
        else cout << end << endl;
        getline(cin, str);
    }
    return 0;
}
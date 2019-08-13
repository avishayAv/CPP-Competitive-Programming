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

struct car  {
    string name;
    int min;
    int max;
    car(string name, int min, int max)  {
        this->name = name;
        this->min = min;
        this->max = max;
    }
};

int main() {
    int test_cases, cars, tests;
    int min,max;
    string name;
    cin >> test_cases;
    while (test_cases--)    {
        vector<car> car_list;
        cin >> cars;
        while (cars--)  {
            cin >> name;
            cin >> min;
            cin >> max;
            car temp(name, min, max);
            car_list.push_back(temp);
        }
        cin >> tests;
        int price;
        while (tests--) {
            cin >> price;
            car chosen("", 0, 0);
            for (auto it = car_list.begin(); it!=car_list.end(); it++)  {
                if (price >= it->min && price <= it->max)   {
                    if (chosen.name.empty())    {
                        chosen.name = it->name;
                    }
                    else    {
                        chosen.name = "";
                        break;
                    }
                }
            }
            if (chosen.name.empty())    cout << "UNDETERMINED" << endl;
            else    cout << chosen.name << endl;
        }
        if (test_cases != 0) cout << endl;
    }
    return 0;
}
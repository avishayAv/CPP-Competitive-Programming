
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

double triangle(int x1, int y1, int x2, int y2){
    return (double)(abs(abs(y2)-abs(y1)) * (x2 - x1)) / 2;
}

double trapez(vector<pair<int, int> >& dots){
    double area = 0;
    for (int i = 0; i < 3; ++i) {
        area +=  (dots[i % 4].first * dots[(i+1)% 4].second - dots[(i+1) % 4].first * dots[i % 4].second);
    }
    return area/2;
}



int main()  {
    int test_case;
    string empty_line;
    cin >> test_case;
    while (test_case--) {
        getline(cin, empty_line);
        int dots_count, x, y, width;
        double init_percent, consume, water_falling;
        vector<pair<int,int>> dots;
        cin >> dots_count;
        while (dots_count--)    {
            cin >> x >> y;
            dots.push_back(make_pair(x, y));
        }
        cin >> width;
        cin >> init_percent >> consume >> water_falling;
        long double area = 0;
        for (int i = 0; i < dots.size()-1; ++i) {
            if(i == 0 || i == dots.size() -2){
               area += triangle(dots[i].first, dots[i].second,dots[i+1].first, dots[i+1].second);
            } else{
                vector<pair<int, int> > curr;
                curr.push_back(make_pair(dots[i].first, 0));
                curr.push_back(make_pair(dots[i].first, dots[i].second));
                curr.push_back(make_pair(dots[i+1].first, dots[i+1].second));
                curr.push_back(make_pair(dots[i+1].first, 0));
                area += trapez(curr);
            }
        }
        area *= width;
        double percent = (area * init_percent / 100) - consume;
        if(percent < 0 ){
            cout << "Lack of water. ";
            percent = 0;
        }
        percent += water_falling;
        if (percent > area){
            cout << "Excess of water. Final percentage: 100%" << endl;
        } else{
            cout << "Final percentage: " << (int)(percent / area * 100) << "%" << endl ;
        }


    }
}


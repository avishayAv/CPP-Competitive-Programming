
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

//Calculates ones until (num-1)
ll countOnes(ll num)    {
    ll sum = 0;
    ll bits = log2(num) + 1;
    while (bits)    {
        ll next_pow2 = pow(2, bits);
        ll distance = num%next_pow2;
        ll msb_ones = (num-distance) / 2;   //ones until next_pow2
        ll leftovers = 0;
        ll less_pow2 = pow(2, bits-1);
        if (distance > less_pow2)   {
            leftovers = distance-less_pow2;     //ones lefted-overs between next_pow2 and less_pow2
        }
        sum += msb_ones + leftovers;
        bits--;
    }
    return sum;
}

int main() {
    ll a,b;
    while (scanf("%lld %lld",&a,&b) == 2)   {
        ll countA = countOnes(a);
        ll countB = countOnes(b+1);
        cout << countB - countA << endl;
    }
    return 0;
}
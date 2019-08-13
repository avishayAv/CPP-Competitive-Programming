
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


void paintHull(vector<vector<char> >& letters, int i, int j, char letter){
    if(letter == '#'){
        return;
    }
    if (i < 0 || i >= letters.size()) return;
    if (j < 0 || j >= (letters[0].size())) return;
    if (letters[i][j] != letter)
        return;
    letters[i][j] = '#';
    paintHull(letters, i + 1, j, letter);
    paintHull(letters, i - 1, j, letter);
    paintHull(letters, i, j + 1, letter);
    paintHull(letters, i, j - 1, letter);

}




int main() {
    int num_cases;
    cin >> num_cases;
    int H, W;

    for (int l = 1; l <= num_cases ; ++l) {

        cin >> H >> W;
        vector<vector<char> > letters(H, vector<char>(W));
        vector<int> hist(26,0);
        for (int i = 0; i < H ; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> letters[i][j];
            }
        }
        for (int i = 0; i < H ; ++i) {
            for (int j = 0; j < W; ++j) {
                if (letters[i][j] != '#') {
                    hist[letters[i][j] -'a']++;
                    paintHull(letters,i,j,letters[i][j]);
                }
            }
        }
        cout << "World #" << l << endl;
        vector<pair<char,int>> items(26);
        for (int m = 0; m < 26; ++m) {
            items[m]=pair<char,int>('a'+m,hist[m]);
        }
        auto cmp = [](std::pair<char,int> const & a, std::pair<char,int> const & b)
        {
            return a.second != b.second?  a.second < b.second : a.first > b.first;
        };
        std::sort(items.begin(), items.end(), cmp);
        for (int k = items.size()-1; k >=0 ; --k) {
            if (items[k].second != 0){
                printf("%c: %d\n",items[k].first,items[k].second);
            }
        }
    }
    return 0;
}
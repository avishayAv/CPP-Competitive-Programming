
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

void toBinary(vector<int>& binary, char c)   {
    switch(c)   {
        case '0':
            binary.push_back(0);
            binary.push_back(0);
            binary.push_back(0);
            binary.push_back(0);
            break;
        case '1':
            binary.push_back(0);
            binary.push_back(0);
            binary.push_back(0);
            binary.push_back(1);
            break;
        case '2':
            binary.push_back(0);
            binary.push_back(0);
            binary.push_back(1);
            binary.push_back(0);
            break;
        case '3':
            binary.push_back(0);
            binary.push_back(0);
            binary.push_back(1);
            binary.push_back(1);
            break;
        case '4':
            binary.push_back(0);
            binary.push_back(1);
            binary.push_back(0);
            binary.push_back(0);
            break;
        case '5':
            binary.push_back(0);
            binary.push_back(1);
            binary.push_back(0);
            binary.push_back(1);
            break;
        case '6':
            binary.push_back(0);
            binary.push_back(1);
            binary.push_back(1);
            binary.push_back(0);
            break;
        case '7':
            binary.push_back(0);
            binary.push_back(1);
            binary.push_back(1);
            binary.push_back(1);
            break;
        case '8':
            binary.push_back(1);
            binary.push_back(0);
            binary.push_back(0);
            binary.push_back(0);
            break;
        case '9':
            binary.push_back(1);
            binary.push_back(0);
            binary.push_back(0);
            binary.push_back(1);
            break;
        case 'a':
            binary.push_back(1);
            binary.push_back(0);
            binary.push_back(1);
            binary.push_back(0);
            break;
        case 'b':
            binary.push_back(1);
            binary.push_back(0);
            binary.push_back(1);
            binary.push_back(1);
            break;
        case 'c':
            binary.push_back(1);
            binary.push_back(1);
            binary.push_back(0);
            binary.push_back(0);
            break;
        case 'd':
            binary.push_back(1);
            binary.push_back(1);
            binary.push_back(0);
            binary.push_back(1);
            break;
        case 'e':
            binary.push_back(1);
            binary.push_back(1);
            binary.push_back(1);
            binary.push_back(0);
            break;
        case 'f':
            binary.push_back(1);
            binary.push_back(1);
            binary.push_back(1);
            binary.push_back(1);
            break;
    }
}

void paintBackGround(vector<vector<int>>& binary, int i, int j) {
    if (i<0 || i>=binary.size()) return;
    if (j<0 || j>=(binary[0].size())) return;
    if (binary[i][j] != 0) return;
    binary[i][j] = 2;
    paintBackGround(binary, i+1, j);
    paintBackGround(binary, i-1, j);
    paintBackGround(binary, i, j+1);
    paintBackGround(binary, i, j-1);
}

void paintHull(vector<vector<int>>& binary, int i, int j)   {
    if (i < 0 || i >= binary.size()) return;
    if (j < 0 || j >= (binary[0].size())) return;
    if (binary[i][j] != 0) return;
    binary[i][j] = 4;
    paintHull(binary, i + 1, j);
    paintHull(binary, i - 1, j);
    paintHull(binary, i, j + 1);
    paintHull(binary, i, j - 1);
}

void recognizeLetter(vector<vector<int>>& binary, int i, int j, int& count) {
    if (i < 0 || i >= binary.size()) return;
    if (j < 0 || j >= (binary[0].size())) return;
    if (binary[i][j] == 0) {
        count++;
        paintHull(binary, i, j);
    }
    if (binary[i][j] != 1) return;
    binary[i][j] = 3;
    recognizeLetter(binary, i + 1, j, count);
    recognizeLetter(binary, i - 1, j, count);
    recognizeLetter(binary, i, j + 1, count);
    recognizeLetter(binary, i, j - 1, count);
}

char whichLetter(int count) {
    switch (count)  {
        case 0 : return 'W';
        case 1 : return 'A';
        case 2 : return 'K';
        case 3 : return 'J';
        case 4 : return 'S';
        case 5 : return 'D';
    }
}

int main()  {
    int test_case = 1;
    int H,W;
    cin >> H >> W;
    while (H!=0 || W!=0)    {
        vector<vector<char>> image_hexa;
        vector<vector<int>> binary;
        vector<char> letters;
        char temp;
        for (int i=0; i<H; i++) {
            image_hexa.push_back(vector<char>());
            binary.push_back(vector<int>());
            for (int j=0; j<W; j++) {
                cin >> temp;
                image_hexa[i].push_back(temp);
                toBinary(binary[i], temp);
            }
        }

        for (int j=0; j<4*W-1; j++) {
            paintBackGround(binary, 0, j);
            paintBackGround(binary, H-1, j);
        }
        for (int i=1; i<H-1; i++)   {
            paintBackGround(binary, i, 0);
            paintBackGround(binary, i, 4*W-1);
        }

        for (int i=0; i<H; i++) {
            for (int j=0; j<4*W; j++) {
                if (binary[i][j] == 1) {
                    int count = 0;
                    recognizeLetter(binary, i, j, count);
                    letters.push_back(whichLetter(count));
                }
            }
        }

        sort(letters.begin(), letters.end());
        cout << "Case " << test_case++ << ": ";
        for (int i=0; i<letters.size(); i++)    {
             cout << letters[i];
        }
        cout << endl;
        cin >> H >> W;
    }

    return 0;
}
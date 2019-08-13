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

struct unionfind
{
    vector<int> rank;
    vector<int> parent;
    vector<int> tree;
    unionfind(int size) {
        rank=vector<int>(size,0);
        parent=vector<int>(size);
        tree=vector<int>(size);
        for(int i=0;i<size;i++) {
            parent[i]=i;
            tree[i]=1;
        }

    }
    int find(int x){
        int tmp=x;
        while(x!=parent[x]) x=parent[x];
        while(tmp!=x) {
            int remember=parent[tmp];
            parent[tmp]=x;
            tmp=remember; }
        return x;
    }
    void Union(int p, int q){
        p = find(p);
        q = find(q);
        if(q==p)
        {
            return;
        }
        if(rank[p] < rank[q]) {
            parent[p] = q;
            tree[q]+=tree[p];
        }

        else {
            parent[q] = p;
            tree[p]+=tree[q];
        }
        if(rank[p] == rank[q])
            rank[p]++;
    }
    int size (int x)    {
        return tree[find(x)];
    }
};

int main()  {
    int test_cases;
    cin >> test_cases;
    while (test_cases--)    {
        int friendships;
        int count = 1;
        int person1, person2;
        string name1, name2;
        map<string, int> maps;
        cin >> friendships;
        unionfind friends_record(friendships*4);
        while (friendships--)   {
            cin >> name1;
            cin >> name2;
            /*for (int i=0; i<name1.length(); i++)    {
                name1[i] = toupper(name1[i]);
            }
            for (int i=0; i<name2.length(); i++)    {
                name2[i] = toupper(name2[i]);
            }*/
            if (maps.find(name1) != maps.end())  {
                person1 = maps.find(name1)->second;
            } else  {
                person1 = count;
                maps.insert(make_pair(name1, count));
                count++;
            }
            if (maps.find(name2) != maps.end())  {
                person2 = maps.find(name2)->second;
            } else  {
                person2 = count;
                maps.insert(make_pair(name2, count));
                count++;
            }
            friends_record.Union(person1, person2);
            cout << friends_record.size(person1) << endl;
        }
    }
    return 0;
}


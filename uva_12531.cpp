#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    while (scanf("%d", &num)!=EOF)    {
        if (num % 6 == 0)   {
            cout << "Y" << endl;
        }
        else    {
            cout << "N" << endl;
        }
    }

    return 0;
}
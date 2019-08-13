#include <iostream>

using namespace std;

int main() {
    int test_cases;
    int length, width, height;
    int count = 1;
    cin >> test_cases;
    while (count <= test_cases)    {
        cin >> length >> width >> height;
        cout << "Case " + to_string(count);
        if (length <= 20 && width <= 20 && height <= 20)    {
            cout << ": good" << endl;
        }
        else    {
            cout << ": bad" << endl;
        }
        count++;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

bool checkIfWon(vector<string> board, char c)   {
    if ((board[0][0] == c && board[0][1] == c && board[0][2] == c) ||
            (board[1][0] == c && board[1][1] == c && board[1][2] == c) ||
            (board[2][0] == c && board[2][1] == c && board[2][2] == c) ||
            (board[0][0] == c && board[1][0] == c && board[2][0] == c) ||
            (board[0][1] == c && board[1][1] == c && board[2][1] == c) ||
            (board[0][2] == c && board[1][2] == c && board[2][2] == c) ||
            (board[0][0] == c && board[1][1] == c && board[2][2] == c) ||
            (board[0][2] == c && board[1][1] == c && board[2][0] == c))
        return true;
    return false;
}

int main()  {
    int test_cases;
    vector<string> board(3);
    cin >> test_cases;
    while (test_cases--)    {
        //get 3 lines
        for (int row = 0; row < 3; row++)   {
                cin >> board[row];
        }
        int count_first = 0;
        int count_second = 0;
        for (int row = 0; row < 3; row++)   {
            for (int col = 0; col < 3; col++)   {
                count_first += (board[row][col] == 'X');
                count_second += (board[row][col] == 'O');
            }
        }
        if ((count_first == count_second) || (count_first == count_second + 1)) {
            if (count_first == count_second)    {
                //if x wins its illegal
                bool illegal = checkIfWon(board, 'X');
                if (illegal) cout << "no" << endl;
                else cout << "yes" << endl;
            }
            else    {
                //if 0 wins its illegal
                bool illegal = checkIfWon(board, 'O');
                if (illegal) cout << "no" << endl;
                else cout << "yes" << endl;
            }
        }
        else    {
            cout << "no" << endl;
        }
    }
    return 0;
}
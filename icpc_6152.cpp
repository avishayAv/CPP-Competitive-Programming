#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count_char(string str, char c)  {
    int count = 0;
    for (int i=0; i<str.size(); i++)    {
        if (str[i]==c) count++;
    }
    return count;
}

int main() {
    string s,t;
    int test_cases;
    int case_id = 0;
    cin >> test_cases;
    while (test_cases--)    {
        case_id++;
        cin >> s;
        cin >> t;
        int s_zero = count_char(s, '0');
        int s_one = count_char(s, '1');
        int s_ques = count_char(s, '?');
        int t_zero = count_char(t, '0');
        int t_one = count_char(t, '1');
        if (s_one > t_one) {
            printf("Case %d: -1\n", case_id);
            continue;
        }
        int count=0;
        for (int i=0; i<s.size(); i++)  {
            if (s[i] == '?')    {
                count++;
                if (t[i] == '1' && t_one > s_one)   {
                    s[i] = '1';
                    s_one++;
                }
                else if ((t[i] == '1' && t_one <= s_one))   {
                    s[i] = '0';
                    s_zero++;
                }
                else if (t[i] == '0' && t_zero > s_zero)    {
                    s[i] = '0';
                    s_zero++;
                }
                else if ((t[i] == '0' && t_zero <= s_zero)) {
                    s[i] = '1';
                    s_one++;
                }
                else    {
                    s[i] = '0';
                    s_zero++;
                }
            }
        }
        if (t_one > s_one)  {
            for (int i=0; i<s.size(); i++)  {
                if (t[i] == '1' && s[i] == '0' && t_one > s_one) {
                    s[i] = '1';
                    s_zero--;
                    s_one++;
                    count++;
                }
            }
        }
        if (t_one > s_one)  {
            for (int i=0; i<s.size(); i++ && t_one > s_one)  {
                if (s[i] == '0') {
                    s[i] = '1';
                    s_zero--;
                    s_one++;
                    count++;
                }
            }
        }
        int count_swaps = 0;
        for (int i=0; i<s.size(); i++)  {
            if (s[i] != t[i]) count_swaps++;
        }
        count += (count_swaps / 2);
        printf("Case %d: %d\n", case_id, count);
    }
    return 0;
}
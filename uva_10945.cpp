#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string str)   {
    int len = str.size();
    for (int i=0; i<len/2; i++)   {
        if (str[i] != str[len-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string sentence;
    int length;
    getline(cin, sentence);
    string sentence_no_punct;
    length = sentence.size();
    for (int i=0; i < length ; i++)    {
        if (!ispunct(sentence.at(i)) && !isspace(sentence.at(i))) {
            sentence_no_punct.push_back(sentence.at(i));
        }
    }
    transform(sentence_no_punct.begin(), sentence_no_punct.end(), sentence_no_punct.begin(), ::toupper);

    while (sentence_no_punct.compare("DONE")!=0) {
        if (isPalindrome(sentence_no_punct)) {
            cout << "You won't be eaten!" << endl;
        }
        else {
            cout << "Uh oh.." << endl;
        }
        sentence = "";
        sentence_no_punct = "";
        getline(cin, sentence);
        length = sentence.size();
        for (int i=0; i < length ; i++)    {
            if (!ispunct(sentence.at(i)) && !isspace(sentence.at(i))) {
                sentence_no_punct.push_back(sentence.at(i));
            }
        }
        transform(sentence_no_punct.begin(), sentence_no_punct.end(), sentence_no_punct.begin(), ::toupper);
    }

    return 0;
}
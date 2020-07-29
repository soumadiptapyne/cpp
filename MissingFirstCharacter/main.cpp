/*
 * Author:Soumadipta Pyne
 * Program: First missing alphabet

Given a string, find the first missing alphabet.

======================

Example
Input:  "@aYBed56$=CAg"
Output: 'f'

This input string contains characters a/A,B,C,d,e, but f is missing before g.
 */


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    string s1{};
    string temp{};
    
    cout << "Enter your message: ";
    getline(cin, s1);
 
 //ignore any other character apart from alphabets
    for (size_t i = 0; i < s1.size(); ++i)
    {
        if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z'))
        {
            temp += s1[i];
        }
    }
    
    s1 = temp;
    
//convert all the alphabet to lower case
    for_each(s1.begin(), s1.end(), [](char & l) {
        l = tolower(l);
    });
    cout << "Output String: " << s1 <<endl;
 
//first missing alphabet
    string alphabet {"abcdefghijklmnopqrstuvwxyz"};
    string missing{};
    
    for(char c:alphabet)
    {
        size_t mp = s1.find(c);
        if(mp == string::npos)
            {
                cout<<c<<endl;
                break;
            }
    }
    cout << missing<<endl;
    
    cout<<endl;
    return 0;
}

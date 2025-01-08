//
//  main.cpp
//  URLify
//
//  Created by daniel saghbine on 12/9/24.
//
//  CTCI 1.3 URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string. (Note: If implementing in Java, please use a character array so that you can perform this operation in place.)
//  Auxiliary space complexity: O(1). Time complexity: O(n^2).

#include <iostream>
using namespace std;

void URLify(string &s, int n);

int main()
{
    string str;
    int num;
    
    cout<<"Type a string: ";
    getline(cin, str);
    cout<<"Type the number of characters: ";
    cin>>num;
    
    URLify(str, num);
    
    cout<<"The URLified string is: "<<str<<endl;
    
    return 0;
}

void URLify(string &s, int n) // s is a C++ string and n is the "true" length of it
{
    for(int u=0; u < n && n < s.size(); u++) // check char at indices 0...n-1 in string
    {
        if(s[u] == ' ') // u is index of space
        {
            for(int r=1; r <= 2; r++) // repeat 2 times
            {
                for(int i=n-1; i >= u; i--) // check char at indices n-1...u in string
                    s[i+1]=s[i]; // shift every char one index to right
                
                n++; // increment upper bound n to accomodate the space made around the original space char at index u
                u++; // move lower bound u to next index in string after room next to original space char gets made
            }
            
            s[u-2]='%'; // insert '%' at index u-2 in string
            s[u-1]='2'; // insert '2' at index u-1 in string
            s[u]='0'; // insert '0' at index u in string
        }
    }
}

//
//  main.cpp
//  CTCI 1.3 URLify
//
//  Created by daniel saghbine on 12/9/24.
//

#include <iostream>
using namespace std;

void URLify(string &s, int n);

int main()
{
    cout<<"problem\n-------\n\tWrite a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the \"true\" length of the string. (Note: If implementing in Java, please use a character array so that you can perform this operation in place.)\n\n";
    
    cout<<"input\n-----\n\tType: ";
    string str;
    int num;
    getline(cin, str);
    cout<<"\tType its \"true\" length: ";
    cin>>num;
    
    URLify(str, num);
    
    cout<<"\noutput\n------\n\t\""<<str<<"\"\n\n";
    
    cout<<"solution\n--------\n\tAuxiliary space complexity: O(1); time complexity: O(n^2).\n\n";
    
    return 0;
}

void URLify(string &s, int n) // s is input string and n is input size
{
    for(int u=0; u < n && n < s.size(); u++) // check char at indices 0...n-1 in s and n stays within size of s
    {
        if(s[u] == ' ') // if char at u in s is a space
        {
            for(int r=1; r <= 2; r++) // repeat twice
            {
                for(int i=n-1; i >= u; i--) // check char at indices n-1...u in s
                    s[i+1]=s[i]; // shift every char one index to right in s
                
                n++; // increment upper bound n to accomodate the space made around the original space char at index u
                u++; // increment lower bound u to next index in s after room next to original space char gets made
            }
            
            s[u-2]='%'; // insert '%' at index u-2 in s
            s[u-1]='2'; // insert '2' at index u-1 in s
            s[u]='0'; // insert '0' at index u in s
        }
    }
}

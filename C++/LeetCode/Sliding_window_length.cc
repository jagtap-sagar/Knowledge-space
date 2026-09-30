/*
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

  */

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
     string s = "abcabcbdeb" ;//"abcabcdbb" ;//"abcabcbb";
     int left =0 , maxlen =0;
     unordered_set<char> window;
     //for (ch : s) {
     for (int right =0; right < s.size() ; ++right) {
        cout<<"\n right :"<<right << " s[right] :"<<s[right]; 
        while(window.count(s[right])) { //which equivalent while (window.find(s[right]) != window.end()) {
              // check given char present in set or not.
             cout<<"\n left :"<<left << " s[left] :"<<s[left]<<"\n";
          
            window.erase(s[left]);
            cout<<"\n ";
             for (auto ch : window) 
            cout<< "=="<<ch ;
            left++;
        }   
        // not match in set then add into set.
        window.insert(s[right]) ;
        
        cout<<"\n ------------------------- :";
        for (auto ch : window) 
           cout<< " "<<ch ;
         
        int len = right - left +1 ;
        maxlen = max(maxlen ,len);
     }

    cout<< " len:"<<maxlen;

    return 0;
}

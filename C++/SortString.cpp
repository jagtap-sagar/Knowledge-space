/* 
Very Kharatnak Logic for cummulative count
  */


#include<iostream>

using namespace std;

int const RANGE =26;

void SortString(string& str){
    int len = str.length();

    int count[RANGE]={0};
    char out[len+1];

    for (int i=0;i<len;++i){
        count[str[i]-'a']++;
    }
    //print the count 
    for (int i=0;i<RANGE;++i){
        cout<<" "<<count[i];
    }

    // Modify count array to store cumulative
  	// position of characters
    for (int i=1;i<RANGE;++i){
        count[i] += count[i - 1];
    }

    cout<<"\n";
    for (int i=1;i<RANGE;++i){
        cout<<" "<<count[i];
    }

    cout<<"\n";
    // Building output array based on the 
  	// cumulative positions
      for (int i = len - 1; i >= 0; i--) {
        int c = count[str[i] - 'a'] - 1;
        cout<<" c="<<c;
       // out[count[str[i] - 'a'] - 1] = str[i];
       out[c]=str[i];
        count[str[i] - 'a']--;
    }
    out[len] = '\0';
    str= out;
}

int main () {
    string str ="banana";//"geeksforgeeks";
    SortString(str);

    cout<<"\n Sorted String :"<<str;
}

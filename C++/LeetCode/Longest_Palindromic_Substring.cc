class Solution {
public:

      string check(string str) {
        int  right = str.length()-1;

        for (int left =0 ; left < right; left++, --right) {
            if (str[left]!= str[right])
                return "" ;
        }
        
        return str;
    }

    int expand(string& s, int left , int right) {
       // while( left >=0 && right < s.length() && s[left] == s[right]) {
           while( left >=0 && right < s.length() ) {
                if( s[left] == s[right]) {
                    --left;
                    ++right ; 
                } else {break ; }
                    
           }
           // --left;
            //++right ; 
        //}
        return (right - left -1);
    }
    
    string longestPalindrome(string s) {
        /*
         My Own logic 
         /// used sliding window 
        int k =2; 
        int len = s.length();//size() -1 ;
        int mid = len /2 ;
        string ans = "",maxstr="";
       // int i =0;
        for (;k<=len ; ++k){
            int i =0;
            for ( ; i<len ; ++i){
                ans= check ( s.substr(i,k) );
                if ( ! ans.empty() ) {
                    cout<<"\n ***** ans : "<<ans;
                    //maxstr=std::max(maxstr,ans);
                    maxstr = (maxstr.length() > ans.length() ? maxstr : ans); 
                    cout<<"  +++ maxstr : "<<maxstr<<" ";
                }
                //cout<<"\n maxstr : "<<maxstr;
            }
            //i =k;
           // maxstr=std::max(maxstr,ans);
        }
        return maxstr;
    }
        */

         /// Two pointer Technique /pattern
        if (s.empty()) return "";
        if (s.length() == 1) return s;

        int start = 0, maxlen =1;

        for (int i=0; i < s.length(); ++i) {
            //below code for Even string
            int len1 = expand(s,i,i); 

            //below code for Odd string
            int len2 = expand(s,i,i+1);

            int len =std::max(len1,len2); 
            if ( len > maxlen) {
                maxlen =len ;
                //Now  change , starting point
                // TODO **** very IMP & not undertood fully *****
                start = i - (len -1)/2;
            }

        }// for 
        return s.substr(start, maxlen);


    }
       

};

int main () {
    Solution obj;
    string str = "cxabba"; //"aabbaabcd"; //"racecar";
    cout<<" \n " <<obj.longestPalindrome(str);
    
    return 0;
}

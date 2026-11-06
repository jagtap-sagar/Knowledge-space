bool isPalindrome(int x) {
        if (x < 0) return false;

        string str = std::to_string(x);
        int last = str.size()-1;
        int first = 0;
        while(first<last){
            if (str[first] !=str[last]) return false;
            else {
                ++first;
                --last;
            }
        }//while
        return true;
    }

=================================
  bool isPalindrome( const int x) {
    if (x < 0 ) return false;
    
    if (x !=0) {
        int reverse =0, digit =0;
        int num = x;
        while (num > 0) {
            digit = num % 10;
            reverse = reverse *10 + digit;
            num /=10;
        }    
        if (reverse == x) return true;
    }
    return false;
}

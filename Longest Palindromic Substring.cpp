// T.C. : O(n^3) and S.C. : o(n) 
//check for each substring for palindrome and get the max length substring which is palindrome.
bool is_palindrome(string s){
    string rev = s;
    reverse(rev.begin() , rev.end());
    return s == rev;
}
class Solution {
public:
    string longestPalindrome(string s) {
       
        int n = s.size();
        int best_len = 0;
        string best_sub = "";
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j< n ;j++){
                int len = j - i + 1;
                if(len > best_len and is_palindrome(s.substr(i , len))){
                    best_len = len ;
                    best_sub = s.substr(i , len);
                }
            }
        }
        return best_sub;
    }
};


//T.C. : O(n^2) and S.C. : o(n) 
//use the property that if a substring L to R is pallindrome than a substring L+1 to R-1 is also a pallindrome , use the property of resusing the values 
//to optimise the soln , this is dp .
//we will split the substring based on mid element and will check the element before and after mid if it is pallindrome or not , this will make complexity as quadratic
bool is_palindrome(string s){
    string rev = s;
    reverse(rev.begin() , rev.end());
    return s == rev;
}
class Solution {
public:
    string longestPalindrome(string s) {
       
        int n = s.size();
        int best_len = 0;
        string best_sub = "";
        for(int mid = 0; mid < n ; mid++){
            for(int i = 0; mid-i >= 0 and mid+i < n; i++){
                if(s[mid-i] != s[mid+i])
                    break;
                int len = 2 * i + 1;
                if(len > best_len){
                    best_len = len;
                    best_sub = s.substr(mid - i , len);
                }
            }
        }
        
         for(int mid = 0; mid < n - 1 ; mid++){
            for(int i = 0; mid-i+1 >= 0 and mid+i < n; i++){
                if(s[mid-i+1] != s[mid+i])
                    break;
                int len = 2 * i;
                if(len > best_len){
                    best_len = len;
                    best_sub = s.substr(mid - i + 1, len);
                }
            }
        }
        return best_sub;   
    }
};


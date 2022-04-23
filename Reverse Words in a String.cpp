//Say, s = " . . . a . . good . . . example . ." [ dot (.) means space here, as i cannt add multiple spaces in discussions! ]
//Step 1: Remove spaces from the beginning and ending. Now, s = "a . . good . . . example"
//Step 2: Now remove extra spaces from middle. Nows = "a good example"
//Step 3: Reverse the string. Now, s = "elpmaxe doog a"
//Step 4: Now reverse each word. Final s = "example good a"

//Code: T.C. : o(n) and S.C. : o(n)
class Solution {
public:
    string reverseWords(string s) {
        
    int n = s.size();
    string result ;
    int beg = 0 ;
    while(beg < n){    
    while(beg < n and s[beg] == ' ')
        beg++;
    if(beg >= n) break;    
    int end = beg+1;
    while(end < n and s[end] != ' ')
        end++;
    string sub = s.substr(beg , end-beg);
    if(result.size()==0)
        result = sub ;
    else result = sub + " " + result;
    beg = end+1;    
  }     
  return result; 
 }
};


//Code: T.C. : o(n) and S.C. : o(1)
class Solution {
public:
    string reverseWords(string s) {
        
        while(s[0] == ' ') s.erase(0, 1); //Remove spaces from the beginning
        while(s[s.size()-1]==' ') s.erase(s.size()-1); //Remove spaces from the ending
        
        int i = 0, space_count = 0;
		/*Now we count the middle spaces between two words, if more than one space
		found between two words, then remove it*/
        while(s[i])
        {
		
		   /*if the character is not space, then this is the starting of a new word. 
		   So, make the space count 0.*/
		   
            if(s[i] == ' ') space_count++;
            else space_count = 0; 
            if(space_count > 1) //more than one space found
            {
                s.erase(i,1);
                continue;
            }
            i++;
        }
        reverse(s.begin(),s.end());
        int left = 0;
        for(i=1;i<s.size();i++)
        {
            if(s[i] == ' ') // space found means we have a word in our left and we have to reverse it
            {
                reverse(s.begin()+left, s.begin()+i);
                left = i+1;
            }
            else if(i == s.size()-1)
            {
                reverse(s.begin()+left, s.begin()+i+1);
            }
        }
        return s;
    }
};

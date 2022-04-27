//T.C. o(n) and S.C. o(1)
//use the ques approach to subtract if less
class Solution {
public:
    int romanToInt(string s) {
        
        int n = s.size();
        
        map<char,int> mp;
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        
        int ans = mp[s[n-1]] ;
        
        for(int i = n-2; i >= 0; i--){
            
            if( mp[s[i]] < mp[s[i+1]] )
                ans -= mp[s[i]] ;
            else
                ans += mp[s[i]];
        }
       return ans; 
    }
};

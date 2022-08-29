class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0) return 0;
        
        //remove the white space from the first and make a substring
        int i = 0;
        while(i<s.size() && s[i] == ' '){
            i++;
        }
        s = s.substr(i);
        
        int sign = +1;
        long ans = 0;
        
        //check if the first index is + or - and if - return that and save in sign             variable
        
        if(s[0] == '-') sign = -1;
        int MIN = INT_MIN, MAX = INT_MAX;
        
        //if first element is any sign set the iteration from s[1] index-->
        
       i = (s[0] == '+' || s[0] == '-') ? 1:0;
        
        while(i<s.length()){
            if(s[0] == ' ' || !isdigit(s[i] )) break;
            
            ans  = ans * 10 + s[i] - '0';
            if(sign == -1 && -1*ans < MIN)return MIN;
            if(sign == 1 && ans > MAX)return MAX;
            
            i++;
            
         

        }
        
        return (int) (sign*ans);
    }
};
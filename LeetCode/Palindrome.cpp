class Solution {
public:
    bool isPalindrome(int x) {
        int z = x;
        int y = 0;

        if(x<0){
            return false;
        }
        
        while(x!=0){
        y = y*10 + x%10;
        x = x/10;
        }

        return y==z?true:false;
        
    }
};
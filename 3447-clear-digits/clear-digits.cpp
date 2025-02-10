class Solution {
public:
    string clearDigits(string s) {
         while (true) {
       
        int d1 = s.find_first_of("0123456789");

       
        if (d1 == string::npos) {
            break;
        }

      
        for (int i = d1; i > 0; --i) {
            if (! isdigit(s[i - 1])) {
                s.erase(i - 1, 1);  
                break;
            }
        }

        
        s.erase(d1 - 1, 1);  
    }

    return s;
    }
};
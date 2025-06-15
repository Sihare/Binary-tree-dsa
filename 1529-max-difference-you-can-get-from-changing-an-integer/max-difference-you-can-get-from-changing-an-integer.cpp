class Solution {
public:
    int maxDiff(int num) {
        string temp1=to_string(num);
        string temp2=to_string(num);
        char ch1='/';
        for(int i=0;i<temp1.size();i++){
            if(temp1[i]!='9'){
                ch1=temp1[i];
                break;
            }
        }
        for(int i=0;i<temp1.size();i++){
                if(temp1[i]==ch1){
                    temp1[i]='9';
                }
        }
        char ch2='/';
        int idx=-1;
        for(int i=0;i<temp2.size();i++){
            if(temp2[i]!='1' && temp2[i]!='0'){
                ch2=temp2[i];
                idx=i;
                break;
            }
        }
        if(idx==0){
            for(int i=0;i<temp2.size();i++){
                if(temp2[i]==ch2){
                    temp2[i]='1';
                }
            }
        }else if(idx!=-1){
            for(int i=0;i<temp2.size();i++){
                if(temp2[i]==ch2){
                    temp2[i]='0';
                }
            }
        }
        int num1=stoi(temp1);
        int num2=stoi(temp2);
        return num1-num2; 

    }
};
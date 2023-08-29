class Solution {
public:
    int bestClosingTime(string customers) {
        int y=0,n=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y') y++;
            else n++;
        }
        int score=y,ans=0,prevscore=y;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y'){
                score--;
                if(score<prevscore){
                    prevscore=score;
                    ans=i+1;
                }
            }
            else{
                score++;
            }

        }
        return ans;
    }
};

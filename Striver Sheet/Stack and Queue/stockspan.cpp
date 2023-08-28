class StockSpanner {
public:
vector<int> jumps,nums;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int n=nums.size(),i=n-1;
        int ans=1;
        while(i>-1){
            if(nums[i]<=price){
                ans+=jumps[i];
                i-=jumps[i];
            }
            else{
                break;
            }
        }
        jumps.push_back(ans);
        nums.push_back(price);
        return ans;
    }
};

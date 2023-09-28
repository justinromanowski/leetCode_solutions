class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minLoc = 0; //location of min stock price
        int maxLoc = 0; //location of max stock price
        int maxProfit = 0; //max profit
        int totalProfit = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < prices[minLoc]){
                minLoc = i;
                //cout << "Minloc @ " << minLoc << endl;
            }
            if((maxProfit < (prices[i]-prices[minLoc]))){
                maxProfit = prices[i]-prices[minLoc];
                totalProfit+=maxProfit;
                //cout << maxProfit << " @ " << i << " Total Profit: " << totalProfit << endl;
                maxProfit=0;
                maxLoc = i;
                minLoc = i;
            }
        }

        return totalProfit;
    }
};
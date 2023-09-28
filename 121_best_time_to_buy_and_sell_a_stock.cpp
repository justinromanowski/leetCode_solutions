class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minLoc = 0; //location of min stock price
        int maxLoc = 0; //location of max stock price
        int maxProfit = 0; //max profit
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < prices[minLoc]){
                minLoc = i;
            }
            if(maxProfit < (prices[i]-prices[minLoc])){
                maxLoc = i;
                maxProfit = prices[i]-prices[minLoc];
            }

            /*for(int j = i+1; j<prices.size(); j++){
                if((prices[j] - prices[i]) > maxProfit){
                    minLoc = i;
                    maxLoc = j; 
                    maxProfit = prices[maxLoc] - prices[minLoc];
                } 
            }*/
        }

        return maxProfit;
    }
};
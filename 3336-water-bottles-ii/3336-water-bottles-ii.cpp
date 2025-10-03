class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int drink = numBottles, empty = numBottles;
        int newBottles = 0;
        while(true){
            if(empty >= numExchange){
                empty -= numExchange;
                ++numExchange;
                drink++;
                empty++;
            }
            else{
                break;
            }
        }
        return drink + newBottles;

    }
};

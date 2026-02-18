class Solution {
  public:
   bool canPlaceCows(vector<int>& stallPositions, int numCows, int minDist) {
        int cowsPlaced = 1;                  
        int lastCowPosition = stallPositions[0];

        for (int i = 1; i < stallPositions.size(); i++) {
            if (stallPositions[i] - lastCowPosition >= minDist) {
                cowsPlaced++;                 
                lastCowPosition = stallPositions[i];
            }
            if (cowsPlaced >= numCows) return true; 
        }
        return cowsPlaced >= numCows;
    }
    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());  
        int n = stalls.size();
        
        int low = 1;                          
        int high = stalls[n-1] - stalls[0];    
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;   
            
            if (canPlaceCows(stalls, k, mid)) {
                ans = mid;                      
                low = mid + 1;
            } else {
                high = mid - 1;                  
            }
        }
        return ans;
    }
};

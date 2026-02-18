class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max_piles = 0;
        for (int i = 0; i < n; i++) {
            if (piles[i] > max_piles)
                max_piles = piles[i];
        }
        int low = 1;
        int high = max_piles;
        int ans = max_piles;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalHours = 0;
            for (int i = 0; i < n; i++) {
                totalHours += (piles[i] + mid - 1) / mid;
            }
            if (totalHours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

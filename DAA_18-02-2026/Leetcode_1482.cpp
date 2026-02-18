//UID:24BCS10773

class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int numBouquets,
                         int flowersPerBouquet, int days) {
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= days) {
                flowers++;
                if (flowers == flowersPerBouquet) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= numBouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if ((long long)m * k > n)
            return -1;

        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int minDaysRequired = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                minDaysRequired = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return minDaysRequired;
    }
};

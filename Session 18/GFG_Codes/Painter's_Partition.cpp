class Solution {
  public:
         bool canPaint(vector<int>& arr, int k, long long maxTime) {
        int painters = 1;
        long long current = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (current+ arr[i] > maxTime) {
                painters++;
                current = arr[i];
                if (painters > k) return false;
            } else {
                current += arr[i];
            }
        }
        return true;
    }

    int minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;
        for (int x : arr) high += x;

        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
        
    }
};

//UID:24BCS10773

//GFG: K Sized Subarray Maximum

//BRUTE FORCE
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int>res;
       int l=0;
       int r=k;
       while(r<=arr.size()){
           int maxE=arr[l];
       for(int i=l;i<r;i++){
           if(arr[i]>maxE){
          maxE=arr[i];
           }
       }
       res.push_back(maxE);
       l++;
       r++;
       }
        return res;
    }
};

//OPTIMAL APPROACH
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
  deque<int> dq;
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++) {
        if(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while(!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();
        dq.push_back(i);
        if(i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }
    return ans;
}};



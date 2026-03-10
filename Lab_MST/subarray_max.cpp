class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int>res;
       int l=0;
       int r=l+k;
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

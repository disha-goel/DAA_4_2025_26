#include<iostream>
#include<vector>
using namespace std;

int lowerbound(int x,vector<int>& arr){
    int left=0;
    int right=arr.size()-1;
    int ans=arr.size(); //if not found then ans would be equal to array size
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]>=x){
            ans=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return ans;
}
int upperbound(int x,vector<int>& arr){
    int left=0;
    int right=arr.size()-1;
    int ans=arr.size();
    while(left<=right){
        int mid=(left+right)/2;
         if(arr[mid]>x){
            ans=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
        return ans;
}
int main(){
    cout<<"Enter the size of the array"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the value to be searched"<<endl;
    int x;
    cin>>x;
    cout<<"Lower bound Index :"<<lowerbound(x,arr)<<endl;
     cout<<"Upper bound Index :"<<upperbound(x,arr)<<endl;

     return 0;
}
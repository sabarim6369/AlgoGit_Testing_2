class Solution {
public:
vector<vector<int>> threeSum
(vector<int>& nums) {
set<vector<int>>st;
sort(nums.begin(),nums.end());
int n=nums.size();
for(int i=0;i<n-2;i++){
int left=i+1;
int right=n-1;
while(left<right){
int sum=nums[left]+nums
[right]+nums[i];
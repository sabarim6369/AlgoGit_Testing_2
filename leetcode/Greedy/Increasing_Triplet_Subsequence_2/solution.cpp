class Solution {
public:
bool increasingTriplet(vector<int>&
nums) {
int first=INT_MAX,second=INT_MAX;
for(auto a:nums){
if(a<=first){
first=a;
}
else if(a<=second){
second=a;
else{
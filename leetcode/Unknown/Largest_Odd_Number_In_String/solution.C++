class Solution {
public:
string largestOddNumber(string num) {
int n=num.size();
for(int right=n-1;right>=0;right--){
if((num[right]-'0')%2!=0){
return num.substr(0,right+1);
}
return "";
};
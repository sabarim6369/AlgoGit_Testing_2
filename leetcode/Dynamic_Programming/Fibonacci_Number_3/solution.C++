class Solution {
public:
int fib(int n){
if(n==0)return 0;
int prevprev=0;
int prev=1;
for(int i=2;i<=n;i++){
int curr=prevprev+prev;
prevprev=prev;
prev=curr;
}
return prev;
};
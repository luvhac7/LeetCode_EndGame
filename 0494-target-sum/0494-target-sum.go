func findTargetSumWays(nums []int, tar int) int {
    s:=0
    for _,x:=range nums{
        s+=x
    }
    if s+tar<0 || (s+tar)%2!=0{
        return 0
    }
    sum:=(s+tar)/2
    dp:=make([]int,sum+1)
    dp[0]=1
    for _,i:=range nums{
        for j:=sum;j>=i;j--{
            dp[j]+=dp[j-i]
        }
    }
    return dp[sum]
}
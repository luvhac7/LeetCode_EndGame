func countPartitions(nums []int) int {
    ts:=0
    for _ , x:=range nums{
        ts+=x
    }
    if ts%2==0{
        return len(nums)-1
    }
    return 0
}
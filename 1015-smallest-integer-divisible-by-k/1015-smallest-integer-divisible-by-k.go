func smallestRepunitDivByK(k int) int {
if k%2 ==0 || k%5 ==0{
    return -1
}
rem:=0
for l:=1;l<=k;l++{
    rem=(rem*10+1)%k
    if rem==0{
        return l
    }
}
return -1
}
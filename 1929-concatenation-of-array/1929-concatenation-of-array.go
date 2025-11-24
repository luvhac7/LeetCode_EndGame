func getConcatenation(nums []int) []int {

    cs := append(nums,nums...)
    return cs
}
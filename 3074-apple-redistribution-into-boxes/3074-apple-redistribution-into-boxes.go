func minimumBoxes(apple []int, capacity []int) int {
    total := 0
    for _, a := range apple {
        total += a
    }

    sort.Slice(capacity, func(i, j int) bool {
        return capacity[i] > capacity[j]
    })

    curr := 0
    count := 0
    for _, cap := range capacity {
        curr += cap
        count++
        if curr >= total {
            break
        }
    }

    return count
}
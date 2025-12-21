func minDeletionSize(strs []string) int {
    n := len(strs)
    m := len(strs[0])

    // resolved[i] => strs[i] < strs[i+1] is finalized
    resolved := make([]bool, n-1)
    unresolved := n - 1
    deletions := 0

    for col := 0; col < m && unresolved > 0; col++ {
        needDelete := false

        // Check for lexicographical violation
        for row := 0; row < n-1; row++ {
            if !resolved[row] && strs[row][col] > strs[row+1][col] {
                needDelete = true
                break
            }
        }

        if needDelete {
            deletions++
            continue
        }

        // Update resolved row pairs
        for row := 0; row < n-1; row++ {
            if !resolved[row] && strs[row][col] < strs[row+1][col] {
                resolved[row] = true
                unresolved--
            }
        }
    }

    return deletions
}
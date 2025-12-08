import "math"

func countTriples(n int) int {
    count := 0

    for a := 1; a <= n; a++ {
        for b := 1; b <= n; b++ {
            sumSquares := a*a + b*b

            c := int(math.Sqrt(float64(sumSquares)))
            if c <= n && c*c == sumSquares {
                count++
            }
        }
    }

    return count
}
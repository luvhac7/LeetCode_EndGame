func sumFourDivisors(nums []int) int {
        divSum := 0

            for _, n := range nums {
                    divCount := 0
                            inSum := 0

                                    for d := 1; d*d <= n; d++ {
                                                if n%d == 0 {
                                                                other := n / d

                                                                                if d == other {
                                                                                                    divCount++
                                                                                                                        inSum += d
                                                                                                                                        } else {
                                                                                                                                                            divCount += 2
                                                                                                                                                                                inSum += d + other
                                                                                                                                                                                                }

                                                                                                                                                                                                                if divCount > 4 {
                                                                                                                                                                                                                                    break
                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                if divCount == 4 {
                                                                                                                                                                                                                                                                                            divSum += inSum
                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                            return divSum
                                                                                                                                                                                                                                                                                                            }

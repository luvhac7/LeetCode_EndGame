func findFirstNegative(nums []int) int {
    	l, r := 0, len(nums)-1

        	for l <= r {
            		mid := l + (r-l)/2
                    		if nums[mid] >= 0 {
                            			l = mid + 1
                                        		} else {
                                                			r = mid - 1
                                                            		}
                                                                    	}

                                                                        	return l
                                                                            }

                                                                            func countNegatives(grid [][]int) int {
                                                                            	ans := 0
                                                                                	for i := 0; i < len(grid); i++ {
                                                                                    		ans += len(grid[i]) - findFirstNegative(grid[i])
                                                                                            	}
                                                                                                	return ans
                                                                                                    }

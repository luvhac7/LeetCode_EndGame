func numberOfPaths(grid [][]int, k int) int {

        	const mod int = 1e9 + 7

            	gridHeight, gridWidth := len(grid), len(grid[0])
                	getCell := func(y, x int) int { return grid[y][x] }
                    	if gridHeight < gridWidth {
                        		gridWidth, gridHeight = gridHeight, gridWidth
                                		getCell = func(y, x int) int { return grid[x][y] }
                                        	}

                                            	curPathCounts := make([][]int, gridWidth)
                                                	prevPathCounts := make([][]int, gridWidth)
                                                    	for x := range gridWidth {
                                                        		curPathCounts[x] = make([]int, k)
                                                                		prevPathCounts[x] = make([]int, k)
                                                                        	}
                                                                                prevPathCounts[0][0] = 1

                                                                                	for y := range gridHeight {
                                                                                    		cell := getCell(y, 0) % k
                                                                                            		for i := range k {
                                                                                                    			curPathCounts[0][(i+cell)%k] = prevPathCounts[0][i] % mod
                                                                                                                		}

                                                                                                                        		for x := 1; x < gridWidth; x++ {
                                                                                                                                			cell := getCell(y, x) % k
                                                                                                                                            			for i := range k {
                                                                                                                                                        				curPathCounts[x][(i+cell)%k] =
                                                                                                                                                                        					(prevPathCounts[x][i] + curPathCounts[x-1][i]) % mod
                                                                                                                                                                                            			}
                                                                                                                                                                                                        		}
                                                                                                                                                                                                                		prevPathCounts, curPathCounts = curPathCounts, prevPathCounts
                                                                                                                                                                                                                        	}
                                                                                                                                                                                                                                return prevPathCounts[gridWidth-1][0]
                                                                                                                                                                                                                                }

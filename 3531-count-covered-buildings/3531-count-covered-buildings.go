package main

import (
	"sort"
)

func countCoveredBuildings(n int, buildings [][]int) int {
	row := make(map[int][]int)
	col := make(map[int][]int)

	for _, b := range buildings {
		x, y := b[0], b[1]
		row[x] = append(row[x], y)
		col[y] = append(col[y], x)
	}

	for k := range row {
		sort.Ints(row[k])
	}
	for k := range col {
		sort.Ints(col[k])
	}

	ans := 0
	for _, b := range buildings {
		x, y := b[0], b[1]
		ys := row[x]
		xs := col[y]
		posY := sort.SearchInts(ys, y)
		posX := sort.SearchInts(xs, x)
		insideRow := posY > 0 && posY < len(ys)-1
		insideCol := posX > 0 && posX < len(xs)-1
		if insideRow && insideCol {
			ans++
		}
	}
	return ans
}
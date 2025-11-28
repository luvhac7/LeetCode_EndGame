const MAXN = 30000

var adj [MAXN]uint16
var deg [MAXN]uint8
var stack [MAXN / 2]uint16

func maxKDivisibleComponents(n int, edges [][]int, values []int, k int) int {
	if n == 1 {
		return 1
	}
	for i := range n {
		adj[i] = 0
		deg[i] = 0
	}
	for _, e := range edges {
		adj[e[0]] ^= uint16(e[1])
		adj[e[1]] ^= uint16(e[0])
		deg[e[0]]++
		deg[e[1]]++
	}
	var s uint16
	pushstack := func(i uint16) {
		if deg[i] == 1 {
			stack[s] = i
			s++
		}
	}
	for i := range uint16(n) {
		pushstack(i)
	}
	result := 0
	for s != 0 {
		s--
		curr := stack[s]
		next := adj[curr]
		adj[next] ^= curr
		deg[next]--
		pushstack(next)
		values[curr] %= k
		if values[curr] == 0 {
			result++
		}
		values[next] += values[curr]
	}
	return result
}
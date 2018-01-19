package main

import (
    "fmt"
    "lib/graph"
)

func main() {
    g := [][]int{[]int{0, 2, 3, 0}, []int{0, 0, 0, 3}, []int{0, 5, 0, 2}, []int{0, 0, 0, 0}}
    maxFlow := graph.FordFulkerson(g, 0, 3)
    fmt.Println(maxFlow)
	g = [][]int{ []int{0, 16, 13, 0, 0, 0},
                 []int{0, 0, 10, 12, 0, 0},
                 []int{0, 4, 0, 0, 14, 0},
                 []int{0, 0, 9, 0, 0, 20},
                 []int{0, 0, 0, 7, 0, 4},
                 []int{0, 0, 0, 0, 0, 0}}
    maxFlow = graph.FordFulkerson(g, 0, 5)
    fmt.Println(maxFlow)
}

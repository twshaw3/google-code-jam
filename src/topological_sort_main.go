package main

import (
    "fmt"
    "lib/graph"
)

func main() {
    g := make(map[int][]int)
    g[5]= []int{2, 0}
    g[4] = []int{0, 1}
    g[3] = []int{1}
    g[2] = []int{3}
    g[1] = []int{}
    g[0] = []int{}
    fmt.Println("Running topological sort")
    sorted := graph.TopologicalSort(g)
    fmt.Println(sorted)
}

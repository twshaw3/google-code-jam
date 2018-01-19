package graph

import (
    "lib/math"
)

func bfs(g [][]int, s int, t int) (bool, []int) {
    visited := make([]bool, len(g))
    path := make([]int, len(g))
    q := make([]int, 0)
    q = append(q, s)
    for len(q) != 0 {
        current := q[0]
        q = q[1:]
        visited[current] = true
        for i := 0; i < len(g[current]); i++ {
            if visited[i] {
                continue
            }
            flow := g[current][i]
            if flow > 0 {
                q = append(q, i)
                path[i] = current
            }
        }
    }
    return visited[t], path
}

func FordFulkerson(g [][]int, s int, t int) int {
    maxFlow := 0
    for found, path := bfs(g, s, t); found; found, path = bfs(g, s, t) {
        pathFlow := 1000
        for node := t; node != s; node = path[node] {
            prev := path[node]
            flow := g[prev][node]
            pathFlow = math.Min(pathFlow, flow)
        }
        maxFlow += pathFlow
        for node := t; node != s; node = path[node] {
            prev := path[node]
            g[prev][node] -= pathFlow
            g[node][prev] += pathFlow
        }
    }
    return maxFlow
}

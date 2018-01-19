package graph

func TopologicalSort(g map[int][]int) []int {
    ret := make([]int, 0)
    inDegree := make(map[int]int)
    for u, vs := range(g) {
        _, found := inDegree[u]
        if !found {
            inDegree[u] = 0
        }
        for j := 0; j < len(vs); j++ {
            v := vs[j]
            d, found := inDegree[v]
            if found {
                inDegree[v] = d + 1
            } else {
                inDegree[v] = 1
            }
        }
    }
    q := make([]int, 0)
    for u, d := range(inDegree) {
        if d == 0 {
            q = append(q, u)
        }
    }
    for len(q) > 0 {
        u := q[0]
        ret = append(ret, u)
        q = q[1:]
        nbs := g[u]
        for i := 0; i < len(nbs); i++ {
            v := nbs[i]
            d, _ := inDegree[v]
            if d == 1 {
                q = append(q, v)
            }
            inDegree[v] = d - 1
        }
    }
    return ret
}

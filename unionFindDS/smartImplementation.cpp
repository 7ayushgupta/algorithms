int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set_size(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets_size(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
///And here is the implementation of union by rank based on the depth of the trees:

void make_set_rank(int v) {
    parent[v] = v;
    rank[v] = 0;
}

void union_sets_rank(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 10
#define AVG(a, b)((a + b) / 2)

int build(int *values, int *seg_tree, int s_interval, int e_interval, int bfs_posi);

int update(int new_value, int posi, int *seg_tree, int s_interval, int e_interval, int bfs_posi);

int query(int *seg_tree, int s_segment, int e_segment, int s_interval, int e_interval, int bfs_posi);

/**
 * Function main
 */
int main(int argc, char const *argv[]){

    // Alocação values
    int values[MAX] = {5, 10, 65, 1, 100, 1, 32, 45, 2, 75}, seg_tree_values[MAX * 4];
    // Set value 0 in array
    memset(seg_tree_values, 0, sizeof(int) * MAX * 4);

    build(values, seg_tree_values, 0, MAX, 0);

    for (int i = 0; i <= MAX * 3; i++)
        printf("%d; ", seg_tree_values[i]);
    printf("\n");
    
    printf("%d\n", query(seg_tree_values, 0, 1, 0, MAX, 0));

    return 0;
}

int build(int *values, int *seg_tree, int s_interval, int e_interval, int bfs_posi){
    if (s_interval == e_interval - 1) 
        return seg_tree[bfs_posi] = values[s_interval];

    int avg = AVG(s_interval, e_interval);
    seg_tree[bfs_posi] = build(values, seg_tree, s_interval, avg, bfs_posi * 2 + 1)
                    + build(values, seg_tree, avg, e_interval, bfs_posi * 2 + 2);

    return seg_tree[bfs_posi];
}

int update(int new_value, int posi, int *seg_tree, int s_interval, int e_interval, int bfs_posi){
    if (s_interval == e_interval - 1)
        return seg_tree[bfs_posi] = new_value;

    int avg = AVG(s_interval, e_interval);

    if (posi < avg)
        return seg_tree[bfs_posi] = seg_tree[bfs_posi * 2 + 2]
                                    + update(new_value, posi, seg_tree, s_interval, avg, bfs_posi * 2 + 1);
                                    
    return seg_tree[bfs_posi] = seg_tree[bfs_posi * 2 + 1]
                                + update(new_value, posi, seg_tree, avg, e_interval, bfs_posi * 2 + 2);
}

int query(int *seg_tree, int s_segment, int e_segment, int s_interval, int e_interval, int bfs_posi){
    if (s_segment >= e_interval || e_segment  <= s_interval)
        return 0;

    if (s_segment <= s_interval && e_segment >= e_interval)
        return seg_tree[bfs_posi];

    int avg = AVG(s_interval, e_interval);

    return query(seg_tree, s_segment, e_segment, s_interval, avg, bfs_posi * 2 + 1)
            + query(seg_tree, s_segment, e_segment, avg, e_interval, bfs_posi * 2 + 2);
}
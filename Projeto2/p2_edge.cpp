#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int org, dest, weight;
};

bool sortbyweight(const Edge &e1, const Edge &e2) {
    return (e1.weight > e2.weight); 
} 


struct Tree{
    int parent;
    int rank;
};

void make_set( int x, Tree * trees){
    trees[x].parent = x;
    trees[x].rank = 0;
}

int find_set(int x, Tree * trees){
    if (x != trees[x].parent){
        return trees[trees[x].parent].parent;
    }
    return x;
}

void link_set(int x, int y, Tree * trees){
    if (trees[x].rank > trees[y].rank){
        trees[y].parent = trees[x].parent;
        //trees[x].rank++;
        //trees[y].rank++;
    }
    else{
        trees[x].parent = trees[y].parent;
        if (trees[x].rank == trees[y].rank){
            trees[y].rank++;
            //trees[x].rank++;
        }
    }
}

void union_set(int x, int y, Tree * trees){
    link_set(find_set(x, trees), find_set(y, trees), trees);
}





int main()
{
    int num_vertices, num_edges;


    //Read the number of vertices
    scanf( "%d", &num_vertices);

    //Read the number of edges
    scanf( "%d", &num_edges);

    //Array of edges an their respective weights
    vector<Edge> edges;    //O(E)

    //Populate the edges array
    for (int i = 0; i < num_edges; i++){    //O(E)
        int org, dest, weight;
        if (scanf( "%d %d %d", &org, &dest, &weight) != 3){
            exit(1);
        };
        edges.push_back({org, dest, weight});
    }



    /**********************************KRUSKAL'S ALGORITHM**************************/
    int cost = 0;
    Tree trees[num_vertices];

    for (int i = 0; i < num_vertices; i++){
        make_set(i, trees);
    }

    sort(edges.begin(), edges.end(), sortbyweight); //O(ElogE)

    for (int i = 0; i < num_edges; i++){
        if (find_set(edges[i].org - 1, trees) != find_set(edges[i].dest - 1, trees)){
            cost += edges[i].weight;
            union_set(edges[i].org - 1, edges[i].dest - 1, trees);
        }
    }
    
/*******************************************************************************/

    printf( "%d\n", cost); 

    return 0;

    







    return 0;

}
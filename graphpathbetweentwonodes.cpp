/* C++ program to count all the possible paths
from a source to a destination */

#include <bits/stdc++.h>
using namespace std;

/* Modified dfs unction to count the possible
paths between 2 vertices */
void dfs(list<int> graph[], int s, int d, int *cnt, bool *visited)
{
    /*If we have reached the destination vetex
    then increase the path count by 1 */
    if(s == d){
        *cnt = *cnt+1;
        return ;
    }

    if(visited[s] == true)
        return;

    /*Mark the current vertex as visited*/
    visited[s] = true;
    list<int>::iterator it;

    /* Call to the modified dfs function on
    all the child nodes of the current vetex */
    for( it = graph[s].begin() ; it != graph[s].end() ; it++)
    {
        if(visited[*it] == false)
            dfs(graph, *it, d, cnt, visited);
    }

    /*Mark the current vertex as unvisited*/
    visited[s] = false;

    return;
}

// Function to count the possible paths between 2 vertices
int countPaths(list<int> graph[], int V, int s, int d)
{
    //Array to store visited vertices
    bool visited[V+1] = {false};

    //variable to count total number
    //of possible path b/w two vertices
    int count = 0;

    /*call to the modified DFS function with
    count variable passed by reference */
    dfs(graph, s, d, &count, visited);

    //return the possible paths between 2 vertices
    return count;
}

//Main Driver Code
int main() {

    int n = 5;
    int s = 1, d = 5;
    list <int> *adj = new list <int>[n + 1];

    adj[1].push_back (2);
    adj[1].push_back (3);
    adj[1].push_back (5);
    adj[2].push_back (4);
    adj[2].push_back (5);
    adj[3].push_back (5);
    adj[4].push_back (3);

    cout << countPaths(adj, n, s, d) << endl;

    return 0;
}

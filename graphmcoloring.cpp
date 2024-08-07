bool isafe(bool graph[][101],vector<int>&color,int c,int V,int node)
{
    for(int i=0;i<V;i++)
    {
        if(graph[node][i]==1 && color[i]==c)
        return false;
    }
    return true;
}
bool helper(bool graph[101][101],int m,int V,vector<int>&color,int node)
{
    if(node==V)
    return true;
    
    for(int i=0;i<m;i++)
    {
        if (color[node]==-1 && isafe(graph,color,i,V,node) )
        {
            color[node]=i;
            if(helper(graph,m,V,color,node+1))
            return true;
            else
            color[node]=-1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int>color(V,-1);
    return helper(graph,m,V,color,0);
    // your code here
}

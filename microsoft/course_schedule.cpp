class Solution {
/*
this is directed graph problem
as there is a prerequisite given that inorder to take course ai you must take bi first
hence there is a directed edge between bi to ai (bi -> ai)
so all courses can only be finished if there is isn't a cycle in given directed graph
so we have to check whether the given graph is a DAG or not
if it is then return true else return false

to detect cycle in given directed graph we will keep a check that the current node is residing on a visited path.

for that we should maintain to arrays vis array and pathVis array

every time we visit a node we will mark it as visited also we mark the path as visited
and when ever we back track from a path we mark path Visited as 0.

while doing these steps if we found a node which is visited and pathVisited then we return false because a cycle is detected in that path.

hence all these courses cannot be scheduled.
*/
private:
    bool dfs(int node,vector<int> adj[],int vis[],int pathVis[]){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)==false) return false;
            }
            else if(pathVis[it]) return false;
        }
        pathVis[node]=0;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        int vis[numCourses];
        int pathVis[numCourses];
        for(int i=0;i<numCourses;i++) vis[i]=pathVis[i]=0;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)==false) return false;
            }
        }
        return true;
    }
};
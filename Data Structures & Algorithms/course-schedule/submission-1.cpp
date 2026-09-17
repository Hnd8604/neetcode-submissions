class Solution {
   unordered_map<int, vector<int>> preMap;
   unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++){
            preMap[i] = {};
        }
        for(const auto& prereq : prerequisites){
            preMap[prereq[0]].push_back(prereq[1]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!dfs(i)) return false;
        }
        return true;
    }
    
private: 
    bool dfs(int crs){
        if(visiting.count(crs)) return false;
        if(preMap[crs].empty()) return true;
        visiting.insert(crs);
        for(int pre : preMap[crs]){
            if(!dfs(pre)) return false;
        }
        visiting.erase(crs);
        preMap[crs].clear();
        return true;
    }
};



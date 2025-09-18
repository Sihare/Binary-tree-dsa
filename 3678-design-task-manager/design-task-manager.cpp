class TaskManager {
public:
set<pair<int,int>>s;
map<int,int>task_user;
map<int,int>task_priority;
    TaskManager(vector<vector<int>>& tasks) {
       for(auto &i:tasks){
        int user=i[0];
        int task=i[1];
        int prio=i[2];
        s.insert({prio,task});
        task_user[task]=user;
        task_priority[task]=prio;
       } 
    }
    
    void add(int userId, int taskId, int priority) {
         s.insert({priority,taskId});
        task_user[taskId]=userId;
        task_priority[taskId]=priority;
    }
    
    void edit(int taskId, int newPriority) {
        int old=task_priority[taskId];
        s.erase({old,taskId});
        task_priority[taskId]=newPriority;
        s.insert({newPriority,taskId});
    }

    
    void rmv(int taskId) {
        int old=task_priority[taskId];
        s.erase({old,taskId});
        task_user.erase(taskId);
        task_priority.erase(taskId);
    }
    
    int execTop() {
         if(s.empty())return -1;
        pair<int,int>temp=*s.rbegin();
        s.erase(temp);
        return task_user[temp.second];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
class Solution {
public:
    string simplifyPath(string path) {
        deque<string>directoryName;
        istringstream ss(path);
        string token;
        while(getline(ss , token , '/')){
            
            if(token == "" || token == "."){
                continue;
            }
            
            if(token == ".."){
                if(!directoryName.empty()){
                    directoryName.pop_back();
                }
            }
            
            else{
                directoryName.push_back(token);
            }
        }
        if(directoryName.empty()){
            return "/";
        }
        
        string result;
        
        for(string it : directoryName){
            result += "/" + it;
        }
        return result;
    }
};
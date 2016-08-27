#include <string>
#include <iostream>

using namespace std;

void simplifyPathRecursive(string& path, string& simPath){
  size_t pos1 = path.find_first_not_of("/");
  if(pos1 == string::npos)
    return;
  size_t pos2 = path.find_first_of("/", pos1 + 1);
  string name = path.substr(pos1, pos2 - pos1);
  if(name == ".."){
    if(simPath.size() != 1){
      simPath.pop_back();
      size_t pos3 = simPath.find_last_of("/");
      simPath.erase(pos3 + 1, string::npos);
    }
  }
  else if(name != "."){
    simPath = simPath + name + "/";
  }
  path.erase(0, pos2);
  simplifyPathRecursive(path, simPath);
}

string simplifyPath(string path) {
  string simPath = "/";
  simplifyPathRecursive(path, simPath);
  if(simPath.size() > 1)
    return simPath.substr(0, simPath.size() - 1);
  return simPath;
}

int main(){
  string path = "/a/./b/../../c/";
  cout << path << "==>" << simplifyPath(path) << endl;
  path = "/.././/";
  cout << path << "==>" << simplifyPath(path) << endl;
}

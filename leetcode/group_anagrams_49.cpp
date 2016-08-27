#include <vector>
#include <iostream>
#include <map>
#include "../utils.h"
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  map<string, vector<string>> mp;
  for(string str : strs){
    string k = str;
    sort(k.begin(), k.end());
    auto it = mp.find(k);
    if(it == mp.end()){
      vector<string> vs{str};
      mp[k] = vs;
    }
    else{
      it->second.push_back(str);
    }
  }
  vector<vector<string>> groups;
  for(auto const & vs : mp){
    groups.push_back(vs.second);
  }
  return groups;
}

int main(){
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  cout << vectorToString(strs) << endl;
  auto groups = groupAnagrams(strs);
  cout << vectorVectorToString(groups) << endl;
}

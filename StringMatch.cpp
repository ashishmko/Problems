#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>



using namespace std;


class Finder {
  private:
    vector<string> list;
    vector<string> result;

  public:
    Finder(vector<string> &list) {
      this->list = list;
    }

    vector<string> find(const string &val) {
      result.clear();
      bool isSame;
      unordered_map<char, int> hashMap;
      for (int i = 0 ; i < this->list.size() ; i++ ) {
        if (val.length() == this->list[i].length()) {
          isSame = true;
          for (int j = 0 ; j < val.length() ; j++) {
            hashMap[val[j]] ++;
            hashMap[this->list[i][j]] ++;
          }
          for (int j = 0 ; j < val.length() ; j++) {
            if ((hashMap[val[j]]%2) != 0) {
              isSame =false;
              break;
            }
          }
          hashMap.clear();
          if(isSame) {
            result.push_back(this->list[i]);
          }
        }
      }
      return result;
    }

};


int main() {

  //Add the strings in this list to be compared with
  vector<string> v {"asd", "assd", "asda", "das"};

  
  Finder finder(v);
  vector<string> res;

  res = finder.find("sad");



  for (auto it: res)
    cout << it << endl;

  res = finder.find("sads");
  for (auto it: res)
    cout << it << endl;

}

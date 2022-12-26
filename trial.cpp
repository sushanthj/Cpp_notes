#include <iostream>
#include <map>
#include <functional>
#include <string>
using namespace std;

int main()
{
  std::multimap<std::string, int> Map;

  Map.insert(std::make_pair("Bot", 1111));
  Map.insert(std::make_pair("Bot", 1112));

  // Get all paris of a given key
  auto range = Map.equal_range("Bot");
  for(auto it = range.first; it != range.second; ++it)
  {
    cout << it->first << " " << it->second << endl;
  }
}
#include<bits/stdc++.h>
using namespace std;
class Router {
  int n;
  deque<tuple<int, int, int>> que;
  unordered_map<int, unordered_map<int, unordered_set<int>>> has;
  unordered_map<int, deque<int>> dests;

  public:
  Router(int memoryLimit) : n(memoryLimit) {}

  bool addPacket(int source, int destination, int timestamp) {
    auto [it, bo] = has[source][destination].insert(timestamp);
    if (bo) {
      dests[destination].push_back(timestamp);
      que.push_back({source, destination, timestamp});
      if (que.size() > n) {
        auto [a, b, c] = que.front();
        que.pop_front();
        has[a][b].erase(c);
        dests[b].pop_front();
      }
      return true;
    }
    return false;
  }

  vector<int> forwardPacket() {
    if (que.empty()) {
      return {};
    }
    auto [a, b, c] = que.front();
    que.pop_front();
    has[a][b].erase(c);
    dests[b].pop_front();
    return {a, b, c};
  }

  int getCount(int destination, int startTime, int endTime) {
    auto& v = dests[destination];
    return upper_bound(v.begin(), v.end(), endTime) -
      lower_bound(v.begin(), v.end(), startTime);
  }
};

/**
 *  * Your Router object will be instantiated and called as such:
 *   * Router* obj = new Router(memoryLimit);
 *    * bool param_1 = obj->addPacket(source,destination,timestamp);
 *     * vector<int> param_2 = obj->forwardPacket();
 *      * int param_3 = obj->getCount(destination,startTime,endTime);
 *       */

int main(){
  Router r(2);
  r.addPacket(1, 2, 10);
  r.addPacket(2, 3, 20);
  r.addPacket(3, 4, 30); // evicts first packet

  auto fwd = r.forwardPacket(); // should be {2, 3, 20}
for (int x : fwd) cout << x << " ";
cout << endl;

cout << r.getCount(4, 25, 35) << endl; // should be 1
return 0;
}

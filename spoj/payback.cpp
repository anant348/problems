#include <bits/stdc++.h>
using namespace std;

using matrix = vector<vector<int> >;


class Node {
public: 
  int node, val;
  Node(int node, int val) {
    this->node = node;
    this->val = val;
  }
  bool operator <(const Node &other)  const {
    return this->val < other.val;
  }

  bool operator >(const Node &other) const {
    return this->val > other.val;
  }
};

int totalFlux(matrix &m, int node) {
  int n = m.size();
  int total = 0;
  for (int i = 0; i < n; i++) {
    total += (-m[node][i]);
    total += m[i][node];
  }
  return total;
}

void minimize(matrix &m) {
  int n = m.size();
  vector<Node> nlist;
  vector<Node> plist;
  for (int i = 0; i < n; i++) {
    int f = totalFlux(m, i);
    if (f > 0) plist.push_back(Node(i, f));
    else if (f < 0) nlist.push_back(Node(i, f));
  }
  matrix ans;
  ans.assign(n, vector<int>(n, 0));
  priority_queue<Node, vector<Node>, greater<Node> > minQueue(nlist.begin(), nlist.end());
  priority_queue<Node, vector<Node>, less<Node> > maxQueue(plist.begin(), plist.end());
  while(!minQueue.empty()) {
    Node mintop = minQueue.top();
    Node maxtop = maxQueue.top();
    minQueue.pop(); maxQueue.pop();
    int mVal = min(abs(mintop.val), abs(maxtop.val));
    ans[mintop.node][maxtop.node] += mVal;
    if (mintop.val + mVal != 0) minQueue.push(Node(mintop.node, mintop.val + mVal));
    if (maxtop.val - mVal != 0) maxQueue.push(Node(maxtop.node, maxtop.val - mVal));
  }
  cout << n << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    matrix m(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        int v;
        cin >> v;
        m[i][j] = v;
      }
    }
    minimize(m);   
  }
}
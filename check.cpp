#include<bits/stdc++.h>

#define pii pair <int, int>
#define nd second
#define st first
using namespace std;

class Solution {
    public:
        struct node {
            node* nxt[26];
            int id, cnt; 
            node() {
                for (int i = 0; i < 26; i ++)
                    nxt[i] = NULL;
                id = -1;
                cnt = 0;
            }

            node* edge(char ch) {
                return nxt[ch - 'a'];
            }

            void set(char ch) {
                nxt[ch - 'a'] = new node();
            }
        };

        struct trie {
            node* root;
            int depth;
            trie(int d) {
                root = new node();
                depth = d;
            }

            void dfs(node* u) {
                for (int i = 'a'; i <= 'z'; i ++) {
                    if (u->edge(i))
                        dfs(u->edge(i));
                }
                delete u;
            }
            ~trie() {
                dfs(root);
            }

            void insert(string &word, int v) {
                node* cur = root;
                for (char ch: word) {
                    if (cur->edge(ch) == NULL)
                        cur->set(ch);
                    cur = cur->edge(ch);
                }
                cur->id = v;
                cur->cnt ++;
            }

            pii search(string &s, int l, int r) {
                node* cur = root;
                if (!cur) return  {0, 0};
                for (int i = l; i <= r; i ++) {
                    cur = cur->edge(s[i]);
                    if (!cur) return {0, 0};
                }
                return {cur->id, cur->cnt};
            }
        };

        vector<int> findSubstring(string s, vector<string>& words) {
            int n = s.size(), m = words.size(), d = words[0].size();
            trie myTrie(d);

            for (int i = 0; i < m; i ++)
                myTrie.insert(words[i], i + 1);

            vector <int> ids, cnt(m + 1);
            for (int i = 0; i + d - 1 < n; i ++) {
                pii tmp = myTrie.search(s, i, i + d - 1);
                ids.push_back(tmp.st);
                if (tmp.st > 0) cnt[tmp.st] = tmp.nd;
            }

            int tot = 0;
            for (int i: cnt) if (i) tot ++;

            vector <int> ans;
            for (int i = 0; i < d; i ++) {
                vector <int> mp(m + 1);
                int cur = 0;

                for (int j = i; j < ids.size(); j += d) {
                    if (++ mp[ids[j]] == cnt[ids[j]]) 
                        cur ++;
                    if (mp[ids[j]] - 1 == cnt[ids[j]]) 
                        cur --;
                    if (j >= m * d) {
                        int id = ids[j - m * d];
                        if (-- mp[id] == cnt[id]) 
                            cur ++;
                        if (mp[id] + 1 == cnt[id]) 
                            cur --;
                    }

                    if (cur == tot && j >= (m - 1) * d) 
                        ans.push_back(j - (m - 1) * d);

                }
            }

            return ans;
        }
};

int main(){
    string s;
    cin>>s;
    int len; cin>>len;
    vector<string> words;
    while(len--){
        string tmp; cin>>tmp;
        words.push_back(tmp);
    }
    Solution sol;
    for(int i: sol.findSubstring(s,words)){
        cout<<"ans =>"<<i<<endl;
    }
    return 0;
}

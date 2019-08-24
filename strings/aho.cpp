#include <bits/stdc++.h>
using namespace std;
class Aho{
    public:
        Aho(){
            memset(tree[root].next, -1, sizeof(tree[root].next));
            memset(tree[root].go, -1, sizeof(tree[root].go));
            tree[root].suffix_link = tree[root].dict_link = -1;
            tree[root].p = -1;
            tree[root].c = '$';
            tree[root].in = -1;
        }
        void add_string(string str){
            patterns.push_back(str);
            int state = root;
            for(int i = 0;i < str.size();i++){
                char c = str[i];
                if(tree[state].next[c-'a'] == -1)
                    tree[state].next[c-'a'] = add_node(c, state);
                state = tree[state].next[c-'a'];
            }
            tree[state].in = patterns.size()-1;
        }
        void match(string str){
            int state = 0;
            for(int i = 0;i < str.size();i++){
                state = go(state, str[i]);
                out(state, i);
            }
        }
    private:
        struct node{
            int go[26];
            int next[26];
            char c;
            int p;
            int suffix_link;
            int dict_link;
            int in;
        } tree[10001];
        int sz = 1;
        int root =  0;
        vector<string> patterns;
        int add_node(char c, int p){
            int new_in = sz++;
            memset(tree[new_in].next, -1, sizeof(tree[new_in].next));
            memset(tree[new_in].go, -1, sizeof(tree[new_in].go));
            tree[new_in].p = p;
            tree[new_in].c = c;
            tree[new_in].in = -1;
            tree[new_in].suffix_link = tree[new_in].dict_link = -1;
            return new_in;
        }
        int go(int state, char c){
            if(tree[state].go[c-'a'] == -1){
                if(tree[state].next[c-'a'] != -1)
                    tree[state].go[c-'a'] = tree[state].next[c-'a'];
                else
                    tree[state].go[c-'a'] = state == 0 ? 0 : go(get_suffix_link(state), c);
            }
            return tree[state].go[c-'a'];
        }
        int get_suffix_link(int state){
            if(tree[state].suffix_link == -1){
                if(state == 0 || tree[state].p == 0){
                    tree[state].suffix_link = 0;
                }
                else
                    tree[state].suffix_link = go(get_suffix_link(tree[state].p), tree[state].c);
            }
            return tree[state].suffix_link;
        }
        int get_dict_link(int state){
            if(tree[state].dict_link == -1){
                if(state == 0)
                    tree[state].dict_link = 0;
                else{
                    int suf = get_suffix_link(state);
                    if(tree[suf].in != -1)
                        tree[state].dict_link = suf;
                    else
                        tree[state].dict_link = get_dict_link(suf);
                }
            }
            return tree[state].dict_link;
        }
        void out(int state, int pos){
            if(tree[state].in == -1)
                state = get_dict_link(state);
            while(state != root){
                int in = tree[state].in;
                int p = pos - (int)patterns[in].size()+1;
                cout << patterns[in] << " occured at position " << p << endl;
                state = get_dict_link(state);
            }
        }
};
int main() {
    Aho test;
    test.add_string("he");
    test.add_string("h");
    test.add_string("she");
    test.add_string("her");
    test.add_string("hers");
    test.match("ushers");
}


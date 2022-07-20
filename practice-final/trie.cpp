#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
    Trie *childs[26] = {nullptr};
    bool isEnd = false;
    int val = 0;
    inline int toVal(char c) { return c - 'a'; }
    inline int hasChild(char c) { return (childs[toVal(c)] != nullptr); }

public:
    int cumVal[26] = {0};
    Trie() = default;
    void insert(string &s, int index, Trie *root)
    {
        if (index >= s.length())
            return;
        if (index == s.length() - 1)
            root->isEnd = true;
        root->val++;
        int childIndex = toVal(s[index]);
        for(int i = childIndex+1 ; i < 26 ; i++)
            cumVal[i]++;
        if (root->hasChild(s[index]))
            root = root->childs[childIndex];
        else
            root = root->childs[childIndex] = new Trie();
        insert(s, index + 1, root);
    }
    void remove(string &s, int index, Trie *root)
    {
        if (index >= s.length())
            return;
        root->val--;
        int childIndex = toVal(s[index]);
        remove(s, index + 1, root->childs[childIndex]);
        if (root->childs[childIndex]->val == 0)
        {
            free(root->childs[childIndex]);
            root->childs[childIndex] = nullptr;
        }
    }
    bool search(string &s, int index, Trie *root)
    {
        if (index == s.length() - 1 && root->isEnd)
            return true;
        int childIndex = toVal(s[index]);
        if (root->hasChild(s[index]))
            return search(s, index + 1, root->childs[childIndex]);
        return false;
    }
    vector<string> prefSearch(string& s, int index, Trie* root)
    {
        while(index < s.length())
        {
            if(root->hasChild(s[index]))
                root = root->childs[toVal(s[index])];
            else 
                break;
            index++;
        }
        vector<string> res;
        stack<pair<Trie*,string>> st;
        st.push({root,s.substr(0,index)});
        while(!st.empty())
        {
            Trie* newRoot = st.top().first;
            string str = st.top().second;
            res.push_back(str);
            st.pop();
            for(char c = 'a' ; c <= 'z' ; c++)
            {
                if(newRoot->hasChild(c))
                    st.push({newRoot->childs[toVal(c)],str+c});
            }
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Trie *root = new Trie();
    int q;
    cin >> q;
    while (q--)
    {
        int c;
        string s;
        cin >> c >> s;
        if (c == 1)
            root->insert(s, 0, root);
        else if (c == 2)
        {
            if(root->search(s,0,root))
                root->remove(s, 0, root);
        }
        else if (c == 3)
        {
            if (root->search(s, 0, root))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if (c == 4)
        {
            for(auto& str : root->prefSearch(s,0,root))
                cout << str << ' ';
            cout << '\n';
        }
        else if (c == 5)
        {
            int k;
            cin >> k;
        }
    }
    cout << root->cumVal['r'-'a'];
}
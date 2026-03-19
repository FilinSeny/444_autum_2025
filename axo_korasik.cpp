#include<iostream>
#include<random>
#include<vector>

using namespace std;


struct node {
    bool is_leaf;
    vector<node*> next;
    vector<node*> autom_go;
    node* prev = nullptr;
    char prevEdge;
    node* suf_ref = nullptr;
    bool is_root = false;
    bool is_terminal = false;


    node() : is_leaf(true), next(26, nullptr), autom_go(26, nullptr) {};
};



void add_string(const string& s, node* root) {
    node* cur = root;
    node* prev = nullptr;
    char c;
    for (int i = 0; i < s.size(); ++i) {
        c = s[i];
        if (!cur->next[c - 'a']) {
            cur->next[c - 'a'] = new node;
            cur->next[c - 'a']->prev = cur;
            cur->next[c - 'a']->prevEdge = c;
            cur->is_leaf = false;
        }
        cur = cur->next[c - 'a'];
    }
    cur->is_terminal = true;
}

node* getlink(node* cur, char c);


node* getSufflink(node* cur) {
    if (!cur->suf_ref) {
        if (cur->prev->is_root) {
            cur->suf_ref = cur->suf_ref = cur->prev;
        }
        else {
            cur->suf_ref = getlink(getSufflink(cur->prev), cur->prevEdge);
        }
    }
    return cur->suf_ref;

}

node* getlink(node* cur, char c) {
    if (!cur->autom_go[c - 'a']) {
        if (cur->next[c - 'a']) {
            cur->autom_go[c - 'a'] = cur->next[c - 'a'];
        }
        else if (cur->is_root) {
            cur->autom_go[c - 'a'] = cur;
        }
        else {
            cur->autom_go[c - 'a'] = getlink(getSufflink(cur), c);
        }
    }

    return cur->autom_go[c - 'a'];
}


void ParseText(string text, node* root) {
    node* cur = root;
    for (char c : text) {
        if (cur->is_terminal) {
            cout << "found" << endl;
        }
        cur = getlink(cur, c);

    }

    if (cur->is_terminal) {
        cout << "found" << endl;
    }
}




ostream& operator << (ostream& out, const vector<char>& v) {
    for (auto el : v) {
        out << el;
    }
    out << '\n';

    return out;
}


void output(node* root, vector<char>& v) {
    if (root->is_terminal) {
        cout << v;
    }

    if (!root->is_leaf) {
        for (int i = 0; i < 26; ++i) {
            if (root->next[i]) {
                v.push_back('a' + i);
                output(root->next[i], v);
                v.pop_back();
            }
        }
    }
}



int main() {
    node* root = new node;
    cout << "1\n";
    for (int i = 0; i < 6; ++i) {
        string s;
        cin >> s;
        add_string(s, root);
    }
    cout << "end_of_dict\n";
    root->is_root = true;
    vector<char> v;
    output(root, v);

    string text;
    cin >> text;

    ParseText(text, root);

    return 0;
}
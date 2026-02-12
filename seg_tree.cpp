#include<iostream>
#include<vector>

using namespace std;


struct node {
    int val;
    node *left, *right;
    int l, r;
};

vector<int> v = {1, 20, 4, 6, 7, 8, 9, 10};

node *build_tree(int l, int r) {
    node *new_node = new node;
    new_node->l = l;
    new_node->r = r;
    if (r - l == 1) {
        new_node->val = v[l];
        return new_node;
    } 

    new_node->left = build_tree(l, (l + r) / 2);
    new_node->right = build_tree((l + r) / 2, r);

    new_node->val = max(
        new_node->left->val,
        new_node->right->val
    );

    return new_node;
}

int get_max(int l, int r, node *cur) {
    if (cur->l >= l && cur->r <= r) {
        return cur->val;
    }
    if (cur->l >= r || cur->r <= l) {
        return 0;
    }

    return max(get_max(l, r, cur->left), get_max(l, r, cur->right)); 
}

int main() {
    node * root = build_tree(0, v.size());
    cout << get_max(3, 6, root);
}
#include<iostream>
#include<vector>

using namespace::std;

struct node
{
    int val, height;
    node* left_son, *right_son;

    node(int v) {
        height = 1;
        val   = v;
        left_son = right_son = nullptr;
    }

};

int get_hight(node *root) {
    if (!root) return 0;
    return root->height;
}

int count_hight(node * root) {
    if (!root) return 0;
    return max(get_hight(root->left_son), get_hight(root->right_son)) + 1;
}

node *rotate_left(node * a) {
    node * b = a->right_son;
    a->right_son = b->left_son;
    b->left_son = a;

    a->height = count_hight(a);
    b->height = count_hight(b);
    return b;
}

node *rotate_right(node * a) {
    node * b = a->left_son;
    a->left_son = b->right_son;
    b->right_son = a;

    a->height = count_hight(a);
    b->height = count_hight(b);
    return b;
}

node *big_rotate_left(node * a) {
    a->right_son = rotate_right(a->right_son);
    return rotate_left(a);
}

node * big_rotate_right(node * a) {
    a->left_son = rotate_left(a->left_son);
    return rotate_right(a);
}

bool find(node *root, int val) {
    if (!root) return false;
    if (root->val == val) return true;
    if (root->val > val) return find(root->left_son, val);
    else return find(root->right_son, val);
}


int count_diff(node *root) {
    return root ? get_hight(root->left_son) - get_hight(root->right_son) : 0;
}

node* make_balance(node *root) {
    if (count_diff(root) == 2) {
        if (count_diff(root->left_son) < 0) {
            return big_rotate_right(root);
        } else {
            return rotate_right(root);
        }
    }
    if (count_diff(root) == -2) {
        if (count_diff(root->right_son) > 0) {
            return big_rotate_left(root);
        } else {
            return rotate_left(root);
        }
    }
    return root;
}

node *insert(node *root, int val) {
    if (!root) return new node(val);
    if (root->val > val) {
        root->left_son = insert(root->left_son, val);
    } else {
        root->right_son = insert(root->right_son, val);
    }

    return make_balance(root);
}

node* fin_min(node *root) {
    return root->left_son ? fin_min(root->left_son) : root;
}

node *remove_min(node * root, int val) {
    if (!root->left_son) {
        return root->right_son;
    }
    root->left_son = remove_min(root->left_son, val);
    return make_balance(root);
}

node *remove(node *root, int val) {
    if (!root) return nullptr;
    if (val < root->val) {
        root->left_son = remove(root->left_son, val);
    } else if (val > root->val) {
        root->right_son = remove(root->right_son, val);
    } else {
        node *ls, *rs;
        ls = root->left_son;
        rs = root->right_son;
        delete root;
        if (!rs) {
            return ls;
        }
        if (!ls) {
            return rs;
        }
        node *min_v = fin_min(rs);
        min_v->right_son = remove_min(rs, min_v->val);
        min_v->left_son = ls;
        return make_balance(min_v);
    }
    return root;
}


node *build(const vector<int> & v) {
    node *root = nullptr;
    for (auto el : v) {
        root = insert(root, el);
    }

    return root;
}

ostream & operator << (ostream & out, node * root) {
    if (root) {
        out << root->left_son << ' ' << root->val << ' ' << root->right_son << ' ';

    } 
    return out;
}




int main() {
    vector<int> v = {1, 6, 3, 3, 8, 10, 100, 99, 59, 43};
    node *root = build(v);
    cout << root << endl;
    root = remove(root, 8);
    cout << root << endl;
    
}
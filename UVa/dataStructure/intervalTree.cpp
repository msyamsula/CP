#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

struct node{
    vl key;
    ll lh, rh, bf, m;
    node *left, *right;
    node(){
        key = {};
        lh=rh=bf=0;
        left = right = 0;
    }
};

class AVL{
public:
    AVL(){
        root=0;
    }
    void insert(vl arr){
        root = insert(root, arr);
    }

    void inoder(){
        inorder(root);
        cout << endl;
    }

    node * overlapSearch(vl arr){
        return overlapSearch(root, arr);
    }
    map<vl, ll> mem;
    node *root;
private:
    node * overlapSearch(node *ptr, vl arr){
        if (ptr == 0) return 0;
        if (is_overlap(ptr->key, arr)) return ptr;

        if (ptr->left != 0 && ptr->left->m >= arr[0] && mem.at(ptr->left->key) == 0) return overlapSearch(ptr->left, arr);
        
        if (mem.at(ptr->right->key) == 1) return 0;
        return overlapSearch(ptr->right, arr);
    }
    
    bool is_overlap(vl a, vl b){
        if (b[0] > a[1] || b[1] < a[0]) return 0;
        return 1;
    }
    
    void update(node *ptr){
        ptr->m = ptr->key[1];
        ptr->rh = 0; ptr->lh = 0;
        if (ptr->left != 0){
            ptr->lh = max(ptr->left->lh, ptr->left->rh)+1;
            ptr->m = max(ptr->m, ptr->left->m);
        }
        if (ptr->right != 0){
            ptr->rh = max(ptr->right->lh, ptr->right->rh)+1;
            ptr->m = max(ptr->m, ptr->right->m);
        }
        ptr->bf = ptr->rh - ptr->lh;
    }

    node * insert(node *ptr, vl arr){
        if (ptr == 0){
            ptr = new node;
            ptr->key = arr;
            ptr->m = arr[1];
            update(ptr);
            mem[arr] = 0;
            return ptr;
        }

        if (arr < ptr->key){
            ptr->left = insert(ptr->left, arr);
        } else if (arr > ptr->key){
            ptr->right = insert(ptr->right, arr);
        } else {
            return ptr;
        }

        update(ptr);

        if (ptr->bf < -1 && arr < ptr->left->key){
            return right_rotate(ptr);
        } else if (ptr->bf < -1 && arr > ptr->left->key){
            ptr->left = left_rotate(ptr->left);
            return right_rotate(ptr);
        } else if (ptr->bf > 1 && arr > ptr->right->key){
            return left_rotate(ptr);
        } else if (ptr->bf > 1 && arr < ptr->right->key){
            ptr->right = right_rotate(ptr->right);
            return left_rotate(ptr);
        }

        return ptr;
    }

    node * right_rotate(node *ptr){
        if (ptr == 0) return ptr;
        node *x = ptr;
        if (x->left == 0) return ptr;
        node *y = x->left;

        node *a = y->left, *b = y->right, *c = x->right;

        x->left = b;
        y->right = x;
        update(x); update(y);

        return y;
    }

    node * left_rotate(node *ptr){
        if (ptr == 0) return ptr;
        node *x = ptr;
        if (x->right == 0) return ptr;
        node *y = x->right;

        node *a = x->left, *b = y->left, *c = y->right;

        x->right = b;
        y->left = x;
        update(x); update(y);

        return y;
    }

    void inorder(node *ptr){
        if(ptr == 0){
            cout << "zonk ";
            return;
        }

        if (ptr->left != 0) inorder(ptr->left);
        cout << ptr->m << ' ';
        if (ptr->right != 0) inorder(ptr->right);
    }

};

int main(){
    AVL tree;
    map<vl, ll> mem;
    tree.insert({1,2});
    tree.insert({2,3});
    tree.insert({1,3});
    // tree.insert({20,36});
    // tree.insert({29,99});
    // tree.insert({24,25});
    // tree.insert({15,20});
    // tree.insert({10,30});
    // tree.insert({5,20});
    // tree.insert({12,15});
    // tree.insert({17,19});
    // tree.insert({30,40});
    // tree.insert({21,25});
    node* temp = tree.root;
    // cout << temp->bf << ' ' << temp->rh << ' ' << temp->lh << endl;
    for(ll num : temp->key){
        cout << num << ' ';
    }
    cout << endl;
    tree.inoder();
    node * ov = tree.overlapSearch({1,1});
    if (ov == 0) {
        cout << "not overlap" << endl;
        return 0;
    }
    for(ll num : ov->key){
        cout << num << ' ';
    }
    cout << endl;
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}

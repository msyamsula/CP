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
    ll key;
    ll lh, rh, bf;
    node *left, *right;
    node(){
        key = 0;
        lh = rh = bf = 0;
        left = right = 0;
    }
};

class AVL{
public:
    node *root, *ptr;
    ll n;
    AVL(){
        ptr = root = 0;
        n = 0;
    }

    node* insert(node *ptr, ll num){
        if (ptr == 0){
            ptr = new node;
            ptr->key = num;
            return ptr;
        }

        if (num < ptr->key){
            ptr->left = insert(ptr->left, num);
            ptr->lh = max(ptr->left->lh, ptr->left->rh) + 1;
        } else if ( num > ptr->key){
            ptr->right = insert(ptr->right, num);
            ptr->rh = max(ptr->right->lh, ptr->right->rh) + 1;
        } else return ptr;

        ptr->bf = ptr->rh-ptr->lh;

        if (ptr->bf < -1 && num < ptr->left->key){
            return right_rotate(ptr);
        } else if (ptr->bf > 1 && num > ptr->right->key ){
            return left_rotate(ptr);
        } else if (ptr->bf < -1 && num > ptr->left->key){
            ptr->left = left_rotate(ptr->left);
            return right_rotate(ptr);
        } else if (ptr->bf > 1 && num < ptr->right->key){
            ptr->right = right_rotate(ptr->right);
            return left_rotate(ptr);
        }

        return ptr;
    }

    void insert(ll num){
        root = insert(root, num);
    }

    node* right_rotate(node *ptr){
        node *x = ptr;
        if (x == 0) return ptr;
        node *y = x->left;
        if (y == 0) return ptr;

        node *a = y->left, *b = y->right, *c = x->right;
        x->left = b;
        y->right = x;

        if (b == 0) x->lh = 0;
        else x->lh = max(b->lh, b->rh)+1;

        if (c==0) x->rh = 0;
        else x->rh = max(c->lh, c->rh)+1;

        x->bf = x->rh-x->lh;

        if (a==0) y->lh = 0;
        else y->lh = max(a->lh, a->rh)+1;

        y->rh = max(x->lh, x->rh)+1;
        y->bf = y->rh-y->lh;

        return  y;
    }

    node* left_rotate(node * ptr){
        if (ptr == 0) return ptr;
        node * x = ptr;
        if (x->right == 0) return ptr;
        node *y = x->right;

        node *a = x->left, *b = y->left, *c = y->right;
        
        x->right = b;
        y->left = x;

        if (b == 0) x->rh = 0;
        else x->rh = max(b->rh, b->lh)+1;

        if (a==0) x->lh = 0;
        else x->lh = max(a->rh, a->lh)+1;

        x->bf = x->rh - x->lh;

        if (c == 0) y->rh = 0;
        else y->rh = max(c->rh, c->lh)+1;

        y->lh = max(x->lh, x->rh)+1;

        return y;
    }

    void inorder(node *ptr){
        if (ptr==0){
            cout << "zonk ";
            return;
        }

        if (ptr->left == 0 && ptr->right == 0){
            cout << ptr->key << ' ';
            return;
        }

        if (ptr->left != 0) inorder(ptr->left);
        cout << ptr->key << ' ';
        if (ptr->right != 0) inorder(ptr->right);
    }

    void inorder(){
        inorder(root);
        cout << endl;
    }
};

int main(){
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    AVL tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    cout << tree.root->right->key << endl;
    tree.inorder();
    // node * ptr = tree.rootPtr->left;
    // node * rootPtr = tree.rootPtr;
    // tree.insert(ptr, 1);
    // tree.insert(ptr, 2);
    // tree.insert(ptr, 3);
    // tree.insert(ptr, 4);
    
    // vl arr = {3,3}, arb = {1,5};
    // cout << (arr<arb) << endl;

    return 0;
}

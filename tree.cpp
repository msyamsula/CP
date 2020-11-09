#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree{
    private:
        vi st, arr;
        int n;

        void build(int p, int x, int y){
            if (x==y) st[p] = arr[x];
            else{
                int mid = (x+y)/2;
                build(2*p, x, mid);
                build(2*p+1, mid+1, y);
                st[p] = max(st[2*p],st[2*p+1]);
            }
        }

        int rmq(int p, int x, int y, int a, int b){
            if (y<a || x>b) return -(1<<30);
            if (a<=x && y<=b) return st[p];

            int mid = (x+y)/2;
            return max( rmq(2*p, x, mid, a, b), rmq(2*p+1, mid+1, y, a, b) );
        }

    public:
        SegmentTree(vi a){
            cout << "tes" << endl;
            arr = a;
            st.resize(4*arr.size(),0);
            build(1, 0, arr.size()-1);
        }

        int rmq(int i, int j){
            return this->rmq(1,0,arr.size()-1,i,j);
        }

        void show(){
            for(int i=0; i<st.size(); i++){
                cout << st[i] << ' ';
            }
            cout << endl;
        }
};

class Node {
    public:
        int value;
        Node * left;
        Node * right;
        Node(int v=0){
            value = v;
            left = nullptr;
            right = nullptr;
        };
};

class Tree {
    public:
        Node * root;
        Tree(){
            root = nullptr;
        };

        Node * insert(Node * r,  int v){
            if (r == nullptr) return new Node(v);
            if (v < r->value) r->left = insert(r->left, v);
            else r->right = insert(r->right, v);

            return r;
        }

        Node * search(Node * r, int v){
            if (r == nullptr || r->value == v) return r;
            if (v < r->value){
                return search(r->left, v);
            }
            return search(r->right, v);
        }

        int search(int v){
            Node * temp = search(root, v);
            if (temp == nullptr) return -1;
            return temp->value;
        }

        void insert(int v){
            root = insert(root, v);
        }
        
};

int main(){
    // vi a = {1,2,4,3};
    // SegmentTree st(a);
    // st.show();
    // Node a(1);
    Tree t;
    // Node b(2);
    // cout << b.left << endl;
    t.insert(4);
    t.insert(8);
    t.insert(3);

    // t.insert(Node(3));
    cout << t.root->right->value << endl;
    cout << t.root->left->value << endl;

    cout << t.search(10) << endl;
    return 0;
}
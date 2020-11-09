#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define f(i,s,e,inc) for(int i=s; i<e; i+=inc)
#define iter(a, i) for(i=a.begin(); i!=a.end(); i++)

class Node {
    public:
        int value;
        Node* right;
        Node* left;

        Node(int v){
            this->value = v;
            this->right = nullptr;
            this->left = nullptr;
        };
};

void insert(Node &n, Node &r){
    Node* ptr;
    if (n.value >= r.value && r.right == nullptr){
        r.right = &n;
    } else if (n.value < r.value && r.left == nullptr){
        r.left = &n;
    } else if (n.value >= r.value && r.right != nullptr){
        ptr = r.right;
        insert(n, *ptr);
    } else if (n.value < r.value && r.left != nullptr){
        ptr = r.left;
        insert(n, *ptr);
    }
}

/*2.3.2*/
void inorder(Node root){
    if (root.left == nullptr && root.right == nullptr){
        cout << root.value << endl;
    } else if (root.left != nullptr && root.right == nullptr){
        inorder(*(root.left));
        cout << root.value << endl;
    } else if (root.left == nullptr && root.right != nullptr){
        cout << root.value << endl;
        inorder(*(root.right));
    } else {
        inorder(*(root.left));
        cout << root.value << endl;
        inorder(*(root.right));
    }
}

/*2.3.3.2*/
vi outputRange(int a, int b, Node root){
    vi ans;
    if (root.value >= a && root.value <=b){
        if (root.right == nullptr && root.left == nullptr){
            ans.push_back(root.value);
        } else if (root.right != nullptr && root.left == nullptr){
            ans.push_back(root.value);
            vi temp = outputRange(a, b, *(root.right));
            ans.insert(ans.end(), temp.begin(), temp.end());
        } else if (root.left != nullptr && root.right == nullptr){
            ans = outputRange(a, b, *(root.left));
            ans.push_back(root.value);
        } else {
            ans = outputRange(a, b, *(root.left));
            ans.push_back(root.value);
            vi temp = outputRange(a, b, *(root.right));
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
    } else if (root.value < a && root.right != nullptr) {
        ans = outputRange(a, b, *(root.right));
    } else if (root.value > b && root.left != nullptr){
        ans = outputRange(a, b, *(root.left));
    }

    return ans;
}

/*2.3.3.3*/
void leaves(Node root){
    if (root.left == nullptr && root.right == nullptr){
        cout << root.value << endl;
    } else if (root.left != nullptr && root.right == nullptr){
        leaves(*(root.left));
    } else if (root.left == nullptr && root.right != nullptr){
        leaves(*(root.right));
    } else {
        leaves(*(root.left));
        leaves(*(root.right));
    }
}

int main(){
    Node a(15);
    Node b(6);
    Node c(23);
    Node d(4);
    Node e(7);
    Node ff(71);
    Node g(5);
    Node h(50);
    insert(b, a);
    insert(c, a);
    insert(d, a);
    insert(e, a);
    insert(ff, a);
    insert(g, a);
    insert(h, a);

    Node alone(1);

    // cout << d.right->value << endl;
    inorder(a);
    vi ans = outputRange(5, 50, a);
    vi::iterator i;
    iter(ans, i){
        cout << *i << ' ';
    }
    cout << endl;
    leaves(a);
    return 0;
}
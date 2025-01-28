#include <algorithm> 
#include <vector>
#include <iostream>

class Node{
    public:
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
    int height = 1;

    Node(int k){
        key = k;
    }
};
int height(Node* node){
    if(node == nullptr) return 0;
    return node -> height;
}
int get_balance(Node* node){
    if(node == nullptr) return 0;
    return height(node -> right) - height(node -> left);
}
Node* min (Node* node){
    if(node -> left == nullptr) return node;
    return min(node -> left);
}
Node* max(Node* node){
    if(node -> right == nullptr) return node;
    return max(node -> right);
}

Node* rotate_left(Node* base){
    Node* r = base -> right;
    Node* r_l = r -> left;

    r -> left = base;
    base -> right = r_l;

    base -> height = std::max(height(base -> left), height(base -> right)) + 1;
    r -> height = std::max(height(base), height(r -> right));

    return r;
}

Node* rotate_right(Node* base){
    Node* l = base -> left;
    Node* l_r = l -> right;

    l -> right = base;
    base -> left = l_r;

    base -> height = std::max(height(base -> left), height(base -> right)) + 1;
    l -> height = std::max(height(l -> left), height(base)) + 1;

    return l;
}


Node* balance_subtrees(Node* base){
    int bal = get_balance(base);
    
    if(bal < -1 && get_balance(base -> left) <= 0){
        base = rotate_right(base);
    }else if(bal < -1){
        base -> left = rotate_left(base -> left);
        base = rotate_right(base);
    }else if(bal > 1 && get_balance(base -> right) >= 0){
        base = rotate_left(base);
    }else if(bal > 1){
        base -> right = rotate_right(base -> right);
        base = rotate_left(base);
    }
    return base;
}


Node* insert(Node* base, int k){
    if(base == nullptr){
        return new Node(k);
    }else if(k < base -> key){
        base -> left = insert(base -> left, k);
    }else if(k > base -> key){
        base -> right = insert(base -> right, k);
    }else{
        return base;
    }
    base -> height = std::max(height(base -> left), height(base -> right))+1;
    return balance_subtrees(base);
}

Node* erase(Node* base, int k){
    if(base == nullptr){
        return base;
    }else if(k < base -> key){
        base -> left = erase(base -> left, k); 
    }else if(k > base -> key){
        base -> right = erase(base -> right, k); 
    }else{
        if(base -> height == 1){
            delete base;
            return nullptr;
        }else if(base -> left != nullptr && base -> right == nullptr){
            Node* new_base = base -> left;
            delete base;
            return new_base;
        }else if(base -> right != nullptr && base -> left == nullptr){
            Node* new_base = base -> right;
            delete base;
            return new_base;
        }else{
            int predecessor_val = max(base -> left) -> key;
            base -> key = predecessor_val;
            base -> left = erase(base -> left, predecessor_val);
        }
    }
    base -> height = std::max(height(base -> left), height(base -> right))+1;
    return balance_subtrees(base);
}

bool contains(Node* root, int k){
    if(root == nullptr) return false;
    else if(k < root -> key) return contains(root -> left, k);
    else if(k > root -> key) return contains(root -> right, k);
    else return true;
}

void ordered_list(Node* root, std::vector<int>& list){
    if(root == nullptr) return;
    ordered_list(root -> left, list);
    list.push_back(root -> key);
    ordered_list(root -> right, list);
}

//Test function from https://www.geeksforgeeks.org/deletion-in-an-avl-tree/
void preOrder(Node *root) {
    if (root != nullptr) {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    Node* root = nullptr;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    //Test from https://www.geeksforgeeks.org/deletion-in-an-avl-tree/
    std::cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);



    std::cout << "\nOrdered traversal of the "
            "constructed AVL tree is \n";
    std::vector<int> list;
    ordered_list(root, list);
    for(int val : list){
        std::cout << val << ' ';
    }
    std::cout << std::endl;



    root = erase(root, 10);

    //Test from https://www.geeksforgeeks.org/deletion-in-an-avl-tree/
    std::cout << "\nPreorder traversal after"
            " deletion of 10 \n";
    preOrder(root);



    std::cout << "\nOrdered traversal after"
            " deletion of 10 \n";
    list.clear();
    ordered_list(root, list);
    for(int val : list){
        std::cout << val << ' ';
    }
    std::cout << std::endl;

    return 0;
}
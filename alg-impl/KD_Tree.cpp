#include <algorithm> 
#include <vector>
#include <iostream>

class Node{
    public:
        std::vector<int> key;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(std::vector<int> k){
            key = k;
        }
};

int partition(int l, int r, std::vector<std::vector<int>>& array, int dim){
    int k = array[r][dim], i = l;
    for(int j = l; j < r; j++){
        if(array[j][dim] <= k){
            std::swap(array[i], array[j]);
            i++;
        }
    }
    std::swap(array[r], array[i]);
    return i;
}

std::vector<int> quickselect(int k, int l, int r, std::vector<std::vector<int>>& array, int dim){
    if(k<0 || k>=array.size()) throw std::invalid_argument("k out of bounds in quickselect");
    int i = partition(l, r, array, dim);
    while(k != i){
        if(k < i) r = i-1;
        if(k > i) l = i+1;
        i = partition(l, r, array, dim);
    }
    return array[i];
}

Node* insert_list(Node* root, std::vector<std::vector<int>> points, int dim, int l, int r){
    if(r-l < 0) return nullptr;
    if(r-l == 0){
        root = new Node(points[l]);
        return root;
    }
    std::vector<int> median = quickselect((r-l)/2, l, r, points, dim);
    root = new Node(median);
    root -> right = insert_list(root -> right, points, (dim+1)%median.size(), (r-l)/2+1, r);
    root -> left = insert_list(root -> left, points, (dim+1)%median.size(), l, (r-l)/2-1);
    return root;
}

Node* insert(Node* root, std::vector<int> k, int dim){
    if(root == nullptr) return new Node(k);
    if(k == root -> key) return root;
    if(k[dim%k.size()] < (root -> key)[dim]){
        root -> left = insert(root -> left, k, (dim+1)%k.size());
    }if(k[dim%k.size()] >= (root -> key)[dim]){
        root -> right = insert(root -> right, k, (dim+1)%k.size());
    }
    return root;
}
bool search(Node* root, std::vector<int> k, int dim){
    if(root == nullptr) return false;
    if(k[dim%k.size()] == (root -> key)[dim]){
        if(root -> key == k) return true;
        return search(root -> right, k, (dim+1)%k.size());
    }if(k[dim%k.size()] < (root -> key)[dim]){
        return search(root -> left, k, (dim+1)%k.size());
    }if(k[dim%k.size()] >= (root -> key)[dim]){
        return search(root -> right, k, (dim+1)%k.size());
    }
}  
std::vector<int> find_min(Node* root, std::vector<int> min, int target_dim, int curr_dim){
    if(root == nullptr) return min;
    if((root -> key)[target_dim] <= min[target_dim]) min = root -> key;
    if(curr_dim == target_dim){
       min = find_min(root -> left, min, target_dim, (curr_dim+1)%min.size());
    }else{
        min = std::min(find_min(root -> left, min, target_dim, (curr_dim+1)%min.size()),
        find_min(root -> right, min, target_dim, (curr_dim+1)%min.size()));
    }
    return min;
}
std::vector<int> find_max(Node* root, std::vector<int> max, int target_dim, int curr_dim){
    if(root == nullptr) return max;
    if((root -> key)[target_dim] >= max[target_dim]) max = root -> key;
    if(curr_dim == target_dim){
       max = find_max(root -> right, max, target_dim, (curr_dim+1)%max.size());
    }else{
        max = std::max(find_max(root -> left, max, target_dim, (curr_dim+1)%max.size()),
        find_max(root -> right, max, target_dim, (curr_dim+1)%max.size()));
    }
    return max;
}
Node* erase(Node* root, std::vector<int> k, int dim){
    if(root == nullptr) return nullptr;
    if(k[dim%k.size()] == (root -> key)[dim]){
        if(root -> key == k){
            if(root -> left == nullptr && root -> right == nullptr){
                delete root;
                return nullptr;
            }
            if(root -> left == nullptr){
                root -> key = find_min(root -> right, k, dim, (dim+1)%k.size());
                root -> right = erase(root -> right, root -> key, (dim+1)%k.size());
            }else{
                root -> key = find_max(root -> left, k, dim, (dim+1)%k.size());
                root -> left = erase(root -> left, root -> key, (dim+1)%k.size());
            }
        }
    }if(k[dim%k.size()] < (root -> key)[dim]){
        root -> left = erase(root -> left, k, (dim+1)%k.size());
    }if(k[dim%k.size()] > (root -> key)[dim]){
        root -> right = erase(root -> left, k, (dim+1)%k.size());
    }
    return root;
}

int sq_distance(std::vector<int> p1, std::vector<int> p2){
    if(p1.size() != p2.size()) throw std::invalid_argument("sq distance arguments not same dimension");
    int dist = 0;
    for(int i = 0; i < p1.size(); i++){
        dist += std::pow((p1[0]-p2[0]),2);
    }
    return dist;
}

//TODO: nearest neighbor implementation
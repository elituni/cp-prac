#include <bits/stdc++.h>
using namespace std;

struct MaxHeap{
    vector<int> heap;
    MaxHeap(vector<int>& array){
        heap.clear();
        heap.push_back(0);
        heap.insert(heap.end(), array.begin(), array.end());
        // cout << "heap: ";
        for(int i = 0; i < heap.size(); i++){
            cout << heap[i] << ' ';
        }
        cout << endl;
        bottom_up(1);
    }
    int peek(){
        return heap[1];
    }
    int pop(){
        int val = heap[1];
        heap[1] = heap[heap.size()-1];
        heap.resize(heap.size()-1);
        bubble_down(1);
        return val;
    }
    void insert(int key){
        heap.push_back(key);
        bubble_up(heap.size()-1);
    }
    void bubble_up(int n){
        if(n <= 1) return;
        if(heap[n] < heap[n/2]){
            swap(heap[n], heap[n/2]);
            bubble_up(n/2);
        }
    }
    void bubble_down(int l){
        if(l*2 >= heap.size()){
            return;
        }else if(l*2+1 >= heap.size()){
            if(heap[l]<heap[l*2]){
                swap(heap[l],heap[l*2]);
                // cout << "swapping " << heap[l] << " and " << heap[l*2] << endl;
                return;
            }
        }else if(heap[l*2]>heap[l*2+1] && heap[l*2]>heap[l]){
            // cout << "swapping " << heap[l] << " and " << heap[l*2] << endl;
            swap(heap[l*2],heap[l]);
            bubble_down(l*2);
            return;
        }else if(heap[l*2+1]>heap[l*2] && heap[l*2+1]>heap[l]){
            // cout << "swapping " << heap[l] << " and " << heap[l*2+1] << endl;
            swap(heap[l*2+1], heap[l]);
            bubble_down(l*2+1);
            return;
        }
    }
    void bottom_up(int l){
        if(l*2>=heap.size()) return;
        bottom_up(l*2);
        bottom_up(l*2+1);
        bubble_down(l);
    }
};

int main(){
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    MaxHeap h(numbers);
    for(int i = 0; i < 9; i++){
        cout << h.pop() << " pp ";
    }
    cout << endl;
    
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    cout << h.peek() << " ";
    cout << h.pop() << " ";
    cout << h.peek() << " ";
}
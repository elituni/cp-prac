#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class MinHeap{
    public:
        MinHeap(vector<int>& input){
            heap.insert(heap.begin()+1, input.begin(), input.end());
            r = input.size();
            bottom_up_heapify(1);
        }
        int peek(){
            return heap[1];
        }
        int pop(){
            int min = heap[1];
            heap[1] = heap[r--];
            bubble_down(1);
            return min;
        }
        void insert(int key){
            if(r >= heap.size()-1){
                heap.resize((r+1)*2);
            }
            heap[++r] = key;
            bubble_up(r);
        }
    private:
        vector<int> heap = {0};
        int r;
        void bubble_down(int l){
            if(l*2 > r) return;
            if(l*2+1 > r || heap[l*2] < heap[l*2+1]){
                if(heap[l*2] < heap[l]){
                    swap(heap[l*2], heap[l]);
                    bubble_down(l*2);
                }else{
                    return;
                }
            }else{
                if(heap[l*2+1] < heap[l]){
                    swap(heap[l*2+1], heap[l]);
                    bubble_down(l*2+1);
                }else{
                    return;
                }
            }
        }
        void bubble_up(int loc){
            while(loc > 1){
                if(heap[loc] < heap[loc/2]){
                    swap(heap[loc], heap[loc/2]);
                    loc /= 2;
                }
                else break;
            }
        }
        void bottom_up_heapify(int l){
            if(l*2 > r) return;
            bottom_up_heapify(l*2);
            bottom_up_heapify(l*2+1);
            bubble_down(l);
        }

};

int main(){
    vector<int> numbers = {24, 9, 11, -1, -8, -6, -18, -4, -9, 18, -21, -10, 2, 6, 21, -25, -3, -24, -13, 16};
    MinHeap h(numbers);
    for(int i = 0; i < 20; i++){
        cout << h.pop() << ' ';
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
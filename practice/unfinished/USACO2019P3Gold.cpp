/*
- floodfill to find # of paint coats on each tile
- label grid with -1 for k coats, 1 for k-1 coats, and 0 otherwise
- 2d prefix sums on grid
- iterate through all possible y bounds for paint square, while linearly iterating through x (O(n^3)).
    - track their positions relative to the 4 bounding lines
- iterate through n^2 bounding lines and determine largest area gain
*/

#include <bits/stdc++.h>
using namespace std;

int rsum(vector<vector<int>> psums, int y1, int y2, int x1, int x2){
    int sum = psums[y2][x2];
    if(y1 >= 0) sum -= psums[y1][x2];
    if(x1 >= 0) sum -= psums[y2][x1];
    if(x1 >= 0 && y1 >= 0) sum += psums[y1][x1];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, k;
    cin >> q >> k;

    if(q <= 0){
        cout << 0;
        return 0;
    }

    int n = 10;

    // read in input
    vector<vector<int>> start_points(n, vector<int>(n));
    vector<vector<int>> end_points(n+1, vector<int>(n+1));
    int x1, y1, x2, y2;
    for(int i = 0; i < q; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << x1 << y1 << x2 << y2 << endl;
        start_points[x1][y1] += 1;
        end_points[x2+1][y2+1] += 1;
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << start_points[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            cout << end_points[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // prefix sums with x-1,y-1 to find paint coats on each tile
    vector<vector<int>> layers(n, vector<int>(n));
    layers[0][0] = start_points[0][0];
    //init first row and col
    for(int i = 1; i < n; i++){
        layers[0][i] = layers[0][i-1] + start_points[0][i] - end_points[0][i];
        layers[i][0] = layers[i-1][0] + start_points[i][0] - end_points[i][0];
    }
    //prefix sums
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            layers[i][j] = start_points[i][j] - end_points[i][j] + layers[i][j-1] + layers[i-1][j] - layers[i-1][j-1];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << layers[i][j] << " ";
        }
        cout << endl;
    }

    //label grid with -1 for k coats, 1 for k-1 coats, and 0 otherwise
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(layers[i][j] == k){
                layers[i][j] = -1;
            }else if(layers[i][j] == k-1){
                layers[i][j] = 1;
            }else{
                layers[i][j] = 0;
            }
        }
    }

    //more prefix sums lol
    for(int i = 1; i < n; i++){
        layers[0][i] += layers[0][i-1];
        layers[i][0] += layers[i-1][0];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            layers[i][j] = layers[i][j-1] + layers[i-1][j] - layers[i-1][j-1];
        }
    }


    //iterate through all possible y bounds, then x bounds with 2 pointers, tracking highest area relative to bounding line
    vector<int> left(n+1); vector<int> right(n+1); vector<int> above(n+1); vector<int> below(n+1);
    int l, r;
    for(int y = 0; y < n; y++){
        for(int height = 0; y+height < n; height++){
            l = 0; r = 0;
            while(true){
                left[r+1] = max(left[r+1], rsum(layers, y-1, y+height, l-1, r));
                right[l] = max(right[l], rsum(layers, y-1, y+height, l-1, r));
                above[y+height+1] = max(above[y+height+1], rsum(layers, y-1, y+height, l-1, r));
                below[y] = max(below[y], rsum(layers, y-1, y+height, l-1, r));
                if(r >= n-1){
                    break;
                }else if(l != r && rsum(layers, y-1, height, l-1, r) < 0){
                    l = r;
                }else{
                    r++;
                }
            }
            cout << "height: " << height << endl;
        }
        cout << "y: " << y << endl;
    }

    int largest_x = 0;
    int largest_y = 0;
    for(int i = n-1; i>= 0; i++){
        left[i] = max(largest_x, left[i]); largest_x = max(largest_x, left[i]);
        above[i] = max(largest_y, above[i]); largest_y = max(largest_y, above[i]);
    }
    largest_x = 0;
    largest_y = 0;
    for(int i = 0; i < n; i++){
        right[i] = max(largest_x, right[i]); largest_x = max(largest_x, right[i]);
        below[i] = max(largest_y, below[i]); largest_y = max(largest_y, below[i]);
    }

    //check all bounding lines for largest area increase
    int area = 0;
    for(int i = 1; i < n-1; i++){
        area = max(area, left[i]+right[i]);
        area = max(area, above[i]+below[i]);
    }

    cout << area;
}
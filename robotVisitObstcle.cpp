#include<iostream>
#include<vector>
#include<queue>
#include <tuple>


using namespace std;

//Store the path as a string of directions to reach that node.
struct Cell {
    int x, y;
    int steps;
    string path; 
};

/* 
0. Robot can move 4 direction from any point, up, down, left, rright
1. We need to maintain a 2D matrix to ensure what nodes are already visited.
3. Since we need to move level by level to check all possible path, we will use BFS and hence a queue.
*/
bool 
navigateWithObstacles(vector<vector<int>> grid, int start_x, int start_y, int target_x, int target_y) 
{
    // Directions for moving: up, down, left, right
    const vector<tuple<int, int, string>> directions = {
        {-1, 0, "up"},
        {1, 0, "down"},
        {0, -1, "left"},
        {0, 1, "right"}        
    };
    auto m = grid.size();
    auto n = grid[0].size();

    vector<string> path;
    // Create a visited matrix to track visited cells
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // BFS queue to store the current cell and its path
    queue<Cell> q;

    //Initilize start point with 0 step and empty direction string.
    q.push({start_x, start_y, 0, ""});
    visited[start_x][start_y] = true;    

    while(!q.empty()) {
        Cell current = q.front();
        q.pop();
        //Reached the taget.
        if (current.x == target_x && current.y == target_y) {
            cout << "Reach the target cell, number of steps " << current.steps << endl;
            cout << "Path: " << current.path << endl;
            return true;
        }
        for(auto [dx, dy, dname]: directions) {
            auto nx = current.x + dx;
            auto ny = current.y + dy;

            if ((nx>=0 && nx<m && ny>0 && ny<n) && grid[nx][ny] == 0 and !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, current.steps + 1, current.path + dname + " "});
            }
        }
    }
    return false;
}
int main() {
    /*2D array to represent surface with obstacle(1) and free slot(0). 
    Given a robot at start postion and a target, write program to check is it possible for rebot to reach target or not? 
    */
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };
    auto start_x = 0, start_y = 0;
    auto target_x = 3, target_y = 3;

    // Check if it's possible to navigate to the target
    if (navigateWithObstacles(grid, start_x, start_y, target_x, target_y)) {
        cout << "The robot can reach the target." << endl;
    } else {
        cout << "The robot can not reach the target." << endl;
    }
    return 0;
}

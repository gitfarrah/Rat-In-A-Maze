#include "Maze.h"
#include "StateSpaceTree.h"
#include<fstream>
using namespace std;


void Maze::read(string filename)
{
    ifstream sin;
    sin.open(filename);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            sin >> matrix[i][j];
        }
    }
    cout << "read maze" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << "end of maze" << endl;
}

Maze::Maze(int start[], int end[]) {
    this->start = start;
    this->end = end;
}

//Function to initiate search process
void Maze::findPath() {

    visit(start[0], start[1], arr);
    cout << "Tree \n";
    //stateSpaceTree.display(stateSpaceTree.root);
    //stateSpaceTree.display_tree(stateSpaceTree.root);
}

//Function to visit a cell and recursively make next move
void Maze::visit(int x, int y, int arr[][N]) {
    if (!hasPath) {
        //Base Condition - Reached the destination cell
        if (x == end[0] && y == end[1]) {
            visited[x][y] = 1;
            //Update hasPath to True (Maze has a possible path)
            hasPath = true;
            //Store the minimum of the path length
            if (length < shortLength)
                shortLength = length;

            /*for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {

                    arr[i][j] = visited[i][j];
                }

            }*/
            displaypath(arr);
            //printPath(current_path);
            visited[x][y] = 0; // howa da hena kdea bykhle el destination zero wla el ablha ??
            //return (Backtrack) to explore more possible paths
            return;
        }hasPath = false;

        //Mark the current cell as visited
        visited[x][y] = 1;
        //Increment the current path length by 1
        length++;

        stateSpaceTree.insert(x, y);
        current_path.push_back({ x, y });

        //Check for next move:
        //1.Right
        if (canVisit(x + 1, y)) {
            visit(x + 1, y, arr);
        }

        //2.Down
        if (canVisit(x, y + 1)) {
            visit(x, y + 1, arr);
        }

        //3.Left
        if (canVisit(x - 1, y)) {
            visit(x - 1, y, arr);
        }

        //4.Up
        if (canVisit(x, y - 1)) {
            visit(x, y - 1, arr);
        }

        //Backtrack by unvisiting the current cell and
        //decrementing the value of current path length
        //visited[x][y] = 0;
        //length--;

        current_path.pop_back();
        stateSpaceTree.movetoparent();
    }
}

//Function checks if (x,y) is a vaid cell or not
bool Maze::canVisit(int x, int y) {
    //Number of Columns in Maze
    int m = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    //Number of rows in Maze
    int n = sizeof(matrix) / sizeof(matrix[0]);
    //Check Boundaries
    if (x < 0 || y < 0 || x >= m || y >= n)
        return false;
    //Check 0 or already visited
    if (matrix[x][y] == 0 || visited[x][y] == 1)
        return false;
    return true;
}

void Maze::printPath(vector<vector<int>> v)
{
    cout << "Path length: " << length << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "(" << v[i][0] << "," << v[i][1] << ") ";
    }
    cout << endl << endl;
}

void Maze::displaypath(int arr[][N])
{
    bool found = true;
    ofstream myFile("display.txt", std::ios_base::out);
    int j;
    if (found) {
        if ((visited[N - 1][N - 1] == 1)) {
            found = true;
            for (int i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    if (visited[i][j] == 1 && matrix[i][j] == 1) {
                        arr[i][j] = 2;
                        myFile << arr[i][j] << " ";
                        cout << arr[i][j];
                    }
                    else {

                        arr[i][j] = matrix[i][j];
                        myFile << arr[i][j] << " ";
                        cout << arr[i][j];
                    }
                }

                cout << endl;
                myFile << endl;

            }
            found = false;
        }
    }

}
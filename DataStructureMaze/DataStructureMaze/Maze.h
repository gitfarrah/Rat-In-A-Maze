#pragma once
//Maze Class
#include<iostream>
#include <vector>
#include "StateSpaceTree.h"
using namespace std;
#define N 10

class Maze {
public:
    int matrix[N][N]; /*{
    { 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    { 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    { 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    { 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
     {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    { 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    { 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    { 0, 0 ,0 ,0 ,0 ,0 ,0 , 1, 1, 1 },
    { 0, 0 ,0 ,0 ,0 ,0 ,0 , 1, 1, 0 },
    { 0, 0 ,0 ,0 ,0 ,0 ,0 , 1, 1, 1 }

    };*/
    void read(string filename);
    /* };*/

    int size;
    int* start;
    int* end;
    int visited[N][N] = { 0 };
    int arr[N][N] = { 0 };
    int shortLength = INT_MAX;
    int length = 0;
    vector<vector<int>> current_path = {};
    bool hasPath = false;
    StateSpaceTree stateSpaceTree;

    Maze(int start[], int end[]);
    //Function to initiate search process
    void findPath();
    //Function to visit a cell and recursively make next move
    void visit(int x, int y, int arr[][N]);
    //Function checks if (x,y) is a vaid cell or not
    bool canVisit(int x, int y);
    // function to print paths stored in the vector
    void printPath(vector<vector<int>> v);
    //function to display path matrix
    void displaypath(int arr[][N]);
};
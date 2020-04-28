// A C++ Program to implement A* Search Algorithm
#include <bits/stdc++.h>
using namespace std;

#define ROW 9
#define COL 10

//Creating a shortcut for int, int pair type
typedef pair<int, int> Pair;

//Creating a shortcut for pair<int, pair<int,int>> type
typedef pair<double, pair<int, int>> pPair;

//A structure to hold the necessary parameters
struct cell{
    //Row and column index of its parent
    //Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    //f = g + h
    double f, g, h;
};

//A utility function to check whether given cell (row, col)
//is a valid cell or not
bool isValid(int row, int col){
    //Returns true if row number and column number
    //is in range
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}

//A utility function to check whether the given cell is\
//blocked or not
bool isUnBlocked(int grid[][COL], int row, int col){
    //Returns true if the cell is not blocked else false
    if (grid[row][col] == 1)
        return (true);
    else
    {
        return (false);
    }
}

//A utility function to check whether destination cell
//has been reached or not 
bool isDestination(int row, int col, Pair dest){
    if (row == dest.first && col == dest.second)
        return (true);
    else
    {
        return (false);
    }
}

//A utility function to calculate the 'h' heuristics
double calculateHValue(int row, int col, Pair dest){
    //Return using the distance formula
    return ((double)sqrt ((row-dest.first)*(row-dest.first)
                          + (col-dest.second)*(col-dest.second)));
}

//A utility function to trace the path from Source
//to destination
void tracePath(cell cellDetails[][COL], Pair dest){
    printf("\nThe path is ");
    int row = dest.first;
    int col = dest.second;

    stack<Pair> Path;

    while (!(cellDetails[row][col].parent_i == row
             && cellDetails[row][col].parent_j == col))
    {
        Path.push(make_pair(row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    Path.push(make_pair(row, col));
    while (!Path.empty())
    {
        pair<int, int> p = Path.top();
        Path.pop();
        printf("-> (%d, %d) ", p.first, p.second);
    }

    return;    
}




// Driver program to test above function
int main(){
    /* Description of the Grid-
     1--> The cell is not blocked
     0--> The cell is blocked */
    int grid[ROW][COL] = {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } 
    };

    //Source is the left-most bottom-most corner
    Pair src = make_pair(8, 0);

    //Destination is the left-most top-most corner
    Pair dest = make_pair(0, 0);

    aStarSearch(grid, src, dest);

    return 0;
}
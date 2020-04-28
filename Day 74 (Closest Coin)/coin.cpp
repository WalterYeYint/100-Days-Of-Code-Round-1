#include <iostream>
#include <vector>
using namespace std;
//writing an AI for a 2d map game. You have a grid, my
//position is an X. There are coins
//strewn about in the space. want to find the oins. Given the position of all coins, and my position, find the closest one.
//To execute C++, please define "int main()"

class Point {
    public:
    int x, y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    };
};

//I'm at (1,1),  coin at (3,3) (5,5)
Point closestCoin(Point yourPosition, vector<Point> coinPositions) {
    Point result;
    int shortestIndex = -1;
    int shortestPath = -1;
    for (unsigned int i = 0; i < coinPositions.size(); i++) {
        Point p = coinPositions[i];
        int xDistance = abs(yourPosition.x - p.x);
        int yDistance = abs(yourPosition.y - p.y);
        int totalDistance = xDistance + yDistance;

        if ((shortestPath == -1) || (totalDistance < shortestPath)) {
            shortestPath = totalDistance;
            shortestIndex = i;
        }
    }



    //fill in correct values
    result.y = coinPositions[shortestIndex].y;
    result.x = coinPositions[shortestIndex].x;
    return result;
}

int main() {
    vector<Point> coinPositions;
    coinPositions.push_back(Point(3,3));
    coinPositions.push_back(Point(5,5));
    Point result = closestCoin(Point(1,1), coinPositions);
    cout << result.x << " " << result.y << endl;
    return 0;
}


/*

distance( (2,1) +. (1,3) ) => 3 (1 left + 2 down)
-------------------------
| . | X | . | . | . | . |
-------------------------
| . | . | . | o | . | . |
-------------------------
| o | . | . | . | . | . |
-------------------------
| . | . | . | . | . | . |
-------------------------
| . | . | . | . | o | . |
-------------------------
| . | . | . | . | . | . |
-------------------------
*/
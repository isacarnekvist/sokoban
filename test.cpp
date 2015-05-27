#include <iostream>
#include <queue>
using namespace std;

struct point {
    int x;
    int y;
};

int main() {
    queue<point> q;
    point p1;
    p1.x = 1;
    p1.y = 2;
    point p2;
    p2.x = 3;
    p2.y = 4;
    q.push(p1);
    q.push(p2);
    p1.x = 666;
    point p3 = q.front();
    q.pop();
    q.pop();
    cout << p3.x << "," << p3.y << endl;;
    return 0;
}

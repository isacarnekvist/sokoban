#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <assert.h>
#include <stack>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct point {
    int x;
    int y;
};

// Checks both out of 
bool isvalidmove(unsigned int x, unsigned int y, vector<string> board) {
    if (x < 0 || y < 0)         return false;
    if (y >= board.size())      return false;
    if (x >= board[y].size())   return false;
    if (board[y][x] == '#')     return false;
    if (board[y][x] == '*')     return false;
    if (board[y][x] == '$')     return false;
    if (board[y][x] == '.')     return true;
    if (board[y][x] == ' ')     return true;
    cerr << "Case in 'isvalidmove()' not covered: " << (int)board[y][x] << endl;
    exit(-1);
    // For compiler happiness
    return false;
}

void tests(void);

int main(int argc, char **argv)
{
    if(argc > 1 && strcmp(argv[1], "-t") == 0) {
        cout << "Running tests" << endl;
        tests();
        cout << "Tests OK" << endl;
    }

    unsigned int xmax = 0; 
    unsigned int ymax = 0;
    // Read the board
    std::vector<std::string> board;
    for (std::string line; std::getline(std::cin, line);) {
        xmax = (xmax > line.length()) ? xmax : line.length();
        board.push_back(line);
    }
    ymax = board.size();
    cout << ymax << endl;

    // Create matrix that hold all 'turns'
    // TODO: Some kind of bug here
    char** routemap = new char*[ymax];
    for(unsigned int i=0; i<xmax; i++) {
        routemap[i] = new char[xmax];
    }

    //// Search for starting position
    //point startpos;
    //startpos.x = -1;
    //for (unsigned int y = 0; y < board.size(); y++) {
    //    for (unsigned int x = 0; x < board[y].size(); x++) {
    //        if (board[y][x] == '@' || board[y][x] == '+') {
    //            startpos.x = x;
    //            startpos.y = y;
    //        }
    //    }
    //}
    //if(-1 == startpos.x) {
    //    // No player found
    //    cout << "no path" << endl;
    //    //exit(0);
    //}

    // BFS to find shortest route
    // put root in an empty queue
    // while queue not empty
    //     pop first node in queue and check
    //     for all neighbours
    //         put at end of queue
    // endwhile
    //queue<point> q;
    //// put root in an empty queue
    //q.push(startpos);
    //point pos;
    //point goal; goal.x = -1; goal.y = -1;
    //char postype;

    //while(!q.empty()) {
    //    // pop first node in queue
    //    pos = q.front();
    //    assert(q.size() > 0);
    //    q.pop();

    //    postype = board[pos.y][pos.x];

    //    // Check if goal
    //    if(postype == '.' || postype == '+') {
    //        goal = pos;
    //        break;
    //    }

    //    // Place wall where visited
    //    board[pos.y][pos.x] = '#';

    //    // Check where to go from here
    //    point next;
    //    next.x = pos.x-1; next.y = pos.y;
    //    if(isvalidmove(next.x, next.y, board)) {
    //        q.push(next); routemap[next.y][next.x] = 'L';
    //    }
    //    next.x = pos.x+1; next.y = pos.y;
    //    if(isvalidmove(next.x, next.y, board)) {
    //        q.push(next); routemap[next.y][next.x] = 'R';
    //    }
    //    next.x = pos.x; next.y = pos.y-1;
    //    if(isvalidmove(next.x, next.y, board)) {
    //        q.push(next); routemap[next.y][next.x] = 'U';
    //    }
    //    next.x = pos.x; next.y = pos.y+1;
    //    if(isvalidmove(next.x, next.y, board)) {
    //        q.push(next); routemap[next.y][next.x] = 'D';
    //    }
    //}

    //stack<char> route;
    //if(goal.x != -1) {
    //    while(pos.x != startpos.x || pos.y != startpos.y) {
    //        route.push(routemap[pos.y][pos.x]);
    //        switch (routemap[pos.y][pos.x]) {
    //            case 'U':
    //                pos.y++;
    //                break;
    //            case 'D':
    //                pos.y--;
    //                break;
    //            case 'L':
    //                pos.x++;
    //                break;
    //            case 'R':
    //                pos.x--;
    //                break;
    //        }
    //    }
    //    while(!route.empty()) {
    //        cout << route.top();
    //        route.pop();
    //    }
    //    cout << endl;
    //} else {
    //    cout << "no path" << endl;
    //}

    return 0;
}

void tests() {
    vector<string> map1;
    map1.push_back("#######");
    map1.push_back("# *$. #");
    map1.push_back("#     #");
    map1.push_back("#######");
    assert(isvalidmove(1,1,map1));
    assert(isvalidmove(5,1,map1));
    assert(isvalidmove(5,2,map1));
    assert(isvalidmove(1,2,map1));
    assert(!isvalidmove(0,0,map1));
    assert(!isvalidmove(6,0,map1));
    assert(!isvalidmove(6,3,map1));
    assert(!isvalidmove(0,3,map1));
    // Test for segmentation faults
    assert(!isvalidmove(-1,1,map1));
    assert(!isvalidmove(2,-1,map1));
    assert(!isvalidmove(7,2,map1));
    assert(!isvalidmove(4,4,map1));
    // Test special obstacles
    assert(!isvalidmove(2,1,map1));
    assert(!isvalidmove(3,1,map1));
    assert(isvalidmove(4,1,map1));

    vector<string> map2;
    map2.push_back("@ ");
    map2.push_back("   ");
    map2.push_back("    .");
    assert(isvalidmove(1,0,map2));
    assert(isvalidmove(2,1,map2));
    assert(isvalidmove(3,2,map2));
    assert(isvalidmove(4,2,map2));
    assert(isvalidmove(0,1,map2));
    assert(isvalidmove(0,2,map2));
}

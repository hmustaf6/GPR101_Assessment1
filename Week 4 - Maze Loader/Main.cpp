#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void loadFile(const string &filename, vector<vector<char>> &maze) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        maze.push_back(vector<char>(line.begin(), line.end()));
    }
    file.close();
}

void loadAlphabet(const string &filename, vector<char> &alphabet) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file " << filename << endl;
        exit(1);
    }

    char letter;
    while (file >> letter) {
        alphabet.push_back(letter);
    }
    file.close();
}

void loadDictionary(const string &filename, vector<string> &dictionary) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file " << filename << endl;
        exit(1);
    }

    string word;
    while (getline(file, word)) {
        dictionary.push_back(word);
    }
    file.close();
}

void drawMaze(const vector<vector<char>> &maze) {
    for (const auto &row : maze) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

bool findPath(vector<vector<char>> &maze, int x, int y) {
    if (maze[x][y] == 'E') return true;

    if (maze[x][y] == '*' || maze[x][y] == '#') return false;

    maze[x][y] = '.'; // Mark the path

    // Up
    if (x > 0 && findPath(maze, x - 1, y)) return true;
    // Down
    if (x < maze.size() - 1 && findPath(maze, x + 1, y)) return true;
    // Left
    if (y > 0 && findPath(maze, x, y - 1)) return true;
    // Right
    if (y < maze[0].size() - 1 && findPath(maze, x, y + 1)) return true;

    maze[x][y] = ' '; // Backtrack
    return false;
}

int main() {
    vector<vector<char>> maze;
    vector<char> alphabet;
    vector<string> dictionary;

    loadFile("Maze.txt", maze);
    loadAlphabet("alphabet.txt", alphabet);
    loadDictionary("dictionary.txt", dictionary);

    cout << "Original Maze:" << endl;
    drawMaze(maze);

    cout << "\nAlphabet:" << endl;
    for (char letter : alphabet) {
        cout << letter << " ";
    }
    cout << endl;

    cout << "\nDictionary:" << endl;
    for (const string &word : dictionary) {
        cout << word << endl;
    }

    int startX = -1, startY = -1;
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[i].size(); ++j) {
            if (maze[i][j] == 'S') {
                startX = i;
                startY = j;
            }
        }
    }

    if (startX == -1 || startY == -1) {
        cerr << "No start point (S) found in the maze." << endl;
        return 1;
    }

    if (findPath(maze, startX, startY)) {
        cout << "\nMaze with path:" << endl;
        drawMaze(maze);
    } else {
        cout << "No path found from Start to End." << endl;
    }

    return 0;
}

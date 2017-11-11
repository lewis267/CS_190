#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Objects
const char PEOPLE = '*';
const char WATER = '~';
const char ICE = '.';
const char LARGEICE = '@';
const char LARGEWOOD = '#';
const char MAXLARGEICE = 1;

class Node;

class Node {
public:
	char c;
	Node* r;
	Node* l;
	Node* u;
	Node* d;

	Node(char ch) : c(ch) {}
};

// Inputs 
int X, Y, P;
vector<vector<char>> Map;
vector<vector<Node>> Nodes;

void buildNodes() {
	for (int x = 0; x < Map.size(); ++x) {
		// Extend the Node matrix
		vector<Node> row;
		Nodes.push_back(row);

		for (int y = 0; y < Map[x].size(); ++y) {
			// Make a new Node
			Node n(Map[x][y]);
			Node w(WATER);

			// Up
			if (x == 0) n.u = &w;
			else {
				n.u = &Nodes[x-1][y];
				Nodes[x-1][y].d = &n;
			}
			
			// Left
			if (y == 0) n.l = &w;
			else {
				n.l = &Nodes[x][y-1];
				Nodes[x][y-1].r = &n;
			}

			// Down
			if (x == Map.size() -1) n.d = &w;
			
			// Right
			if (y == Map.size() -1) n.r = &w;

			// Append the Node
			Nodes[x].push_back(n);
		}
	}
}			


bool inMap(char c) {
	for (int x = 0; x < Map.size(); ++x) {
		for (int y = 0; y < Map[x].size(); ++y) {
			if (Map[x][y] == c) {
				return true;
			}
		}
	}
	return false;
}
bool inRow(char c, int r) {
	for (int y = 0; y < Map[r].size(); ++y) {
		if (Map[r][y] == c)
			return true;
	}
	return false;
}

int Analyze() {
	// Generate the Node Map
	buildNodes();
	cout << Nodes.size() << "x" << Nodes[0].size() << endl;

	return 0;
}

int main() {
	while (cin) {
		string line;

		// Read Input
		cin >> X >> Y >> P;
		getline(cin, line);
		for (int x = 0; x < X; ++x) {
			getline(cin, line);
			if (line == "") 
				return 0;
			vector<char> ln(line.begin(), line.end());
			Map.push_back(ln);
		}
		
		// Analyze
		int survivors = Analyze();
		cout << survivors << endl;

		// Reset
		Map.clear();
		Nodes.clear();
	}
   	return 0;
}


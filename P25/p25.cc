#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

void getArea(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n, int i, int j, int &area){
	if(visited[i][j] || (grid[i][j] == 0)) return;
	else area++;
	visited[i][j] = true;
	cout << "(" << i << "," << j << ") : " << area << endl;
	sleep(1);
	if(i - 1 >= 0)  getArea(grid, visited, m, n, i - 1, j, area);
	if(i + 1 < m) getArea(grid, visited, m, n, i + 1, j, area);
	if(j - 1 >= 0) getArea(grid, visited, m, n, i, j - 1, area);
	if(j + 1 < n) getArea(grid, visited, m, n, i, j + 1, area);       
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	// Time: O(mxn), go through entire space
	// Space: O(mxn), for the visited array
	int max_area = 0;
        
	int m = grid.size();
	int n = grid[0].size();
	
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	
	cout << m << " x " << n << endl;

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(visited[i][j] || (grid[i][j] == 0)) {
				visited[i][j] = true;
				continue;
			}
			int area = 0;
			getArea(grid, visited, m, n, i, j, area);
			cout << "(" << i << "," << j << ") : " << area << endl;
			if(area > max_area) max_area = area;
			visited[i][j] = true;
		}
	}
	
	return max_area;
}

int main(int argc, char *argv[]){
	vector<vector<int>> grid = {
									{0,0,1,0,0,0,0,1,0,0,0,0,0},
									{0,0,0,0,0,0,0,1,1,1,0,0,0},
									{0,1,1,0,1,0,0,0,0,0,0,0,0},
									{0,1,0,0,1,1,0,0,1,0,1,0,0},
									{0,1,0,0,1,1,0,0,1,1,1,0,0},
									{0,0,0,0,0,0,0,0,0,0,1,0,0},
									{0,0,0,0,0,0,0,1,1,1,0,0,0},
									{0,0,0,0,0,0,0,1,1,0,0,0,0}
								};
	
	cout << maxAreaOfIsland(grid) << endl;

	return 0;
}
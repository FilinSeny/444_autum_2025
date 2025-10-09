#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;
const int INF = 1e9;



ostream & operator << (ostream & out, const vector<int> & v) {
    for (auto el: v) {
        if (el > INF / 2) {
            cout << setw(5) << 0 << ' ';
        } else {
            cout << setw(5) << el << ' ';
        }
        
    }

    return out;
}


ostream & operator << (ostream & out, const vector<vector<int>> & v) {
    for (auto el: v) {
        cout << el << '\n';
    }

    return out;
}


void Floyd(vector<vector<int>> & dists) {
    ///dist = dp[i][j][k] - кратчайший путь из i в j через вершины с номерами не меньшими к
    for (int k = 0; k < dists.size(); ++k) {
        for (int j = 0; j < dists.size(); ++j) {
            for (int i = 0; i < dists.size(); ++i) {
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
            
        }
        cout << dists << endl;
    }
}







int main() {
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int> (n, INF));
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        dist[x][y] = w;
    }

    Floyd(dist);
    cout << dist; 
}
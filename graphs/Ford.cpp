#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;
const int INF = 1e9;

struct edge
{
    int x, y, w;
};




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


void Ford(const vector<edge> & G, vector<int> & dists, int s) {

    for (int k = 0; k < dists.size(); ++k) {
        bool flag = true;
        for (auto e : G) {  
            if (dists[e.y] > (dists[e.x] < INF ? dists[e.x] + e.w : INF)) {
                flag = false;
                dists[e.y] = (dists[e.x] < INF ? dists[e.x] + e.w : INF);
                ///cout << e.x << ' ' << e.y << endl;
            }         
            
        }
        cout << dists << endl << k << endl;
        if (flag) {
            break;
        }
    }
}










int main() {
    int n;
    cin >> n;
    vector<edge> G;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        edge e;
        cin >> e.x >> e.y >> e.w;
        G.push_back(e);
        
    }

    vector<int> dists(n + 1, INF);
    int s;
    cin >> s;
    dists[s] = 0;

    Ford(G, dists, s);

    cout << dists; 
}
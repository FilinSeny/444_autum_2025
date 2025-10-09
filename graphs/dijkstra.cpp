#include<iostream>
#include<vector>
#include<set>
#define INF 100000


using namespace std;


void dijkstra(int cur, const vector<vector<pair<int, int>>> & G,
     vector<int> & dist) {
        set<pair<int, int>> s = {{0, cur}};
        dist[cur] = 0;

        while (!s.empty())
        {
            auto p = *(s.begin());
            int &cur(p.second);
            s.erase(p);
            for (auto next_p : G[cur]) {
                int &to(next_p.first), &w(next_p.second);
                if (dist[to] > dist[cur] + w) {
                    s.erase({dist[to], to});
                    dist[to] = dist[cur] + w;
                    s.insert({dist[to], to});
                }
            }
        }
        

     }



int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        G[x].push_back({y, w});
    }

    vector<int> dist(n, INF);

    dijkstra(0, G, dist);

    for (auto el : dist) {
        cout << el << ' ';
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<set>
#define INF 100000


using namespace std;


int Time = 0;

ostream & operator << (ostream & out, const vector<int> & v) {
    for (auto el: v) {
        cout << el << ' ';
        
    }

    return out;
}


ostream & operator << (ostream & out, const vector<pair<int, int>> & v) {
    for (auto el: v) {
        cout << el.first << ' ' <<  el.second << endl;
        
    }

    return out;
}   


ostream & operator << (ostream & out, const vector<vector<pair<int, int>>> & v) {
    for (auto el: v) {
        cout <<el << '\n' << "________\n";
        
    }

    return out;
}









void dfs(vector<vector<pair<int, int>>> & G,
     vector<int> & tin, vector<int> &tup,
     int cur, int parent, int p_id) {
        cout << cur << endl;
        string s;
        getline(cin, s);


        tin[cur] = Time;
        tup[cur] = Time;
        ++Time;
        ///cout << G[cur] << endl;
        for (auto p : G[cur]) {
            cout << "to: " << p.first << endl;
            int &to = p.first;
            int &id = p.second;
            if (p_id == id) continue;
            if (to == parent) {
                tup[cur] = min(tin[to], tup[cur]);
            } else {
                if (tin[to] == -1) {
                    dfs(G, tin, tup, to, cur, id);}
                tup[cur] = min(tup[to], tup[cur]);
                /*} else {
                    tup[cur] = min(tin[to], tin[cur]);
                }*/
                

            }
        }

        cout << cur << endl << tin << endl << tup << endl;
}



int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y;
        G[x].push_back({y, i});
        G[y].push_back({x, i});
    }


    ///cout << G << endl;
    
    vector<int> tin(n, -1), tup(n, -1);

    dfs(G, tin, tup, 0, -1, -1); 
    
    ///cout << endl;

    cout << tin << endl << tup << endl;
    cout << endl;

    for (int i = 0; i < G.size(); ++i) {
        for (auto p : G[i]) {
            if (tup[p.first] > tin[i]) {
                cout << i << ' ' << p.first << endl;
            }
        }
    } 
    return 0;
}
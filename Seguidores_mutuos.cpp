
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n, 0);
    vector<pair<int, int>> pares;
    unordered_set<long long> relaciones;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        pares.push_back({u, v});
        long long clave = 1LL * u * (n + 1) + v;
        relaciones.insert(clave);
        --u;
        --v;
        ++deg[v];
    }

    int cant_mutuos = 0;

    for (int i = 0; i < pares.size(); ++i) {
        int u = pares[i].first;
        int v = pares[i].second;

        if (u < v) {
            long long inversa = 1LL * v * (n + 1) + u;

            if (relaciones.count(inversa) > 0) {
                ++cant_mutuos;
            }
        }
    }

    int usuario_mas = 1;
    int max_seguidores = deg[0];

    for (int i = 1; i < n; ++i) {
        if (deg[i] > max_seguidores) {
            max_seguidores = deg[i];
            usuario_mas = i + 1;
        }
    }

    cout << cant_mutuos << " " << usuario_mas << " " << max_seguidores;

    return 0;
}

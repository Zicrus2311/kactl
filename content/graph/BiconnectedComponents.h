/**
 * Author: Sebastian Meineche Falk
 * Date: 2026-11-22
 * License: CC0
 * Source: intuition
 * Description: Finds the biconnected components of an undirected graph.\\
 *  bcc[0, n) represents vertices, bcc[n, n+m) represents edges.
 *  bcc[i] == bcc[j] iff i is unambiguously in the same biconnected component as j.\\
 *  A biconnected component has at least two vertex-disjoint paths between any two vertices. Articulation points are those shared between distinct biconnected components*. They have unique bcc[i].\\
 *  *Note: Bridges and self-loops count as biconnected components. Note that this leads to an unusual definition of "articulation points" above.\\
 *  Let count(c) be the number of *edges* in component c. Then:\\
 *  - count(bcc[i]) == 0 iff vertex i articulation point (see note) OR has deg. 0.\\
 *  - count(bcc[n+i]) == 1 iff edge i bridge OR self-loop.\\
 *  Beware of degree 0, self-loops, vertex with only self-loops.
 * Time: O(V + E)
 * Status: tested on various problems
 */
#pragma once

vl biconnected_components(ll n, vector<pll> &edges) {
    ll k = n, t = 0, c = 0, p = 0;
    vector<vector<pll>> adj(n);
    for (auto [u, v] : edges) {
        if (u != v) adj[u].emplace_back(v, k);
        adj[v].emplace_back(u, k++);
    }
    vl tin(n), stk(k), bcc(k);
    auto dfs = [&](auto &oink, ll i, ll pe) -> ll {
        ll &h = tin[i]; if (h) return h;
        ll cnt = pe > 0, mn = h = ++t;
        for (auto &[e, id] : adj[i]) {
            if (id == pe) continue;
            ll r, lp = p, vis = tin[e] && e != i;
            if (tin[e] <= h) stk[p++] = id;
            mn = min(mn, r = oink(oink, e, id));
            if (!vis && r >= h) {
                while (p > lp) bcc[stk[--p]] = c;
                c++, cnt++;
            }
        }
        if (cnt != 1) bcc[i] = c++;
        else if (pe) stk[p++] = i;
        else bcc[i] = c-1;
        return mn;
    };
    rep(i, 0, n) dfs(dfs, i, 0);
    return bcc;
}

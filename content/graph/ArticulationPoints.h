/**
 * Author: Sebastian Meineche Falk
 * Date: 2025-11-02
 * Source: Folklore
 * Description: Finds a list of all articulation points in an undirected graph. The result is in no particular order.
 * Time: O(V + E)
 * Status: Tested on CSES "Necessary Cities"
 */
#pragma once

vl articulationPoints(vvl &adj) {
    ll n = sz(adj), t = 0; vl tin(n), res;
    auto dfs = [&](auto &self, ll i, ll p) -> ll {
		ll &h = tin[i]; if (h) return h;
        ll mn = h = ++t, mx = 0, cnt = p >= 0;
        for (ll e : adj[i]) if (e != p) {
            ll f = !tin[e], v = self(self, e, i);
            mn = min(mn, v); cnt += (f && v >= h);
        }
        if (cnt > 1) res.push_back(i);
        return mn;
    }; rep(i, 0, n) dfs(dfs, i, -1);
	return res;
}

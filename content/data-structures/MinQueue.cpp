/**
 * Author: Sebastian Meineche Falk
 * Date: 2026-11-22
 * Source: Folklore
 * Description: Queue with global minimum queries. Can be modified to work with any associative and commutative operation (see "op" comments).
 * Time: amortized O(1) per operation
 * Status: Tested on various CSES problems
 */
#pragma once

struct MinQueue {
    ll N, i, j;
    vl a, b;
    MinQueue(ll N) : N(N), i(0), j(N+1), a(N+2), b(N+2) {
        b[i] = b[j] = inf; } // op (identity)
    ll size() { return i + N+1 - j; }
    ll query() { return min(b[i], b[j]); } // op
    void push(ll v) {
        a[++i] = v, b[i] = min(b[i-1], v); // op
        assert(i < j);
    }
    void pop() {
        if (j == N+1) while (i) {
            a[--j] = a[i], b[j] = min(b[j+1], a[i--]); // op
        } assert(++j <= N+1);
    }
};

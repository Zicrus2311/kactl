/**
 * Author: Sebastian Meineche Falk
 * Date: 2025-11-22
 * Source: The kitchen
 * Description: Integer division. Works with negative numbers.
 * Status: Stress-tested
 */
#pragma once

template <class T>
T floorDiv(T a, T b) { return a/b - ((a^b) < 0 && a%b); }

template <class T>
T ceilDiv(T a, T b) { return -floor_div(-a, b); }

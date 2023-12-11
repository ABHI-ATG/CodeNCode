#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> //common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// template <class T>
// using pbset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// less_equal<T> //for multiset
// or,
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbset;

// for multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbset;

//
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
int main()
{
    // pbset<int> s;
    // for first one;

    pbset s;
    s.insert(5); // insertion in O(logn)
    s.insert(9);
    s.insert(2);
    s.insert(2);
    // 2 3 5 9
    cout << *s.find_by_order(0) << endl; // element at index t in O(logn)
    cout << s.order_of_key(3) << endl;   // how many elements less than 5 (this one is valid for multiset too)... or,position of 5 or rank of 5 (for set only)
    cout << s.size() << endl;
    return 0;
}
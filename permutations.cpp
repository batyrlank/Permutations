#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

template<class BidirIt>
bool next_permutation(BidirIt first, BidirIt last)
{
    auto r_first = make_reverse_iterator(last);
    auto r_last = make_reverse_iterator(first);
    auto left = is_sorted_until(r_first, r_last);
    if (left != r_last) {
        auto right = upper_bound(r_first, left, *left);
        iter_swap(left, right);
    }
    reverse(left.base(), last);
    return left != r_last;
}

int main() {
    cout<<"Enter a string without spaces"<<endl;
    string s; 
    cin >> s;
    long long total = 0;
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
        total++;
        cout << "Permutation #" << total << endl;
    } 
    while(next_permutation(s.begin(), s.end()));
}

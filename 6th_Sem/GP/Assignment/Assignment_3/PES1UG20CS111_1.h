// PES1UG20CS111 - Manas Chebrolu

#include <vector>

template <typename T, typename U>
std::vector<int> merge_containers(const T& C1, const U& C2) {
    std::vector<int> merged;

    typename T::const_iterator p = C1.begin();
    typename U::const_iterator q = C2.begin();

    while (p != C1.end() && q != C2.end()) {
        if (*p <= *q) {
            merged.push_back(*p);
            ++p;
        } else {
            merged.push_back(*q);
            ++q;
        }
    }

    if (p == C1.end())
        merged.insert(merged.end(), q, C2.end());
    else
        merged.insert(merged.end(), p, C1.end());

    return merged;
}

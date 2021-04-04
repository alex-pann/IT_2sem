#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <list>
#include <random>
#include <iterator>
#include <map>



int main() {
    //1
    std::array<int, 10> a;
    std::generate(a.begin(), a.end(), [](){{ return std::rand() % 20; }}  );
    for(auto i : a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //2
    std::list<int> l;
    std::partial_sum(a.begin(), a.end(), std::back_inserter(l));
    for(auto i : l) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //3
    std::copy(l.begin(), l.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    //4
    std::map<int, bool> m;
    for (auto i : l) {
        bool p = !(i%2);
        m.insert({i, p});
    }
    for(auto i : m) {
        std::cout << i.first << ": " << i.second << std::endl;
    }
    return 0;


}

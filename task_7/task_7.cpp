#include <iostream>
#include <numeric>
#include <algorithm>
#include <random>
#include <chrono>
#include <deque>

int main() {
//1)
    std::deque<int> deque(10);
    std::iota(deque.begin(), deque.end(), 1);

    std::cout << "1) deque: ";
    for (auto i: deque) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

//2)
    std::deque<int> front_deq(5);
    std::iota(front_deq.begin(), front_deq.end(), 3);
    std::default_random_engine engine( std::chrono::steady_clock::now().time_since_epoch().count());
    std::shuffle(std::begin(front_deq), std::end(front_deq), engine);

    for (auto i: front_deq) {
        deque.push_front(i);
    }

    std::cout << "2) new deque: ";
    for (auto i: deque) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

//3)
    std::vector<int> v;
    v.resize(deque.size());
    std::copy(deque.begin(), deque.end(), v.begin());

    std::cout << "3) vector: ";
    for(auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

//4)
    std::sort(v.begin(), v.end(),std::greater<>());

    std::cout << "4) sorted vector: ";
    for(auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

//5)
    std::shuffle(std::begin(deque), std::end(deque), engine);

    std::cout << "5) shuffled deque: ";
    for(auto x : deque) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

//6)
    std::cout << "6) Scalar product: ";
    std::cout << std::inner_product(v.begin(), v.end(), deque.begin(), 0);
    std::cout << std::endl;

//7)
    std::cout << "7) Number of elements > 4 in vector: ";
    std::cout << std::count_if(v.begin(), v.end(),[](auto x){return x >4 ;});
    std::cout << std::endl;

//8)
    std::cout << "8) Sum of elements in vector: ";
    std::cout << std::accumulate(v.begin(), v.end(), 0);
    std::cout << std::endl;

//9) ?
    std::cout << "9) Composition of elements in deque: ";
    std::cout << std::accumulate(deque.begin(), deque.end(), 1, [](int x, int y){return x * y;});
    std::cout << std::endl;

//10)
    std::cout << "10) Deleting all even numbers > 3 from vector: ";
    auto start = std::remove_if(v.begin(), v.end(), [](auto x){return (!(x % 2) && x > 3);});
    v.erase(start, v.end());
    for(auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

//11)
    std::cout << "11) Deleting all numbers = 4 from deque: ";
    auto start_2 = std::remove(deque.begin(), deque.end(), 4);
    deque.erase(start_2, deque.end());
    for(auto i : deque) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

//12)
    std::cout << "12) Vector (cycle for): ";
    for(auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

//13)
    std::cout << "13) Deque (for each): ";
    std::for_each(std::begin(deque), std::end(deque), [](auto x){std::cout << x << ' ';});
    std::cout << std::endl;

//14)
    auto min_vec = std::min_element(v.begin(), v.end());
    auto max_vec = std::max_element(v.begin(), v.end());
    auto min_deq = std::min_element(deque.begin(), deque.end());
    auto max_deq = std::max_element(deque.begin(), deque.end());

    std::cout << "14) Max_vector =  " << *max_vec << std::endl;
    std::cout << "Min_vector =  " << *min_vec << std::endl;
    std::cout << "Max_deque =  " << *max_deq << std::endl;
    std::cout << "Min_deque =  " << *min_deq << std::endl;
    std::cout << std::endl;
    return 0;
}

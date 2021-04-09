#include <iostream>
#include <map>
#include <list>


class Students {
public:
    Students() {};
    void insert(std::string name, int mark) {
        marks.insert({name, mark});
    }
    void list_students() {
        for (auto i : marks) {
            std::cout << i.first << " gets " << i.second << std::endl;
        }
    }
    auto find(std::string name) {
        for (auto i : marks) {
            if (i.first == name) {
                return i.second;
            }
        }
        throw std::invalid_argument("Invalid argument");
    }

    std::list<std::string> range(int x) {
        std::list<std::string> sts;
        for (auto i : marks) {
            if (i.second == x) {
                sts.push_back(i.first);
            }
        }
        return sts;
    }

    void standings() {
        std::map<int, std::list<std::string>, std::greater<int>> sort_marks;
        for (auto i : marks) {
            sort_marks[i.second].push_back(i.first);
        }

        for (auto i : sort_marks) {
            std::cout << i.first << ": ";
            for (auto j : i.second) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
private:
    std::map<std::string, int> marks;
};

int main() {
    Students st;
    st.insert("A", 90);
    st.insert("M", 100);
    st.insert("E", 50);
    st.insert("B", 10);
    st.insert("R", 10);
    st.insert("X", 90);

    st.list_students();

    try {
        std::cout << st.find("A") << std::endl;
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::list<std::string> ranged = st.range(10);
    for (auto i : ranged) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    st.standings();

    return 0;
}

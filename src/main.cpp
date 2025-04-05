#include <iostream>

#include "circular_linked_list.h"

constexpr size_t k = 2;

int main() {
    CircularLinkedList<std::string> residents{"Laing", "Wilder", "Frobisher"};

    while (residents.size() > 1) {
        std::string eaten = residents.removeNext(k);
        std::cout << "Eaten: " << eaten << '\n';
    }

    const std::string winner = residents.getCurrent();
    std::cout << "The winner is " << winner << "!\n";
    return 0;
}

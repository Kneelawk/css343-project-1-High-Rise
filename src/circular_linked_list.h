//
// Circular Linked List API
//

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

template<typename T>
class CircularLinkedList {
public:
    CircularLinkedList() = delete;

    CircularLinkedList(std::initializer_list<T> list);

    size_t size();

    T removeNext(size_t size);

    T getCurrent();
};

#include "circular_linked_list.tcc"

#endif //CIRCULAR_LINKED_LIST_H

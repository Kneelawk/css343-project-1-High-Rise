//
// Circular Linked List API
//

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

template<typename T>
class LinkedNode {
public:
    T data;
    LinkedNode *next;
    LinkedNode *prev; // this is so much simpler to do with a doubly-linked list

    explicit LinkedNode(const T &data)
        : data(data),
          next(nullptr) {
    }

    LinkedNode(const T &data, LinkedNode *next, LinkedNode *prev)
        : data(data),
          next(next),
          prev(prev) {
    }
};

template<typename T>
class CircularLinkedList {
    LinkedNode<T> *head;
    LinkedNode<T> *current;
    size_t nodeCount;

public:
    CircularLinkedList() = delete;

    CircularLinkedList(std::initializer_list<T> list);

    virtual ~CircularLinkedList();

    [[nodiscard]] size_t size() const;

    T removeNext(size_t next);

    T getCurrent() const;
};

#include "circular_linked_list.tcc"

#endif //CIRCULAR_LINKED_LIST_H

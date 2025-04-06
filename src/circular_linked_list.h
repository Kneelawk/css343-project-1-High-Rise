//
// Circular Linked List API
//

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H
#include <ostream>

template<typename T>
class LinkedNode {
public:
    T data;
    LinkedNode *next;
    LinkedNode *prev; // this is so much simpler to do with a doubly-linked list

    explicit LinkedNode(const T &data)
        : data(data),
          next(nullptr),
          prev(nullptr) {
    }

    LinkedNode(const T &data, LinkedNode *next, LinkedNode *prev)
        : data(data),
          next(next),
          prev(prev) {
    }
};

template<typename T>
class CircularLinkedList final {
    LinkedNode<T> *head;
    LinkedNode<T> *current;
    size_t nodeCount;

public:
    CircularLinkedList() = delete;

    CircularLinkedList(std::initializer_list<T> list);

    CircularLinkedList(const CircularLinkedList &other);

    ~CircularLinkedList();

    [[nodiscard]] size_t size() const {
        return nodeCount;
    }

    T removeNext(size_t next);

    T getCurrent() const;

    template<typename T2>
    friend bool operator==(const CircularLinkedList<T2> &lhs, const CircularLinkedList<T2> &rhs);

    friend bool operator!=(const CircularLinkedList &lhs, const CircularLinkedList &rhs) {
        return !(lhs == rhs);
    }

    template<typename T2>
    friend std::ostream &operator<<(std::ostream &os, const CircularLinkedList<T2> &obj);
};

#include "circular_linked_list.tcc"

#endif //CIRCULAR_LINKED_LIST_H

//
// Circular Linked List implementation
//

#ifndef CIRCULAR_LINKED_LIST_TCC
#define CIRCULAR_LINKED_LIST_TCC

#include "circular_linked_list.h"

template<typename T>
CircularLinkedList<T>::CircularLinkedList(std::initializer_list<T> list): head(nullptr),
                                                                          current(nullptr),
                                                                          nodeCount(list.size()) {
    // if list is empty, none of these will get initialized, leaving head == nullptr
    LinkedNode<T> *node = nullptr;
    for (const auto &t: list) {
        auto *temp = new LinkedNode<T>(t);

        temp->prev = node;
        if (node != nullptr) {
            node->next = temp;
        }

        node = temp;

        if (head == nullptr) {
            head = temp;
        }
    }

    if (node != nullptr) {
        // node will be at the end of the list, so we wrap it around
        node->next = head;
        head->prev = node;
    }

    current = head;
}

template<typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    // head == nullptr means the list is empty
    if (head == nullptr) {
        return;
    }

    LinkedNode<T> *node = head->next;

    while (node != head) {
        LinkedNode<T> *temp = node->next;
        delete node;
        node = temp;
    }

    delete head;
}

template<typename T>
size_t CircularLinkedList<T>::size() const {
    return this->nodeCount;
}

template<typename T>
T CircularLinkedList<T>::removeNext(size_t next) {
    if (nodeCount == 0) {
        throw std::out_of_range("list is already empty");
    }

    // find the node to remove
    while (next > 1) {
        current = current->next;
        --next;
    }

    // remove the node
    LinkedNode<T> *temp = current;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    current = temp->next;

    T data = temp->data;
    delete temp;
    --nodeCount;

    return data;
}

template<typename T>
T CircularLinkedList<T>::getCurrent() const {
    if (nodeCount == 0) {
        throw std::out_of_range("list is empty");
    }
    return current->data;
}

#endif //CIRCULAR_LINKED_LIST_TCC

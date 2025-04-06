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
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList &other): head(nullptr),
                                                                            current(nullptr),
                                                                            nodeCount(other.size()) {
    LinkedNode<T> *iter = other.head;

    // if list is empty, none of these will get initialized, leaving head == nullptr
    LinkedNode<T> *node = nullptr;
    if (iter != nullptr) {
        do {
            auto *temp = new LinkedNode<T>(iter->data);

            temp->prev = node;
            if (node != nullptr) {
                node->next = temp;
            }

            node = temp;

            if (head == nullptr) {
                head = temp;
            }

            iter = iter->next;
        } while (iter != other.head);
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
T CircularLinkedList<T>::removeNext(size_t next) {
    if (nodeCount == 0) {
        throw std::out_of_range("list is already empty");
    }

    // find the node to remove
    while (next > 1) {
        current = current->next;
        --next;
    }

    // handle deleting head
    if (current == head) {
        head = current->next;
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

template<typename T2>
bool operator==(const CircularLinkedList<T2> &lhs, const CircularLinkedList<T2> &rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }

    // reasonable enough way to check if we're pointing to the same data (or both nullptr more likely)
    if (lhs.head == rhs.head) {
        return true;
    }
    if (lhs.head == nullptr || rhs.head == nullptr) {
        // if both == nullptr, then both would be equal, meaning that if we get here and either head == nullptr,
        // then lhs != rhs
        return false;
    }

    LinkedNode<T2> *node1 = lhs.head;
    LinkedNode<T2> *node2 = rhs.head;

    do {
        if (node1->data != node2->data) {
            return false;
        }
        node1 = node1->next;
        node2 = node2->next;
    } while (node1 != lhs.head || node2 != rhs.head);

    return true;
}

template<typename T2>
std::ostream &operator<<(std::ostream &os, const CircularLinkedList<T2> &obj) {
    os << '[';
    if (obj.head != nullptr) {
        LinkedNode<T2> *node = obj.head;
        do {
            os << node->data;

            node = node->next;

            // check if we're not the last
            if (node != obj.head) {
                os << ", ";
            }
        } while (node != obj.head);
    }
    os << ']';

    return os;
}

#endif //CIRCULAR_LINKED_LIST_TCC

#include <gtest/gtest.h>

#include "circular_linked_list.h"

TEST(circular_linked_list, creation) {
    const CircularLinkedList<std::string> list{"a", "b", "c"};
    ASSERT_EQ(3, list.size());
}

TEST(circular_linked_list, comparison) {
    const CircularLinkedList<std::string> list{"a", "b", "c"};
    ASSERT_EQ(list, list);
}

TEST(circular_linked_list, comparison2) {
    const CircularLinkedList<std::string> list{"a", "b", "c"};
    const CircularLinkedList<std::string> list2{"a", "b", "c"};
    ASSERT_EQ(list, list2);
}

TEST(circular_linked_list, remove_next) {
    CircularLinkedList<std::string> list{"a", "b", "c"};
    const CircularLinkedList<std::string> expected{"a", "c"};

    ASSERT_EQ("b", list.removeNext(2));

    ASSERT_EQ(expected, list);
}

TEST(circular_linked_list, get_current) {
    CircularLinkedList<std::string> list{"a", "b", "c"};

    ASSERT_EQ("a", list.getCurrent());

    ASSERT_EQ("b", list.removeNext(2));

    ASSERT_EQ("c", list.getCurrent());
}

constexpr size_t k = 2;
TEST(circular_linked_list, winner) {
    CircularLinkedList<std::string> residents{"Laing", "Wilder", "Frobisher"};

    ASSERT_EQ(3, residents.size());
    ASSERT_EQ("Wilder", residents.removeNext(2));

    ASSERT_EQ(2, residents.size());
    ASSERT_EQ("Laing", residents.removeNext(2));

    ASSERT_EQ(1, residents.size());
    ASSERT_EQ("Frobisher", residents.getCurrent());
}

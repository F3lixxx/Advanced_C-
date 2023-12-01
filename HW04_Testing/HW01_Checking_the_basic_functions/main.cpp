
#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "catch2/src/catch2/catch_session.hpp"



struct ListNode{
public:
    explicit ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
    : value(value), prev(prev), next(next)
    {
        if(prev != nullptr) prev->next = this;
        if(next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;

};

class List {
public:
    List()
    : m_head(new ListNode(static_cast<int>(0))), m_size(0),
    m_tail(new ListNode(0, m_head)){}

    virtual ~List() {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value) {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value) {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }
    int PopFront() {
        if(Empty()) throw std::runtime_error("List is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }
    int PopBack() {
        if(Empty()) throw std::runtime_error("List is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete  node;
        return ret;
    }

    void Clear() {
        while (!Empty()) PopFront();
    }

private:
    ListNode* extractPrev(ListNode* node) {
        --m_size;
        return node;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;

};

TEST_CASE("test Empty is zero", "[zero]") {
    List list;
    CHECK(list.Empty() == 1);
    list.Clear();
}

TEST_CASE("test clear is not working", "[clear]"){
    List list;
    list.Clear();
    CHECK(list.Empty());
}

TEST_CASE("Clear Size", "[clear]") {
    List list;
    CHECK(list.Size() == 0);
}

int main() {

    try {
        List list;
        std::cout << "List is empty: "<< list.Empty() << std::endl;
        std::cout << "List size: " << list.Size() << std::endl;
       /* list.PushBack(45);
        list.PushBack(12);
        list.PushFront(45);*/
        list.Clear();
        std::cout << "List after clear: " << list.Size() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return Catch::Session().run();
}

#include "Deque.hxx"

#include <catch.hxx>

using namespace ipd;

TEST_CASE("New_is_empty")
{
    Deque<int> dq;
    CHECK(dq.empty());
}

TEST_CASE("New_has_size_0")
{
    Deque<int> dq;
    CHECK(dq.size() == 0);
}


TEST_CASE("Push_front_changes_size")
{
    Deque<int> dq;
    dq.push_front(5);
    CHECK(dq.size() == 1);
    CHECK_FALSE(dq.empty());
    dq.push_front(6);
    CHECK(dq.size() == 2);
    CHECK_FALSE(dq.empty());
}

TEST_CASE("Push_back_changes_size")
{
    Deque<int> dq;
    dq.push_back(5);
    CHECK(dq.size() == 1);
    CHECK_FALSE(dq.empty());
    dq.push_back(6);
    CHECK(dq.size() == 2);
    CHECK_FALSE(dq.empty());
}

TEST_CASE("Push_front_changes_front")
{
    Deque<int> dq;
    dq.push_front(5);
    CHECK(dq.front() == 5);
    dq.push_front(6);
    CHECK(dq.front() == 6);
}

TEST_CASE("Push_back_changes_back")
{
    Deque<int> dq;
    dq.push_back(5);
    CHECK(dq.back() == 5);
    dq.push_back(6);
    CHECK(dq.back() == 6);
}

TEST_CASE("Push_back_pop_back")
{
    Deque<int> dq;
    dq.push_back(5);
    dq.push_back(6);
    dq.push_back(7);
    CHECK(dq.front() == 5);
    CHECK(dq.back() == 7);
    dq.pop_back();
    CHECK(dq.front() == 5);
    CHECK(dq.back() == 6);
    dq.pop_back();
    CHECK(dq.front() == 5);
    CHECK(dq.back() == 5);
    dq.pop_back();
    CHECK(dq.empty());
}

TEST_CASE("Pop_front_removes_front")
{
    Deque<int> dq;
    dq.push_back(5);
    dq.push_back(6);
    dq.push_back(7);
    CHECK(dq.front() == 5);
    dq.pop_front();
    CHECK(dq.front() == 6);
    dq.pop_front();
    CHECK(dq.front() == 7);
    dq.pop_front();
    CHECK(dq.empty());
}

TEST_CASE("Push_front_pop_front")
{
    Deque<int> dq;
    dq.push_front(5);
    dq.push_front(6);
    dq.push_front(7);
    CHECK(dq.front() == 7);
    CHECK(dq.back() == 5);
    dq.pop_front();
    CHECK(dq.front() == 6);
    CHECK(dq.back() == 5);
    dq.pop_front();
    CHECK(dq.front() == 5);
    CHECK(dq.back() == 5);
    dq.pop_front();
    CHECK(dq.empty());
}


TEST_CASE("Pop_back_removes_back")
{
    Deque<int> dq;
    dq.push_front(5);
    dq.push_front(6);
    dq.push_front(7);
    CHECK(dq.back() == 5);
    dq.pop_back();
    CHECK(dq.back() == 6);
    dq.pop_back();
    CHECK(dq.back() == 7);
    dq.pop_back();
    CHECK(dq.empty());
}

TEST_CASE("Can_push_after_pop")
{
    Deque<int> dq;
    dq.push_back(5);
    dq.push_back(6);
    dq.push_back(7);
    dq.pop_front();
    dq.push_back(8);
    CHECK(dq.front() == 6);
    CHECK(dq.back() == 8);
    dq.pop_front();
    CHECK(dq.front() == 7);
    CHECK(dq.back() == 8);
    dq.pop_front();
    CHECK(dq.front() == 8);
    CHECK(dq.back() == 8);
    dq.pop_front();
    CHECK(dq.empty());
    dq.push_back(9);
    dq.push_back(10);
    CHECK(dq.front() == 9);
    CHECK(dq.back() == 10);
}

TEST_CASE("Copy")
{
    Deque<int> dq1;
    dq1.push_back(5);
    dq1.push_back(6);

    Deque<int> dq2(dq1);
    CHECK(dq2.front() == 5);
    CHECK(dq2.back() == 6);

    dq2.push_back(7);
    CHECK(dq2.front() == 5);
    CHECK(dq2.back() == 7);
    CHECK(dq1.front() == 5);
    CHECK(dq1.back() == 6);
}

TEST_CASE("Assign")
{
    Deque<int> dq1;
    dq1.push_back(5);
    dq1.push_back(6);

    Deque<int> dq2;
    dq2.push_back(10);

    dq2 = dq1;
    CHECK(dq2.front() == 5);
    CHECK(dq2.back() == 6);

    dq2.push_back(7);
    CHECK(dq2.front() == 5);
    CHECK(dq2.back() == 7);
    CHECK(dq1.front() == 5);
    CHECK(dq1.back() == 6);
}

TEST_CASE("Fronts_and_backs_then_fronts")
{
    Deque<int> dq;
    dq.push_front(5);
    dq.push_back(6);
    dq.push_front(4);
    dq.push_back(7);
    dq.push_front(3);
    dq.push_back(8);
    dq.push_front(2);
    dq.push_back(9);
    dq.push_front(1);
    dq.push_back(10);
    CHECK(dq.front() == 1);
    dq.pop_front();
    CHECK(dq.front() == 2);
    dq.pop_front();
    CHECK(dq.front() == 3);
    dq.pop_front();
    CHECK(dq.front() == 4);
    dq.pop_front();
    CHECK(dq.front() == 5);
    dq.pop_front();
    CHECK(dq.front() == 6);
    dq.pop_front();
    CHECK(dq.front() == 7);
    dq.pop_front();
    CHECK(dq.front() == 8);
    dq.pop_front();
    CHECK(dq.front() == 9);
    dq.pop_front();
    CHECK(dq.front() == 10);
    dq.pop_front();
    CHECK(dq.empty());
}

TEST_CASE("Fronts_and_backs_then_backs")
{
    Deque<int> dq;
    dq.push_front(5);
    dq.push_back(6);
    dq.push_front(4);
    dq.push_back(7);
    dq.push_front(3);
    dq.push_back(8);
    dq.push_front(2);
    dq.push_back(9);
    dq.push_front(1);
    dq.push_back(10);
    CHECK(dq.back() == 10);
    dq.pop_back();
    CHECK(dq.back() == 9);
    dq.pop_back();
    CHECK(dq.back() == 8);
    dq.pop_back();
    CHECK(dq.back() == 7);
    dq.pop_back();
    CHECK(dq.back() == 6);
    dq.pop_back();
    CHECK(dq.back() == 5);
    dq.pop_back();
    CHECK(dq.back() == 4);
    dq.pop_back();
    CHECK(dq.back() == 3);
    dq.pop_back();
    CHECK(dq.back() == 2);
    dq.pop_back();
    CHECK(dq.back() == 1);
    dq.pop_back();
    CHECK(dq.empty());
}

TEST_CASE("Splice Empty/Empty")
{
    Deque<int> dq1;
    Deque<int> dq2;
    dq1.splice(dq2);
    CHECK(dq1.size() == 0);
    CHECK(dq2.size() == 0);
}

TEST_CASE("Splice Empty/Non-Empty")
{
    Deque<int> dq1;
    Deque<int> dq2;
    dq1.push_front(11);
    dq1.splice(dq2);
    CHECK(dq1.size() == 1);
    CHECK(dq2.size() == 0);
    CHECK(dq1.front() == 11);
}

TEST_CASE("Splice Non-Empty/Empty")
{
    Deque<int> dq1;
    Deque<int> dq2;
    dq2.push_front(11);
    dq1.splice(dq2);
    CHECK(dq1.size() == 1);
    CHECK(dq2.size() == 0);
    CHECK(dq1.front() == 11);
}

TEST_CASE("Splice Non-Empty/Non-Empty")
{
    Deque<int> dq1;
    Deque<int> dq2;
    dq1.push_front(11);
    dq1.push_front(10);
    dq2.push_front(13);
    dq2.push_front(12);
    dq1.splice(dq2);
    CHECK(dq1.size() == 4);
    CHECK(dq2.size() == 0);
    CHECK(dq1.front() == 10);
    dq1.pop_front();
    CHECK(dq1.front() == 11);
    dq1.pop_front();
    CHECK(dq1.front() == 12);
    dq1.pop_front();
    CHECK(dq1.front() == 13);
    dq1.pop_front();
    CHECK(dq1.size() == 0);
}


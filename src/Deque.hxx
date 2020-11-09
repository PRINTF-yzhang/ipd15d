#pragma once

/*
 * A deque (pronounced like "deck") is a double-ended queue. This file
 * This file contains an implementation of a deque represented as a
 * doubly-linked list.
 */

#include <cstddef>
#include <initializer_list>
#include <utility>

namespace ipd {
//
// The main `Deque` class
//

    template<typename T>
    class Deque {
    public:
        // Constructs a new, empty deque.
        Deque();

        // Constructs a deque with the given elements;
        Deque(std::initializer_list<T>);

        // Copy constructor.
        Deque(const Deque &);

        // Copy-assignment operator.
        Deque &operator=(const Deque &);

        // Returns true if the deque is empty.
        bool empty() const;

        // Returns the number of elements in the deque.
        size_t size() const;

        // Returns a reference to the first element of the deque. If the deque is
        // empty then the behavior is undefined.
        const T &front() const;

        T &front();

        // Returns a reference to the last element of the deque. If the deque is
        // empty then the behavior is undefined.
        const T &back() const;

        T &back();

        // Inserts a new element at the front of the deque.
        void push_front(const T &);

        // Inserts a new element at the back of the deque.
        void push_back(const T &);

        // Removes the first element of the deque. Undefined if the
        // deque is empty.
        void pop_front();

        // Removes the last element of the deque. Undefined if the
        // deque is empty.
        void pop_back();

        // Removes all elements from the deque.
        void clear();

        void splice(Deque<T> &);

        // The destructor.
        ~Deque();

    private:
        // The linked list is made out of nodes, each of which contains a data
        // element (val) and pointers to next and previous nodes.
        struct node_ {
            T val;
            node_ *prev;
            node_ *next;

            // Constructs a new node, forwarding the arguments to construct the
            // data element. The prev and next pointers are initialized to nullptr.
            template<typename... Args>
            explicit node_(Args &&... args)
                    : val(std::forward<Args>(args)...), prev(nullptr), next(nullptr) {}
        };

        // Private member variables:
        node_ *head_;
        node_ *tail_;
        size_t size_;

    };

///
/// IMPLEMENTATIONS
///

    template<typename T>
    Deque<T>::Deque()
            : head_(nullptr), tail_(nullptr), size_(0) {}

    template<typename T>
    Deque<T>::Deque(std::initializer_list<T> args)
            : Deque() {
        for (const auto &arg : args)
            push_back(arg);
    }

    template<typename T>
    Deque<T>::Deque(const Deque &other)
            : Deque() {
        for (node_ *curr = other.head_; curr != nullptr; curr = curr->next) {
            push_back(curr->val);
        }
    }

    template<typename T>
    Deque<T> &Deque<T>::operator=(const Deque &other) {
        clear();

        for (node_ *curr = other.head_; curr != nullptr; curr = curr->next) {
            push_back(curr->val);
        }

        return *this;
    }

    template<typename T>
    bool Deque<T>::empty() const {
        return size_ == 0;
    }

    template<typename T>
    size_t Deque<T>::size() const {
        return size_;
    }

    template<typename T>
    const T &Deque<T>::front() const {
        return head_->val;
    }

    template<typename T>
    T &Deque<T>::front() {
        return head_->val;
    }

    template<typename T>
    const T &Deque<T>::back() const {
        return tail_->val;
    }

    template<typename T>
    T &Deque<T>::back() {
        return tail_->val;
    }

    template<typename T>
    void Deque<T>::push_front(const T &value) {
        node_ *newNode = new node_(value);
        if (empty()) {
            head_ = newNode;
            tail_ = newNode;
        } else {
            head_->prev = newNode;
            newNode->next = head_;
            head_ = newNode;
        }
        size_++;
    }

    template<typename T>
    void Deque<T>::push_back(const T &value) {
        node_ *newNode = new node_(value);
        if (empty()) {
            head_ = newNode;
            tail_ = newNode;
        } else {
            tail_->next = newNode;
            newNode->prev = tail_;
            tail_ = newNode;
        }
        size_++;
    }

    template<typename T>
    void Deque<T>::pop_front() {
        if (empty())
            return;
        if (head_ == tail_) {
            head_ = nullptr;
            tail_ = nullptr;
        } else {
            head_ = head_->next;
            head_->prev = nullptr;
        }
        size_--;
    }

    template<typename T>
    void Deque<T>::pop_back() {
        if (empty())
            return;

        if (head_ == tail_) {
            head_ = nullptr;
            tail_ = nullptr;
        } else {
            tail_ = tail_->prev;
            tail_->next = nullptr;
        }
        size_--;

    }

    template<typename T>
    void Deque<T>::clear() {
        while (!empty()) {
            pop_front();
        }
    }

    template<typename T>
    void Deque<T>::splice(Deque<T> &that) {
        if(that.empty()){
            return;
        }
        if (empty() ){
            head_=that.head_;
            tail_=that.tail_;
            size_=that.size();
            that.head_= nullptr;
            that.tail_= nullptr;
            that.size_=0;
            return;
        }
        while(!that.empty() &&!empty())
        {
            push_back(that.front());
            that.pop_front();
        }
        size_+=that.size_;

    }

    template<typename T>
    Deque<T>::~Deque() {
        clear();
    }
}

/*
 * push_back     Add element at the end (public member function )
   push_front    Insert element at beginning (public member function )
   pop_back      Delete last element (public member function )
   pop_front     Delete first element (public member function )
   splice        assign the src elements to the back of destination
 */

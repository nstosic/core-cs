#include "lru_cache.h"
#include <assert.h>

template <typename T>
LruCache<T>::LruCache() : LruCache(1, 0, nullptr, nullptr) {}

template <typename T>
LruCache<T>::LruCache(unsigned int capacity) : LruCache(capacity, 0, nullptr, nullptr) {}

template <typename T>
LruCache<T>::LruCache(unsigned int capacity, unsigned int size, DoubleLinkedNode<int>* first, DoubleLinkedNode<int>* last) {
    assert (capacity > 0);
    this->capacity_ = capacity;
    this->size_ = size;
    this->first_ = first;
    this->last_ = last;
    this->cache_ = std::unordered_map<int, T>(this->size_);
}

template <typename T>
LruCache<T>::~LruCache() {
    if (this->first_ != this->last_) {
        delete this->last_;
    }
    delete this->first_;
}

template <typename T>
void LruCache<T>::moveToFront(int key) {
    DoubleLinkedNode<int>* obj = this->first_;
    while (obj != nullptr && obj->getData() != key) {
        obj = obj->getNext();
    }
    if (obj == nullptr || obj == this->first_) {
        return;
    }
    if (obj->getPrev() != nullptr) {
        obj->getPrev()->setNext(obj->getNext());
        if (obj->getNext() != nullptr) {
            obj->getNext()->setPrev(obj->getPrev());
        }
        assert(this->first_ != obj);
        obj->setNext(this->first_);
        obj->setPrev(nullptr);
        this->first_ = obj;
    }
}

template <typename T>
T LruCache<T>::get(int key) {
    if (this->cache_.find(key) != this->cache_.end()) {
        DoubleLinkedNode<T> obj = this->cache_[key];
        
        return obj.getData();
    }
    return T();
}

template <typename T>
void LruCache<T>::put(int key, T value) {
    if (this->size_ == 0) {
        // If empty
        this->cache_[key] = value;
        this->first_ = new DoubleLinkedNode<int>(key);
        this->last_ = this->first_;
        this->size_++;
    } else if (this->cache_.find(key) != this->cache_.end()) {
        // If already present
        moveToFront(key);
        this->first_->setData(value);
    } else if (this->size_ == this->capacity_) {
        // If full
        int lastKey = this->last_->getData();
        this->cache_.erase(lastKey);
        DoubleLinkedNode<int>* temp = this->last_;
        this->last_ = this->last_->getPrev();
        delete temp;
        this->cache_[key] = value;
        moveToFront(key);
    } else {
        this->cache_[key] = value;
        DoubleLinkedNode<int>* indexNode = new DoubleLinkedNode<int>(key);
        indexNode->setNext(this->first_);
        this->first_ = indexNode;
        this->size_++;
    }
}

template <typename T>
unsigned int LruCache<T>::capacity() const {
    return this->capacity_;
}

template <typename T>
unsigned int LruCache<T>::size() const {
    return this->size_;
}

template class LruCache<int>; // forward resolution for template type used in unit tests
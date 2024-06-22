#ifndef S21_MAP_H
#define S21_MAP_H

#include <utility>

namespace s21{

template <class Key, class T>
class map {
 public:
  class MapConstIterator;
  class MapIterator;

  using value_type = std::pair<const Key, T>;
  using reference = value_type&;
  using const_reference =  const reference;
  using iterator = MapIterator;
  using const_iterator = MapConstIterator;
  using size_type = size_t;

 private:
  struct Node {
    bool less;
    Node* parent;
    Node* left;
    Node* right;
    value_type val;
  };

 public:
  class MapIterator {
    friend class map;
    friend class MapConstIterator;

   protected:
    Node* node;

   public:
    MapIterator(Node* nd): node(nd) {};
    ~MapIterator(){};

    reference operator*();
    value_type* operator->();
    iterator& operator++();
    iterator& operator--();
    iterator operator++(int);
    iterator operator--(int);
    bool operator==(iterator it);
    bool operator==(const_iterator it);
    bool operator!=(iterator it);
    bool operator!=(const_iterator it);
   protected:
    // BinarTree Move

    bool goLeft();
    bool goRight();
    bool goParent();
  };

  class MapConstIterator: public MapIterator {
    friend class map;
    friend class MapIterator;

   public:
    MapConstIterator(Node* nd): MapIterator(nd) {};
    MapConstIterator(iterator& it): MapIterator(it.node) {};
    ~MapConstIterator(){};
    const_iterator& operator=(const iterator& it);
    const_reference operator*() const;
    const value_type* operator->() const;
  };
 
 private:
  size_type size_;
  Node fake_;
  Node* min_;
  Node* max_;

 public:
  // Map Member functions
  map();
  /*
  map(std::initializer_list<value_type> const &items);
  map(const map &m);
  map(const map &m);
  map(map &&m);
  ~map();
  */

  // Map Element access
  /*
  T& at(const Key& key)
  T& operator[](const Key& key)
  */

  // Map Iterators
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
 

  // Map Capacity
  bool empty();
  /*
  size_type size();
  size_type max_size();
  */

  // Map Modifiers
  void clear();
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  /*
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  void erase(iterator pos);
  void swap(map& other);
  void merge(map& other);
  */

  // Map Lookup
  /*
  bool contains(const Key& key);
  */
};

};

#include "map_iterator.tpp"
#include "s21_map.tpp"

#endif
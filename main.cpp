#include <iostream>

template< class T >
struct BiList {
  T val;
  BiList< T >* next;
  BiList< T >* prev;
};

template< class T >
BiList< T >* makeBiList(T val);

template< class T >
BiList< T >* pushFront(BiList< T >* h);

template< class T >
BiList< T >* pushBack(BiList< T >* h);

template < class T >
BiList< T >* insert(BiList< T >* h ,size_t pos, T val);

template< class T >
size_t size(BiList< T >* h);

template< class T >
void clear(BiList< T >* h);

template< class T >
void popBack(BiList< T >* h);

template< class T >
void popFront(BiList< T >* h);

template< class T, class R >
R traverse(R r, BiList< T >* h, BiList< T >* e);

template< class T, class R >
R rtraverse(R r, BiList< T >* h, BiList< T >* e);

template< class T >
T& at(BiList< T >* h, size_t pos);

int main()
{}


#include <iostream>

template< class T >
struct BiList {
  T val;
  BiList< T >* next;
  BiList< T >* prev;
};

template< class T >
BiList< T >* makeBiList(T val)
{
  BiList< T >* list = new BiList<T>;
  list->val = val;
  list->next = list;
  list->prev = list;
  return list;
}

template< class T >
BiList< T >* pushFront(BiList< T >* h, T val)
{
  BiList< T >* node = new BiList< T > {val, h, h->prev};
  h->prev->next = node;
  h->prev = node;
  return node;
}

template< class T >
BiList< T >* pushBack(BiList< T >* h, T val)
{
  BiList< T >* node = new BiList< T > {val, h->next, h};
  h->next->prev = node;
  h->next = node;
  return node;
}

template < class T >
BiList< T >* insert(BiList< T >* h ,size_t pos, T val);

template< class T >
size_t size(BiList< T >* h);

template< class T >
void clear(BiList< T >* h)
{
  BiList< T >* e = h->prev;
  BiList< T >* n;
  while (h != e) {
    n = h->next;
    delete h;
    h = n;
  }
  delete e;
}

template< class T >
BiList< T > remove(BiList< T >* h, BiList< T >* e);

template< class T >
BiList< T > popBack(BiList< T >* h);

template< class T >
BiList< T > popFront(BiList< T >* h);

template< class T, class R >
R traverse(R r, BiList< T >* h, BiList< T >* e);

template< class T, class R >
R rtraverse(R r, BiList< T >* h, BiList< T >* e);

template< class T >
T& at(BiList< T >* h, size_t pos);

int main()
{}


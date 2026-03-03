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
BiList< T >* insert(BiList< T >* h ,size_t pos, T val)
{
  BiList< T >* curr = h;
  for (size_t p = 0; p < pos; ++p) {
    curr = curr->next;
  }
  return pushBack(curr, val);
}

template< class T >
size_t size(BiList< T >* h)
{
  BiList< T >* head = h;
  size_t s = 1;
  h = h->next;
  while (h != head) {
    s++;
    h = h->next;
  }
  return s;
}

template< class T >
void clear(BiList< T >* h)
{
  BiList< T >* e = h->prev;
  BiList< T >* n = nullptr;
  while (h != e) {
    n = h->next;
    delete h;
    h = n;
  }
  delete e;
}

template< class T >
BiList< T >* remove(BiList< T >* h, BiList< T >* e)
{
  BiList< T >* n = h;
  while (h != e) {
    h->prev->next = h->next;
    h->next->prev = h->prev;
    n = h->next;
    delete h;
    h = n;
  }
  return n->prev;
}

template< class T >
BiList< T > popBack(BiList< T >* h);

template< class T >
BiList< T > popFront(BiList< T >* h);

template< class T, class R >
R traverse(R r, BiList< T >* h, BiList< T >* e);

template< class T, class R >
R rtraverse(R r, BiList< T >* h, BiList< T >* e);

template< class T >
T& at(BiList< T >* h, size_t pos)
{
  for (size_t i = 0; i < pos; ++i) {
    h = h->next;
  }
  return h->val;
}

int main()
{
  auto bilist = makeBiList< int >(1);
  pushBack(bilist, 2);
  pushFront(bilist, 0);

  insert(bilist->prev, 1, 3);
  std::cout << size(bilist) << '\n';
  std::cout << at(bilist, 0) << '\n';  //1
  std::cout << at(bilist, 1) << '\n';  //3
  std::cout << at(bilist, 2) << '\n';  //2
  std::cout << at(bilist, 3) << "\n\n";//0

  remove(bilist->next, bilist->next->next);
  std::cout << size(bilist) << '\n';
  std::cout << at(bilist, 0) << '\n';
  std::cout << at(bilist, 1) << '\n';
  std::cout << at(bilist, 2) << '\n';
  std::cout << at(bilist, 3) << '\n';

  clear(bilist);
}


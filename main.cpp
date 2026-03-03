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
  return h;
}

template < class T >
BiList< T >* insert(BiList< T >* h ,size_t pos, T val)
{
  BiList< T >* curr = h;
  for (size_t p = 0; p < pos; ++p) {
    curr = curr->next;
  }
  pushBack(curr, val);
  return h;
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
BiList< T >* remove(BiList< T >* h)
{
  if (h->next == h) {
    delete h;
    return nullptr;
  }

  BiList< T >* n = h->next;
  h->prev->next = h->next;
  h->next->prev = h->prev;
  delete h;

  return n;
}

template< class T, class R >
R traverse(R r, BiList< T >* h, BiList< T >* e)
{
  do {
    r(h);
    h = h->next;
  } while (h != e);
  return r;
}

template< class T, class R >
R rtraverse(R r, BiList< T >* h, BiList< T >* e)
{
  do {
    r(h);
    h = h->prev;
  } while (h != e);
  return r;
}

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
  bilist = pushBack(bilist, 2);
  bilist = pushFront(bilist, 0);

  bilist =  insert(bilist, 2, 3);
  std::cout << size(bilist) << '\n';
  std::cout << at(bilist, 0) << '\n';
  std::cout << at(bilist, 1) << '\n';
  std::cout << at(bilist, 2) << '\n';
  std::cout << at(bilist, 3) << "\n\n";

  std::cout << size(bilist) << '\n';
  std::cout << at(bilist, 0) << '\n';
  std::cout << at(bilist, 1) << '\n';
  std::cout << at(bilist, 2) << '\n';
  std::cout << at(bilist, 3) << '\n';

  traverse([](BiList<int>* n) {
    std::cout << n->val << ' ';
  }, bilist, bilist);

  clear(bilist);
}


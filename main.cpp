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
  BiList< T >* list = new BiList<T>{val, nullptr, nullptr};
  list->next = list;
  list->prev = list;
  return list;
}

template< class T >
BiList< T >* add(BiList< T >* h, T val)
{
  BiList< T >* node = new BiList< T > {val, h, h->prev};
  h->prev->next = node;
  h->prev = node;
  return node;
}

template< class T >
BiList< T >* insert(BiList< T >* h, T val)
{
  BiList< T >* node = new BiList< T > {val, h->next, h};
  h->next->prev = node;
  h->next = node;
  return h;
}

template < class T >
BiList< T >* insertAt(BiList< T >* h ,size_t pos, T val)
{
  BiList< T >* curr = h;
  for (size_t p = 0; p < pos; ++p) {
    curr = curr->next;
  }
  add(curr, val);
  return h;
}

template< class T >
size_t size(const BiList< T >* h) noexcept
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
void clear(BiList< T >* h) noexcept
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
BiList< T >* cut(BiList< T >* h) noexcept
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

template< class T >
BiList< T >* erase(BiList< T >* h) noexcept
{
  if (h->next == h) {
    return h;
  }
  BiList< T >* rm = h->next;
  h->next = rm->next;
  rm->next->prev = h;
  delete rm;
  return h;
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
T& at(const BiList< T >* h, size_t pos) noexcept
{
  for (size_t i = 0; i < pos; ++i) {
    h = h->next;
  }
  return h->val;
}

template< class T >
void print(BiList< T >* h)
{
  traverse([](BiList<int>* n)  {
      std::cout << n->val << ' ';
    }, h, h);
}

int main()
{
  size_t sizeArray = 10;
  int* array = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  BiList<int>* h = nullptr;

  try {
    h = makeBiList(array[0]);
  } catch (...) {
    delete[] array;
    return 1;
  }

  for (size_t i = sizeArray - 1; i > 0; --i) {
    try {
      h = insert(h, array[i]);
    } catch (...) {
      clear(h);
      delete[] array;
      return 1;
    }

  }
  print(h);

  clear(h);
  delete[] array;
}


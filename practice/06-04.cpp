template< class T > struct List {
  T data;
  List< T > * next;
};

template< class T, class Hash, class Eq > struct HTable {
  size_t k;
  List< T > * slots[];
};

// Задача 1: вставка (открытое хеширование)
// добавить элемент в хеш-таблицу

template< class T, class Hash, class Eq >
List< T >* insert(const T& val, HTable< T, Hash, Eq > t, Hash hs, Eq eq) {
  size_t home_num = hs(val) % t.k;
  List< T >* home = t.slots[home_num];
  while (home != nullptr) {
    if (eq(val, home -> data)) return nullptr;
    home = home -> next;
  }
  t.slots[home_num] = new List< T > {val, t.slots[home_num]};
}

// Задача 2: отыскать элемент в хеш-таблице

template< class T, class Hash, class Eq >
List< T >* find(const T& val, HTable< T, Hash, Eq > t, Hash hs, Eq eq) {
  size_t home_num = hs(val) % t.k;
  List< T >* home = t.slots[home_num];
  while (home != nullptr) {
    if (eq(home -> data, val)) return home;
    home = home -> next;
  }
  return 0;
}


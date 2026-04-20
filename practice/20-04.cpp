// задача 1 (выполнить поиск в бинароном дереве; все значения в дереве различны)
template< class T >
struct BiTree {
  T val;
  BiTree< T > * lt, * rt;
}

template< class T, class Cmp >
const BiTree< T > * find(const T& d, const BiTree< T > * root, Cmp cmp)
{
  while (root)
  {
    if (cmp(root->val, d))
    {
      root = root->rt;
    }
    else if (cmp(d, root->val))
    {
      root = root->lt;
    }
    else
    {
      return root;
    }
  }
  return root;
}

// поиск в тернарном дереве поиска
template< class T >
struct TriTree {
  T val1, val2;
  TriTree< T > * lt, * rt, * mid;
}

template< class T, class Cmp >
const TriTree< T > * find(const T& d, const TriTree< T > * root, Cmp cmp)
{
  while (root) {
    if (cmp(root->val1, d)) {
      if (cmp(root->val2, d)) {
        root = root->rt;
      }
      else if (cmp(d, root->val2)) {
        root = root->mid;
      }
      else {
        return root;
      }
    }
    else if (cmp(d, root->val1)) {
      root = root->lt;
    }
  }
  return root;
}

// задача 2 (удаление, рекурсивно)
template< class T >
void clear(BiTree< T > * root)
{
  if (!root) {
    return;
  }
  
  clear(root->rt);
  clear(root->lt);
  delete root;
}

//удаление для тернарного
template< class T >
void clear(TriTree< T > * root)
{
  if (!root) {
    return;
  }
  
  clear(root->rt);
  clear(root->lt);
  clear(root->mid);
  delete root;
}


// Теперь пишем итеративные методы //

// задача 1 (обход дерева итеративно "по возрастанию") -подходим слева от родителя
template< class T >
struct BiTree {
  T val;
  BiTree< T > * lt, * rt, * parent;
};

template< class T >
BiTree< T > * toLeft(BiTree< T > * root)
{
  if (!root) {
    return;
  }
  
  while (root->lt) {
    root = root->lt;
  }
}

template< class T, class F >
F traverseUp(BiTree< T > * root, F f)
{
  while (root) {
    f(root->val);
    if (root->rt) {
      root = root->rt;
      root = toLeft(root);
    }
    else {
      BiTree< T > * parent = root->parent;
      while (parent && parent->lt != root) {
        root = parent;
        parent = root->parent;
      }
      root = parent;
    }
  }
  return f;
}


// двигаемся "по убыванию" теперь (просто меняем все местами)
template< class T >
BiTree< T > * toRight(BiTree< T > * root)
{
  if (!root) {
    return;
  }
  
  while (root->rt) {
    root = root->rt;
  }
}

template< class T, class F >
F traverseDown(BiTree< T > * root, F f)
{
  while (root) {
    f(root->val);
    if (root->lt) {
      root = root->lt;
      root = toRight(root);
    }
    else {
      BiTree< T > * parent = root->parent;
      while (parent && parent->rt != root) {
        root = parent;
        parent = root->parent;
      }
      root = parent;
    }
  }
  return f;
}

// двунаправленные итераторы для бинароного дерева "по убыванию"
template< class T >
struct BiTreeIt {
  BiTree< T > * curr;
};

template< class T > T& value(BiTree< T > it) {
  return it.curr->val;
}

template< class T >
BiTree< T > prev(BiTree< T > it) {
  if (it.curr->lt) {
    it.curr = it.curr->lt;
    it.curr = toRight(it.curr);
  }
  else {
    BiTree< T > * parent = it.curr->parent;
    while (parent && parent->rt != it.curr) {
      it.curr = parent;
      parent = it.curr->parent;
    }
    it.curr = parent;
  }
  return it;
}

template< class T >
BiTree< T > next(BiTree< T > it) {
  
}

template< class T >
bool hasNext(BiTree< T > it)

template< class T >
bool hasPrev(BiTree< T > it)


// обход тернарного дерева "по возрастанию"
template< class T >
struct TriTree {
  T val10, val11;
  TriTree< T > * lt, * rt, * mid, * parent;
};

template< class T, class F >
F traverse(TriTree< T > * root, F f)
{
  if (!root) {
    
  }
  while (root->lt) {
    
  }
  while (root) {
    if (ind == 0) {
      if (root->mid) {
        root = root->mid;
        
      }
    }
  }
}



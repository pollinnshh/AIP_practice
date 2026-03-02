// 1 (реализовать однонаправленные итераторы)

template< class T > sruct Vect {
    T* data; size_t s;
};
template< class T > sruct VecIt {
    T* data, *end;
};

template< class T > VecIt< T > begin(VecIt< T > it)
{
    return {v.data, v.data + v.s};
}

template< class T > VecIt< T > next(VecIt< T > it)
{
    ++it.data;
    return it;
}

template< class T > bool hasNext(VecIt< T > it)
{
    return it.data < it.end;
}

template< class T > T& value(VecIt< T > it)
{
    return *(it.data);
}

// 2 (однонаправленные обратные итераторы)

template< class T > sruct Vect {
    T* data; size_t s;
};
template< class T > sruct VecIt {
    T* data, size_t i, s;
};

template< class T > VecIt< T > rbegin(VecIt< T > it)
{
    return {v.data, v.s, v.s};
}

template< class T > VecIt< T > next(VecIt< T > it)
{
    --it.i;
    return it;
}

template< class T > bool hasNext(VecIt< T > it)
{
    return it.i;
}

template< class T > T& value(VecIt< T > it)
{
    return it.data[it.i - 1];
}

################для двунаправленных#####################

template< class T > bool hasPrev(VecIt< T > it)
{
    return it.i == it.s;
}

template< class T > VecIt< T > prev(VecIt< T > it)
{
    ++it.i;
    return it;
}

// 3 (односвязный список)

template< class T > sruct List {
    T val; List< T >* next;
};
template< class T > sruct ListIt {
    List< T >* curr;
};

template< class T > ListIt< T > begin(List< T >* h)
{
    return {h};
}

template< class T > ListIt< T > next(ListIt< T > it)
{
    it.curr = it.curr -> next;
    return it;
}

template< class T > T& value(ListIt< T > it)
{
    return it.curr -> val;
}

template< class T > bool hasNext(ListIt< T > it)
{
    return it.curr;
}

// 4 (односвязный список указателей)

template< class T > ListIt< T* > begin(List< T* > *h)
{
    while (h) {
        if (h -> val) return {h};
        h = h -> next;
    }
    return {h};  // тут h всегда равно nullptr
}

template< class T > ListIt< T* > next(ListIt< T* > it)
{
    return begin(it.curr -> next);
}

template< class T > T& value(ListIt< T* > it)
{
    return *(it.curr -> val);
}

template< class T > bool hasNext(ListIt< T* > it)
{
    return it.curr;
}

#################################2 часть#############################

// 1 (кр)

template< class T > struct List {
    T val;
    List< T >* next;
};

template< class T > size_t size(const List< T >* h) {
    size_t c = 0;
    while (h) {
        ++c;
        h = h -> next;
    }
    return c;
}

template< class T > void clear(List< T >* h) {
    while (h) {
        List< T >* n = h -> next;
        delete h;
        h = n;
    }
}

// 2 (односвязный список указателей)

template< class T > struct List {
    T val;
    List< T >* next;
};

template< class T > size_t size(const List< T* >* h) {
    size_t c = 0;
    while (h) {
        c += h -> val?1:0;
        h = h -> next;
    }
    return c;
}

template< class T > void clear(List< T* >* h) {
    while (h) {
        List< T >* n = h -> next;
        delete h -> val;
        delete h;
        h = n;
    }
}

// 3 (односвязный список односвязных списков)

template< class T > struct List {
    T val;
    List< T >* next;
};

template< class T > size_t size(const List< const List< T >* >* h) {
    
}

template< class T > void clear(List< List< T >* >* h) {
    while (h) {
        clear< T >(h -> val);
        h = h -> next;
    }
    clear< List< T >* >(h);
}

// 4 (вектор списков)

template< class T > sruct Vect {
    T* data; size_t size;
};
template< class T > struct List {
    T val; List< T >* next;
};

template< class T > void clear(Vec< List< T >* > v) {
    for (size_t k = 0; k < v.size; ++k) {
        clear< T >(v.data[k]);
    }
    delete[] v.data;
}

template< class T > size_t size(Vec< List< T >* > v) {
    size_t c = 0;
    for (size_t k = 0; k < v.size; ++k) {
        c += size< T >(v.data[k]);
    }
    return c;
}

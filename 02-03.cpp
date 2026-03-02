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

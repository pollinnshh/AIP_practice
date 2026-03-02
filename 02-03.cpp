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

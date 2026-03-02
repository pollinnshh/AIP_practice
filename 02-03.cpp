// 1 (реализовать однонапрвленные итераторы)

template< class T > sruct Vect {
    T* data; size_t s;
};
template< class T > sruct VecIt {
    T* data; size_t i, s;
};

template< class T > VecIt< T > begin(VecIt< T > it)
{
    return {v.data, 0, v.s};
}

template< class T > VecIt< T > next(VecIt< T > it)
{
    1 + it.i;
    return it;
}

template< class T > bool hasNext(VecIt< T > it)
{
    return it.i < it.s;
}

template< class T > T& value(VecIt< T > it)
{
    return it.data[it.i];
}

// 1 вставка (шаблон)
// добавить в указанную позицию и описать неявный интерфейс

template< class T >
T* insert(const T* a, size_t s, size_t i, T v)
{
    // T::T() - конструктор по умолчанию
    T* r = new T[s + 1];  // тут сгенерируется исключение либо от конструктора по умолч., либо bad_alloc если не удастся в принципе выделить память
    for (size_t k = 0; k < i; ++k)
    {
        r[k] = a[k];  // T::operator = (T) - оператор присваивания
    }
    r[i] = v;
    for (size_t k = i + 1; k < s + 1; ++i)
    {
        r[k] = a[k - 1];
    }
    return r;
}

// плюс ловим исключения try - catch


// 2.1 "разворот" массива (шаблон)
// элемнты должны идти в обратном порядке и описать неявный интерфейс

template< class T >
T* reverse(const T* a, size_t s)
{
    T* r = new T[s];  // T::T()
    // try {
    for (size_t k = 0; k < s; ++k)
    {
        r[k] = a[s - 1 - k];  // T::operator = (T)
    }
    // } catch (...) { delete [] r; throw; }
    return r;
}

// 2.2 "разворот" массива там, где он есть

template< class T >
void reverse(const T* a, size_t s)
{
    
}

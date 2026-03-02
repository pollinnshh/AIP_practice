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


// 2.2 "разворот" массива там, где он есть (опасный шаблон)

template< class T >
void reverse(const T* a, size_t s)
{
    for (size_t k = 0; k < s / 2; ++k)
    {
        std::swap(a[k], a[s - k - 1]);
    }
    // 1 вариант: если T не перемещается и есть копирование (должен хотя бы копироваться, конструктор копирования и оператор копирующего присваивания
    T tmp = a;
    a = b;
    b = tmp;
    
    // 2 вариант: если Т перемещается
    T tmp = std::move(a);
    // T::operator = (T & a);
    a = std::move(b);
    b = std::move(tmp);
}


// 3.1 remove (убрать элементы равные заданному)

template< class T >
void remove (T* a, size_t s, size_t id)
{
    for (size_t k = id; k < s - 1; ++k)
    {
        std::swap(a[k], a[k + 1]);
    }
}

template< class T >
T* remove (T* a, size_t s, T v)
{
    size_t id = 0;
    while (id != s)
    {
        if (a[id] == v)  // T::operator == (T)
        {
            remove(a, s--, id);
        }
        else
        {
            ++id;
        }
    }
    return a + s;
}


// 4.1 перенос элементов (перенести указанный элемент массива в другой массив на указанную позицию)
// с ходу такое писать в шаблоны НЕЛЬЗЯ!


// 4.2 перенести казанный элемент массива в другой массив на указанную позицию (сделать новые)
// это проще, но не рационально

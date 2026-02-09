// 1

int* insert(const int* a, size_t s, size_t i, int v)
{
    int* result = new int* [s + 1];
    for (size_t j = 0; j < i; j++)
    {
        result[j] = a[j];
    }
    result[i] = v;
    for (size_t j = i + 1; j < s; j++)
    {
        result[j] = a[j - 1];
    }
    return result;
};

void insert(int** a; size_t s; size_t i; int v)
{
    int* tmp = a[0]; // *a
    a[0] = insert(tmp, s, v);
    delete[] tmp;
};


// 2 (убрать элемент из заданной позиции)

int* erase(const int* a, size_t s, size_t i)
{
    int* result = new int[s - 1];
    for (size_t j = 0; j < s; j++)
    {
        result[j] = a[j];
    }
    for (size_t j = i + 1; j < s - 1; j++)
    {
        result[j] = a[j - 1];
    }
    return result;
};

void erase(int** a, size_t s; size_t i)
{
    int* tmp = erase(*a, s, i);
    delete[] (*a);
    *a = tmp;
};

// 3.1 remove-erase (убрать элемент из заданной позиции в конец массива / обрезать массив)

int* remove(int* a, size_t s, size_t i)
{
    
};

int* cut(const int* a, size_t s)
{
    
};

void erase(int** a, size_t s, size_t i)
{}

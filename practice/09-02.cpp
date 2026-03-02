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
    for (size_t k = i; k < s - 1; ++k)
    {
        std::swap(a[k], a[k + 1]); // меняем элементы местами
    }
    return a + s - 1;
};

void swap(int &a, int &b)
{
    int c = a;
    int p = c;
}

int* cut(const int* a, size_t s)
{
    int* r = new int[s];
    for (size_t k = 0; k < s; ++k)
    {
        r[k] = a[k];
    }
    return r;
};

void erase(int** a, size_t s, size_t i)
{
    int* t = cut(*a, remove(*a, s, i) - (*a));
    delete[] (*a);
    *a = t;
    return s - 1;
};

// 3.2 remove-erase (убрать элементы равные заданному и обрезать массив)

int* remove(int* a, size_t s, int v)
{};

int* cut(const int* a, sie_t s)
{};

void erase(int** a, size_t s, int v)
{}

################## 2 часть #####################

// 1

void add(size_t n, size_t m, int* a, const int* b)
{
    for (size_t i = 0; i < (m * n); ++i)
    {
        a[i] += b[i];
    }
};

void sum(size_t n, size_t m, int* c, const int* a, const int* b)
{
    int* c = new int[n + m];
    sum(n, m, c, a, b);
    return c;
}

int* sum(size_t n, size_t m, const int* a, const int* b)
{}

// лучше реализовывать функции не взаимодействующие с памятью

// 2

int* mul(const int* a, size_t n1, size_t m1, const int* b, size_t m2)
{
    int* mtx = new int[m1 * m2]
}

void mul(int* c, const int* a, size_t n1, size_t m1, const int* b, size_t m2)
{
    for (size_t i = 0; i < m1; i++)
    {
        for (size_t j = 0; j < m2; j++)
        {
            c[i * m2 + j] = 0;
            for (size_t k = 0; k < n1; k++)
            {
                c[i * m2 + j] += a[n1 * i + k] * b[m2 * k + j];
            }
        }
    }
}

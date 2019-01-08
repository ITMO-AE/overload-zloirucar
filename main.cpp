#include <iostream>
#include <math.h>
#include <assert.h>

using namespace std;

class Vector3D
{
public:
    Vector3D():
    x(0), y(0), z(0){}

    Vector3D(int x, int y, int z):
    x(x), y(y), z(z) {}

    int getLength() const
    {
        return sqrt(x*x + y*y + z*z);
    }

    // оператор =
    Vector3D& operator= (Vector3D const &rhs)
    {
        if (this != &rhs)
        {
            this->x = rhs.x, this->y = rhs.y, this->z = rhs.z;
        }
        return *this;
    }

    // бинарный оператор +
    Vector3D operator+(Vector3D const &vector)
    {
        return Vector3D(this->x + vector.x, this->y + vector.y, this->z + vector.z);
    }

    //унарный оператор -
    Vector3D operator-()const
    {
        return Vector3D(-x, -y, -z);
    }

    //унарный оператор !
    bool operator! () const
    {
        return (x == 0 && y == 0 && z == 0);
    }

    // операторы сравнения
    friend bool operator== (const Vector3D &vector1, const Vector3D &vector2);
    friend bool operator!= (const Vector3D &vector1, const Vector3D &vector2);

    friend bool operator> (const Vector3D &vector1, const Vector3D &vector2);
    friend bool operator<= (const Vector3D &vector1, const Vector3D &vector2);

    friend bool operator< (const Vector3D &vector1, const Vector3D &vector2);
    friend bool operator>= (const Vector3D &vector1, const Vector3D &vector2);

    //оператор индексации
    /**
     * Рассмотрим подробнее, как обрабатывается стейтмент array[4] = 5.
     * Поскольку приоритет оператора индексации выше приоритета оператора присваивания,
     * то сначала выполняется часть array[4]. array[4] приводит к вызову функции перегрузки
     * оператора [], которая возвратит array.m_array[4]. Поскольку оператор [] использует возврат
     * по ссылке, то он возвращает фактический элемент array.m_array[4]. Наше частично обработанное
     * выражение становится array.m_array[4] = 5, что является прямой операцией присваивания значения элементу массива.
     */
    int& operator[](const int index)
    {
        assert(index >= 0 && index < 3);

        switch (index)
        {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
        }

    }

    //версия для констрантных объектов
    const int& operator[](const int index) const
    {
        assert(index >= 0 && index < 3);

        switch (index)
        {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
        }
    }

    //operator (), может принимать любое количество аргументов
    void operator()(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // версия префикс
    Vector3D& operator++()
    {
        ++x;
        ++y;
        ++z;

    }
    // версия префикс
    Vector3D& operator--()
    {
        --x;
        --y;
        --z;
    }
    // версия постфикс
    Vector3D operator++(int)
    {
        Vector3D tmp(this->x, this->y, this->z);
        ++(*this);

        return tmp;
    }

    // версия постфикс
    Vector3D operator--(int)
    {
        Vector3D tmp(this->x, this->y, this->z);
        --(*this);

        return tmp;
    }



//    int getZ() const
//    {
//        return z;
//    }
//
//    int getY() const
//    {
//        return y;
//    }
//
//    int getX() const
//    {
//        return x;
//    }

    /* Объявление операторов ввода и вывода как дружественных.
     * Мы не можем перегрузить их через методы класса.
     * Потому что при перегрузке через метод класса в качестве левого операнда используется текущий объект.
     * В этом случае левым операндом является объект типа std::ostream. std::ostream является частью стандартной
     * библиотеки C++. Мы не можем использовать std::ostream в качестве левого неявного параметра,
     * на который бы указывал скрытый указатель *this, так как *this может указывать только на текущий
     * объект текущего класса, члены которого мы можем изменить.
     * Поэтому, перегрузка оператора << должна осуществляться через дружественную функцию.
     * */
    friend ostream& operator<< (ostream &os, Vector3D const &vector);
    friend istream& operator>> (istream &os, Vector3D &vector);

private:
    int x, y, z;

};

//Vector3D operator+(Vector3D const &vector1, Vector3D const &vector2)
//{
//    return Vector3D(vector1.getX() + vector2.getX(), vector1.getY() + vector2.getY(), vector1.getZ() + vector2.getZ());
//}

// перегрузка оператора вывода
ostream& operator<< (ostream &os, Vector3D const &vector)
{
    os << "( "<< vector.x << ", " <<  vector.y << ", " <<  vector.z << " )" << endl;
    return os;
}

// перегрузка оператора ввода
istream& operator>> (istream &in, Vector3D &vector)
{
    cout << "enter x: \n";
    in >> vector.x;
    cout << "enter y: \n";
    in >> vector.y;
    cout << "enter z: \n";
    in >> vector.z;
    return in;
}

bool operator==(const Vector3D &vector1, const Vector3D &vector2)
{
    return (vector1.x == vector2.x && vector1.y == vector2.y && vector1.z == vector2.z);
}

bool operator!=(const Vector3D &vector1, const Vector3D &vector2)
{
    return !(vector1==vector2);
}

bool operator>(const Vector3D &vector1, const Vector3D &vector2)
{
    return vector1.getLength() > vector2.getLength();
}

bool operator<=(const Vector3D &vector1, const Vector3D &vector2)
{
    return vector1.getLength() <= vector2.getLength();
}

bool operator<(const Vector3D &vector1, const Vector3D &vector2)
{
    return vector1.getLength() < vector2.getLength();
}

bool operator>=(const Vector3D &vector1, const Vector3D &vector2)
{
    return vector1.getLength() >= vector2.getLength();
}


int main()
{
    Vector3D v1(2, 8 ,10);
    Vector3D v2;
    v2 = v1;
    cout << v2;

    Vector3D v3;
    v3 = v2 + v1;
    cout << v3;

//    cin >> v1;
//    cout << v1;

    Vector3D v4;
    v4 = -v3;

    cout << v4;

    Vector3D v5;
    if (!v5)
    {
        cout << "vector is 0" << endl;
    }

    v5[1] = 100;
    cout << v5;

    const Vector3D v6(5, 76, 90);
    cout << v6[2] << endl;

    Vector3D v7;
    v7(10, 54, 18);
    cout << v7 << endl;

    return 0;
}
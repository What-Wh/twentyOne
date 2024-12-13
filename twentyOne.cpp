#include <iostream>

using namespace std;

template <typename t>
class Matrycha {
    t** arr;
    int sizeI;
    int sizeJ;
public:
    Matrycha(int sizeI, int sizeJ) : sizeI(sizeI), sizeJ(sizeJ) {
        arr = new t * [sizeI];
        for (int i = 0; i < sizeI; i++)
        {
            arr[i] = new t[sizeJ];
        }
        for (int i = 0; i < sizeI; i++)
        {
            for (int j = 0; j < sizeJ; j++)
            {
                arr[i][j] = rand() % 10;
            }
        }
    }
    ~Matrycha() {
        for (int i = 0; i < sizeI; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    void show() {
        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrycha operator+(const Matrycha& m2) {
        Matrycha temp(this->sizeI, this->sizeJ);
        for (int i = 0; i < temp.sizeI; i++)
        {
            for (int j = 0; j < temp.sizeJ; j++)
            {
                temp.arr[i][j] = this->arr[i][j] + m2.arr[i][j];
            }
        }
        return temp;
    }
    Matrycha operator-(const Matrycha& m2) {
        Matrycha temp(this->sizeI, this->sizeJ);
        for (int i = 0; i < temp.sizeI; i++)
        {
            for (int j = 0; j < temp.sizeJ; j++)
            {
                temp.arr[i][j] = this->arr[i][j] - m2.arr[i][j];
            }
        }
        return temp;
    }
    Matrycha operator*(const Matrycha& m2) {
        Matrycha temp(this->sizeI, this->sizeJ);
        for (int i = 0; i < temp.sizeI; i++)
        {
            for (int j = 0; j < temp.sizeJ; j++)
            {
                temp.arr[i][j] = this->arr[i][j] * m2.arr[i][j];
            }
        }
        return temp;
    }
    Matrycha operator/(const Matrycha& m2) {
        Matrycha temp(this->sizeI, this->sizeJ);
        for (int i = 0; i < temp.sizeI; i++)
        {
            for (int j = 0; j < temp.sizeJ; j++)
            {
                temp.arr[i][j] = this->arr[i][j] / m2.arr[i][j];
            }
        }
        return temp;
    }
};

int main()
{
    srand(time(0));
    Matrycha<int> m1(3, 3);
    Matrycha<int> m2(3, 3);
    Matrycha<int> m3 = m1 / m2;
    m3.show();
}
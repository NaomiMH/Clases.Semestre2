#ifndef MATRICES_H
#define MATRICES_H

using namespace std;

#include <fstream>
#include <iostream>

const int MAX=50;

class Matrices
{
    public:
        Matrices(int size=MAX);
        Matrices transpuesta();

        friend Matrices operator + (const Matrices& mat1, const Matrices& mat2);
        friend Matrices operator - (const Matrices& mat1, const Matrices& mat2);
        friend Matrices operator * (const Matrices& mat1, const Matrices& mat2);
        friend ostream& operator << (ostream& salida, const Matrices& mat);
        friend istream& operator >> (istream& entrada, Matrices& mat);
    private:
        int arr[MAX][MAX];
        int num;
};

Matrices::Matrices(int size)
{
    num=size;
}

Matrices Matrices::transpuesta()
{
    Matrices tem(num);
    for(int ren=0; ren<num; ren++){
        for(int col=0; col<num; col++){
            tem.arr[col][ren]=arr[ren][col];
        }
    }
    return tem;
}

Matrices operator + (const Matrices& mat1, const Matrices& mat2)
{
    Matrices tem(mat1.num);
    for(int ren=0; ren<tem.num; ren++){
        for(int col=0; col<tem.num; col++){
            tem.arr[ren][col]=mat1.arr[ren][col]+mat2.arr[ren][col];
        }
    }
    return tem;
}

Matrices operator - (const Matrices& mat1, const Matrices& mat2)
{
    Matrices tem(mat1.num);
    for(int ren=0; ren<tem.num; ren++){
        for(int col=0; col<tem.num; col++){
            tem.arr[ren][col]=mat1.arr[ren][col]-mat2.arr[ren][col];
        }
    }
    return tem;
}

Matrices operator * (const Matrices& mat1, const Matrices& mat2)
{
    Matrices tem(mat1.num);
    for(int ren=0; ren<tem.num; ren++){
        for(int col=0; col<tem.num; col++){
            tem.arr[ren][col]=mat1.arr[ren][col]*mat2.arr[ren][col];
        }
    }
    return tem;
}

ostream& operator << (ostream& salida, const Matrices& mat)
{
    for(int ren=0; ren<mat.num; ren++){
        for(int col=0; col<mat.num; col++){
            salida << mat.arr[ren][col] << " ";
        }
        salida << endl;
    }
    return salida;
}

istream& operator >> (istream& entrada, Matrices& mat)
{
    entrada>> mat.num;
    for(int ren=0; ren<mat.num; ren++){
        for(int col=0; col<mat.num; col++){
            entrada >> mat.arr[ren][col];
        }
    }
    return entrada;
}


#endif // MATRICES_H

#include "Matrices.h"

namespace Matrices
{

    Matrix::Matrix(int _rows, int _cols) : rows(_rows), cols(_cols)
    {
        a = vector<vector<double>>(rows, vector<double>(cols,0));
    }


    Matrix operator+(const Matrix& m1, const Matrix& m2)
    {
        if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols())
        {
            throw std::invalid_argument("Matrix does not match");
        }

        Matrix result(m1.getRows(), m1.getCols());
        for (int i = 0; i < m1.getRows(); ++i)
        {
            for (int j = 0; j < m1.getCols(); ++j)
            {
                result(i, j) = m1(i, j) + m2(i, j);
            }
        }

        return result;
    }


    Matrix operator*(const Matrix& m1, const Matrix& m2)
    {
        if (m1.getCols() != m2.getRows())
        {
            throw std::invalid_argument("Matrix does not match");
        }

        Matrix result(m1.getRows(), m2.getCols());
        for (int i = 0; i < m1.getRows(); ++i)
        {
            for (int j = 0; j < m2.getCols(); ++j)
            {
                for (int k = 0; k < m1.getCols(); ++k)
                {
                    result(i, j) += m1(i, k) * m2(k, j);
                }
            }
        }

        return result;
    }


    bool operator==(const Matrix& m1, const Matrix& m2)
    {
        if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols())
        {
            return false;
        }

        for (int i = 0; i < m1.getRows(); ++i)
        {
            for (int j = 0; j < m1.getCols(); ++j)
            {
                if (m1(i, j) != m2(i, j))
                {
                    return false;
                }
            }
        }

        return true;
    }


    bool operator!=(const Matrix& m1, const Matrix& m2)
    {
        return !(m1 == m2);
    }


    ostream& operator<<(ostream& os, const Matrix& m)
    {
        for (int i = 0; i < m.getRows(); ++i)
        {
            for (int j = 0; j < m.getCols(); ++j)
            {
                os << m(i, j);
                if (j < m.getCols() - 1)
                {
                    os << " ";
                }
            }
            os << "\n";
        }
        return os;
    }


    RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2)
    {
        a[0][0] = cos(theta);
        a[0][1] = -sin(theta);
        a[1][0] = sin(theta);
        a[1][1] = cos(theta);
    }


    ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
    {
        a[0][0] = scale;
        a[0][1] = 0;
        a[1][0] = 0;
        a[1][1] = scale;
    }


    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols)
    {
        for (int i = 0; i < nCols; ++i)
        {
            a[0][i] = xShift;
            a[1][i] = yShift;
        }
    }
}

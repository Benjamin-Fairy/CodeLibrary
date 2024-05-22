/*
The MIT License (MIT)
Copyright (C) 2024 Izumi Sucrose

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this
permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO
EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <bits/stdc++.h>
#define complex_type pair<double, double>
#define complex_vector vector<complex_type>
#define matrix_type vector<complex_vector>
#define GET_VARIABLE_NAME(variable) #variable

using namespace std;

// Analog Complex Number Type
pair<double, double> x(double i, double j = 0) {
  return make_pair(i, j);
} // 1+2i==x(1,2)

// convert string to complex
complex_type str2cmpx(string a) {
  bool _img = false;
  string real, img;
  double real_d = 0, img_d = 0;
  for (auto i : a) {
    if (i == '+')
      _img = true;
    else if (_img)
      img += i;
    else
      real += i;
  }
  if (img != "")
    return x(stod(real), stod(img));
  else {
    if ((real.back() == 'j') || (real.back() == 'i')) {
      real.pop_back();
      return x(0, stod(real));
    } else
      return x(stod(real), 0);
  }
}

// Function:Matrix dot product
complex_type x_multiple(complex_type xx, complex_type y) {
  double a = xx.first, b = xx.second;
  double c = y.first, d = y.second;
  return x(a * c - b * d, a * d + b * c);
}

// Function:Matrix dot divide
complex_type x_divide(complex_type xx, complex_type y) {
  double a = xx.first, b = xx.second;
  double c = y.first, d = y.second;
  double real = (a * c + b * d) / (c * c + d * d);
  double imagine = (b * c - a * d) / (c * c + d * d);
  if (isnan(real))
    real = 0;
  if (isnan(imagine))
    imagine = 0;
  return x(real, imagine);
}

// Function:Matrix add
complex_type x_add(complex_type xx, complex_type y) {
  double a = xx.first, b = xx.second;
  double c = y.first, d = y.second;
  return x(a + c, b + d);
}

// Function:Matrix subtract
complex_type x_minus(complex_type xx, complex_type y) {
  double a = xx.first, b = xx.second;
  double c = y.first, d = y.second;
  return x(a - c, b - d);
}

// Reload Operators
complex_type operator+(const complex_type &a, const complex_type &b) {
  return x_add(a, b);
}

complex_type operator-(const complex_type &a, const complex_type &b) {
  return x_minus(a, b);
}

complex_type operator*(const complex_type &a, const complex_type &b) {
  return x_multiple(a, b);
}

complex_type operator/(const complex_type &a, const complex_type &b) {
  return x_divide(a, b);
}

ostream &operator<<(ostream &out, const complex_type &d) {
  out << d.first << "+j" << d.second;
  return out;
}

ostream &operator<<(ostream &out, const complex_vector &d) {
  for (int i = 0; i < d.size(); i++)
    out << d[i] << "\t";
  return out;
}

// Matrix Class, used to store and operate a complex matrix
class matrix {
public:
  matrix();
  void init(int, int, complex_type); // initialize the matrix using given
                                     // row,column count and default value
  void fork(matrix_type);            // fork the existed matrix_type variable
  void set(int, int, complex_type);  // set the i,j value
  complex_type get(int, int);        // get paired value from matrix
  int numel();                       // get the number of elements of the matrix
  int size(int); // get the matrix size,argv decides measured dimention:1 means
                 // row,2 means col
  void print();  // print matrix on console
  matrix_type export_matrix();
  matrix slice(int, int, int, int);

private:
  void size_calc(); // Calculate the row and col of the internal_matrix
  void size_expand(int, int);  // expand matrix to given size
  matrix_type internal_matrix; // matrix itself
  int row;                     // matrix row counts
  int col;                     // matrix column counts
};

matrix::matrix() {
  // internal_matrix={{x(0)}};
  row = -1; // initialize the row count
  col = -1; // initialize the column count
}

// (re)Initialize the matrix
void matrix::init(int i, int j, complex_type dv = x(0)) {
  internal_matrix.clear();
  for (int ii = 0; ii < i; ii++) {
    complex_vector N;
    internal_matrix.push_back(N);
    for (int jj = 0; jj < j; jj++) {
      internal_matrix[ii].push_back(dv);
    }
  }
  size_calc();
}

// Copy a existed matrix_type variable to self
void matrix::fork(matrix_type input_matrix) {
  internal_matrix = input_matrix;
  size_calc();
}

// Calculate the size of the matrix, and update the row and col
void matrix::size_calc() {
  row = internal_matrix.size();
  col = -1;
  for (int i = 0; i < row; i++)
    if (int(internal_matrix[i].size()) > col)
      col = int(internal_matrix[i].size());
}

// Set single element to matrix
void matrix::set(int i, int j, complex_type value) {
  size_expand(i, j);
  internal_matrix[i - 1][j - 1] = value;
}

// Expand the memory zone of the matrix
void matrix::size_expand(int i, int j) {
  if (1) {
    while (int(internal_matrix.size()) < i) {
      complex_vector M;
      internal_matrix.push_back(M);
    }
    size_calc();
  }
  if (1) {
    for (int t = 0; t < row; t++) {
      while (int(internal_matrix[t].size()) < j) {
        complex_type N = x(0);
        internal_matrix[t].push_back(N);
      };
    }
    size_calc();
  }
}

// Return the value of the given position (i,j)
complex_type matrix::get(int i, int j) { return internal_matrix[i - 1][j - 1]; }

// Return the area size (row*col)
int matrix::numel() { return row * col; }

// Return the matrix size,argument 1=row,2=col
int matrix::size(int type) {
  if (type == 1)
    return row;
  if (type == 2)
    return col;
  return 0;
}

// Print the matrix on the console
void matrix::print() {
  cout << "Matrix Nodes Count:" << row * col << endl;
  cout << "Matrix Row Count: " << row << " ,Matrix Col Count: " << col << endl;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++)
      cout << setw(10) << setprecision(4) << showpoint
           << internal_matrix[i][j].first << "+j"
           << internal_matrix[i][j].second << "\t";
    cout << endl;
  }
}

// Export the matrix to a matrix_type variable
matrix_type matrix::export_matrix() { return internal_matrix; }

// Slice out a matrix from original matrix area (_a:_b,a:b) and return it
matrix matrix::slice(int a, int b, int _a = 1, int _b = 1) {
  matrix new_matrix;
  new_matrix.init(a - _a + 1, b - _b + 1);
  for (int i = 1; i <= a - _a + 1; i++)
    for (int j = 1; j <= b - _b + 1; j++)
      new_matrix.set(i, j, internal_matrix[i - 2 + _a][j - 2 + _b]);
  return new_matrix;
}

// Function:Revert a matrix and return it
matrix revert_matrix(matrix input_matrix) {
  matrix reverted_matrix;
  reverted_matrix.init(input_matrix.size(2), input_matrix.size(1));
  for (int i = 1; i <= input_matrix.size(1); i++)
    for (int j = 1; j <= input_matrix.size(2); j++)
      reverted_matrix.set(j, i, input_matrix.get(i, j));
  return reverted_matrix;
}

// Function:Matrix Cross Product
matrix m_multiple(matrix A, matrix B) {
  matrix result;
  int SIZE_M = A.size(1), SIZE_S = B.size(2), SIZE_N = A.size(2);
  result.init(SIZE_M, SIZE_S);
  // cout << SIZE_M << " " << SIZE_N << " " << SIZE_S << endl;
  for (int m = 1; m <= SIZE_M; m++) {
    for (int s = 1; s <= SIZE_S; s++) {
      for (int n = 1; n <= SIZE_N; n++) {
        result.set(m, s, result.get(m, s) + A.get(m, n) * B.get(n, s));
      }
    }
  }
  return result;
}

// Reload Operator
matrix operator*(const matrix &a, const matrix &b) { return m_multiple(a, b); }

// Function:Calculate Unbalanced Value
matrix_type Unbalanced(int n, int m, matrix P, matrix Q, matrix U, matrix G,
                       matrix B, matrix theta) {
  // Calculating ΔPi
  matrix Pn, Pi, dP;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      complex_type temp;
      temp =
          U.get(1, i) * U.get(1, j) *
          (G.get(i, j) * x(cos(theta.get(1, i).first - theta.get(1, j).first)) +
           B.get(i, j) * x(sin(theta.get(1, i).first - theta.get(1, j).first)));
      Pn.set(1, j, temp);
    }
    complex_type sum = x(0);
    for (int k = 1; k <= Pn.size(2); k++) {
      sum = sum + Pn.get(1, k);
    }
    Pi.set(1, i, sum);
  }
  for (int i = 1; i <= n - 1; i++)
    dP.set(1, i, P.get(1, i) - Pi.get(1, i));

  // Calculating ΔQi
  matrix Qn, Qi, dQ;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      complex_type temp;
      temp =
          U.get(1, i) * U.get(1, j) *
          (G.get(i, j) * x(sin(theta.get(1, i).first - theta.get(1, j).first)) -
           B.get(i, j) * x(cos(theta.get(1, i).first - theta.get(1, j).first)));
      Qn.set(1, j, temp);
    }
    complex_type sum = x(0);
    for (int k = 1; k <= Qn.size(2); k++)
      sum = sum + Qn.get(1, k);
    Qi.set(1, i, sum);
  }
  for (int i = 1; i <= m; i++)
    dQ.set(1, i, Q.get(1, i) - Qi.get(1, i));

  // Convert result to matrix in order to hand over across functions
  matrix_type res;
  complex_vector fdP, fdQ, fPi, fQi;
  for (int i = 1; i <= dP.size(2); i++)
    fdP.push_back(dP.get(1, i));
  for (int i = 1; i <= dQ.size(2); i++)
    fdQ.push_back(dQ.get(1, i));
  for (int i = 1; i <= Pi.size(2); i++)
    fPi.push_back(Pi.get(1, i));
  for (int i = 1; i <= Qi.size(2); i++)
    fQi.push_back(Qi.get(1, i));
  res.push_back(fdP);
  res.push_back(fdQ);
  res.push_back(fPi);
  res.push_back(fQi);
  return res;
}

// Function:Calculate Jacobi Matrix
matrix Jacobi(int n, int m, matrix U, matrix theta, matrix B, matrix G,
              complex_vector Pi, complex_vector Qi) {
  // Slice:H,N,K,L
  matrix H, N, K, L, res;

  // When i!=j
  for (int i = 1; i <= n - 1; i++)
    for (int j = 1; j <= n - 1; j++) {
      complex_type temp;
      temp =
          x(-1) * U.get(1, i) * U.get(1, j) *
          (G.get(i, j) * x(sin(theta.get(1, i).first - theta.get(1, j).first)) -
           B.get(i, j) * x(cos(theta.get(1, i).first - theta.get(1, j).first)));
      H.set(i, j, temp);
    }
  for (int i = 1; i <= n - 1; i++)
    for (int j = 1; j <= m; j++) {
      complex_type temp;
      temp =
          x(-1) * U.get(1, i) * U.get(1, j) *
          (G.get(i, j) * x(cos(theta.get(1, i).first - theta.get(1, j).first)) +
           B.get(i, j) * x(sin(theta.get(1, i).first - theta.get(1, j).first)));
      N.set(i, j, temp);
    }
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n - 1; j++) {
      complex_type temp;
      temp =
          U.get(1, i) * U.get(1, j) *
          (G.get(i, j) * x(cos(theta.get(1, i).first - theta.get(1, j).first)) +
           B.get(i, j) * x(sin(theta.get(1, i).first - theta.get(1, j).first)));
      K.set(i, j, temp);
    }
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) {
      complex_type temp;
      temp =
          x(-1) * U.get(1, i) * U.get(1, j) *
          (G.get(i, j) * x(sin(theta.get(1, i).first - theta.get(1, j).first)) -
           B.get(i, j) * x(cos(theta.get(1, i).first - theta.get(1, j).first)));
      L.set(i, j, temp);
    }

  // When i==j

  for (int i = 1; i <= n - 1; i++)
    H.set(i, i, U.get(1, i) * U.get(1, i) * B.get(i, i) + Qi[i - 1]);
  for (int i = 1; i <= m; i++)
    N.set(i, i, x(-1) * U.get(1, i) * U.get(1, i) * G.get(i, i) - Pi[i - 1]);
  for (int i = 1; i <= m; i++)
    K.set(i, i, U.get(1, i) * U.get(1, i) * G.get(i, i) - Pi[i - 1]);
  for (int i = 1; i <= m; i++)
    L.set(i, i, U.get(1, i) * U.get(1, i) * B.get(i, i) - Qi[i - 1]);

  /*
  cout << "\nH:";
  H.print();
  cout << "\nN:";
  N.print();
  cout << "\nK:";
  K.print();
  cout << "\nL:";
  L.print();
  */

  // Join Matrices
  //   | H N |
  //   | K L |
  for (int i = 1; i <= m + n - 1; i++)
    for (int j = 1; j <= m + n - 1; j++) {
      matrix current_matrix;
      int rel_i, rel_j;
      if (i <= n - 1)
        if (j <= n - 1)
          current_matrix = H, rel_i = i, rel_j = j;
        else
          current_matrix = N, rel_i = i, rel_j = j - n + 1;
      else if (j <= n - 1)
        current_matrix = K, rel_i = i - n + 1, rel_j = j;
      else
        current_matrix = L, rel_i = i - n + 1, rel_j = j - n + 1;
      res.set(i, j, current_matrix.get(rel_i, rel_j));
    }
  return res;
}

// Invert Matrix Class
class invert_matrix {
public:
  invert_matrix(matrix a) {
    row_matrix = a;
    row = row_matrix.size(1);
    col = row_matrix.size(2);
  };
  matrix matrix_inverse();

private:
  int col;
  int row;
  matrix row_matrix;
  void matrix_swap_row(matrix &input_matrix, int i, int j,
                       int n) // Exchange 2 rows of the matrix
  {
    complex_type temp;
    for (int k = 1; k <= n; k++) {
      temp = input_matrix.get(i, k);
      input_matrix.set(i, k, input_matrix.get(j, k));
      input_matrix.set(j, k, temp);
    }
  }
  void matrix_minus_inner(matrix &input_matrix, complex_type a, int i, int j,
                          int n) {
    for (int k = 1; k <= n; k++)
      input_matrix.set(i, k,
                       input_matrix.get(i, k) - a * input_matrix.get(j, k));
  }
};

matrix invert_matrix::matrix_inverse() {
  matrix A_E;
  matrix A_inverse;
  // Building Augmented Matrix
  A_E.init(row, col * 2);
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= col * 2; j++) {
      if (j <= col) {
        A_E.set(i, j, row_matrix.get(i, j));
      } else if ((j - col) == i) {
        A_E.set(i, j, x(1));
      } else {
        A_E.set(i, j, x(0));
      }
    }
  }
  // Transforming the matrix into an upper triangular matrix
  for (int i = 1; i <= row; i++) {
    if (A_E.get(i, i) == x(0)) {
      for (int k = i + 1; k <= col; k++) {
        if (A_E.get(k, i) != x(0)) {
          matrix_swap_row(A_E, i, k, 2 * col);
          break;
        }
      }
    }
    for (int j = i + 1; j <= col; j++) {
      matrix_minus_inner(A_E, A_E.get(j, i) / A_E.get(i, i), j, i, col * 2);
    }
  }
  // Determine whether the matrix is invertible
  for (int i = 1; i <= row; i++) {
    if (A_E.get(i, i) == x(0)) {
      cout << "Matrix is not invertible" << endl;
      exit(0);
    }
  }
  // Convert upper triangle to diagonal matrix
  for (int j = 2; j <= col; j++) {
    for (int i = 1; i < j; i++) {
      matrix_minus_inner(A_E, A_E.get(i, j) / A_E.get(j, j), i, j, 2 * col);
    }
  }
  for (int i = 1; i <= row; i++) {
    for (int j = col + 1; j <= 2 * col; j++) {
      A_inverse.set(i, j - col, A_E.get(i, j) / A_E.get(i, i));
    }
  }
  return A_inverse;
}

// Function:Calculating voltage correction using PQ decomposition method
matrix_type PQ_LJ(int n, int m, complex_vector dP, complex_vector dQ, matrix U,
                  matrix B) {
  complex_vector dP_U, dQ_U, dUdtheta, dtheta, dU;
  for (int i = 1; i <= n - 1; i++)
    dP_U.push_back(dP[i - 1] / U.get(1, i));
  for (int i = 1; i <= m; i++)
    dQ_U.push_back(dQ[i - 1] / U.get(1, i));

  matrix dU_inv;

  invert_matrix temp(B.slice(n - 1, n - 1));
  dU_inv = temp.matrix_inverse();
  matrix dP_U_0, dUdtheta_0;
  dP_U_0.fork({dP_U}); // Row vector
  dUdtheta_0 = dU_inv * revert_matrix(dP_U_0);
  dUdtheta_0 = revert_matrix(dUdtheta_0);
  for (int i = 1; i <= dUdtheta_0.size(2); i++)
    dUdtheta.push_back(dUdtheta_0.get(1, i) * x(-1));
  for (int i = 1; i <= n - 1; i++)
    dtheta.push_back(dUdtheta[i - 1] / U.get(1, i));

  invert_matrix temp1(B.slice(m, m));
  dU_inv = temp1.matrix_inverse();
  matrix dQ_U_0, dU_0;
  dQ_U_0.fork({dQ_U}); // Row vector
  dU_0 = dU_inv * revert_matrix(dQ_U_0);
  dU_0 = revert_matrix(dU_0);
  for (int i = 1; i <= dU_0.size(2); i++)
    dU.push_back(dU_0.get(1, i) * x(-1));
  for (int i = 1; i <= n - m; i++)
    dU.push_back(x(0));
  dtheta.push_back(x(0));
  matrix_type res;
  res.push_back(dU);
  res.push_back(dtheta);
  return res;
}

// Function:Correct node voltage
matrix_type Correct(int n, int m, matrix U, complex_vector dP,
                    complex_vector dQ, matrix J) {
  matrix Ud2;
  complex_vector dPQ, dUtheta, dtheta, dU;
  matrix_type res;
  for (int i = 1; i <= m; i++)
    Ud2.set(i, i, U.get(1, i));

  invert_matrix J_inv(J);

  dPQ = dP;
  dPQ.insert(dPQ.end(), dQ.begin(), dQ.end());
  matrix dPQ_0, dUtheta_0;
  dPQ_0.fork({dPQ});
  dPQ_0 = revert_matrix(dPQ_0);
  dUtheta_0 = J_inv.matrix_inverse() * dPQ_0;
  dUtheta_0 = revert_matrix(dUtheta_0);
  for (int i = 1; i <= dUtheta_0.size(2); i++)
    dUtheta.push_back(x(-1) * dUtheta_0.get(1, i));
  for (int i = 1; i <= n - 1; i++)
    dtheta.push_back(dUtheta[i - 1]);
  dtheta.push_back(x(0));

  matrix dU_0;
  dU_0 = Ud2 * revert_matrix(dUtheta_0.slice(1, n + m - 1, 1, n));
  dU_0 = revert_matrix(dU_0);
  for (int i = 1; i <= dU_0.size(2); i++)
    dU.push_back(x(-1) * dU_0.get(1, i));
  for (int i = 1; i <= n - m; i++)
    dU.push_back(x(0));

  res.push_back(dU);
  res.push_back(dtheta);
  return res;
}

int main() {
  clock_t start, end; // time variable
  start = clock();    // start time
  int SB = 100;       // Benchmark Capacity, take 100 as default
  vector<double> Bus;

  // This is SAMPLE DATA, please adjust them to your own data
  // int SB = 100; // Benchmark capacity in MVA
  /*
  Bus=[230 230 230 230 230 230 18 13.8 16.5]
  vector<double> Bus = {230, 230, 230,  230, 230,
                        230, 18,  13.8, 16.5}; // Bus reference voltage
  */
  matrix Line, Trans, Gen, Load, Zt;
  // AC line parameters:
  // I-side bus Number, J-side bus Number, impedance, 1/2 ground admittance
  /*
  Line=[6   1   0.01+0.085i     0.088i
        1   4   0.032+0.161i    0.153i
        4   3   0.0085+0.072i   0.0745i
        3   5   0.0119+0.1008i  0.1045i
        5   2   0.039+0.17i     0.179i
        2   6   0.017+0.092i    0.079i]

  Line.fork({{x(6), x(1), x(0.01, 0.085), x(0, 0.088)},
             {x(1), x(4), x(0.032, 0.161), x(0, 0.153)},
             {x(4), x(3), x(0.0085, 0.072), x(0, 0.0745)},
             {x(3), x(5), x(0.0119, 0.1008), x(0, 0.1045)},
             {x(5), x(2), x(0.039, 0.17), x(0, 0.179)},
             {x(2), x(6), x(0.017, 0.092), x(0, 0.079)}});
  */

  // Transformer parameters
  // I-side bus Number, J-side bus Number, impedance, transformer ratio
  // Transformer impedance reduction to side I
  /*
  Trans=[ 9   6   0.0576i   1
          7   4   0.0625i   1
          8   5   0.0586i   1]
  Trans.fork({{x(9), x(6), x(0, 0.0576), x(1)},
              {x(7), x(4), x(0, 0.0625), x(1)},
              {x(8), x(5), x(0, 0.0586), x(1)}});
  */

  // Generator parameters
  // Bus Number, node type, PV/U, θ
  /*
  Gen=[ 9   3   1.04  0
        7   2   1.63  1.025
        8   2   0.85  1.025]
  Gen.fork({{x(9), x(3), x(1.04), x(0)},
            {x(7), x(2), x(1.63), x(1.025)},
            {x(8), x(2), x(0.85), x(1.025)}});
  */

  // Load parameters
  // Bus, node type, P, Q
  /*
  Load=[  1   1   -1.25   -0.5
          2   1   -0.9    -0.3
          3   1   -1      -0.35]
  Load.fork({{x(1), x(1), x(-1.25), x(-0.5)},
             {x(2), x(1), x(-0.9), x(-0.3)},
             {x(3), x(1), x(-1), x(-0.35)}});
  */

  //##########################################################
  fstream input_data("Newton_PQ_data.dat", ios::in);
  string buffer;
  // Get Benchmark Capacity parameters
  input_data.seekg(0, ios::beg);
  while (getline(input_data, buffer)) {
    if (buffer == "[Benchmark Capacity]") {
      while (getline(input_data, buffer))
        if (buffer == "")
          break;
        else
          SB = atoi(buffer.c_str());
      break;
    }
  }

  // Get Bus Parameters
  input_data.seekg(0, ios::beg);
  string raw_data;
  while (getline(input_data, buffer)) {
    if (buffer == "[Bus]") {
      while (getline(input_data, buffer))
        if (buffer == "")
          break;
        else
          raw_data = buffer;
      break;
    }
  }

  string temp;
  for (auto i : raw_data) {
    if (i != ' ')
      temp += i;
    else {
      Bus.push_back(stod(temp));
      temp = "";
    }
  }
  Bus.push_back(stod(temp));

  // Get AC line parameters
  input_data.seekg(0, ios::beg);
  while (getline(input_data, buffer)) {
    if (buffer == "[AC Line Parameters]") {
      int row = 1;
      while (getline(input_data, buffer)) {
        if (buffer == "")
          break;
        else {
          temp = "";
          int cnt = 1;
          for (auto a : buffer)
            if (a == ' ') {
              Line.set(row, cnt++, str2cmpx(temp));
              temp = "";
            } else
              temp += a;
          Line.set(row, cnt++, str2cmpx(temp));
          temp = "";
        }
        row++;
      }
      break;
    }
  }

  // Get Transformer parameters
  input_data.seekg(0, ios::beg);
  while (getline(input_data, buffer)) {
    if (buffer == "[Transformer Parameters]") {
      int row = 1;
      while (getline(input_data, buffer)) {
        if (buffer == "")
          break;
        else {
          temp = "";
          int cnt = 1;
          for (auto a : buffer)
            if (a == ' ') {
              Trans.set(row, cnt++, str2cmpx(temp));
              temp = "";
            } else
              temp += a;
          Trans.set(row, cnt++, str2cmpx(temp));
          temp = "";
        }
        row++;
      }
      break;
    }
  }

  // Get Generator parameters
  input_data.seekg(0, ios::beg);
  while (getline(input_data, buffer)) {
    if (buffer == "[Generator Parameters]") {
      int row = 1;
      while (getline(input_data, buffer)) {
        if (buffer == "")
          break;
        else {
          temp = "";
          int cnt = 1;
          for (auto a : buffer)
            if (a == ' ') {
              Gen.set(row, cnt++, str2cmpx(temp));
              temp = "";
            } else
              temp += a;
          Gen.set(row, cnt++, str2cmpx(temp));
          temp = "";
        }
        row++;
      }
      break;
    }
  }

  // Load Parameters
  input_data.seekg(0, ios::beg);
  while (getline(input_data, buffer)) {
    if (buffer == "[Load Parameters]") {
      int row = 1;
      while (getline(input_data, buffer)) {
        if (buffer == "")
          break;
        else {
          temp = "";
          int cnt = 1;
          for (auto a : buffer)
            if (a == ' ') {
              Load.set(row, cnt++, str2cmpx(temp));
              temp = "";
            } else
              temp += a;
          Load.set(row, cnt++, str2cmpx(temp));
          temp = "";
        }
        row++;
      }
      break;
    }
  }

  // Redirect output stream
  freopen("Newton_PQ_output.log", "w+", stdout);
  //##########################################################
  int mode = 2;
  // 1- Newton's method in polar coordinates, 2- PQ decomposition method
  int Tmax = 20;                    // Max iterating count
  double limit = 1.0 * pow(10, -8); // Required precision

  Zt.init(Trans.size(1), 3);
  for (int i = 1; i <= Zt.size(1); i++)
    Zt.set(i, 1, Trans.get(i, 3) / Trans.get(i, 4));
  for (int i = 1; i <= Zt.size(1); i++)
    Zt.set(i, 2, Trans.get(i, 3) / (x(1) - Trans.get(i, 4)));
  for (int i = 1; i <= Zt.size(1); i++)
    Zt.set(i, 3,
           Trans.get(i, 3) /
               (Trans.get(i, 4) * Trans.get(i, 4) - Trans.get(i, 4)));
  matrix Trans_pi;
  for (int i = 1; i <= Trans.size(1); i++)
    for (int j = 1; j <= 2; j++) {
      Trans_pi.set(i, j, Trans.get(i, j));
    }
  for (int i = 1; i <= Zt.size(1); i++)
    for (int j = 1; j <= 1; j++) {
      Trans_pi.set(i, j + 2, Zt.get(i, j));
    }
  for (int i = 1; i <= Zt.size(1); i++)
    for (int j = 2; j <= 2; j++) {
      Trans_pi.set(i, j + 2, x(1) / Zt.get(i, j));
    }
  for (int i = 1; i <= Zt.size(1); i++)
    for (int j = 3; j <= 3; j++) {
      Trans_pi.set(i, j + 2, x(1) / Zt.get(i, j));
    }
  int n = Bus.size();
  int m = n - 1;
  for (int i = 1; i <= Gen.size(1); i++)
    if (Gen.get(i, 2) == x(2))
      m = m - 1;

  for (int i = 1; i <= Load.size(1); i++)
    if (Load.get(i, 2) == x(2))
      m = m - 1;

  matrix P, Q, U, theta;
  P.init(1, n);
  Q.init(1, n);
  U.init(1, n, x(1));
  theta.init(1, n);
  for (int i = 1; i <= Gen.size(1); i++) {
    if (Gen.get(i, 2) == x(1)) {
      P.set(1, Gen.get(i, 1).first, Gen.get(i, 3));
      Q.set(1, Gen.get(i, 1).first, Gen.get(i, 4));
    }
    if (Gen.get(i, 2) == x(2)) {
      P.set(1, Gen.get(i, 1).first, Gen.get(i, 3));
      U.set(1, Gen.get(i, 1).first, Gen.get(i, 4));
    }
    if (Gen.get(i, 2) == x(3)) {
      U.set(1, Gen.get(i, 1).first, Gen.get(i, 3));
      theta.set(1, Gen.get(i, 1).first, Gen.get(i, 4));
    }
  }
  for (int i = 1; i <= Load.size(1); i++) {
    if (Load.get(i, 2) == x(1)) {
      P.set(1, Load.get(i, 1).first, Load.get(i, 3));
      Q.set(1, Load.get(i, 1).first, Load.get(i, 4));
    }
    if (Load.get(i, 2) == x(2)) {
      P.set(1, Load.get(i, 1).first, Load.get(i, 3));
      U.set(1, Load.get(i, 1).first, Load.get(i, 4));
    }
    if (Load.get(i, 2) == x(3)) {
      U.set(1, Load.get(i, 1).first, Load.get(i, 3));
      theta.set(1, Load.get(i, 1).first, Load.get(i, 4));
    }
  }
  cout << "------------------------------------------------------------"
          "-------"
       << endl;
  cout << "Initial Arguments" << endl;
  cout << "\nNode Active Power" << endl;
  P.print();
  cout << "\nNode Reactive Power" << endl;
  Q.print();
  cout << "\nNode Voltage Amplitude" << endl;
  U.print();
  cout << "\nNode Phase Angle(degree)" << endl;
  theta.print();

  // Phase angle to radian
  for (int i = 1; i <= theta.size(1); i++)
    for (int j = 1; j <= theta.size(2); j++)
      theta.set(i, j, x(theta.get(i, j).first / 180 * M_PI));

  // Calculate node admittance matrix
  matrix Y, y;
  Y.init(n, n);
  y.init(n, n);
  for (int i = 1; i <= Line.size(1); i++) {
    complex_type ii = Line.get(i, 1), jj = Line.get(i, 2);
    y.set(ii.first, jj.first, x(1) / Line.get(i, 3));
    y.set(jj.first, ii.first, y.get(ii.first, jj.first));
  }
  for (int i = 1; i <= Trans_pi.size(1); i++) {
    complex_type ii = Trans_pi.get(i, 1), jj = Trans_pi.get(i, 2);
    y.set(ii.first, jj.first, x(1) / Trans_pi.get(i, 3));
    y.set(jj.first, ii.first, y.get(ii.first, jj.first));
  }
  // Calculate y(i,i)
  for (int i = 1; i <= Line.size(1); i++) {
    complex_type ii = Line.get(i, 1), jj = Line.get(i, 2);
    y.set(ii.first, ii.first, y.get(ii.first, ii.first) + Line.get(i, 4));
    y.set(jj.first, jj.first, y.get(jj.first, jj.first) + Line.get(i, 4));
  }
  for (int i = 1; i <= Trans_pi.size(1); i++) {
    complex_type ii = Trans_pi.get(i, 1), jj = Trans_pi.get(i, 2);
    y.set(ii.first, ii.first, y.get(ii.first, ii.first) + Trans_pi.get(i, 4));
    y.set(jj.first, jj.first, y.get(jj.first, jj.first) + Trans_pi.get(i, 5));
  }
  // Calculate y using Y
  complex_vector ysum;
  for (int i = 1; i <= y.size(1); i++) {
    complex_type sum = x(0);
    for (int j = 1; j <= y.size(2); j++)
      sum = sum + y.get(i, j);
    ysum.push_back(sum);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i == j)
        Y.set(i, j, ysum[i - 1]);
      else
        Y.set(i, j, y.get(i, j) * x(-1));
  cout << "\nNode Admittance Matrix" << endl;
  Y.print();
  matrix G, B;
  for (int i = 1; i <= Y.size(1); i++)
    for (int j = 1; j <= Y.size(2); j++) {
      G.set(i, j, x(Y.get(i, j).first));
      B.set(i, j, x(Y.get(i, j).second));
    }

  // Calculate Unbalanced Values
  matrix_type Unbalanced_receive = Unbalanced(n, m, P, Q, U, G, B, theta);
  complex_vector dP, dQ, Pi, Qi;
  dP = Unbalanced_receive[0], dQ = Unbalanced_receive[1],
  Pi = Unbalanced_receive[2], Qi = Unbalanced_receive[3];
  cout << "\nUnbalanced Active Power" << endl;
  cout << dP << endl;
  cout << "\nUnbalanced Reactive Power" << endl;
  cout << dQ << endl;

  int cnt = 1;
  for (; cnt <= Tmax; cnt++) {
    cout << "----------------------------------------------------------"
            "---------"
         << endl;
    cout << "Iteration " << cnt << endl;
    matrix J;
    if (mode == 1) {
      J = Jacobi(n, m, U, theta, B, G, Pi, Qi);
      cout << "\nJacobi Matrix" << endl;
      J.print();
      cout << endl;
    }
    complex_vector dU, dtheta;
    matrix_type Correct_receive;
    if (mode == 1)
      Correct_receive = Correct(n, m, U, dP, dQ, J);
    else
      Correct_receive = PQ_LJ(n, m, dP, dQ, U, B);
    dU = Correct_receive[0];
    dtheta = Correct_receive[1];

    cout << "\nVoltage & Phase Angle Offset" << endl;
    cout << "Voltage: " << dU << endl;
    cout << "Phase Angle: " << dtheta << endl;
    // Correct node voltage
    for (int i = 1; i <= U.size(2); i++)
      U.set(1, i, U.get(1, i) + dU[i - 1]);
    for (int i = 1; i <= theta.size(2); i++)
      theta.set(1, i, theta.get(1, i) + dtheta[i - 1]);

    cout << "\nNode Voltage Amplitude" << endl;
    U.print();
    cout << "\nNode Phase Angle(rad)" << endl;
    theta.print();

    Unbalanced_receive = Unbalanced(n, m, P, Q, U, G, B, theta);
    dP = Unbalanced_receive[0], dQ = Unbalanced_receive[1],
    Pi = Unbalanced_receive[2], Qi = Unbalanced_receive[3];
    cout << "\nUnbalanced Active Power" << endl;
    cout << setw(10) << dP << endl;
    cout << "\nUnbalanced Reactive Power" << endl;
    cout << setw(10) << dQ << endl;

    double dP_max = 0, dQ_max = 0;
    for (int i = 0; i < dP.size(); i++)
      dP_max = dP_max > fabs(dP[i].first) ? dP_max : fabs(dP[i].first);
    for (int i = 0; i < dQ.size(); i++)
      dQ_max = dQ_max > fabs(dQ[i].first) ? dQ_max : fabs(dQ[i].first);
    cout << "\nLimit: " << limit << " ,dP_max: " << dP_max
         << " ,dQ_max: " << dQ_max << endl;
    if ((dP_max < limit) && (dQ_max < limit)) {
      cout << "Compute Converged" << endl;
      break; // If current precision meet the requirement, then break
    } else
      cout << "Lack of precision" << endl;
  }

  // Iteration Ended
  fclose(stdout);
  freopen("Newton_PQ_result.dat", "w+", stdout);
  /*
  cout << "------------------------------------------------------------"
          "-------"
       << endl;
  */
  cout << "Chosen Method: "
       << (mode == 1 ? "Newton-Raphson" : "P-Q Decomposition") << endl;
  cout << "\nIteration counts: " << cnt << endl;
  cout << "\nNode Voltage Amplitude" << endl;
  U.print();
  cout << "\nNode Phase Angle(rad)" << endl;
  theta.print();
  cout << "\nActive Power Result" << endl;
  cout << setw(10) << Pi << endl;
  cout << "\nDeactive Power Result" << endl;
  cout << setw(10) << Qi << endl;
  end = clock(); // end time
  cout << "\nCalculation Cost = " << double(end - start) / CLOCKS_PER_SEC << "s"
       << endl;
  fclose(stdout);
  return 0;
}

// End of file

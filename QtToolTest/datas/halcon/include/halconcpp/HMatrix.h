/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 18.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HMATRIX
#define HCPP_HMATRIX

namespace HalconCpp
{

// Represents an instance of a matrix.
class LIntExport HMatrix : public HHandle
{

public:

  // Create an uninitialized instance
  HMatrix():HHandle() {}

  // Copy constructor
  HMatrix(const HMatrix& source) : HHandle(source) {}

  // Copy constructor
  HMatrix(const HHandle& handle);

  // Create HMatrix from handle, taking ownership
  explicit HMatrix(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('matrix')!
  virtual void AssertType(Hphandle handle) const;

public:

  // Deep copy of all data represented by this object instance
  HMatrix Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_matrix: Read a matrix from a file.
  explicit HMatrix(const HString& FileName);

  // read_matrix: Read a matrix from a file.
  explicit HMatrix(const char* FileName);

#ifdef _WIN32
  // read_matrix: Read a matrix from a file.
  explicit HMatrix(const wchar_t* FileName);
#endif

  // create_matrix: Create a matrix.
  explicit HMatrix(Hlong Rows, Hlong Columns, const HTuple& Value);

  // create_matrix: Create a matrix.
  explicit HMatrix(Hlong Rows, Hlong Columns, double Value);


/*****************************************************************************
 * Operator overloads (non-member overloads reside in HOperatorOverloads.h)
 *****************************************************************************/

  // Negate matrix
  HMatrix operator - () const;

  // Cast to HTuple
#if defined(HCPP_LEGACY_HANDLE_API)
  // Up to HALCON 13.0 it used to return all matrix elements, 
  // keep this behavior in place for legacy code
  operator HTuple() const
  {
    return GetFullMatrix();
  }
#else
  // However for consistency with new handle mechanism cast HMatrix
  // should keep the case class behavior and wrap the handle instead.
#endif

  // Access matrix element
  double operator () (Hlong row, Hlong column) const;


/*****************************************************************************
 * Non-generic convenience members
 *****************************************************************************/

  Hlong NumRows() const;
  Hlong NumColumns() const;





  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Deserialize a serialized matrix.
  void DeserializeMatrix(const HSerializedItem& SerializedItemHandle);

  // Serialize a matrix.
  HSerializedItem SerializeMatrix() const;

  // Read a matrix from a file.
  void ReadMatrix(const HString& FileName);

  // Read a matrix from a file.
  void ReadMatrix(const char* FileName);

#ifdef _WIN32
  // Read a matrix from a file.
  void ReadMatrix(const wchar_t* FileName);
#endif

  // Write a matrix to a file.
  void WriteMatrix(const HString& FileFormat, const HString& FileName) const;

  // Write a matrix to a file.
  void WriteMatrix(const char* FileFormat, const char* FileName) const;

#ifdef _WIN32
  // Write a matrix to a file.
  void WriteMatrix(const wchar_t* FileFormat, const wchar_t* FileName) const;
#endif

  // Perform an orthogonal decomposition of a matrix.
  HMatrix OrthogonalDecomposeMatrix(const HString& DecompositionType, const HString& OutputMatricesType, const HString& ComputeOrthogonal, HMatrix* MatrixTriangularID) const;

  // Perform an orthogonal decomposition of a matrix.
  HMatrix OrthogonalDecomposeMatrix(const char* DecompositionType, const char* OutputMatricesType, const char* ComputeOrthogonal, HMatrix* MatrixTriangularID) const;

#ifdef _WIN32
  // Perform an orthogonal decomposition of a matrix.
  HMatrix OrthogonalDecomposeMatrix(const wchar_t* DecompositionType, const wchar_t* OutputMatricesType, const wchar_t* ComputeOrthogonal, HMatrix* MatrixTriangularID) const;
#endif

  // Decompose a matrix.
  HMatrix DecomposeMatrix(const HString& MatrixType, HMatrix* Matrix2ID) const;

  // Decompose a matrix.
  HMatrix DecomposeMatrix(const char* MatrixType, HMatrix* Matrix2ID) const;

#ifdef _WIN32
  // Decompose a matrix.
  HMatrix DecomposeMatrix(const wchar_t* MatrixType, HMatrix* Matrix2ID) const;
#endif

  // Compute the singular value decomposition of a matrix.
  HMatrix SvdMatrix(const HString& SVDType, const HString& ComputeSingularVectors, HMatrix* MatrixSID, HMatrix* MatrixVID) const;

  // Compute the singular value decomposition of a matrix.
  HMatrix SvdMatrix(const char* SVDType, const char* ComputeSingularVectors, HMatrix* MatrixSID, HMatrix* MatrixVID) const;

#ifdef _WIN32
  // Compute the singular value decomposition of a matrix.
  HMatrix SvdMatrix(const wchar_t* SVDType, const wchar_t* ComputeSingularVectors, HMatrix* MatrixSID, HMatrix* MatrixVID) const;
#endif

  // Compute the generalized eigenvalues and optionally the generalized eigenvectors of general matrices.
  void GeneralizedEigenvaluesGeneralMatrix(const HMatrix& MatrixBID, const HString& ComputeEigenvectors, HMatrix* EigenvaluesRealID, HMatrix* EigenvaluesImagID, HMatrix* EigenvectorsRealID, HMatrix* EigenvectorsImagID) const;

  // Compute the generalized eigenvalues and optionally the generalized eigenvectors of general matrices.
  void GeneralizedEigenvaluesGeneralMatrix(const HMatrix& MatrixBID, const char* ComputeEigenvectors, HMatrix* EigenvaluesRealID, HMatrix* EigenvaluesImagID, HMatrix* EigenvectorsRealID, HMatrix* EigenvectorsImagID) const;

#ifdef _WIN32
  // Compute the generalized eigenvalues and optionally the generalized eigenvectors of general matrices.
  void GeneralizedEigenvaluesGeneralMatrix(const HMatrix& MatrixBID, const wchar_t* ComputeEigenvectors, HMatrix* EigenvaluesRealID, HMatrix* EigenvaluesImagID, HMatrix* EigenvectorsRealID, HMatrix* EigenvectorsImagID) const;
#endif

  // Compute the generalized eigenvalues and optionally generalized eigenvectors of symmetric input matrices.
  HMatrix GeneralizedEigenvaluesSymmetricMatrix(const HMatrix& MatrixBID, const HString& ComputeEigenvectors, HMatrix* EigenvectorsID) const;

  // Compute the generalized eigenvalues and optionally generalized eigenvectors of symmetric input matrices.
  HMatrix GeneralizedEigenvaluesSymmetricMatrix(const HMatrix& MatrixBID, const char* ComputeEigenvectors, HMatrix* EigenvectorsID) const;

#ifdef _WIN32
  // Compute the generalized eigenvalues and optionally generalized eigenvectors of symmetric input matrices.
  HMatrix GeneralizedEigenvaluesSymmetricMatrix(const HMatrix& MatrixBID, const wchar_t* ComputeEigenvectors, HMatrix* EigenvectorsID) const;
#endif

  // Compute the eigenvalues and optionally the eigenvectors of a general matrix.
  void EigenvaluesGeneralMatrix(const HString& ComputeEigenvectors, HMatrix* EigenvaluesRealID, HMatrix* EigenvaluesImagID, HMatrix* EigenvectorsRealID, HMatrix* EigenvectorsImagID) const;

  // Compute the eigenvalues and optionally the eigenvectors of a general matrix.
  void EigenvaluesGeneralMatrix(const char* ComputeEigenvectors, HMatrix* EigenvaluesRealID, HMatrix* EigenvaluesImagID, HMatrix* EigenvectorsRealID, HMatrix* EigenvectorsImagID) const;

#ifdef _WIN32
  // Compute the eigenvalues and optionally the eigenvectors of a general matrix.
  void EigenvaluesGeneralMatrix(const wchar_t* ComputeEigenvectors, HMatrix* EigenvaluesRealID, HMatrix* EigenvaluesImagID, HMatrix* EigenvectorsRealID, HMatrix* EigenvectorsImagID) const;
#endif

  // Compute the eigenvalues and optionally eigenvectors of a symmetric matrix.
  HMatrix EigenvaluesSymmetricMatrix(const HString& ComputeEigenvectors, HMatrix* EigenvectorsID) const;

  // Compute the eigenvalues and optionally eigenvectors of a symmetric matrix.
  HMatrix EigenvaluesSymmetricMatrix(const char* ComputeEigenvectors, HMatrix* EigenvectorsID) const;

#ifdef _WIN32
  // Compute the eigenvalues and optionally eigenvectors of a symmetric matrix.
  HMatrix EigenvaluesSymmetricMatrix(const wchar_t* ComputeEigenvectors, HMatrix* EigenvectorsID) const;
#endif

  // Compute the solution of a system of equations.
  HMatrix SolveMatrix(const HString& MatrixLHSType, double Epsilon, const HMatrix& MatrixRHSID) const;

  // Compute the solution of a system of equations.
  HMatrix SolveMatrix(const char* MatrixLHSType, double Epsilon, const HMatrix& MatrixRHSID) const;

#ifdef _WIN32
  // Compute the solution of a system of equations.
  HMatrix SolveMatrix(const wchar_t* MatrixLHSType, double Epsilon, const HMatrix& MatrixRHSID) const;
#endif

  // Compute the determinant of a matrix.
  double DeterminantMatrix(const HString& MatrixType) const;

  // Compute the determinant of a matrix.
  double DeterminantMatrix(const char* MatrixType) const;

#ifdef _WIN32
  // Compute the determinant of a matrix.
  double DeterminantMatrix(const wchar_t* MatrixType) const;
#endif

  // Invert a matrix.
  void InvertMatrixMod(const HString& MatrixType, double Epsilon) const;

  // Invert a matrix.
  void InvertMatrixMod(const char* MatrixType, double Epsilon) const;

#ifdef _WIN32
  // Invert a matrix.
  void InvertMatrixMod(const wchar_t* MatrixType, double Epsilon) const;
#endif

  // Invert a matrix.
  HMatrix InvertMatrix(const HString& MatrixType, double Epsilon) const;

  // Invert a matrix.
  HMatrix InvertMatrix(const char* MatrixType, double Epsilon) const;

#ifdef _WIN32
  // Invert a matrix.
  HMatrix InvertMatrix(const wchar_t* MatrixType, double Epsilon) const;
#endif

  // Transpose a matrix.
  void TransposeMatrixMod() const;

  // Transpose a matrix.
  HMatrix TransposeMatrix() const;

  // Returns the elementwise maximum of a matrix.
  HMatrix MaxMatrix(const HString& MaxType) const;

  // Returns the elementwise maximum of a matrix.
  HMatrix MaxMatrix(const char* MaxType) const;

#ifdef _WIN32
  // Returns the elementwise maximum of a matrix.
  HMatrix MaxMatrix(const wchar_t* MaxType) const;
#endif

  // Returns the elementwise minimum of a matrix.
  HMatrix MinMatrix(const HString& MinType) const;

  // Returns the elementwise minimum of a matrix.
  HMatrix MinMatrix(const char* MinType) const;

#ifdef _WIN32
  // Returns the elementwise minimum of a matrix.
  HMatrix MinMatrix(const wchar_t* MinType) const;
#endif

  // Compute the power functions of a matrix.
  void PowMatrixMod(const HString& MatrixType, const HTuple& Power) const;

  // Compute the power functions of a matrix.
  void PowMatrixMod(const HString& MatrixType, double Power) const;

  // Compute the power functions of a matrix.
  void PowMatrixMod(const char* MatrixType, double Power) const;

#ifdef _WIN32
  // Compute the power functions of a matrix.
  void PowMatrixMod(const wchar_t* MatrixType, double Power) const;
#endif

  // Compute the power functions of a matrix.
  HMatrix PowMatrix(const HString& MatrixType, const HTuple& Power) const;

  // Compute the power functions of a matrix.
  HMatrix PowMatrix(const HString& MatrixType, double Power) const;

  // Compute the power functions of a matrix.
  HMatrix PowMatrix(const char* MatrixType, double Power) const;

#ifdef _WIN32
  // Compute the power functions of a matrix.
  HMatrix PowMatrix(const wchar_t* MatrixType, double Power) const;
#endif

  // Compute the power functions of the elements of a matrix.
  void PowElementMatrixMod(const HMatrix& MatrixExpID) const;

  // Compute the power functions of the elements of a matrix.
  HMatrix PowElementMatrix(const HMatrix& MatrixExpID) const;

  // Compute the power functions of the elements of a matrix.
  void PowScalarElementMatrixMod(const HTuple& Power) const;

  // Compute the power functions of the elements of a matrix.
  void PowScalarElementMatrixMod(double Power) const;

  // Compute the power functions of the elements of a matrix.
  HMatrix PowScalarElementMatrix(const HTuple& Power) const;

  // Compute the power functions of the elements of a matrix.
  HMatrix PowScalarElementMatrix(double Power) const;

  // Compute the square root values of the elements of a matrix.
  void SqrtMatrixMod() const;

  // Compute the square root values of the elements of a matrix.
  HMatrix SqrtMatrix() const;

  // Compute the absolute values of the elements of a matrix.
  void AbsMatrixMod() const;

  // Compute the absolute values of the elements of a matrix.
  HMatrix AbsMatrix() const;

  // Norm of a matrix.
  double NormMatrix(const HString& NormType) const;

  // Norm of a matrix.
  double NormMatrix(const char* NormType) const;

#ifdef _WIN32
  // Norm of a matrix.
  double NormMatrix(const wchar_t* NormType) const;
#endif

  // Returns the elementwise mean of a matrix.
  HMatrix MeanMatrix(const HString& MeanType) const;

  // Returns the elementwise mean of a matrix.
  HMatrix MeanMatrix(const char* MeanType) const;

#ifdef _WIN32
  // Returns the elementwise mean of a matrix.
  HMatrix MeanMatrix(const wchar_t* MeanType) const;
#endif

  // Returns the elementwise sum of a matrix.
  HMatrix SumMatrix(const HString& SumType) const;

  // Returns the elementwise sum of a matrix.
  HMatrix SumMatrix(const char* SumType) const;

#ifdef _WIN32
  // Returns the elementwise sum of a matrix.
  HMatrix SumMatrix(const wchar_t* SumType) const;
#endif

  // Divide matrices element-by-element.
  void DivElementMatrixMod(const HMatrix& MatrixBID) const;

  // Divide matrices element-by-element.
  HMatrix DivElementMatrix(const HMatrix& MatrixBID) const;

  // Multiply matrices element-by-element.
  void MultElementMatrixMod(const HMatrix& MatrixBID) const;

  // Multiply matrices element-by-element.
  HMatrix MultElementMatrix(const HMatrix& MatrixBID) const;

  // Scale a matrix.
  void ScaleMatrixMod(const HTuple& Factor) const;

  // Scale a matrix.
  void ScaleMatrixMod(double Factor) const;

  // Scale a matrix.
  HMatrix ScaleMatrix(const HTuple& Factor) const;

  // Scale a matrix.
  HMatrix ScaleMatrix(double Factor) const;

  // Subtract two matrices.
  void SubMatrixMod(const HMatrix& MatrixBID) const;

  // Subtract two matrices.
  HMatrix SubMatrix(const HMatrix& MatrixBID) const;

  // Add two matrices.
  void AddMatrixMod(const HMatrix& MatrixBID) const;

  // Add two matrices.
  HMatrix AddMatrix(const HMatrix& MatrixBID) const;

  // Multiply two matrices.
  void MultMatrixMod(const HMatrix& MatrixBID, const HString& MultType) const;

  // Multiply two matrices.
  void MultMatrixMod(const HMatrix& MatrixBID, const char* MultType) const;

#ifdef _WIN32
  // Multiply two matrices.
  void MultMatrixMod(const HMatrix& MatrixBID, const wchar_t* MultType) const;
#endif

  // Multiply two matrices.
  HMatrix MultMatrix(const HMatrix& MatrixBID, const HString& MultType) const;

  // Multiply two matrices.
  HMatrix MultMatrix(const HMatrix& MatrixBID, const char* MultType) const;

#ifdef _WIN32
  // Multiply two matrices.
  HMatrix MultMatrix(const HMatrix& MatrixBID, const wchar_t* MultType) const;
#endif

  // Get the size of a matrix.
  void GetSizeMatrix(Hlong* Rows, Hlong* Columns) const;

  // Repeat a matrix.
  HMatrix RepeatMatrix(Hlong Rows, Hlong Columns) const;

  // Copy a matrix.
  HMatrix CopyMatrix() const;

  // Set the diagonal elements of a matrix.
  void SetDiagonalMatrix(const HMatrix& VectorID, Hlong Diagonal) const;

  // Get the diagonal elements of a matrix.
  HMatrix GetDiagonalMatrix(Hlong Diagonal) const;

  // Set a sub-matrix of a matrix.
  void SetSubMatrix(const HMatrix& MatrixSubID, Hlong Row, Hlong Column) const;

  // Get a sub-matrix of a matrix.
  HMatrix GetSubMatrix(Hlong Row, Hlong Column, Hlong RowsSub, Hlong ColumnsSub) const;

  // Set all values of a matrix.
  void SetFullMatrix(const HTuple& Values) const;

  // Set all values of a matrix.
  void SetFullMatrix(double Values) const;

  // Return all values of a matrix.
  HTuple GetFullMatrix() const;

  // Set one or more elements of a matrix.
  void SetValueMatrix(const HTuple& Row, const HTuple& Column, const HTuple& Value) const;

  // Set one or more elements of a matrix.
  void SetValueMatrix(Hlong Row, Hlong Column, double Value) const;

  // Return one ore more elements of a matrix.
  HTuple GetValueMatrix(const HTuple& Row, const HTuple& Column) const;

  // Return one ore more elements of a matrix.
  double GetValueMatrix(Hlong Row, Hlong Column) const;

  // Free the memory of a matrix.
  static void ClearMatrix(const HMatrixArray& MatrixID);

  // Free the memory of a matrix.
  void ClearMatrix() const;

  // Create a matrix.
  void CreateMatrix(Hlong Rows, Hlong Columns, const HTuple& Value);

  // Create a matrix.
  void CreateMatrix(Hlong Rows, Hlong Columns, double Value);

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HMatrix> HMatrixArrayRef;
typedef HSmartPtr< HMatrixArrayRef > HMatrixArrayPtr;


// Represents multiple tool instances
class LIntExport HMatrixArray : public HHandleBaseArray
{

public:

  // Create empty array
  HMatrixArray();

  // Create array from native array of tool instances
  HMatrixArray(HMatrix* classes, Hlong length);

  // Copy constructor
  HMatrixArray(const HMatrixArray &tool_array);

  // Destructor
  virtual ~HMatrixArray();

  // Assignment operator
  HMatrixArray &operator=(const HMatrixArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HMatrix* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HMatrixArrayPtr *mArrayPtr;
};

}

#endif

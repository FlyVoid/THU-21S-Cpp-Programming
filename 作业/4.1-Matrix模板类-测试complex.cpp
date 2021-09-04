#include<iostream>
#include<cstdlib>
#include<cmath>
#include <cstdarg>
using namespace std;



using namespace std;


class complex{
public:
    complex(double real = 0.0, double imag = 0.0): m_real(real), m_imag(imag){ };
public:
    friend complex operator+(const complex & A, const complex & B);
    friend complex operator-(const complex & A, const complex & B);
    friend complex operator*(const complex & A, const complex & B);
    friend istream & operator>>(istream & in, complex & A);
    friend ostream & operator<<(ostream & out, complex & A);
private:
    double m_real;  //实部
    double m_imag;  //虚部
};
//重载加法运算符
complex operator+(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real + B.m_real;
    C.m_imag = A.m_imag + B.m_imag;
    return C;
}
//重载减法运算符
complex operator-(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real - B.m_real;
    C.m_imag = A.m_imag - B.m_imag;
    return C;
}
//重载乘法运算符
complex operator*(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real * B.m_real - A.m_imag * B.m_imag;
    C.m_imag = A.m_imag * B.m_real + A.m_real * B.m_imag;
    return C;
}

//重载输入运算符
istream & operator>>(istream & in, complex & A){
    in >> A.m_real >> A.m_imag;
    return in;
}


//重载输出运算符
ostream & operator<<(ostream & out, complex & A){
    out << A.m_real;
    if (A.m_imag > 0)
		out<<" + "<< A.m_imag <<" i ";
	else if(A.m_imag<0)
		out<< A.m_imag <<" i ";
	else {}
    return out;
}




template<typename T>
class Matrix{
private: 
	int row;  //矩阵的行
	int col;  //矩阵的列
	T **a;  //保存二维数组的元素
public:
	Matrix();                 //默认构造函数
	Matrix(int m, int n);     //构造m行n列矩阵，并元素值设为0。 
	Matrix(const Matrix & M); //拷贝构造函数
	~Matrix();                //析构函数 
 
	Matrix operator+(const Matrix &M) const;   //重载operator+
	Matrix operator-(const Matrix &M) const;   //重载operator-
	Matrix operator*(const Matrix &M) const;   //重载operator*
	Matrix & operator=(const Matrix & M);      //重载operator=
	T * operator [](const int &i);          //重载operator[]
	void set(T& t1, ...);                               //输入矩阵
	void display();                            //输出矩阵
};


//构造函数
template<typename T> 
Matrix<T>::Matrix(int m, int n){
	this->row = m;
	this->col = n;
	a=new T* [row];  
	for (int i = 0; i < row; i++)
		a[i]= new T[col];   
	
	for (int i = 0; i < row; i++){            //矩阵初始化为0   
		for(int j = 0; j <col; j++)
			a[i][j]=0;
	}
			
}

//拷贝构造函数
template<typename T>
Matrix<T>::Matrix(const Matrix & M){
	for(int i = 0; i < row; i++){  //删除 
		delete[] a[i];	
	}
	delete []a;
	this->row = M.row;
	this->col = M.col;
	a = new T*[row];             //申请内存 
	for (int i = 0; i < row; i++)
		a[i] = new T[col];
	a = M.a;                      //复制成员 
	this->row = M.row;
	this->col = M.col;	 
}

//析构函数
template<typename T>
Matrix<T>::~Matrix(){
	for(int i = 0; i < row; i++){
		delete[] a[i];	
	}
	delete []a;
} 


//重载[]
template<typename T>
T * Matrix<T>::operator [](const int &i){          
	return a[i];
}


 
//重载=
template<typename T>
Matrix<T> & Matrix<T>::operator=(const Matrix & M){
	if( this != &M){                  //判断是否是给自己赋值
		for(int i = 0; i < row; i++){  //清空 
		delete[] a[i];	
		}
		delete []a;
		a = new T*[row];             //申请
		for (int i = 0; i < row; i++)
			a[i] = new T[col];
		a = M.a;                      //复制成员 
		this->row = M.row;
		this->col = M.col;
	}
	return *this; 
}




//重载+
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &M) const{
	Matrix M1(this->row, this->col);
	if (row != M.row || col != M.col)     //判断两矩阵是否符合相加条件
		throw row;
	else{
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++)
				M1.a[i][j]= a[i][j] + M.a[i][j];
		}
	}
	return M1;	
}

//重载-
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &M) const{
	Matrix M2(this->row, this->col);
	if (row != M.row || col != M.col)     //判断两矩阵是否符合相加条件
		throw row;
	else{
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++)
				M2.a[i][j]= a[i][j] - M.a[i][j];
		}
	}
	return M2;	
} 

//重载*
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &M) const{
	Matrix M3(this->row, M.col);
	if (this->col != M.row){     //判断两矩阵是否符合相乘条件
		throw row;
	} 
	else{
		for (int i = 0; i < M3.row; i++){
		     for (int j = 0; j < M3.col; j++){
		         for (int n = 0; n < M.row; n++){
		             M3.a[i][j] = M3.a[i][j]+ a[i][n] * M.a[n][j];					  
		         }
		     }
		}	
	}
	return M3;	
}

 

//输出矩阵
template<typename T>
void Matrix<T>::display(){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
		 cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//输入矩阵元素
template<typename T>
void Matrix<T>::set(T& t1, ...){
	va_list arguments;
	va_start ( arguments, t1 ); 
	for (int i = 0 ; i < row; i++){
		for (int j = 0; j < col; j++){
			a[i][j]= va_arg ( arguments, T );
		}        
	}
	va_end ( arguments );       
}



int main(){
	complex c0(0,0) ;
	complex c1(1,1) ;
	complex c2(2,2) ;
	complex c3(3,3) ;
	complex c4(4,4) ;
	complex c5(5,5) ;
	complex c6(6,6) ;
	complex c11(11,11) ;
	complex c22(22,22) ;
	complex c33(33,33) ;
	complex c44(44,44) ;
	complex c55(55,55) ;
	complex c66(66,66) ;
	cout<<"设置复数矩阵1的行数和列数：2行 3列"<<endl;
	Matrix<complex> m1(2,3);
	m1.set(c0,c1,c2,c3,c4,c5,c6); 
	cout<<"矩阵1为；"<<endl;
	m1.display();
	
	
	cout<<"设置矩阵2的行数和列数：2行 3列"<<endl;
	Matrix<complex> m2(2,3);
	m2.set(c0,c11,c22,c33,c44,c55,c66); 
	cout<<"矩阵2为；"<<endl;
	m2.display();
	
	cout<<"设置矩阵3的行数和列数：3行 2列"<<endl;
	Matrix<complex> m3(3,2);
	m3.set(c0,c1,c2,c3,c4,c5,c6); 
	cout<<"矩阵3为；"<<endl;
	m3.display();
	 
	cout<<"求矩阵1的第2行第2列元素"<<endl;     //测试重载[] 
	cout<<"该元素为："<<m1[1][1]<<endl;
	cout<<endl;
	
	
	try{
		Matrix<complex> m3=m1+m2;                          //测试重载+
		cout<<"矩阵1+矩阵2="<<endl;             
		m3.display(); 
	}
	catch(const int row){
		cout<<"【警告】矩阵加法需行列相等"<<endl;
	} 
	
	try {
		Matrix<complex> m4=m1-m2;
		cout<<"矩阵1-矩阵2="<<endl;        //测试重载-
		m4.display(); 
	} 
	catch(const int row){
		cout<<"【警告】矩阵减法需行列相等"<<endl;
	}                         
	
	try{
	Matrix<complex> m5=m1*m3;                          //测试重载*
	cout<<"矩阵1*矩阵3="<<endl;
	m5.display();	
	} 
	catch(const int row){
		cout<<"【警告】无法进行矩阵乘法"<<endl;
	}  

	
	cout<<"将矩阵2赋值给矩阵1"<<endl;         //测试重载=
	m1=m2;                          
	cout<<"现在矩阵1="<<endl;
	m1.display();	
		
	return 0;
} 



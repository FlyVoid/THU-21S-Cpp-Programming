/*

完善题目1.3中的Matrix类：
利用上述矩阵模板类，编写测试程序，进行复数矩阵运算。
*/ 


#include<iostream>
#include<cstdlib>
using namespace std;

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
	void set();                                //输入矩阵
	void display();                            //输出矩阵
};

//重载operator[]
template<typename T>
T * Matrix<T>::operator [](const int &i){          
	return a[i];
}

//构造函数
template<typename T> 
Matrix<T>::Matrix(int m, int n){
	this->row = m;
	this->col = n;
	a=new int* [row];  
	for (int i = 0; i < row; i++)
		a[i]= new int[col];   
	
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
	a = new int*[row];             //申请内存 
	for (int i = 0; i < row; i++)
		a[i] = new int[col];
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

 
//重载=
template<typename T>
Matrix<T> & Matrix<T>::operator=(const Matrix & M){
	if( this != &M){                  //判断是否是给自己赋值
		for(int i = 0; i < row; i++){  //清空 
		delete[] a[i];	
		}
		delete []a;
		a = new int*[row];             //申请
		for (int i = 0; i < row; i++)
			a[i] = new int[col];
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
		             M3.a[i][j] += a[i][n] * M.a[n][j];					  
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
void Matrix<T>::set(){
	for (int i = 0 ; i < row; i++){
		for (int j = 0; j < col; j++){
			cin >> a[i][j];
		}        
	}      
}

int main(){
	int row1,col1;
	cout<<"请设置矩阵1的行数和列数："<<endl;
	cin>>row1;
	cin>>col1; 
	Matrix<int> m1(row1,col1);
	cout<<"请一行行的从左至右输入矩阵1的元素："<<endl;
	m1.set(); 
	cout<<"矩阵1为；"<<endl;
	m1.display();
	
	int row2,col2;
	cout<<"请设置矩阵2的行数和列数："<<endl;
	cin>>row2;
	cin>>col2; 
	Matrix<int> m2(row2,col2);
	cout<<"请一行行的从左至右输入矩阵2的元素："<<endl;
	m2.set(); 
	cout<<"矩阵2为；"<<endl;
	m2.display();
	
	int i,j; 
	cout<<"求矩阵1的第2行第2列元素"<<endl;     //测试重载[] 
	cout<<"该元素为："<<m1[1][1]<<endl;
	
	try{
		Matrix<int> m3=m1+m2;                          //测试重载+
		cout<<"矩阵1+矩阵2="<<endl;             
		m3.display(); 
	}
	catch(const int row){
		cout<<"【警告】矩阵加法需行列相等"<<endl;
	} 
	
	try {
		Matrix<int> m4=m1-m2;
		cout<<"矩阵1-矩阵2="<<endl;        //测试重载-
		m4.display(); 
	} 
	catch(const int row){
		cout<<"【警告】矩阵减法需行列相等"<<endl;
	}                         
	
	try{
	Matrix<int> m5=m1*m2;                          //测试重载*
	cout<<"矩阵1*矩阵2="<<endl;
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

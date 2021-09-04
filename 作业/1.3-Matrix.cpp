#include<iostream>
using namespace std;

class Matrix{
private:
	int m; //m行 
	int n; //n列 
	int **array; //储存矩阵元素 
public: 
	 Matrix(){}
     Matrix(int m, int n);               //初始化矩阵,元素值设为0
     Matrix(const Matrix &is);           //拷贝构造函数 
	 void set();                         //输入矩阵元素
	 void show();                        //输出矩阵元素
     int get(int i, int j);              //获取元素M[i, j]的值
	 void set(int i, int j, int val);    //修改元素M[i, j]的值为val
	 Matrix add(const Matrix & N);       //矩阵加法
	 Matrix sub(const Matrix & N);       //矩阵减法
	 Matrix mul(const Matrix & N);       //矩阵乘法
 };

//初始化矩阵
Matrix::Matrix(int m, int n){
    this->m=m;
    this->n=n;
	if (m < 0)
		cout << "错误，矩阵列数不能为负数" << endl;
	else if (n < 0)
		cout << "错误，矩阵行数不能为负数" << endl;
	else{	
	    array = new int*[m];          //动态申请二维数组 m行 n列 
	    for(int i=0;i<m;i++){
	        array[i] = new int[n];
	    }
	    for(int i=0;i<m;i++){          //给数组赋值为0 
	        for(int j=0;j<n;j++)
	        {
	            array[i][j] = 0; 
	        }
	    }
	}
} 
 
//拷贝构造函数
Matrix::Matrix(const Matrix & is){
	m = is.m;
	n = is.n;
	array = new int*[m];
	for (int i = 0; i < m; i++){
		array[i] = new int[n];
 	}
 	array = is.array;
}

//输入矩阵元素
void Matrix::set(){
	int array[m][n];
	int *p = new int[10];
	cout<<"一行行的输入矩阵："<< endl;
	for (int i = 0 ; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> array[i][j];
		}        
	}      
}

//输出矩阵
void Matrix::show(){
     for (int i = 0; i < m; i++){
         for (int j = 0; j < n; j++){
             cout << array[i][j] << " ";
         }
         cout << endl;
     }
     cout << endl;
 } 
 
//获取元素M[i, j] 
int Matrix::get(int i, int j) {   
	return array[i][j];   
}

//修改元素M[i, j]的值为val
void Matrix::set(int i, int j, int val){
	array[i][j]=val;
}   

//矩阵加法
Matrix Matrix::add(const Matrix & N)
{
	Matrix Madd(this->m, N.n);
	if (this->m != N.m || this->n != N.n){        
	 cout << "两矩阵无法相加" ;
	}
	else{	
		for (int i = 0; i < Madd.m; i++){
			for (int j = 0 ; j < Madd.n; j++){
			 Madd.array[i][j] = this->array[i][j] + N.array[i][j];
			}
	    }
    }
    return Madd;
}

//矩阵减法 
Matrix Matrix::sub(const Matrix & N)
{
	Matrix Msub(this->m, N.n);
	if (this->m != N.m || this->n != N.n){        
	 cout << "两矩阵无法相减" ;
	}
	else{	
		for (int i = 0; i < Msub.m; i++){
			for (int j = 0 ; j < Msub.n; j++){
			 Msub.array[i][j] = this->array[i][j] - N.array[i][j];
			}
	    }
    }
    return Msub;
}

//矩阵乘法 
Matrix Matrix::mul(const Matrix & N)
{
	 Matrix Mmul(this->m, N.n);
	 if (this->m != N.n){        
	     cout << "两矩阵无法相乘"<<endl;
	 }
	 else{
	     for (int i = 0; i < Mmul.m; i++){
	         for (int j = 0 ; j < Mmul.n; j++){
	             Mmul.array[i][j] = 0 ;
	             for (int k = 0; k < N.m; k++){
	                 Mmul.array[i][j] += this->array[i][k] * N.array[k][j];
	             }
	         }
	     }
	 }
	 return Mmul;
}





 

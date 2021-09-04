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
    double m_real;  //ʵ��
    double m_imag;  //�鲿
};
//���ؼӷ������
complex operator+(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real + B.m_real;
    C.m_imag = A.m_imag + B.m_imag;
    return C;
}
//���ؼ��������
complex operator-(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real - B.m_real;
    C.m_imag = A.m_imag - B.m_imag;
    return C;
}
//���س˷������
complex operator*(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real * B.m_real - A.m_imag * B.m_imag;
    C.m_imag = A.m_imag * B.m_real + A.m_real * B.m_imag;
    return C;
}

//�������������
istream & operator>>(istream & in, complex & A){
    in >> A.m_real >> A.m_imag;
    return in;
}


//������������
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
	int row;  //�������
	int col;  //�������
	T **a;  //�����ά�����Ԫ��
public:
	Matrix();                 //Ĭ�Ϲ��캯��
	Matrix(int m, int n);     //����m��n�о��󣬲�Ԫ��ֵ��Ϊ0�� 
	Matrix(const Matrix & M); //�������캯��
	~Matrix();                //�������� 
 
	Matrix operator+(const Matrix &M) const;   //����operator+
	Matrix operator-(const Matrix &M) const;   //����operator-
	Matrix operator*(const Matrix &M) const;   //����operator*
	Matrix & operator=(const Matrix & M);      //����operator=
	T * operator [](const int &i);          //����operator[]
	void set(T& t1, ...);                               //�������
	void display();                            //�������
};


//���캯��
template<typename T> 
Matrix<T>::Matrix(int m, int n){
	this->row = m;
	this->col = n;
	a=new T* [row];  
	for (int i = 0; i < row; i++)
		a[i]= new T[col];   
	
	for (int i = 0; i < row; i++){            //�����ʼ��Ϊ0   
		for(int j = 0; j <col; j++)
			a[i][j]=0;
	}
			
}

//�������캯��
template<typename T>
Matrix<T>::Matrix(const Matrix & M){
	for(int i = 0; i < row; i++){  //ɾ�� 
		delete[] a[i];	
	}
	delete []a;
	this->row = M.row;
	this->col = M.col;
	a = new T*[row];             //�����ڴ� 
	for (int i = 0; i < row; i++)
		a[i] = new T[col];
	a = M.a;                      //���Ƴ�Ա 
	this->row = M.row;
	this->col = M.col;	 
}

//��������
template<typename T>
Matrix<T>::~Matrix(){
	for(int i = 0; i < row; i++){
		delete[] a[i];	
	}
	delete []a;
} 


//����[]
template<typename T>
T * Matrix<T>::operator [](const int &i){          
	return a[i];
}


 
//����=
template<typename T>
Matrix<T> & Matrix<T>::operator=(const Matrix & M){
	if( this != &M){                  //�ж��Ƿ��Ǹ��Լ���ֵ
		for(int i = 0; i < row; i++){  //��� 
		delete[] a[i];	
		}
		delete []a;
		a = new T*[row];             //����
		for (int i = 0; i < row; i++)
			a[i] = new T[col];
		a = M.a;                      //���Ƴ�Ա 
		this->row = M.row;
		this->col = M.col;
	}
	return *this; 
}




//����+
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &M) const{
	Matrix M1(this->row, this->col);
	if (row != M.row || col != M.col)     //�ж��������Ƿ�����������
		throw row;
	else{
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++)
				M1.a[i][j]= a[i][j] + M.a[i][j];
		}
	}
	return M1;	
}

//����-
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &M) const{
	Matrix M2(this->row, this->col);
	if (row != M.row || col != M.col)     //�ж��������Ƿ�����������
		throw row;
	else{
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++)
				M2.a[i][j]= a[i][j] - M.a[i][j];
		}
	}
	return M2;	
} 

//����*
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &M) const{
	Matrix M3(this->row, M.col);
	if (this->col != M.row){     //�ж��������Ƿ�����������
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

 

//�������
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

//�������Ԫ��
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
	cout<<"���ø�������1��������������2�� 3��"<<endl;
	Matrix<complex> m1(2,3);
	m1.set(c0,c1,c2,c3,c4,c5,c6); 
	cout<<"����1Ϊ��"<<endl;
	m1.display();
	
	
	cout<<"���þ���2��������������2�� 3��"<<endl;
	Matrix<complex> m2(2,3);
	m2.set(c0,c11,c22,c33,c44,c55,c66); 
	cout<<"����2Ϊ��"<<endl;
	m2.display();
	
	cout<<"���þ���3��������������3�� 2��"<<endl;
	Matrix<complex> m3(3,2);
	m3.set(c0,c1,c2,c3,c4,c5,c6); 
	cout<<"����3Ϊ��"<<endl;
	m3.display();
	 
	cout<<"�����1�ĵ�2�е�2��Ԫ��"<<endl;     //��������[] 
	cout<<"��Ԫ��Ϊ��"<<m1[1][1]<<endl;
	cout<<endl;
	
	
	try{
		Matrix<complex> m3=m1+m2;                          //��������+
		cout<<"����1+����2="<<endl;             
		m3.display(); 
	}
	catch(const int row){
		cout<<"�����桿����ӷ����������"<<endl;
	} 
	
	try {
		Matrix<complex> m4=m1-m2;
		cout<<"����1-����2="<<endl;        //��������-
		m4.display(); 
	} 
	catch(const int row){
		cout<<"�����桿����������������"<<endl;
	}                         
	
	try{
	Matrix<complex> m5=m1*m3;                          //��������*
	cout<<"����1*����3="<<endl;
	m5.display();	
	} 
	catch(const int row){
		cout<<"�����桿�޷����о���˷�"<<endl;
	}  

	
	cout<<"������2��ֵ������1"<<endl;         //��������=
	m1=m2;                          
	cout<<"���ھ���1="<<endl;
	m1.display();	
		
	return 0;
} 



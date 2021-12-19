/*

������Ŀ1.3�е�Matrix�ࣺ
������������ģ���࣬��д���Գ��򣬽��и����������㡣
*/ 


#include<iostream>
#include<cstdlib>
using namespace std;

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
	void set();                                //�������
	void display();                            //�������
};

//����operator[]
template<typename T>
T * Matrix<T>::operator [](const int &i){          
	return a[i];
}

//���캯��
template<typename T> 
Matrix<T>::Matrix(int m, int n){
	this->row = m;
	this->col = n;
	a=new int* [row];  
	for (int i = 0; i < row; i++)
		a[i]= new int[col];   
	
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
	a = new int*[row];             //�����ڴ� 
	for (int i = 0; i < row; i++)
		a[i] = new int[col];
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

 
//����=
template<typename T>
Matrix<T> & Matrix<T>::operator=(const Matrix & M){
	if( this != &M){                  //�ж��Ƿ��Ǹ��Լ���ֵ
		for(int i = 0; i < row; i++){  //��� 
		delete[] a[i];	
		}
		delete []a;
		a = new int*[row];             //����
		for (int i = 0; i < row; i++)
			a[i] = new int[col];
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
		             M3.a[i][j] += a[i][n] * M.a[n][j];					  
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
void Matrix<T>::set(){
	for (int i = 0 ; i < row; i++){
		for (int j = 0; j < col; j++){
			cin >> a[i][j];
		}        
	}      
}

int main(){
	int row1,col1;
	cout<<"�����þ���1��������������"<<endl;
	cin>>row1;
	cin>>col1; 
	Matrix<int> m1(row1,col1);
	cout<<"��һ���еĴ��������������1��Ԫ�أ�"<<endl;
	m1.set(); 
	cout<<"����1Ϊ��"<<endl;
	m1.display();
	
	int row2,col2;
	cout<<"�����þ���2��������������"<<endl;
	cin>>row2;
	cin>>col2; 
	Matrix<int> m2(row2,col2);
	cout<<"��һ���еĴ��������������2��Ԫ�أ�"<<endl;
	m2.set(); 
	cout<<"����2Ϊ��"<<endl;
	m2.display();
	
	int i,j; 
	cout<<"�����1�ĵ�2�е�2��Ԫ��"<<endl;     //��������[] 
	cout<<"��Ԫ��Ϊ��"<<m1[1][1]<<endl;
	
	try{
		Matrix<int> m3=m1+m2;                          //��������+
		cout<<"����1+����2="<<endl;             
		m3.display(); 
	}
	catch(const int row){
		cout<<"�����桿����ӷ����������"<<endl;
	} 
	
	try {
		Matrix<int> m4=m1-m2;
		cout<<"����1-����2="<<endl;        //��������-
		m4.display(); 
	} 
	catch(const int row){
		cout<<"�����桿����������������"<<endl;
	}                         
	
	try{
	Matrix<int> m5=m1*m2;                          //��������*
	cout<<"����1*����2="<<endl;
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

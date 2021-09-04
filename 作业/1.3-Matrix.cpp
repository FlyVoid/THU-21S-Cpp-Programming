#include<iostream>
using namespace std;

class Matrix{
private:
	int m; //m�� 
	int n; //n�� 
	int **array; //�������Ԫ�� 
public: 
	 Matrix(){}
     Matrix(int m, int n);               //��ʼ������,Ԫ��ֵ��Ϊ0
     Matrix(const Matrix &is);           //�������캯�� 
	 void set();                         //�������Ԫ��
	 void show();                        //�������Ԫ��
     int get(int i, int j);              //��ȡԪ��M[i, j]��ֵ
	 void set(int i, int j, int val);    //�޸�Ԫ��M[i, j]��ֵΪval
	 Matrix add(const Matrix & N);       //����ӷ�
	 Matrix sub(const Matrix & N);       //�������
	 Matrix mul(const Matrix & N);       //����˷�
 };

//��ʼ������
Matrix::Matrix(int m, int n){
    this->m=m;
    this->n=n;
	if (m < 0)
		cout << "���󣬾�����������Ϊ����" << endl;
	else if (n < 0)
		cout << "���󣬾�����������Ϊ����" << endl;
	else{	
	    array = new int*[m];          //��̬�����ά���� m�� n�� 
	    for(int i=0;i<m;i++){
	        array[i] = new int[n];
	    }
	    for(int i=0;i<m;i++){          //�����鸳ֵΪ0 
	        for(int j=0;j<n;j++)
	        {
	            array[i][j] = 0; 
	        }
	    }
	}
} 
 
//�������캯��
Matrix::Matrix(const Matrix & is){
	m = is.m;
	n = is.n;
	array = new int*[m];
	for (int i = 0; i < m; i++){
		array[i] = new int[n];
 	}
 	array = is.array;
}

//�������Ԫ��
void Matrix::set(){
	int array[m][n];
	int *p = new int[10];
	cout<<"һ���е��������"<< endl;
	for (int i = 0 ; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> array[i][j];
		}        
	}      
}

//�������
void Matrix::show(){
     for (int i = 0; i < m; i++){
         for (int j = 0; j < n; j++){
             cout << array[i][j] << " ";
         }
         cout << endl;
     }
     cout << endl;
 } 
 
//��ȡԪ��M[i, j] 
int Matrix::get(int i, int j) {   
	return array[i][j];   
}

//�޸�Ԫ��M[i, j]��ֵΪval
void Matrix::set(int i, int j, int val){
	array[i][j]=val;
}   

//����ӷ�
Matrix Matrix::add(const Matrix & N)
{
	Matrix Madd(this->m, N.n);
	if (this->m != N.m || this->n != N.n){        
	 cout << "�������޷����" ;
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

//������� 
Matrix Matrix::sub(const Matrix & N)
{
	Matrix Msub(this->m, N.n);
	if (this->m != N.m || this->n != N.n){        
	 cout << "�������޷����" ;
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

//����˷� 
Matrix Matrix::mul(const Matrix & N)
{
	 Matrix Mmul(this->m, N.n);
	 if (this->m != N.n){        
	     cout << "�������޷����"<<endl;
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





 

/* ������ 
Ȩֵ 
1.5    ����Ա1��   = ���� + ���� + ����                     
1      ׷����3��   = 2 * ���� + 0.5 * ���� + 0.5 * ����     
0.5    ������2��   = 0.5 * ���� + 2 * ���� + 0.5 * ����    
2      ������1��   = 0.5 * ���� + 0.5 * ���� + 2 * ����      
*/ 

#include<iostream>
#include<cstring>
using namespace std;

class Quidditch{
	protected:
		string name; 
		int hit;     //����
		int endu;    //���� 
		int agile;   //����
		int role[420];
		string finalrole;				
	public:
		Quidditch(){}
		Quidditch(int a,int b,int c,string d): hit(a),endu(b),agile(c), name(d){}
		~Quidditch(){}

		string getname() { return name;	}
		string setname(string _name){ name=_name;}
		
		void setrole(int k,int _role){ role[k]=_role;}
		int getrole(int k){ return role[k];}
		
				
		string getfinalrole(int k);   //������ս�ɫ 
		int getpot(int k);  	       //�������Ч��	
}; 



int Quidditch::getpot(int k){
	if (role[k]==15)
		return (10* hit + 10*endu + 10 * agile);
	else if(role[k]==10)
		return (20 * hit + 5 * endu + 5 * agile);
	else if( role[k]==5 )
		return (5 * hit + 20 * endu + 5 * agile);	 
	else if( role[k]==20 )
		return (5 * hit + 5 * endu + 20 * agile);	
} 

string Quidditch::getfinalrole(int k){
	if (role[k]==15)
		return "����Ա";
	else if(role[k]==10)
		return "׷����";
	else if(role[k]==5)
		return "������";	 
	else if(role[k]==20)
		return "������"; 	
}




 


//�Ƿ񽻻�
bool isSwap(int array[],int len,int index){
        for(int i=index+1;i<len;++i)
            if(array[index]==array[i])
                return false;
        return true;
}


 
//ʵ����������
void swap(int* o,int i,int j){
    int tmp = o[i];
    o[i] = o[j];
    o[j] = tmp;
}


int pot[420];      //������Ч������������7*6*C(5,2)=420��
int k=0;           //��¼���������±꣬pot[k]��Ϊ��Ч�� 
Quidditch q0;
Quidditch q1;
Quidditch q2; 
Quidditch q3;
Quidditch q4;
Quidditch q5;
Quidditch q6;

//�ݹ�ʵ�����ظ�Ԫ�ص�����ȫ����
void permutation(int a[],int len,int index,Quidditch &q0,Quidditch &q1,Quidditch &q2,Quidditch &q3,Quidditch &q4,Quidditch &q5,Quidditch &q6){

    if(index==len){  //ȫ���н���
    	q0.setrole(k,a[0]);
        q1.setrole(k,a[1]);
        q2.setrole(k,a[2]);
        q3.setrole(k,a[3]);
        q4.setrole(k,a[4]);
        q5.setrole(k,a[5]);
        q6.setrole(k,a[6]);
        pot[k]=q0.getpot(k)*a[0]+q1.getpot(k)*a[1]+q2.getpot(k)*a[2]+q3.getpot(k)*a[3]+q4.getpot(k)*a[4]+q5.getpot(k)*a[5]+q6.getpot(k)*a[6];     
        k++; 
    }
    else
        for(int i=index;i<len;++i){
            if(isSwap(a,len,i)){ //�����ж��Ƿ񽻻�            
                swap(a,index,i);  //����i��Ԫ�ؽ�������ǰindex�±괦              
                permutation(a,len,index+1,q0,q1,q2,q3,q4,q5,q6); //�Եݹ�ķ�ʽ��ʣ��Ԫ�ؽ���ȫ����
                swap(a,index,i); //����i��Ԫ�ؽ�����ԭ��
            }
        }
}

int main(){
	cout<<"������Ч��MAX�滮"<<endl; 
	cout<<"����������7����Ա�����������С������� ����:"<<endl;	
	int q01,q02,q03;
	int q11,q12,q13;
	int q21,q22,q23;
	int q31,q32,q33;
	int q41,q42,q43;
	int q51,q52,q53;
	int q61,q62,q63;
	string q0s,q1s,q2s,q3s,q4s,q5s,q6s;
	cin>>q0s>>q01>>q02>>q03;
	cin>>q1s>>q11>>q12>>q13;
	cin>>q2s>>q21>>q22>>q23;
	cin>>q3s>>q31>>q32>>q33;
	cin>>q4s>>q41>>q42>>q43;
	cin>>q5s>>q51>>q52>>q53;
	cin>>q6s>>q61>>q62>>q63;
	Quidditch q0(q01,q02,q03,q0s);
	Quidditch q1(q11,q12,q13,q1s);
	Quidditch q2(q21,q22,q23,q2s); 
	Quidditch q3(q31,q32,q33,q3s);
	Quidditch q4(q41,q42,q43,q4s);
	Quidditch q5(q51,q52,q53,q5s);
	Quidditch q6(q61,q62,q63,q6s);
	
	int a[7]={15,20,10,10,10,5,5};      //�ڲ�Ϊ��Ȩֵ*10������1��1.5��3��1, 2��0.5��1��2
	permutation(a,7,0,q0,q1,q2,q3,q4,q5,q6);
	
	int maxpot=pot[0];            //��Ч�� 
	int index=0;                  //pot[index]=��Ч�� 
	for(int n=0;n<420;n++){
		if(pot[n]>maxpot){
			maxpot=pot[n];
			index=n;
		}
	} 
	
	cout<<endl; 
	cout<<"�����Ч��="<<(double)maxpot/100<<endl;
	cout<<endl;	
	cout<<"Ч��MAX���������£�����/ְλ/�ڴ�ְλ��Ч������"<<endl;
	cout<<q0.getname()<<" "<<q0.getfinalrole(index)<<" "<<(double)q0.getpot(index)/10<<endl;
	cout<<q1.getname()<<" "<<q1.getfinalrole(index)<<" "<<(double)q1.getpot(index)/10<<endl; 
	cout<<q2.getname()<<" "<<q2.getfinalrole(index)<<" "<<(double)q2.getpot(index)/10<<endl; 
	cout<<q3.getname()<<" "<<q3.getfinalrole(index)<<" "<<(double)q3.getpot(index)/10<<endl; 
	cout<<q4.getname()<<" "<<q4.getfinalrole(index)<<" "<<(double)q4.getpot(index)/10<<endl; 
	cout<<q5.getname()<<" "<<q5.getfinalrole(index)<<" "<<(double)q5.getpot(index)/10<<endl;  
	cout<<q6.getname()<<" "<<q6.getfinalrole(index)<<" "<<(double)q6.getpot(index)/10<<endl;
	 	
	return 0;
	
} 




/* 魁地奇 
权值 
1.5    守门员1名   = 命中 + 耐力 + 敏捷                     
1      追球手3名   = 2 * 命中 + 0.5 * 耐力 + 0.5 * 敏捷     
0.5    击球手2名   = 0.5 * 命中 + 2 * 耐力 + 0.5 * 敏捷    
2      找球手1名   = 0.5 * 命中 + 0.5 * 耐力 + 2 * 敏捷      
*/ 

#include<iostream>
#include<cstring>
using namespace std;

class Quidditch{
	protected:
		string name; 
		int hit;     //命中
		int endu;    //耐力 
		int agile;   //敏捷
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
		
				
		string getfinalrole(int k);   //输出最终角色 
		int getpot(int k);  	       //输出最终效力	
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
		return "守门员";
	else if(role[k]==10)
		return "追球手";
	else if(role[k]==5)
		return "击球手";	 
	else if(role[k]==20)
		return "找球手"; 	
}




 


//是否交换
bool isSwap(int array[],int len,int index){
        for(int i=index+1;i<len;++i)
            if(array[index]==array[i])
                return false;
        return true;
}


 
//实现两数交换
void swap(int* o,int i,int j){
    int tmp = o[i];
    o[i] = o[j];
    o[j] = tmp;
}


int pot[420];      //储存总效力，可能性有7*6*C(5,2)=420种
int k=0;           //记录数组排列下标，pot[k]即为总效力 
Quidditch q0;
Quidditch q1;
Quidditch q2; 
Quidditch q3;
Quidditch q4;
Quidditch q5;
Quidditch q6;

//递归实现有重复元素的数组全排列
void permutation(int a[],int len,int index,Quidditch &q0,Quidditch &q1,Quidditch &q2,Quidditch &q3,Quidditch &q4,Quidditch &q5,Quidditch &q6){

    if(index==len){  //全排列结束
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
            if(isSwap(a,len,i)){ //新增判断是否交换            
                swap(a,index,i);  //将第i个元素交换至当前index下标处              
                permutation(a,len,index+1,q0,q1,q2,q3,q4,q5,q6); //以递归的方式对剩下元素进行全排列
                swap(a,index,i); //将第i个元素交换回原处
            }
        }
}

int main(){
	cout<<"魁地奇效力MAX规划"<<endl; 
	cout<<"请依次输入7名队员的姓名、命中、耐力、 敏捷:"<<endl;	
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
	
	int a[7]={15,20,10,10,10,5,5};      //内部为赋权值*10，含有1个1.5，3个1, 2个0.5，1个2
	permutation(a,7,0,q0,q1,q2,q3,q4,q5,q6);
	
	int maxpot=pot[0];            //总效力 
	int index=0;                  //pot[index]=总效力 
	for(int n=0;n<420;n++){
		if(pot[n]>maxpot){
			maxpot=pot[n];
			index=n;
		}
	} 
	
	cout<<endl; 
	cout<<"最大总效力="<<(double)maxpot/100<<endl;
	cout<<endl;	
	cout<<"效力MAX布阵结果如下（姓名/职位/在此职位的效力）："<<endl;
	cout<<q0.getname()<<" "<<q0.getfinalrole(index)<<" "<<(double)q0.getpot(index)/10<<endl;
	cout<<q1.getname()<<" "<<q1.getfinalrole(index)<<" "<<(double)q1.getpot(index)/10<<endl; 
	cout<<q2.getname()<<" "<<q2.getfinalrole(index)<<" "<<(double)q2.getpot(index)/10<<endl; 
	cout<<q3.getname()<<" "<<q3.getfinalrole(index)<<" "<<(double)q3.getpot(index)/10<<endl; 
	cout<<q4.getname()<<" "<<q4.getfinalrole(index)<<" "<<(double)q4.getpot(index)/10<<endl; 
	cout<<q5.getname()<<" "<<q5.getfinalrole(index)<<" "<<(double)q5.getpot(index)/10<<endl;  
	cout<<q6.getname()<<" "<<q6.getfinalrole(index)<<" "<<(double)q6.getpot(index)/10<<endl;
	 	
	return 0;
	
} 




#include<iostream>
#include<cstdio> 
#include<cstdlib>
#include<istream>
#include<ostream>
#include<vector>
#include<cmath>
#include<fstream> 
#include<string>
#include<cstring>
using namespace std;

#define M 30

int end = 0;

struct Info_Booklist
{
	int ISBN;
	int Form;
	int Wnum;
	int State;
	int Keeper;
	int Pbdate;
	string Bookname;
	string Publisher;
	string Wrriter; 
};

struct Info_Lists
{
	string UserID;
	int Role;
	string Password;
	string Username;
};

input()
{
	FILE *filehandler;
 	filehandler = fopen("UserList.txt","r");
 	if (filehandler==NULL)
 	{
 		cout<<"Error!"<<endl;
 		exit(1);
	}
	else
	{
		//fwrite(&ulists_a,sizeof(ulists_a),1,filehandler);
	}
};

class Book{    //����ͼ�������� 
public:    
	Book()
	{//���캯�� 
		isbn=wnum=pbdate=form=keeper=0;
		state=1;
		bookname=writter=publisher=bookadd='0';
	};
	void Book_setter(const int a,string Input);  //aΪ������Ŀ��InputΪ���������(string)
	void Book_setter(const int a,int Input);     //aΪ������Ŀ��InputΪ���������(int)
	int Book_getter(const int str1,const int str2);     //������� 
	friend class Resource_Manager;    //������Ԫ�� 
	string Book_getter(const int str1); 
	~Book() {}    //�������� 
                               	
private: 
	int isbn;         //Ψһȷ����ͼ����
	int wnum;         //������
	int pbdate;       //����ʱ��  publish book date
	int form;         //�鼮�洢��ʽ�����ӣ�0����ʵ�壨1��
	int state;        //ͼ��״̬-�����0����δ�����1�����쳣��-1��
	int keeper;       //��ǰ������
	string bookname;  //���� 
	string writter;   //���� 
	string publisher; //������ 
	string bookadd;   //ͼ��洢��ַ

}; 

void Book::Book_setter(const int a,string Input)
{
	switch(a)
	{
		case '1':    //��ѡ��1����Ϊ¼��ͼ������ 
			bookname=Input;
			break;
		case '2':    //��ѡ��2����Ϊ¼������ 
			writter=Input;
			break;
		case '3':    //��ѡ��3����Ϊ¼������� 
			publisher=Input;
			break;
		case '4':    //��ѡ��5����Ϊͼ��洢��ַ 
			bookadd=Input;
			break;
		//default:     //�������ǣ�����ʾ�������� 
			//cout<<"Error!"<<endl;
	}
};

void Book::Book_setter(const int a,int Input)
{
	switch(a)
	{
		case '1':    //��ѡ��1����Ϊ¼��ͼ���� 
			isbn=Input;
			break;
		case '2':    //��ѡ��2����Ϊ¼���������� 
			wnum=Input;
			break;
		case '3':    //��ѡ��3����Ϊ¼��ͼ�����ʱ�� 
			pbdate=Input;
			break;
		case '4':    //��ѡ��4����Ϊ¼��ͼ���ʽ 
			form=Input;
			break;
		case '5':    //��ѡ��5����Ϊ¼��ͼ�鵱ǰ״̬ 
			state=Input;
			break;
		case '6':    //��ѡ��6����Ϊ¼�뵱ǰ������ѧ�� 
			keeper=Input;
			break;
		//default:     //�������ǣ�����ʾ�������� 
			//cout<<"Error!"<<endl;
	} 
};

int Book::Book_getter(const int str1,const int str2)
{
	switch(str1)
	{
		case '1':
			return isbn;
			break;
		case '2':
			return state;
			break;
		case '3':
			return pbdate;
			break;
	}
};

string Book::Book_getter(const int str1)
{
	switch(str1)
	{
		case '1':
			return bookname;
			break;
		case '2':
			return writter;
			break;
		case '3':
			return publisher;
			break;
		case '4':
			return bookadd;
			break;
	}
};

class Paper{   //�������������� 
public:
	Paper()    //���캯�� 
	{
		id=anum=ppdate=0;
		title=author=publication=paperadd='0'; 
	};
	void Paper_setter(const int a,string Input);    //����string�������� 
	void Paper_setter(const int a,int Input);  //����int�������� 
	string Paper_getter(const int b);  //show 
	int Paper_getter(const int b,const int str2);
	friend class Resource_Manager;   //������Ԫ�� 
	~Paper() {}	  //�������� 
	
private:
	int id;  //���ı�� 
	int anum;  //������ 
	int ppdate;   //����ʱ��publish paper date
	string title;   //���ı��� 
	string author;  //�������ߣ������ж���� 
	string publication;   //���濯�� 
	string paperadd;  //���Ĵ洢��ַ 
};

void Paper::Paper_setter(const int a,string Input)
{
	switch(a)
	{
		case '1':    //��ѡ��1����Ϊ¼�����ı��� 
			title=Input;
			break;
		case '2':    //��ѡ��2����Ϊ¼������ 
			author=Input;
			break;
		case '3':    //��ѡ��3����Ϊ¼����濯�� 
			publication=Input;
			break;
		case '4':    //��ѡ��4����Ϊ¼�����Ĵ����ַ 
			paperadd=Input;
			break;
		default:     //�������ǣ�����ʾ�������� 
			cout<<"Error!"<<endl;
	}
};

void Paper::Paper_setter(const int a,int Input)
{
	switch(a)
	{
		case '1':    //��ѡ��1����Ϊ¼�����ı�� 
			id=Input;
			break;
		case '2':    //��ѡ��2����Ϊ¼���������� 
			anum=Input;
			break;
		case '3':    //��ѡ��3����Ϊ¼�����ĳ���ʱ�� 
			ppdate=Input;
			break;
		default:     //�������ǣ�����ʾ�������� 
			cout<<"Error!"<<endl;
	} 
};
int Paper::Paper_getter(const int b,const int str2)
{
	switch(b)
	{
		case '1':
			return id;
			break;
		case '2':
			return anum;
			break;
		case '3':
			return ppdate;
			break;
	}
};

string Paper::Paper_getter(const int b)
{
	switch(b)
	{
		case '1':
			return title;
			break;
		case '2':
			return author;
			break;
		case '3':
			return publication;
			break;
		case '4':
			return paperadd;
			break;
	}
};

class UserAccount{     //����Useraccount������ 
public:
	UserAccount()
	{   //���캯��
		userId=role=0;
		username=password="123"; 
	};       
	void User_Borrow(string userid,Book *book);     //���� 
	void User_Return(string userid,Book *book);     //���� 
	string User_Show(string str1);     //��ʾ�˻���Ϣ 
	int User_Show(string str1,const int a);  
	void User_Change(const int str1,string str2);   //�����û���Ϣ���ʻ��� ���룩
	void User_Change(const int str1);    //�����û���Ϣ����ɫ�� 
	void User_AddLabel(string str1);     //��ӱ�ǩ 
	friend class Resource_Manager;    //������Ԫ�� 
	~UserAccount() {};   //�������� 
		 
private:
	int userId;         //ѧ��(Ψһ��Ӧ)
	int role;   //��ɫ����ͨ�û�-0�����Ա-1��
	string username;  //�˻��� 
	string password;  //����
	string label;     //��ǩ 
};

void UserAccount::User_AddLabel(string Input)
{
	User_Show(label,0) ;
/*	if (label != NULL)
		cout<<"Ture!"<<endl;
	else 
		cout<<"False!"<<endl;	*/
};

int UserAccount::User_Show(string str1,const int a)
{
	string c1="userId";
	string c2="role";

	if ( str1==c1 )
		return userId;
	else if ( str1==c2 )
		return role;
};

string UserAccount::User_Show(string str1)
{
	string c3="username";
	string c4="password";
	
	if ( str1==c3 )
		return username;
	else if ( str1==c4 )
		return password;
};

void UserAccount::User_Change(const int str1,string str2)
{
	switch(str1)
	{
		case '1':     //�����ʻ���
			username=str2;
			break; 
		case '2':     //��������
			password=str2; 
			break;
		default:
			cout<<"Error!"<<endl;
	}
};

void UserAccount::User_Change(const int str1)
{
	role=str1;
};

void UserAccount::User_Borrow(string userid,Book *book)
{
	book->Book_setter(5,0);   //��ͼ��״̬��Ϊ��� 
	book->Book_setter(6,userid);  //�Ǽ�ͼ�鵱ǰ������ 
}; 

void UserAccount::User_Return(string userid,Book *book)
{
	book->Book_setter(5,1);   //��ͼ��״̬��Ϊδ��� 
	book->Book_setter(6,0); //��ͼ�鵱ǰ�����˸�Ϊ0 
};

class Account_Manager{  //�����˻������� 
public:
	Account_Manager();   //���캯�� 
	void Add_User(const int str1,string str2);      //����û����� 
	void Update_User();   //�����û��б� 
	void Delete_User(UserAccount *user);   //ɾ���û� 
	bool Set_UserRole(const int n,UserAccount *user);  //���Ž�ɫ���� 
	friend class Resource_Manager;    //������Ԫ�� 
	~Account_Manager() {};  //�������� 
	
private:
	FILE UserList;  	//�û��б� 
}; 

void Account_Manager::Add_User(const int str1,string str2)   
//���ѧ��Ϊstr1������Ϊstr2���˻� 
{
	ofstream SaveFile("UserList.txt",ios::app);
	cout<<"Please create user's role!"<<endl;
	int rr;
	cin>>rr;
	SaveFile<<"\n"<<str1;
	SaveFile<<" "<<str2<<" "<<rr;
	SaveFile.close();
	if (!SaveFile)
		cout<<"false"<<endl;
	else 
		cout<<"true"<<endl;
};

void Account_Manager::Delete_User(UserAccount *user)
{   //ɾ������ 
	user->~UserAccount();
};

bool Account_Manager::Set_UserRole(const int n,UserAccount *user)
{  //�����˺�Ȩ��
	int old; 
	if ( n==0 )   //��ԭ���˻���ɫΪѧ������������Ϊ����Ա 
	{
		old=0;    //��¼ԭ����� 
		user->User_Change(1);   //������� 
		string cc = "role";
		if ( user->User_Show(cc,0) != old  ) 
			return true;     //���ظ��ĳɹ� 
		else
			return false;
	}	
	else  
	{
	//��ԭ���˻���ɫΪ����Ա����������Ϊѧ�� 
	
		old=1;
		user->User_Change(0);   //������� 
		string cc = "role";
		if ( user->User_Show(cc,0)!=old  )  
			return true;    //���ظ��ĳɹ� 
		else    //���򷵻ظ���ʧ�� 
			return false;
	}
};

class Resource_Manager{    //������Դ������ 
public:
	Reasource_Manager();
	void Reasource_Input(char t1[]);   
	//¼��ͼ����Դ 
	void Reasource_Update(string newname);  
	//����ͼ���б� 
	void Reasource_Delete();  
	//ɾ��ͼ����� 
	void Reasource_View();    
	//show 
	void Reasource_Search(string str1,string str2);
	//���� 
	//str1Ϊ�������ͣ����߻������� str2Ϊ�������� 
	void out1();  //��½��ע�� 
	void out2(string uu);  //�û����� 
	
private:
	Book bok;   //����ͼ������� 
	Paper pap;  //������������� 
}; 

void Resource_Manager::out1()
{  //��ʼ���� ϵͳ��ʾ 
//	create()
//{
	Info_Lists ulists_a[M];
	Info_Booklist blist[M];
	ulists_a[1].UserID = "20170001";
	ulists_a[1].Role = 1;
	ulists_a[1].Username = "Mark";
	ulists_a[1].Password = "20170001";
	ulists_a[2].UserID = "20170002";
	ulists_a[2].Role = 0;
	ulists_a[2].Username = "Ann";
	ulists_a[2].Password = "20170002";
	ulists_a[3].UserID = "20170003";
	ulists_a[3].Role = 0;
	ulists_a[3].Username = "Gery";
	ulists_a[3].Password = "20170003";
	//blist[1].ISBN = 
//};
	string s1 = "Welcome To the Lab Reasource Management System!";
	cout<<s1<<endl;
	string s2 = "Please choose to login or register!";
	cout<<s2<<endl;
	string s3 = "1.login";
	string s4 = "2.register";
	cout<<s3<<endl;
	cout<<s4<<endl;
	char d=getchar();
	switch(d)
	{
		case '1':
		{
			cout<<"Please enter the ID!"<<endl;
			string line;
			cin>>line;
			for ( int i=1; i<=3; i++)
			{
				if ( line.compare( ulists_a[i].UserID ) == 0)
				{
					cout<<"Welcome,"<<line<<"!"<<endl;
				}
				else
					continue;
			}
			break;
		}	
		case '2':
		{
			cout<<"Please create your ID!"<<endl;
			cin>>ulists_a[4].UserID;
			ulists_a[4].Role = 0;
			cout<<"Please create your username!"<<endl;
			cin>>ulists_a[4].Username;
			cout<<"Please create your password!"<<endl;
			cin>>ulists_a[4].Password;
			cout<<"You've successfully created an account!Welcome to join!"<<endl;
			break;
		}	
	}
	
};

void Resource_Manager::out2(string uu)
{
	Info_Lists ulists_a[M];
	Info_Booklist blist[M];
	ulists_a[1].UserID = "20170001";
	ulists_a[1].Role = 1;
	ulists_a[1].Username = "Mark";
	ulists_a[1].Password = "20170001";
	ulists_a[2].UserID = "20170002";
	ulists_a[2].Role = 0;
	ulists_a[2].Username = "Ann";
	ulists_a[2].Password = "20170002";
	ulists_a[3].UserID = "20170003";
	ulists_a[3].Role = 0;
	ulists_a[3].Username = "Gery";
	ulists_a[3].Password = "20170003";
	
	int qx;
	for ( int i=1; i<=3; i++)
	{
		if ( uu.compare( ulists_a[i].UserID ) == 0)
		{
			qx = ulists_a[i].Role;
		}
	}
	if ( qx != 0 )
	{
		Account_Manager *account;
		string s1 = "Please select the action to take!";
		cout<<s1<<endl;
		cout<<"1.Borrow"<<endl;
		cout<<"2.Return"<<endl;
		cout<<"3.Addlabel"<<endl;
		cout<<"4.Show"<<endl;
		cout<<"5.Change"<<endl;
		cout<<"6.Secede"<<endl;
		cout<<"7.InputBook"<<endl;
		cout<<"8.DeleteBook"<<endl;
		cout<<"9.AddUser"<<endl;
		cout<<"10.DeleteUser"<<endl;
		int s;
		cin>>s;
		if ( s==1 )
		{
			Book *book1;
			UserAccount user1;
			cout<<"Please enter the book's name!"<<endl;
			string bbk;
			cin>>bbk;
			Resource_Manager mana;
			mana.Reasource_Search("book",bbk);
			cout<<"Whether or not to choose to borrow the book?"<<endl;
			cout<<"(Yes for 1,No for 0)"<<endl;
			getchar();
			int sa;
			cin>>sa;
			if ( sa==1 )
			{
				user1.User_Borrow(uu,book1);
				cout<<"Modification successful!"<<endl;
			}
			
		}
		else if ( s==2 )
		{
			Book *book1;
			UserAccount user1;
			cout<<"Please enter the book's name!"<<endl;
			string bbk;
			cin>>bbk;
			Resource_Manager mana;
			mana.Reasource_Search("book",bbk);
			cout<<"Whether or not to choose to return the book?"<<endl;
			cout<<"(Yes for 1,No for 0)"<<endl;
			getchar();
			int sa;
			cin>>sa;
			if ( sa==1 )
			{
				user1.User_Return(uu,book1);
				cout<<"Modification successful!"<<endl;
			}
		}
		else if ( s==6 )
		{
			cout<<"Log off!"<<endl;
			end=1;
		}
		/*else if ( s==7 )
		{
			char jj[10];
			cout<<"Please create new book's name!"<<endl;
			cin>>jj;
			Reasource_Input(jj);
		}*/
		else if ( s==9 && qx ==1 )
		{
			
			int ii;
			string jj;
			cout<<"Please create new ID!"<<endl;
			cin>>ii;
			cout<<"Please create new PASSWORD!"<<endl;
			cin>>jj;
			account->Add_User( ii, jj);
			cout<<"Modification successful!"<<endl;
		}		
	}
};

void Resource_Manager::Reasource_Input(char t1[])
{
	char postfix[] = {".txt"}; 
	strcat(t1,postfix);
	ofstream SaveFile(t1,ios_base::app);
	//����һ���ļ���Ϊt1��txt�ļ� 
	string str1;
	cout<<"Please create the basis of the book!"<<endl;
	cin>>str1;
	string str2;
	cout<<"Please create the basis of the book!"<<endl;
	cin>>str2;
	SaveFile<<"\n"<<str1;
	//¼����Ļ������� 
    SaveFile<<"\n"<<str2;
    //¼��������� 
    SaveFile.close();
};

void Resource_Manager::Reasource_Update(string newname)
{
	ofstream SaveFile("BookList.txt",ios_base::app);
	SaveFile<<"\n"<<newname;
	SaveFile.close();
};
 
void Resource_Manager::Reasource_Search(string str1,string str2)
{   //������Һ��� ���ļ��б�������struct�����б��� 
	if ( str1=="book" )
	{
		FILE *fp;
		long ISize;
		char *buffer;
		size_t result;
		fp = fopen( "BookList.txt", "rb" );
		if ( fp == NULL )
		{
			fputs( "File error", stderr);
			exit(1);
		}
		fseek( fp, 0, SEEK_END);
		ISize = ftell(fp);
		rewind(fp);
		buffer = (char*)malloc(sizeof(char)*ISize);
		if (buffer == NULL)
		{
			fputs( "Memory error\n",stderr);
			//exit(2);
		}
		result = fread(buffer,1,ISize,fp);
		if (result!=ISize)
		{
			fputs("Reading error\n",stderr);
			//exit(3);
		}
		fclose(fp);
		free(buffer);
		string sss;
		sss.assign(buffer,result);
		string::size_type idx;
		if (idx == string::npos)
			cout<<"Not found!"<<endl;
		else
			cout<<"Found!"<<endl;
	}
	else if ( str1=="paper" )
	{
		FILE *fp;
		long ISize;
		char *buffer;
		size_t result;
		fp = fopen( "PaperList.txt", "rb" );
		if ( fp = NULL )
		{
			fputs( "File error", stderr);
			exit(1);
		}
		fseek( fp, 0, SEEK_END);
		ISize = ftell(fp);
		rewind(fp);
		buffer = (char*)malloc(sizeof(char)*ISize);
		if (buffer == NULL)
		{
			fputs( "Memory error",stderr);
			exit(2);
		}
		result = fread(buffer,1,ISize,fp);
		if (result!=ISize)
		{
			fputs("Reading error",stderr);
			exit(3);
		}
		fclose(fp);
		free(buffer);
		string sss;
		sss.assign(buffer,result);
		string::size_type idx;
		if (idx == string::npos)
			cout<<"Not found!"<<endl;
		else
			cout<<"Found!"<<endl;
	}
	
}; 

int main ()
{
	Resource_Manager manager;
	manager.out1();
	cout<<"Whether or not to choose to continue the operation? "<<endl;
	cout<<"(Yes for 1,No for 0)"<<endl;
	int w;
	cin>>w;
	if ( w == 1 )
	{
		manager.out2("20170001");
		cout<<"Whether or not to choose to continue the operation? "<<endl;
		cout<<"(Yes for 1,No for 0)"<<endl;
		getchar();
		int ww;
		cin>>ww;
		if ( end==1 | ww ==0 )
		{
			cout<<"Log off!"<<endl;
			return 0;
		}
	}
	else  
	{
		cout<<"Log off!"<<endl;
		return 0;
	}
}

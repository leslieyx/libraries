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

class Book{    //声明图书类类型 
public:    
	Book()
	{//构造函数 
		isbn=wnum=pbdate=form=keeper=0;
		state=1;
		bookname=writter=publisher=bookadd='0';
	};
	void Book_setter(const int a,string Input);  //a为操作项目，Input为输入的内容(string)
	void Book_setter(const int a,int Input);     //a为操作项目，Input为输入的内容(int)
	int Book_getter(const int str1,const int str2);     //输出属性 
	friend class Resource_Manager;    //声明友元类 
	string Book_getter(const int str1); 
	~Book() {}    //析构函数 
                               	
private: 
	int isbn;         //唯一确定的图书编号
	int wnum;         //作者数
	int pbdate;       //出版时间  publish book date
	int form;         //书籍存储形式，电子（0）、实体（1）
	int state;        //图书状态-借出（0）、未借出（1）、异常（-1）
	int keeper;       //当前保管人
	string bookname;  //书名 
	string writter;   //作者 
	string publisher; //出版社 
	string bookadd;   //图书存储地址

}; 

void Book::Book_setter(const int a,string Input)
{
	switch(a)
	{
		case '1':    //若选择1，则为录入图书名称 
			bookname=Input;
			break;
		case '2':    //若选择2，则为录入作者 
			writter=Input;
			break;
		case '3':    //若选择3，则为录入出版社 
			publisher=Input;
			break;
		case '4':    //若选择5，则为图书存储地址 
			bookadd=Input;
			break;
		//default:     //若都不是，则显示操作错误 
			//cout<<"Error!"<<endl;
	}
};

void Book::Book_setter(const int a,int Input)
{
	switch(a)
	{
		case '1':    //若选择1，则为录入图书编号 
			isbn=Input;
			break;
		case '2':    //若选择2，则为录入作者数量 
			wnum=Input;
			break;
		case '3':    //若选择3，则为录入图书出版时间 
			pbdate=Input;
			break;
		case '4':    //若选择4，则为录入图书格式 
			form=Input;
			break;
		case '5':    //若选择5，则为录入图书当前状态 
			state=Input;
			break;
		case '6':    //若选择6，则为录入当前保管人学号 
			keeper=Input;
			break;
		//default:     //若都不是，则显示操作错误 
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

class Paper{   //声明论文类类型 
public:
	Paper()    //构造函数 
	{
		id=anum=ppdate=0;
		title=author=publication=paperadd='0'; 
	};
	void Paper_setter(const int a,string Input);    //设置string类型属性 
	void Paper_setter(const int a,int Input);  //设置int类型属性 
	string Paper_getter(const int b);  //show 
	int Paper_getter(const int b,const int str2);
	friend class Resource_Manager;   //声明友元类 
	~Paper() {}	  //析构函数 
	
private:
	int id;  //论文编号 
	int anum;  //作者数 
	int ppdate;   //出版时间publish paper date
	string title;   //论文标题 
	string author;  //论文作者（可能有多个） 
	string publication;   //出版刊物 
	string paperadd;  //论文存储地址 
};

void Paper::Paper_setter(const int a,string Input)
{
	switch(a)
	{
		case '1':    //若选择1，则为录入论文标题 
			title=Input;
			break;
		case '2':    //若选择2，则为录入作者 
			author=Input;
			break;
		case '3':    //若选择3，则为录入出版刊物 
			publication=Input;
			break;
		case '4':    //若选择4，则为录入论文储存地址 
			paperadd=Input;
			break;
		default:     //若都不是，则显示操作错误 
			cout<<"Error!"<<endl;
	}
};

void Paper::Paper_setter(const int a,int Input)
{
	switch(a)
	{
		case '1':    //若选择1，则为录入论文编号 
			id=Input;
			break;
		case '2':    //若选择2，则为录入作者数量 
			anum=Input;
			break;
		case '3':    //若选择3，则为录入论文出版时间 
			ppdate=Input;
			break;
		default:     //若都不是，则显示操作错误 
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

class UserAccount{     //声明Useraccount类类型 
public:
	UserAccount()
	{   //构造函数
		userId=role=0;
		username=password="123"; 
	};       
	void User_Borrow(string userid,Book *book);     //借书 
	void User_Return(string userid,Book *book);     //还书 
	string User_Show(string str1);     //显示账户信息 
	int User_Show(string str1,const int a);  
	void User_Change(const int str1,string str2);   //更改用户信息（帐户名 密码）
	void User_Change(const int str1);    //更改用户信息（角色） 
	void User_AddLabel(string str1);     //添加标签 
	friend class Resource_Manager;    //声明友元类 
	~UserAccount() {};   //析构函数 
		 
private:
	int userId;         //学号(唯一对应)
	int role;   //角色（普通用户-0或管理员-1）
	string username;  //账户名 
	string password;  //密码
	string label;     //标签 
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
		case '1':     //更改帐户名
			username=str2;
			break; 
		case '2':     //更改密码
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
	book->Book_setter(5,0);   //将图书状态改为借出 
	book->Book_setter(6,userid);  //登记图书当前保管人 
}; 

void UserAccount::User_Return(string userid,Book *book)
{
	book->Book_setter(5,1);   //将图书状态改为未借出 
	book->Book_setter(6,0); //将图书当前保管人改为0 
};

class Account_Manager{  //声明账户管理类 
public:
	Account_Manager();   //构造函数 
	void Add_User(const int str1,string str2);      //添加用户函数 
	void Update_User();   //更新用户列表 
	void Delete_User(UserAccount *user);   //删除用户 
	bool Set_UserRole(const int n,UserAccount *user);  //安排角色函数 
	friend class Resource_Manager;    //声明友元类 
	~Account_Manager() {};  //析构函数 
	
private:
	FILE UserList;  	//用户列表 
}; 

void Account_Manager::Add_User(const int str1,string str2)   
//添加学号为str1，密码为str2的账户 
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
{   //删除对象 
	user->~UserAccount();
};

bool Account_Manager::Set_UserRole(const int n,UserAccount *user)
{  //设置账号权限
	int old; 
	if ( n==0 )   //若原有账户角色为学生，则更改身份为管理员 
	{
		old=0;    //记录原有身份 
		user->User_Change(1);   //更改身份 
		string cc = "role";
		if ( user->User_Show(cc,0) != old  ) 
			return true;     //返回更改成功 
		else
			return false;
	}	
	else  
	{
	//若原有账户角色为管理员，则更改身份为学生 
	
		old=1;
		user->User_Change(0);   //更改身份 
		string cc = "role";
		if ( user->User_Show(cc,0)!=old  )  
			return true;    //返回更改成功 
		else    //否则返回更改失败 
			return false;
	}
};

class Resource_Manager{    //定义资源管理器 
public:
	Reasource_Manager();
	void Reasource_Input(char t1[]);   
	//录入图书资源 
	void Reasource_Update(string newname);  
	//更新图书列表 
	void Reasource_Delete();  
	//删除图书对象 
	void Reasource_View();    
	//show 
	void Reasource_Search(string str1,string str2);
	//找书 
	//str1为查找类型（作者或书名） str2为查找内容 
	void out1();  //登陆或注册 
	void out2(string uu);  //用户操作 
	
private:
	Book bok;   //定义图书类对象 
	Paper pap;  //定义论文类对象 
}; 

void Resource_Manager::out1()
{  //开始界面 系统提示 
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
	//创建一个文件名为t1的txt文件 
	string str1;
	cout<<"Please create the basis of the book!"<<endl;
	cin>>str1;
	string str2;
	cout<<"Please create the basis of the book!"<<endl;
	cin>>str2;
	SaveFile<<"\n"<<str1;
	//录入书的基本属性 
    SaveFile<<"\n"<<str2;
    //录入书的内容 
    SaveFile.close();
};

void Resource_Manager::Reasource_Update(string newname)
{
	ofstream SaveFile("BookList.txt",ios_base::app);
	SaveFile<<"\n"<<newname;
	SaveFile.close();
};
 
void Resource_Manager::Reasource_Search(string str1,string str2)
{   //定义查找函数 在文件中遍历或在struct数组中遍历 
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

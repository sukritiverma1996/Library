/*
      ##      ######   ########  ########     ##       ########  ##    ##
      ##        ##     ##    ##  ##    ##    ## ##     ##    ##   ##  ##
      ##        ##     ########  ########   #######    ########     ##
      ##        ##     ##    ##  ##  ##    ##     ##   ##  ##       ##
      ###### ########  ########  ##   ##  ##       ##  ##   ##      ##


 ###  ###   ##   ## ##   ##   ###### ####### ###  ### ####### ## ## #######
 ## ## ##  ####  ##|##  ####  ## ### #####   ## ## ## #####   ##|##    ##
 ##    ## ##  ## ## ## ##  ## ###### ####### ##    ## ####### ## ##    ##  */

/****************************
 Including Header Files
 ****************************/

#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
#include<dos.h>

/***********************
 Declaring classes
************************/

class book
{ protected:
  char bname[40];
  char aname[20];
  char bprice[5];
  char regno[5];
  int bstatus;
  int edition;

  public:

  char* return_bname(char tcode[6]);
  char book_found(char tcode[]);
  void book_add();
  void input();
  void output(int);
  void book_edit();
  void book_delete();
  void book_display();
  int book_recno(char tcode[]);
  void book_modify();
  void modify();
  int status(char tcode[6]);
  void modify_status(char tcode[6],int num);


} ;

class member
{ protected:
  int cardno;
  char uname[20];
  char uphone[20];
  char b_iss[5];
  int b_iss_date;
  int b_iss_month;
  int b_iss_year;
  int return_date;
  int return_month;
  int return_year;

  public:

  void member_add();
  char member_found(int);
  void getdata();
  void putdata(int);
  void member_edit();
  void member_delete();
  void member_display();
  int member_recno(int tcode);
  void member_modify();
  void modify();
  void extend_date(int card,char tcode[6]);
  int diff_dates(int card);
  char match(int, char*);
  char book_issued(int);
  void set_date(int card);
  member()
  {
	strcpy(b_iss,"\0");
	b_iss_date=0;
	b_iss_month=0;
	b_iss_year=0;
  }

};

class menu
{ public:
  void introduction();
  void main_menu();
  void edit_menu();
  void password();
};

class working : public member, public book
{ 	public:

	void issue();
	void reissue();
	void return_book();
};

/******************************************
Function to input password and username
*******************************************/

void menu::password()
{	clrscr();
	char login[20], pass[20];


  for(int i=0;i<3;i++)
  {     clrscr();
	gotoxy(25,10);
	cout<<"Please enter your username and password";
	gotoxy(25,12);
	cout<<"Username:";
	gotoxy(35,12);
	cin>>login;
	gotoxy(25,14);
	cout<<"Password:";
	gotoxy(35,14);


	for(int j=0;j!=20;j++)
	{   pass[j]=getch();
		 if(pass[j]==13)
		break;
		 else
		cout<<"*";
	}
	pass[j]='\0';


	if((strcmpi(login,"library")==0) && (strcmp(pass,"student")==0) && (strlen(pass)==7) )
	{       gotoxy(25,16);
		cout<<"Password accepted.Press any key to go to main menu.";
		getch();
		main_menu();

	}
	else
	{	if(i!=2)
		{      gotoxy(25,17);
			cout<<"Incorrect username or password.Please re-enter."<<endl;
			getch();


		}
		else
		{
			gotoxy(25,17);
			cout<<"Incorrect username or password.";
			gotoxy(25,18);
			cout<<"System is shutting down due to security reasons.";
		}
	}

  }
}

/**********************************
Function to define main menu
***********************************/

void menu::main_menu()
{

	char ch ;
	working w;
	book b;
   member m;
	while (1)
	{
		clrscr();
		gotoxy (29,6) ;
		cout <<"B O O K  L I B R A R Y" ;
		gotoxy (29,7) ;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy (30,10) ;
		cout <<"1. INTRODUCTION" ;
		gotoxy (30,11) ;
		cout <<"2. ADD NEW BOOK" ;
		gotoxy (30,12) ;
		cout <<"3. ADD NEW MEMBER" ;
		gotoxy (30,13) ;
		cout <<"4. ISSUE BOOK" ;
		gotoxy (30,14) ;
		cout <<"5. RETURN BOOK" ;
		gotoxy (30,15) ;
		cout <<"6. LIST OF BOOKS" ;
		gotoxy (30,16) ;
		cout <<"7. LIST OF MEMBERS" ;
		gotoxy (30,17) ;
		cout <<"8. EDIT" ;
		gotoxy (30,18) ;
		cout<<"9. RE-ISSUE";
		gotoxy(30,19);
		cout <<"0. QUIT" ;
		gotoxy (30,21) ;
		cout <<"Enter your choice : " ;
		cin>>ch;
		switch(ch)
		{
			case '1':introduction();
				 break;
			case '2':b.book_add()  ;
				break;
			case '3':m.member_add();
				break;
			case '4':w.issue();
				 break;
			case '5':w.return_book();
				break;
			case '6':b.book_display();
				break;
			case '7':m.member_display() ;
				break;
			case '8':
				edit_menu();
				break;
			case '9':
				w.reissue();
				break;
			case '0':exit(0);
			default:cout<<"Enter valid choice";
				break;
		}
	getch();
	clrscr();
	}
}


/***********************************
Function to display introduction
************************************/

void menu::introduction()
{
	clrscr();
	gotoxy (23,5) ;
	cout <<"Welcome to Library Management Project" ;
	gotoxy (33,7) ;
	printf(" BOOK LIBRARY ") ;
	gotoxy (15,10) ;
	cout <<"This  project has facility of maintaining  records" ;
	gotoxy (15,11) ;
	cout <<"of BOOKS and MEMBERS." ;
	gotoxy (15,13) ;
	cout <<"This  project  can  hold more  than  10,000  books" ;
	gotoxy (15,14) ;
	cout <<"records." ;
	gotoxy (15,16) ;
	cout <<"One member can issue one book at a time. If he/she" ;
	gotoxy (15,17) ;
	cout <<"does  not return book upto 15 days he/she have  to" ;
	gotoxy (15,18) ;
	cout <<"pay fine of Rs.2/- per day." ;
	gotoxy (27,24) ;
	cout<<"Press any key to continue" ;
	getch () ;
}


/*********************************
Function to display edit menu
**********************************/

void menu::edit_menu()

{       clrscr();
	char ch ;
	while (1)
	{       clrscr();
		gotoxy (32,9) ;
		cout <<"E D I T  M E N U";
		gotoxy (32,10) ;
		cout <<"~~~~~~~~~~~~~~~~" ;
		gotoxy (34,13) ;
		cout <<"1. BOOKS" ;
		gotoxy (34,14) ;
		cout <<"2. MEMBERS" ;
		gotoxy (34,15) ;
		cout <<"0. EXIT" ;
		gotoxy (31,17) ;
		cout <<"Enter your choice : " ;
		cin>>ch ;

		if (ch =='1')
		{	book b;
			b.book_edit () ;
		}
		else if (ch == '2')
		{       member m;
			m.member_edit () ;
		}
		else if (ch == '0')
		{
			main_menu();
		}
		else
			cout<<"Enter valid choice";
	}
}

/**************************************************************************
FUNCTIONS OF BOOK CLASS
***************************************************************************/

/********************************************
Function to display edit menu for books
********************************************/

void book::book_edit()
 {
	char ch ;
	while (1)
	{       clrscr();
		gotoxy (31,9) ;
		cout <<"E D I T  B O O K S";
		gotoxy (31,10) ;
		cout <<"~~~~~~~~~~~~~~~~~~" ;
		gotoxy (34,13) ;
		cout <<"1. MODIFY" ;
		gotoxy (34,14) ;
		cout <<"2. DELETE" ;
		gotoxy (34,15) ;
		cout <<"0. EXIT" ;
		gotoxy (31,17) ;
		cout <<"Enter your choice : " ;
		cin>>ch ;
		if (ch == '1')
		{        book_modify() ;
		}
		 else if (ch == '2')
		{
				 book_delete() ;
		}
		else if (ch == '0')
		{	menu men;
			men.edit_menu();
		}
		else
			cout<<"Enter valid choice";
	}
 }


/************************************************************
Function to check if a book exists with a given book code
*************************************************************/

char book::book_found(char tcode[])
{
	fstream f;
	char ch='n';
	f.open("book.dat",ios::in);
	member mem;
	f.seekg(0,ios::beg);
	book bk;
	while(f)
	{       f.read((char *) &bk,sizeof (book));
			if(strcmp(tcode,bk.regno)==0)
			{
				ch='y';

			}

	}
	return ch;
}

/***********************************************************
Function to input details for an object of book class
************************************************************/

void book::input()
{       char reg[6];
	lb5:
	clrscr();
	gotoxy (29,3) ;
	cout <<"ADDITION OF THE BOOKS" ;
	gotoxy (29,4) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~" ;
	int flag;
	gotoxy(15,10);
	cout<<"Book Registration Number:";
	gotoxy(40,10);
	cin>>reg;

	char res=book_found(reg);

	if(res=='y')
	{       gotoxy(3,12);
		cout<<"Sorry!This registration number already exists.Enter another valid number.";
		getch();
		goto lb5;

	}
	else if(res=='n')
	{       strcpy(regno,reg);
		gotoxy(15,12);
		cout<<"Book Name:";
		gotoxy(25,12);
		gets(bname);
		gotoxy(15,14);
		cout<<"Author Name:";
		gotoxy(27,14);
		gets(aname);
		gotoxy(15,16);
		cout<<"Copies:";
		gotoxy(22,16);
		cin>>bstatus;

		lb:
		gotoxy(15,18);
		cout<<"Price:Rs";
		gotoxy(21,18);
		clreol();
		cin>>bprice;

		if((strlen(bprice)>5))
		{       gotoxy (15,20) ;
			cout <<"Enter correctly" ;
			getch () ;
			goto lb;
		}
		else
		{
			flag=1;
			for(int n=0;bprice[n]!='\0';n++)
			{	if(!(isdigit(bprice[n])))
					flag=0;
				if(flag==0)
				{
					gotoxy (15,20) ;
					cout <<"Enter correctly" ;
					getch () ;
					goto lb;
				}
			}
		}
	}
}


/***********************************************************
Function to show details for an object of book class
************************************************************/

void book::output(int pos)
{       clrscr();
	gotoxy(35,7);
	cout<<"BOOK #"<<pos;
	gotoxy(15,10);
	cout<<"Book Registration Number:";
	gotoxy(40,10);
	cout<<regno;
	gotoxy(15,12);
	cout<<"Book Name:";
	gotoxy(25,12);
	puts(bname);
	gotoxy(15,14);
	cout<<"Author Name:";
	gotoxy(27,14);
	puts(aname);
	gotoxy(15,16);
	cout<<"Copies:";
	gotoxy(22,16);
	cout<<bstatus;
	gotoxy(15,18);
	cout<<"Price:Rs";
	gotoxy(21,18);
	cout<<bprice;

}

/*****************************
Function to add a new book
******************************/

void book::book_add()
{
	clrscr();
	gotoxy (29,3) ;
	cout <<"ADDITION OF THE BOOKS" ;
	gotoxy (29,4) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~" ;
	gotoxy (72,1) ;
	cout <<"<0>=Exit" ;
	book b1;
	fstream f;
	char ch,ch1;
	f.open("book.dat",ios::app);

	do
	{
		b1.input();
		gotoxy(15,22);
		cout<<"Do you wish to save the record(y/n)?";
		cin>>ch;
		ch=tolower(ch);
		if(ch=='0')
		{
			menu m;
			m.main_menu();
		}
		if(ch=='y')
		{
			f.write((char *) &b1,sizeof (book));
		}
		else
		{       menu m;
			m.main_menu();
		}
		gotoxy(15,24);
		cout<<"Do you wish to enter more(y/n)?";

		cin>>ch1;
		ch1 = tolower(ch1);
	}while(ch1=='y');
	f.close();
}


/***************************************
Function to display list of books
****************************************/

void book::book_display()
{
	clrscr();


	int found=0;
	int j;
	int i = 0;
	j=0;
	book bk;
	gotoxy (33,4) ;
	cout <<"LIST OF BOOKS" ;
	gotoxy (32,5) ;
	cout <<"~~~~~~~~~~~~~~~" ;
	gotoxy (1,7) ;
	cout <<"CODE  BOOK NAME                        AUTHOR                    PRICE  COPIES" ;
	gotoxy (1,8);
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;

	fstream f;
	f.open("book.dat",ios::in);
	f.seekg(0,ios::beg);
	while(f.read((char *) &bk , sizeof (book)))
	{


		found=1;
		gotoxy(1,9+j);
		cout<<bk.regno;
		gotoxy(6,9+j) ;
		cout<<bk.bname;
		gotoxy(40,9+j);
		cout<<bk.aname;
		gotoxy(66,9+j);
		cout<<bk.bprice;
		gotoxy(75,9+j);
		cout<<bk.bstatus;
		i++;
		j++;
	}
	f.close();
	if(!found)
	{
		gotoxy(31,15);
		cout<<"NO RECORDS FOUND";
	}

	gotoxy(1,29) ;
	cout<<"Press any key to go to main menu..." ;
	getche() ;
	menu m;
	m.main_menu();
}


/**************************************************
Function to return record number in file of book
***************************************************/

int book::book_recno(char tcode[])
{
	fstream f;
	int rec=0;
	f.open("book.dat",ios::in);
	f.seekg(0,ios::beg);
	book bk;
	while(f)
	{
		f.read((char *) &bk,sizeof (book));
		rec++;

		if(strcmp(tcode,bk.regno)==0)
		{
			return rec;
		}

	}
	return 0;

}

/*********************************
Function to delete a book
**********************************/

void book::book_delete()
{

	fstream f1,f2;
	char ch1,ch2;
	book bk;
	char tcode[6];
	enter:
	clrscr();
	gotoxy (72,1) ;
	cout <<"<0>=Exit" ;
	gotoxy(15,10);
	cout<<"Enter the code of book to be deleted:";
	cin>>tcode;
	if(tcode[0]=='0')
		book_edit();
	int y=book_recno(tcode);
	int rec=0;
	if(y==0)
	{       gotoxy(15,13);
		cout<<"Sorry!This registration number does not exist.Please re-enter.";
		getch();
		goto enter;
	}
	else
	{
		f1.open("book.dat",ios::in);
		f1.seekg(0,ios::beg);
		int num=book_recno(tcode);
		f1.seekg((num-1)*sizeof(book));
		f1.read((char *) &bk,sizeof (book));
		bk.output(num);
		clreol();
		lb:
		gotoxy(15,22);
		cout<<"Do you wish to delete the record(y/n)?";
		cin>>ch1;
		ch1=tolower(ch1);
		if(ch1=='y')
		{
			f2.open("temp.dat",ios::out);
			f1.seekg(0,ios::beg);

			while(f1.read((char *) &bk ,sizeof (book)))
			{       rec++;
				if(rec!=y)
				{
					f2.write((char *) &bk,sizeof (book));
				}
			}
			f1.close();
			f2.close();
			f1.open("book.dat",ios::out);
			f2.open("temp.dat",ios::in);
			while(f2.read((char *) &bk,sizeof (book)))
			{
				f1.write((char *) &bk,sizeof (book));
			}
			f1.close();
			f2.close();

			remove("temp.dat");

			gotoxy(15,24);
			cout<<"Record has been deleted.";
			midway:
			clreol();
			gotoxy(15,26);
			cout<<"Do you wish to continue(y/n)?";
			cin>>ch2;
			if(ch2=='y')
				goto enter;
			else if(ch2=='n')
				book_edit();
			else
			{       gotoxy(10,28);
				cout<<"You have entered an invalid choice.Please re-enter.";
				getch();
				goto midway;
			}
		}

		else if(ch1=='n')
			book_edit();
		else
		{       gotoxy(10,24);
			cout<<"You have entered an invalid choice.Please re-enter";
			getch();
			goto lb;
		}
	}
}



/****************************************
Function to modify a book record
*****************************************/

void book::book_modify()
{
	again1:
	clrscr();
	int num;
	char ch, ch3;
	book bk;
	char choice, reg[6];
	gotoxy(10,10);
	cout<<"Enter registration number of book to be modified:";
	cin>>reg;
	if(reg[0]=='0')
	{	book_edit();
	}
	else
	{	char ans = book_found(reg);
		if(ans=='n')
		{
			gotoxy(10,12);
			cout<<"Please enter valid registration number";
			getch();
			goto again1;
		}
		else if(ans=='y')
		{       gotoxy(10,12);
			cout<<"Do you wish to modify record(y/n)?";
			cin>>choice;
			if(choice=='n')
			{
				book_edit();
			}
			else if(choice=='y')
			{
				num=book_recno(reg);
				fstream f;
				f.open("book.dat",ios::in|ios::ate);
				f.seekg((num-1)*(sizeof (book)));
				book b;
				f.read((char *) &b,sizeof (book));
				f.close();
				b.output(num);
				gotoxy(35,21);
				cout<<"ENTER NEW RECORD";
				b.modify();

				gotoxy(15,33);
				cout<<"Do you wish to save the changes(y/n)?";
				cin>>ch;
				if(ch=='n')
				{
					book_edit();
				}
				else if(ch=='0')
				{
					book_edit();
				}
				else if(ch=='y')
				{       fstream f1,f2;
					book b1;
					int rec=0;
					f1.open("book.dat",ios::in);
					f2.open("temp.dat",ios::out);
					f1.seekg(0,ios::beg);

					while(f1.read((char *) &b1,sizeof (book)))
					{       rec++;
						if(rec!=num)
						{
							f2.write((char *) &b1,sizeof (book));
						}
						else
						{
							f2.write((char *) &b,sizeof (book));
						}
					}
					f1.close();
					f2.close();
					f1.open("book.dat",ios::out);
					f2.open("temp.dat",ios::in);
					while(f2.read((char *) &bk,sizeof (book)))
					{
						f1.write((char *) &bk,sizeof (book));
					}
					f1.close();
					f2.close();

					remove("temp.dat");

					gotoxy(15,35);
					cout<<"The record has been modified";
					gotoxy(15,37);
					cout<<"Do you wish to continue(y/n)?";
					cin>>ch3;
					if(ch3=='n')
						book_edit();
					else if(ch3=='0')
						book_edit();
					else if(ch=='y')
						goto again1;
				}
			}
		}
	}
}


/****************************************************************
Function to enter new details of book for modification
*****************************************************************/

void book::modify()
{
	int flag,copy;
	char newauthor[30],newname[30],newprice[5];
	char reg[5];
	lb5:
	gotoxy(15,23);
	cout<<"Enter new registration number:";
	clreol();
	cin>>reg;
	char res=book_found(reg);

	if(res=='y')
	{       gotoxy(10,24);
		cout<<"Sorry!This registration number already exists.Please re-enter.";
		getch();
		goto lb5;
	}
	else if(res=='n')
	{
		strcpy(regno,reg);
		gotoxy(15,25);
		cout<<"Book Name:";
		gets(newname);
		strcpy(bname,newname);
		gotoxy(15,27);
		cout<<"Author name:";
		gets(newauthor);
		strcpy(aname,newauthor);
		gotoxy(15,29);
		cout<<"Copies:";
		cin>>copy;
		bstatus=copy;
		lb1:
		gotoxy(15,31);
		cout<<"Price: Rs";
		clreol();
		cin>>newprice;

		if((strlen(newprice)>5))
		{       gotoxy (15,30) ;
			cout <<"\7Enter correctly" ;
			getch () ;
			goto lb1;
		}
		else
		{
			flag=1;
			for(int n=0;newprice[n]!='\0';n++)
				if(!(isdigit(newprice[n])))
			flag=0;
			if(flag==0)
			{
				gotoxy (15,30) ;
				cout <<"\7Enter correctly" ;
				getch () ;
				goto lb1;
			}
		}

		strcpy(bprice,newprice);

	}
}

/***********************************************************************
Function to return book name for a given book registration number
************************************************************************/

char* book::return_bname(char tcode[6])
  {  int r=book_recno(tcode);
     fstream f1;
     f1.open("book.dat",ios::in);
     f1.seekg(0,ios::beg);
     book buk;
     f1.seekg((r-1)*sizeof(book));
     f1.read((char *) &buk,sizeof (book));
     return buk.bname;
  }


/*********************************************************
Function to return available copies of a given book
*********************************************************/

int book::status(char tcode[6])
{
	int num = book_recno(tcode);
	fstream f;
	book b;
	f.open("book.dat",ios::in);
	f.seekg((num-1)*(sizeof (book)));
	f.read((char *) &b,sizeof (book));
	return b.bstatus;

}

/**************************************************
Function to modify copies of a given book
***************************************************/

void book::modify_status(char tcode[6],int num)
{       int num1;
	num1=book_recno(tcode);
	fstream f;
	f.open("book.dat",ios::in|ios::ate);
	f.seekg((num1-1)*(sizeof (book)));
	book b;
	f.read((char *) &b,sizeof (book));
	b.bstatus=b.bstatus+num;
	f.close();
	fstream f1,f2;
	book b1;
	int rec=0;
	f1.open("book.dat",ios::in);
	f2.open("temp.dat",ios::out);
	f1.seekg(0,ios::beg);

	while(f1.read((char *) &b1,sizeof (book)))
	{       rec++;
		if(rec!=num1)
		{
			f2.write((char *) &b1,sizeof (book));
		}
		else
		{
			f2.write((char *) &b,sizeof (book));
		}
	}
	f1.close();
	f2.close();
	f1.open("book.dat",ios::out);
	f2.open("temp.dat",ios::in);
	book b2;
	while(f2.read((char *) &b2,sizeof (book)))
	{
		f1.write((char *) &b2,sizeof (book));
	}
	f1.close();
	f2.close();

	remove("temp.dat");

}

/**************************************************************************
FUNCTIONS OF MEMBER CLASS
***************************************************************************/

/********************************************
Function to display edit menu for members
*********************************************/

void member::member_edit()
 {
	char ch ;
	while (1)
	{       clrscr();
		gotoxy (29,9) ;
		cout <<"E D I T  M E M B E R S";
		gotoxy (29,10) ;
		cout <<"~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy (34,13) ;
		cout <<"1. MODIFY" ;
		gotoxy (34,14) ;
		cout <<"2. DELETE" ;
		gotoxy (34,15) ;
		cout <<"0. EXIT" ;
		gotoxy (29,17) ;
		cout <<"Enter your choice : " ;
		cin>>ch ;
		if (ch == '1')
		{
			member_modify() ;
		}
		else if (ch == '2')
		{
			member_delete() ;
		}
		else if (ch == '0')
		{	menu men;
			men.edit_menu() ;
		}
		else
			cout<<"Enter valid choice";
	}
 }

/************************************************************
Function to check if a member exists with a given member code
*************************************************************/

char member::member_found(int tcode)
{
	fstream f;
	char ch='n';
	f.open("member.dat",ios::in);
	f.seekg(0,ios::beg);
	member mem;
	while(f)
	{
		f.read((char *) &mem,sizeof (member));
		if(tcode==mem.cardno)
		{
				ch='y';
		}

	}
	return ch;
}


/***********************************************************
Function to input details for an object of member class
************************************************************/

void member::getdata()
{
	again:
	int card;
	clrscr();
	gotoxy (29,3) ;
	cout <<"ADDITION OF THE MEMBERS" ;
	gotoxy (29,4) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~" ;

	int flag;
	gotoxy(15,9);
	cout<<"Card number:";
	cin>>card;
	char ans=member_found(card);
	if(ans=='y')
	{       gotoxy(12,12);
		cout<<"Sorry!This card number already exists.Please re-enter.";
		getch();
		goto again;
	}
	else if(ans=='n')
	{       strcpy(b_iss,"\0");
		b_iss_date=0;
		b_iss_month=0;
		b_iss_year=0;
		cardno=card;
		gotoxy(15,11);
		cout<<"Name:";
		gets(uname);
		lb:
		gotoxy(15,13);
		cout<<"Phone:";
		clreol();
		cin>>uphone;

		if((strlen(uphone)!=10))
		{       gotoxy (15,15) ;
			cout <<"\7Enter correctly" ;
			getch () ;
			goto lb;
		}

		else
		{
			flag=1;
			for(int n=0;uphone[n]!='\0';n++)
				if(!(isdigit(uphone[n])))
					flag=0;
			if(flag==0)
			{
				gotoxy (15,15) ;
				cout <<"\7Enter correctly" ;
				getch () ;
				goto lb;
			}
		}
	}

}

/***********************************************************
Function to show details for an object of member class
************************************************************/

void member::putdata(int x)
{
	clrscr();
	gotoxy(35,6);
	cout<<"MEMBER # "<<x;
	gotoxy(15,9);
	cout<<"Card number:";
	cout<<cardno;
	gotoxy(15,11);
	cout<<"Name:";
	gotoxy(22,11);
	puts(uname);
	gotoxy(15,13);
	cout<<"Phone:";
	gotoxy(22,13);
	cout<<uphone;

}

/*****************************
Function to add a new member
******************************/

void member::member_add()
{
	clrscr();
	gotoxy (29,3) ;
	cout <<"ADDITION OF THE MEMBERS" ;
	gotoxy (29,4) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~" ;
	member m1;
	fstream f;
	char ch,ch1;
	f.open("member.dat",ios::app);
	do
	{
		m1.getdata();
		gotoxy(15,17);
		cout<<"Do you wish to save the record(y/n)?";
		cin>>ch;
		ch = tolower(ch);
		if(ch=='0')
		{
			menu mem;
			mem.main_menu();
		}
		if(ch=='y')
		{
			f.write((char *) &m1,sizeof (member));
		}
		else
		{       menu m;
			m.main_menu();
		}
		gotoxy(15,19);
		cout<<"Do you wish to enter more(y/n)?";
		cin>>ch1;
		ch1=tolower(ch1);
	}while(ch1=='y');
	f.close();
}

/****************************************
Function to modify a member record
*****************************************/

void member::member_modify()
{
	again1:
	clrscr();
	int card,num;
	char ch,ch3;
	char choice;
	member memb;
	gotoxy(10,10);
	cout<<"Enter card number of member to be modified:";
	cin>>card;
	if(card==0)
	{	member_edit();
	}
	else
	{	char ans = member_found(card);
		if(ans=='n')
		{
			gotoxy(10,12);
			cout<<"Please enter valid card number";
			getch();
			goto again1;
		}
		else if(ans=='y')
		{
			gotoxy(10,12);
			cout<<"Do you wish to modify record(y/n)?";
			gotoxy(45,12);
			cin>>choice;
			if(choice=='n')
			{
				member_edit();
			}
			else if(choice=='y')
			{
				num=member_recno(card);
				fstream f;
				f.open("member.dat",ios::in|ios::ate);
				f.seekg((num-1)*(sizeof (member)));
				member mem;
				f.read((char *) &mem,sizeof (member));
				f.close();
				mem.putdata(num);
				gotoxy(35,16);
				cout<<"ENTER NEW RECORD";
				mem.modify();
				gotoxy(15,26);
				cout<<"Do you wish to save the changes(y/n)?";
				cin>>ch;
				if(ch=='n')
				{
					member_edit();
				}
				else if(ch=='0')
				{
					member_edit();
				}
				else if(ch=='y')
				{       fstream f1,f2;
					member m1;
					int rec=0;
					f1.open("member.dat",ios::in);
					f2.open("temp.dat",ios::out);
					f1.seekg(0,ios::beg);

					while(f1.read((char *) &m1,sizeof (member)))
					{
					rec++;
					if(rec!=num)
					{
						f2.write((char *) &m1,sizeof (member));
					}
					else
					{
							 f2.write((char *) &mem,sizeof (member));
					}
					}
					f1.close();
					f2.close();
					f1.open("member.dat",ios::out);
					f2.open("temp.dat",ios::in);
					while(f2.read((char *) &memb,sizeof (member)))
					{
						f1.write((char *) &memb,sizeof (member));
					}
					f1.close();
					f2.close();
					remove("temp.dat");

					gotoxy(15,28);
					cout<<"The record has been modified";
					gotoxy(15,30);
					cout<<"Do you wish to continue(y/n)?";
					cin>>ch3;
					if(ch3=='n')
						member_edit();
					else if(ch3=='0')
						member_edit();
					else if(ch=='y')
						goto again1;
				}
			}
		}
	}
}

/****************************************************************
Function to enter new details of member for modification
*****************************************************************/

void member::modify()
{
	again:
	int flag=0;
	char newname[30],newphone[11];
	int newcard;
	gotoxy(15,18);
	cout<<"Enter new card number:";
	clreol();
	cin>>newcard;

	char ans=member_found(newcard);
	if(ans=='y')
	{       gotoxy(15,19);
		cout<<"This card number already exists.Please re-enter.";
		getch();
		goto again;
	}
	else if(ans=='n')
	{
		cardno=newcard;
		gotoxy(15,20);
		cout<<"Enter new name";
		gets(newname);
		if(newname[0]!='&')
			strcpy(uname,newname);
		lb:
		gotoxy(15,22);
		cout<<"Enter new phone number:";
		clreol();

		cin>>newphone;

		if((strlen(newphone)!=10))
		{	gotoxy (15,21) ;
			cout <<"\7Enter correctly" ;
			getch () ;
			goto lb;
		}

		else
		 {
			flag=1;
			for(int n=0;newphone[n]!='\0';n++)
				if(!(isdigit(newphone[n])))
					flag=0;
			if(flag==0)
			{
				gotoxy (15,21) ;
				cout <<"\7Enter correctly" ;
				getch () ;
				goto lb;
			}
		}
		if(flag==1)
			strcpy(uphone,newphone);
			return;
	}
}

/*********************************
Function to delete a member
**********************************/

void member::member_delete()
{  	start:
	clrscr();
	fstream f1,f2;
	char ch1,ch2;
	member mem,memb;
	int tcode;
	gotoxy (72,1) ;
	cout <<"<0>=Exit" ;
	gotoxy (15,7) ;
	cout <<"Enter Card no. of the Member to be Deleted:" ;
	cin>>tcode;
	if(tcode==0)
		member_edit();
	char ch3=mem.book_issued(tcode);
	if(ch3=='y')
	{       gotoxy(15,9);
		cout<<"Member has a book issued on this card number.";
		gotoxy(5,11);
		cout<<"Please return the book before deleting the record or press 0 to exit.";
		char ch4=getch();
		if(ch4=='0')
		{
			member_edit();
		}
		else
			goto start;
	}
	int y=mem.member_recno(tcode);
	int rec=0;

	if(y==0)
	{       gotoxy(5,10);
		cout<<"The member code does not exist.Please re-enter the code.";
		getch();
		goto start;
	}
	else
	{
		f1.open("member.dat",ios::in);
		f1.seekg(0,ios::beg);
		int num=mem.member_recno(tcode);
		f1.seekg((num-1)*sizeof(member));
		f1.read((char *) &mem,sizeof (member));
		mem.putdata(y);
		lb:
		clreol();
		gotoxy(15,15);
		cout<<"Do you wish to delete the record(y/n)?";
		cin>>ch1;
		ch1=tolower(ch1);
		if(ch1=='y')
		{
			f2.open("temp.dat",ios::out);
			f1.seekg(0,ios::beg);

			while(f1.read((char *) &mem,sizeof (member)))
			{
				rec++;
				if(rec!=y)
				{
					f2.write((char *) &mem,sizeof (member));
				}
			}
			f1.close();
			f2.close();
			f1.open("member.dat",ios::out);
			f2.open("temp.dat",ios::in);
			while(f2.read((char *) &mem,sizeof (member)))
			{
				f1.write((char *) &mem,sizeof (member));
			}
			f1.close();
			f2.close();
			remove("temp.dat");
			gotoxy(15,17);
			cout<<"Record has been deleted.";
			midway:
			clreol();
			gotoxy(15,19);
			cout<<"Do you wish to continue(y/n)?";
			cin>>ch2;
			if(ch2=='y')
				goto start;
			else if(ch2=='n')
				member_edit();
			else
			{       gotoxy(5,21);
				cout<<"You have entered an invalid choice.Please re-enter.";
				getch();
				goto midway;
			}
		}
		else if(ch1=='n')
			member_edit();
		else
		{       gotoxy(7,17);
			cout<<"You have entered an invalid choice.";
			getch();
			goto lb;
		}
	}
}
/***************************************
Function to display list of members
****************************************/

void member::member_display()
{
	clrscr();
	member mem;
	int found=0,j,i;
	j=0;
	gotoxy (32,4) ;
	cout <<"LIST OF MEMBERS" ;
	gotoxy (31,5) ;
	cout <<"~~~~~~~~~~~~~~~~~" ;
	gotoxy (1,7) ;
	cout <<"CODE  NAME                BOOK CODE  BOOK ISSUED                  RETURN DATE               " ;
	gotoxy (1,8) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;


	fstream f;
	f.open("member.dat",ios::in);
	f.seekg(0,ios::beg);

	while(f.read((char *) &mem ,sizeof (member)))
	{
		found=1;

		gotoxy(1,9+j);
		cout<<mem.cardno;
		gotoxy(6,9+j) ;
		puts(mem.uname);
		gotoxy(30,9+j);
		cout<<mem.b_iss;
		if(strcmp(mem.b_iss,"\0")!=0)
		{	gotoxy(40,9+j);
			char name[50];
			book b2;
			strcpy(name,b2.return_bname(b_iss));
			puts(name);
			gotoxy(67,9+j);
			cout<<mem.return_date<<"-"<<mem.return_month<<"-"<<mem.return_year;
		}
		else
		{       gotoxy(30,9+j);
			cout<<"NIL";
			gotoxy(40,9+j);
			cout<<"NIL";
			gotoxy(67,9+j);
			cout<<"NIL";
		}

		j++;
	}
	f.close();

	if(!found)
	{
		gotoxy(31,15);
		cout<<"NO RECORDS FOUND";
	}

	gotoxy(1,29) ;
	cout <<"Press any key to go to main menu..." ;
	getche() ;
	menu m;
	m.main_menu();
}

/******************************************************
Function to return record number in file of member
*******************************************************/

int member::member_recno(int tcode)
{
	fstream f;
	int rec=0;
	member mem;
	f.open("member.dat",ios::in);
	f.seekg(0,ios::beg);
	while(f)
	{
		f.read((char *) &mem,sizeof (member));
		rec++;
		{
			if(tcode==mem.cardno)
			{
				return rec;
			}
		}
	}
	return 0;

}

/******************************************************
Function to extend a date by 15 days
*****************************************************/

void member::extend_date(int card,char tcode[6])
{
	//Calculate today's date
	int d1, m1, y1,d2,y2,m2, month,num ;
	struct date d;
	getdate (&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	gotoxy(5,4);
	cout<<"Today is:"<<d1<<"-"<<m1<<"-"<<y1;

	int month_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(y1%4==0)
	month_days[1]=29;

	month=month_days[m1-1];

	if(d1+15>month)
	{	d2= (d1 + 15)-month;
		if(m1+1>12)
		{	m2=1;
			y2=y1+1;
		}
		else
		{
			m2=m1+1;
			y2=y1;
		}

	}
	else
	{	d2=d1+15;
		m2=m1;
		y2=y1;
	}
	gotoxy(15,14);
	cout<<"The date of return is "<<d2<<"-"<<m2<<"-"<<y2<<".";
	num=member_recno(card);
	fstream f;
	f.open("member.dat",ios::in|ios::ate);
	f.seekg((num-1)*(sizeof (member)));
	member mem;
	f.read((char *) &mem,sizeof (member));
	f.close();
	mem.b_iss_date=d1;
	mem.b_iss_month=m1;
	mem.b_iss_year=y1;
	mem.return_date=d2;
	mem.return_month=m2;
	mem.return_year=y2;
	strcpy(mem.b_iss,tcode);



	fstream f1,f2;
	member m8;
	int rec=0;
	f1.open("member.dat",ios::in);
	f2.open("temp.dat",ios::out);
	f1.seekg(0,ios::beg);

	while(f1.read((char *) &m8,sizeof (member)))
	{
	rec++;
	if(rec!=num)
	{
		f2.write((char *) &m8,sizeof (member));
	}
	else
	{
		f2.write((char *) &mem,sizeof (member));
	}
	}
	f1.close();
	f2.close();
	member mem2;
	f1.open("member.dat",ios::out);
	f2.open("temp.dat",ios::in);
	while(f2.read((char *) &mem2,sizeof (member)))
	{
	 f1.write((char *) &mem2,sizeof (member));
	}
	f1.close();
	f2.close();
	remove("temp.dat");

}


/**************************************************
Function to return difference of two dates
*************************************************/

int member::diff_dates(int card)
{
	int d1,m1,y1,days,ldays,a,b,c,x,y,d2,m2,y2;
	struct date d;
	getdate (&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;

	fstream f;
	member mem2;
	f.open("member.dat",ios::in);
	f.seekg(0,ios::beg);
	int num=member_recno(card);
	f.seekg((num-1)*sizeof(member));
	f.read((char *) &mem2,sizeof (member));

	d2=mem2.b_iss_date;
	m2=mem2.b_iss_month;
	y2=mem2.b_iss_year;


       int month_days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(y1%4==0)
		month_days[1]=29;


	if(y1==y2&&m1==m2)
	{	days=d1-d2;
	}
	else if(y1==y2)
	{	days=(month_days[m2-1]-d2)+d1;

		for(a=m2+1;a<m1;a++)
			days=days+month_days[a-1];
	}

	else
	{	days=(month_days[m2-1]-d2)+d1;

		for(b=m2+1;b<12;b++)
			days=days+month_days[b-1];
		for(c=1;c<m1;c++)
			days=days+month_days[c-1];

		for(x=1;x<(y1-y2);x++)
			for(y=1;y<13;y++)
				days=days+month_days[y-1];
	}

	ldays=days-15;

	return ldays;
}

/******************************************************
Function to check if the given member has book
*******************************************************/

char member::book_issued(int card)
{
	fstream f1;
	char ch='y';
	f1.open("member.dat",ios::in);
	int num=member_recno(card);
	f1.seekg((num-1)*sizeof(member));
	member mem;
	f1.read((char*) &mem, sizeof (member));
	if(mem.b_iss[0]=='\0')
	{  ch='n';

	}

	return ch;
}


/****************************************************************
Function to check if a given book is issued to given member
*****************************************************************/

char member::match(int card, char reg[])
{
	fstream f1;
	char ch1='n';
	member mem;
	f1.open("member.dat",ios::in);
	int num=member_recno(card);
	f1.seekg((num-1)*sizeof(member));
	f1.read((char*) &mem, sizeof (member));
	if(strcmp(mem.b_iss,reg)==0)
	{	ch1 = 'y';
	}
	return ch1;
}

/******************************************************
Function to set a date of a given member to 0
*****************************************************/

void member::set_date(int card)
{       int num;
	num=member_recno(card);
	fstream f;
	f.open("member.dat",ios::in|ios::ate);
	f.seekg((num-1)*(sizeof (member)));
	member mem;
	f.read((char *) &mem,sizeof (member));
	f.close();
	mem.b_iss_date=0;
	mem.b_iss_month=0;
	mem.b_iss_year=0;
	strcpy(mem.b_iss,"\0");



	fstream f1,f2;
	member m1;
	int rec=0;
	f1.open("member.dat",ios::in);
	f2.open("temp.dat",ios::out);
	f1.seekg(0,ios::beg);

	while(f1.read((char *) &m1,sizeof (member)))
	{
	rec++;
	if(rec!=num)
	{
		f2.write((char *) &m1,sizeof (member));
	}
	else
	{
		f2.write((char *) &mem,sizeof (member));
	}
	}
	f1.close();
	f2.close();
	f1.open("member.dat",ios::out);
	f2.open("temp.dat",ios::in);
	member mem2;
	while(f2.read((char *) &mem2,sizeof (member)))
	{
	 f1.write((char *) &mem2,sizeof (member));
	}
	f1.close();
	f2.close();
	remove("temp.dat");

}

/**************************************************************************
FUNCTIONS OF WORKING CLASS
***************************************************************************/

/************************************************
Function to issue a book to a given member
************************************************/

void working::issue()
{	iss:
	int i,j,card,num;
	book b;
	member memb;
	char code[6],ch1,ch,ch2,ch3,ch7;
	clrscr();
	gotoxy(60,1);
	cout<<"Enter 0 for Mainmenu";
	gotoxy(15,10);
	cout<<"Enter the code number of book to be issued:";
	cin>>code;

	if(code[0]=='0')
	{	menu m;
		m.main_menu();
	}

	else
	{	ch = b.book_found(code);
		if(ch=='n')
		{       gotoxy(20,12);
			cout<<"The book code is invalid.Please re-enter.";
			getch();
			goto iss;
		}
		else
		{
			num = b.status(code);


			if(num==0)
			{	gotoxy(10,12);
				cout<<"Sorry, this book is not available.Please issue some other book.";

				getch();
				goto iss;
			}
			else
			{       int rec=b.book_recno(code);
					fstream f;

				f.open("book.dat",ios::in);
				f.seekg((rec-1)*(sizeof (book)));
				f.read((char *) &b,sizeof (book));
				b.output(rec);
				gotoxy(15,24);
				cout<<"Press any key to continue.";
				getch();
				mem:
				clrscr();
				gotoxy(60,1);
				cout<<"Enter 0 for Mainmenu";
				gotoxy(15,8);
				cout<<"Enter the member code:";

				cin>>card;
					if(card==0)
					{	menu m;
						m.main_menu();
					}
					else
					{	ch1=memb.member_found(card);
						if(ch1=='n')
						{       gotoxy(15,10);
							cout<<"Please enter a valid card number.";
							getch();
							goto mem;
						}
						else
						{	ch2=memb.book_issued(card);
							if(ch2=='y')
							{       gotoxy(15,10);
								cout<<"Sorry you have already been issued a book.";
								gotoxy(15,12);
								cout<<"You may issue a book on another card or press 0 to exit";
								ch3 = getch();
								if(ch3=='0')
								{	menu m;
									m.main_menu();
								}
								else
									goto mem;
							}
							else
							{	memb.extend_date(card,code);
								gotoxy(15,12);
								cout<<"The book has been issued to you.";
								num=-1;
								b.modify_status(code,num);
								midway:
								gotoxy(15,18);
								cout<<"Do you wish to continue?(y/n)";
								cin>>ch7;
								if(ch7=='y')
								{	goto iss;
								}
								else if(ch7=='n')
								{
									menu m;
									m.main_menu();
								}
								else
								{       gotoxy(15,20);
									cout<<"Please enter a valid option.";
									goto midway;
								}


							}
						}
					}
			}
		}
	}
}


/************************************************
Function to re-issue a book to a given member
************************************************/

void working::reissue()
{	iss:
	int i,j,card,num;
	char code[6],ch1,ch,ch2,ch3,ch7;
	book b;
	member memb;
	clrscr();
	gotoxy(60,1);
	cout<<"Enter 0 for Mainmenu";
	gotoxy(15,10);
	cout<<"Enter the code number of book to be re-issued:";
	cin>>code;

	if(code[0]=='0')
	{	menu m;
		m.main_menu();
	}

	else
	{	ch = b.book_found(code);
		if(ch=='n')
		{       gotoxy(20,12);
			cout<<"The book code is invalid.Please re-enter.";
			getch();
			goto iss;
		}
		else
		{       int rec=b.book_recno(code);
				fstream f;

				f.open("book.dat",ios::in);
				f.seekg((rec-1)*(sizeof (book)));
				f.read((char *) &b,sizeof (book));
			b.output(rec);
			gotoxy(15,24);
			cout<<"Press any key to continue.";
			getch();
			mem:
			clrscr();
			gotoxy(60,1);
			cout<<"Enter 0 for Mainmenu";
			gotoxy(15,8);
			cout<<"Enter the member code:";

			cin>>card;
			if(card==0)
			{	menu m;
				m.main_menu();
			}
			else
			{	ch1=memb.member_found(card);
				if(ch1=='n')
				{       gotoxy(15,10);
					cout<<"Please enter a valid card number.";
					getch();
					goto mem;
				}
				else
				{	ch2=memb.match(card,code);
					if(ch2=='n')
					{       gotoxy(15,10);
						cout<<"Sorry the card number and book code do not match.Please re-enter";
						ch3 = getch();
						if(ch3=='0')
						{	menu m;
							m.main_menu();
						}
						else
							goto iss;
					}
					else
					{       int late=memb.diff_dates(card);
						if(late<0)
						{	gotoxy(20,10);
							cout<<"It has not been 15 days since date of issue. ";
							gotoxy(30,12);
							cout<<"Book cannot be re-issued.";
							getch();
							menu m3;
							m3.main_menu();
						}
						int fine=2*late;
						gotoxy(10,12);
						cout<<"The book is late by "<<late<<" days and the fine due is Rs "<<fine;
						gotoxy(15,14);
						cout<<"The book has been re-issued to you.";
						memb.extend_date(card,code);

						midway:
						gotoxy(15,18);
						cout<<"Do you wish to continue?(y/n)";
						cin>>ch7;
						if(ch7=='y')
						{	goto iss;
						}
						else if(ch7=='n')
						{
							menu m;
							m.main_menu();
						}
						else
						{       gotoxy(15,20);
							cout<<"Please enter a valid option.";
							goto midway;
						}
														    }
					}
				}

		}
	}
}

/*****************************************************
Function to return a book issued to a given member
******************************************************/

void working::return_book()
{	iss:
	int i,j,card,num;
	char code[6],ch1,ch,ch2,ch3,ch7;
	book b;
	member memb;
	clrscr();
	gotoxy(60,1);
	cout<<"Enter 0 for Mainmenu";
	gotoxy(15,10);
	cout<<"Enter the code number of book to be returned:";
	cin>>code;

	if(code[0]=='0')
	{	menu m;
		m.main_menu();
	}

	else
	{	ch = b.book_found(code);
		if(ch=='n')
		{       gotoxy(20,12);
			cout<<"The book code is invalid.Please re-enter.";
			getch();
			goto iss;
		}
		else
		{       int rec=b.book_recno(code);
				fstream f;
				f.open("book.dat",ios::in);
				f.seekg((rec-1)*(sizeof (book)));
				f.read((char *) &b,sizeof (book));
			b.output(rec);
			gotoxy(15,24);
			cout<<"Press any key to continue.";
			getch();
			mem:
			clrscr();
			gotoxy(60,1);
			cout<<"Enter 0 for Mainmenu";
			gotoxy(15,8);
			cout<<"Enter the member code:";

			cin>>card;
			if(card==0)
			{	menu m;
				m.main_menu();
			}
			else
			{	ch1=memb.member_found(card);
				if(ch1=='n')
				{       gotoxy(15,10);
					cout<<"Please enter a valid card number.";
					getch();
					goto mem;
				}
				else
				{	ch2=memb.match(card,code);
					if(ch2=='n')
					{       gotoxy(15,10);
						cout<<"Sorry the card number and book code do not match.Please re-enter";
						ch3 = getch();
						if(ch3=='0')
						{	menu m;
							m.main_menu();
						}
						else
							goto iss;
					}
					else
					{       int late=memb.diff_dates(card);
						if(late<0)
						{	gotoxy(20,12);
							cout<<"It has not been 15 days since date of issue. ";
							gotoxy(30,14);
							cout<<"Book cannot be returned.";
							getch();
							menu m3;
							m3.main_menu();
						}
						int fine=2*late;
						gotoxy(10,14);
						cout<<"The book is late by "<<late<<" days and the fine due is Rs "<<fine;
						int n1=1;
						b.modify_status(code,n1);
						memb.set_date(card);
						midway:
						gotoxy(15,18);
						cout<<"Do you wish to continue?(y/n)";
						cin>>ch7;
						if(ch7=='y')
						{	goto iss;
						}
						else if(ch7=='n')
						{
							menu m;
							m.main_menu();
						 }
						 else
						 {       gotoxy(15,20);
							 cout<<"Please enter a valid option.";
							 goto midway;
						 }
					}
				}
			}
		}
	}
}

/**********************
Main Function
***********************/
void main()
{
	clrscr();

	menu m;
	m.password();
	getch();
}


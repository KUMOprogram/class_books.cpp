#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdbool.h>
using namespace std;

class Book
{
	private:
		string isbn;
		string title;
		string author;
		string subject;
		double price;
	public:
		Book(string xisbn,string xtitle,string xauthor,string xsubject,double xprice);
		void setisbn(string xisbn);
		void settitle(string xtitle);
		void setauthor(string xauthor);
		void setsubject(string xsubject);
		void setprice(double price);
		string getisbn();
		string gettitle();
		string getauthor();
		string getsubject();
		double getprice();
		_Bool find(string searcher);
		_Bool more_than(double target);
		_Bool less_than(double target);
		_Bool more_equal(double target);
		_Bool less_equal(double target);
		_Bool fullfind(string searcher, double target1, double target2);
};

Book::Book(string xisbn,string xtitle,string xauthor,string xsubject,double xprice)
{
	isbn=xisbn;
	title=xtitle;
	author=xauthor;
	subject=xsubject;
	price=xprice;
}

void Book::setisbn(string xisbn)
{
	isbn=xisbn; 
}

void Book::settitle(string xtitle)
{
	title=xtitle;
}

void Book::setauthor(string xauthor)
{
	author=xauthor;
}

void Book::setsubject(string xsubject)
{
	subject=xsubject;
}

void Book::setprice(double xprice)
{
	price=xprice;
}

string Book::getisbn()
{
	return isbn;
}

string Book::gettitle()
{
	return title;
}

string Book::getauthor()
{
	return author;
}

string Book::getsubject()
{
	return subject;
}

double Book::getprice()
{
	return price;
}

_Bool Book::find(string searcher)
{
	if (isbn.find(searcher)!=string::npos)
	{
		return 1;
	}else if (title.find(searcher)!=string::npos)
	{
		return 1;
	}else if (author.find(searcher)!=string::npos)
	{
		return 1;
	}else if (subject.find(searcher)!=string::npos)
	{
		return 1;
	}else{
		return 0;
	}
}

_Bool Book::more_than(double target)
{
    if (price>target)
	{
		return 1;
	}else{
		return 0;
	}
}

_Bool Book::less_than(double target)
{
    if (price<target)
	{
		return 1;
	}else{
		return 0;
	}
}

_Bool Book::more_equal(double target)
{
    if (price>=target)
	{
		return 1;
	}else{
		return 0;
	}
}

_Bool Book::less_equal(double target)
{
    if (price<=target)
	{
		return 1;
	}else{
		return 0;
	}
}

_Bool Book::fullfind(string searcher, double target1, double target2)
{
	if(find(searcher))
	{
		if((more_equal(target1))&&(less_equal(target2)))
		{
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}


void menu()
{
    system("cls");
    cout<<endl;
    cout<<" Add book ----------------------------------------- 1"<<endl;
    cout<<" Show books --------------------------------------- 2"<<endl;
	cout<<" Find books by keyword ---------------------------- 3"<<endl;
	cout<<" Find books by price (bigger) --------------------- 4"<<endl;
	cout<<" Find books by price (smaller) -------------------- 5"<<endl;
	cout<<" Find books by keyword && range of price ---------- 6"<<endl;
	cout<<" Close -------------------------------------------- 0"<<endl<<endl;
	cout<<" CHOICE: ";
}

vector <Book> bubblebeam(vector <Book> bubblebooks);
vector <Book> bubblegun(vector <Book> bubblebooks);

int main()
{
system("color f1");
	int choose, sum_books=0;
	string isbn, title, author, subject, searcher, CPPbug;
	double price, target;
	Book newbook(isbn, title, author, subject, price);
	vector <Book> mybooks;
				
	while(true)
	{
		menu();
		cin>>choose;
		cout<<endl;
		
		if (choose==1)
		{
			getline(cin,CPPbug);
			cout<<" --- BOOK "<<(sum_books+1)<<" ---"<<endl;

			cout<<" GIVE ISBN: ";
			getline(cin,isbn);
			newbook.setisbn(isbn);

			cout<<" GIVE TITLE: ";
			getline(cin,title);
			newbook.settitle(title);

			cout<<" GIVE AUTHOR: ";
			getline(cin,author);
			newbook.setauthor(author);

			cout<<" GIVE SUBJECT: ";
			getline(cin,subject);
			newbook.setsubject(subject);

			while(true)
			{
				cout<<" GIVE PRICE: ";
				cin>>price;
				if (price>=0)
				{
					break;
				}else{
					cout<<" @@@ ERROR: WRONG PRICE @@@"<<endl;
				}
			}
			newbook.setprice(price);

			mybooks.push_back(newbook);
			cout<<endl;
			
			++sum_books;
		}
		
		if (choose==2)
		{
			if (sum_books==0)
			{
				cout<<" NO BOOKS YET"<<endl<<endl;
			}else{
				for(int i=0; i<sum_books; ++i)
				{
			        cout<<" --- BOOK "<<(i+1)<<" ---"<<endl;
					cout<<" ISBN: "<<mybooks[i].getisbn()<<endl;
					cout<<" TITLE: "<<mybooks[i].gettitle()<<endl;
					cout<<" AUTHOR: "<<mybooks[i].getauthor()<<endl;
					cout<<" SUBJECT: "<<mybooks[i].getsubject()<<endl;
					cout<<" PRICE: "<<mybooks[i].getprice()<<endl<<endl;
				}
			}
		}
		
		if (choose==3)
		{
            getline(cin,CPPbug);
			cout<<" KEYWORD TO SEARCH: ";
			getline(cin,searcher);
			
			if (sum_books==0)
			{
				cout<<" NO BOOKS YET"<<endl<<endl;
			}else{
				int count=0;
				for(int i=0; i<sum_books; ++i)
				{
					if (mybooks[i].find(searcher))
					{
						cout<<" --- BOOK "<<(i+1)<<" ---"<<endl;
						cout<<" ISBN: "<<mybooks[i].getisbn()<<endl;
						cout<<" TITLE: "<<mybooks[i].gettitle()<<endl;
						cout<<" AUTHOR: "<<mybooks[i].getauthor()<<endl;
						cout<<" SUBJECT: "<<mybooks[i].getsubject()<<endl;
						cout<<" PRICE: "<<mybooks[i].getprice()<<endl<<endl;
						++count;
					}
				}
				if (count>0)
				{
					cout<<" "<<count<<" RESULT(S) FOUND"<<endl;
				}else{
					cout<<endl<<" NO RESULTS"<<endl;
				}
			}
			cout<<endl;
		}
		
		if (choose==4)
		{
			cout<<" PRICES BIGGER THAN: ";
			cin>>target;

			if (sum_books==0)
			{
				cout<<" NO BOOKS YET"<<endl<<endl;
			}else{
	
				vector <Book> bubblebooks=bubblebeam(mybooks);
				
				int count=0;
				for(int i=0; i<sum_books; ++i)
				{
					if (bubblebooks[i].more_than(target))
					{
						cout<<" --- BOOK "<<(i+1)<<" ---"<<endl;
						cout<<" ISBN: "<<bubblebooks[i].getisbn()<<endl;
						cout<<" TITLE: "<<bubblebooks[i].gettitle()<<endl;
						cout<<" AUTHOR: "<<bubblebooks[i].getauthor()<<endl;
						cout<<" SUBJECT: "<<bubblebooks[i].getsubject()<<endl;
						cout<<" PRICE: "<<bubblebooks[i].getprice()<<endl<<endl;
						++count;
					}
				}
				if (count>0)
				{
					cout<<" "<<count<<" RESULT(S) FOUND"<<endl;
				}else{
					cout<<endl<<" NO RESULTS"<<endl;
				}
			}
			cout<<endl;
		}
		
		if (choose==5)
		{
			cout<<" PRICES LESS THAN: ";
			cin>>target;

			if (sum_books==0)
			{
				cout<<" NO BOOKS YET"<<endl<<endl;
			}else{

				vector <Book> bubblebooks=bubblegun(mybooks);

				int count=0;
				for(int i=0; i<sum_books; ++i)
				{
					if (bubblebooks[i].less_than(target))
					{
						cout<<" --- BOOK "<<(i+1)<<" ---"<<endl;
						cout<<" ISBN: "<<bubblebooks[i].getisbn()<<endl;
						cout<<" TITLE: "<<bubblebooks[i].gettitle()<<endl;
						cout<<" AUTHOR: "<<bubblebooks[i].getauthor()<<endl;
						cout<<" SUBJECT: "<<bubblebooks[i].getsubject()<<endl;
						cout<<" PRICE: "<<bubblebooks[i].getprice()<<endl<<endl;
						++count;
					}
				}
				if (count>0)
				{
					cout<<" "<<count<<" RESULT(S) FOUND"<<endl;
				}else{
					cout<<endl<<" NO RESULTS"<<endl;
				}
			}
			cout<<endl;
		}
		
		if (choose==6)
		{
			double target1=0, target2=sum_books;
			
			if (sum_books==0)
			{
				cout<<" NO BOOKS YET"<<endl<<endl;
			}else{
                getline(cin,CPPbug);
				cout<<" KEYWORD TO SEARCH: ";
				getline(cin,searcher);

				while(true)
				{
					cout<<" PRICES BIGGER THAN: ";
					cin>>target1;
					if (target1>=0)
					{
						break;
					}else{
						cout<<" @@@ ERROR: WRONG PRICE @@@"<<endl;
					}
				}

				while(true)
				{
					cout<<" PRICES LESS THAN: ";
					cin>>target2;
					if (target2>=0)
					{
						break;
					}else{
						cout<<" @@@ ERROR: WRONG PRICE @@@"<<endl;
					}
				}
				cout<<endl;
				
				vector <Book> bubblebooks=bubblegun(mybooks);

				int count=0;
				for(int i=0; i<sum_books; ++i)
				{
					if (bubblebooks[i].fullfind(searcher,target1,target2))
					{
						cout<<" --- BOOK "<<(i+1)<<" ---"<<endl;
						cout<<" ISBN: "<<bubblebooks[i].getisbn()<<endl;
						cout<<" TITLE: "<<bubblebooks[i].gettitle()<<endl;
						cout<<" AUTHOR: "<<bubblebooks[i].getauthor()<<endl;
						cout<<" SUBJECT: "<<bubblebooks[i].getsubject()<<endl;
						cout<<" PRICE: "<<bubblebooks[i].getprice()<<endl<<endl;
						++count;
					}
				}
				if (count>0)
				{
					cout<<" "<<count<<" RESULT(S) FOUND"<<endl;
				}else{
					cout<<endl<<" NO RESULTS"<<endl;
				}
			}
			cout<<endl;
		}
		
		if (choose==0)
		{
			break;
		}
		
		if ((choose!=0)&&(choose!=1)&&(choose!=2)&&(choose!=3)&&(choose!=4)&&(choose!=5)&&(choose!=6))
		{
			cout<<" ERROR: WRONG CHOICE"<<endl;
		}
		
	system("pause");
	}
system("pause");
}

vector <Book> bubblebeam(vector <Book> bubblebooks)
{
    for(int i=0; i<bubblebooks.size(); ++i)
	{
		for(int j=bubblebooks.size()-1; j>i; --j)
		{
			if(bubblebooks[i].getprice()<bubblebooks[j].getprice())
			{
			        double c=bubblebooks[i].getprice();
			        bubblebooks[i].setprice(bubblebooks[j].getprice());
			        bubblebooks[j].setprice(c);
			
			        string c1=bubblebooks[i].getisbn();
			        bubblebooks[i].setisbn(bubblebooks[j].getisbn());
			        bubblebooks[j].setisbn(c1);
			
			        c1=bubblebooks[i].gettitle();
			        bubblebooks[i].settitle(bubblebooks[j].gettitle());
			        bubblebooks[j].settitle(c1);
			
			        c1=bubblebooks[i].getauthor();
			        bubblebooks[i].setauthor(bubblebooks[j].getauthor());
			        bubblebooks[j].setauthor(c1);
			
			        c1=bubblebooks[i].getsubject();
			        bubblebooks[i].setsubject(bubblebooks[j].getsubject());
			        bubblebooks[j].setsubject(c1);
			}
		}
	}
	return bubblebooks;
}

vector <Book> bubblegun(vector <Book> bubblebooks)
{
    for(int i=0; i<bubblebooks.size(); ++i)
	{
		for(int j=bubblebooks.size()-1; j>i; --j)
		{
			if(bubblebooks[i].getprice()>bubblebooks[j].getprice())
			{
		                double c=bubblebooks[i].getprice();
		                bubblebooks[i].setprice(bubblebooks[j].getprice());
		                bubblebooks[j].setprice(c);
		
		                string c1=bubblebooks[i].getisbn();
		                bubblebooks[i].setisbn(bubblebooks[j].getisbn());
		                bubblebooks[j].setisbn(c1);
		
		                c1=bubblebooks[i].gettitle();
		                bubblebooks[i].settitle(bubblebooks[j].gettitle());
		                bubblebooks[j].settitle(c1);
		
		                c1=bubblebooks[i].getauthor();
		                bubblebooks[i].setauthor(bubblebooks[j].getauthor());
		                bubblebooks[j].setauthor(c1);
		
		                c1=bubblebooks[i].getsubject();
		                bubblebooks[i].setsubject(bubblebooks[j].getsubject());
		                bubblebooks[j].setsubject(c1);
			}
		}
	}
	return bubblebooks;
}

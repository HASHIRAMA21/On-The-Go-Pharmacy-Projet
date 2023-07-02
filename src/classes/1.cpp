//
// Created by krohn on 5/2/23.
//


#include <iostream>
#include<winsock.h>
#include<windows.h>
#include<sstream>
#include<ctime>
#include<string>
#include<mysql.h>
#include<cstring>
#include<conio.h>
#include<cstring>
#include<map>

using namespace std;

int users =0;
int count_attempt=0;
int curr_user=0;
int user_no=0;
map <string,string> issued;
string loggedin_user="";

void showtime()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    cout<<dt;
    cout<<endl<<endl;
}
class user
{
private:
    string username;
    string password;
public:
    void adduser()
    {
        MYSQL *conn;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn ,"localhost" ,"root", "", "librarydb" ,0,NULL,0);
        if(conn)
            cout<<"connected"<<endl;
        else cout<<"not connected"<<endl;

        cout<<"Username:";
        cin>>username;
        cout<<"Password:";
        cin>>password;

        int qstate =0;
        stringstream ss;
        ss<<"INSERT INTO user(username,password) VALUES('"<<username<<"','"<<password<<"')";
        string query =  ss.str();
        const char* q= query.c_str();
        qstate = mysql_query(conn,q);
        if(qstate==0)
            cout<<"Record Inserted Succesfully ... "<<endl;
        else cout<<"Failed"<<endl;

        users++;
    }
    void no_users()
    {
        cout<<"The users are:  "<<endl;
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* res;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn ,"localhost" ,"root", "", "librarydb" ,0,NULL,0);
        if(conn)
        {
            int qstate = mysql_query(conn,"SELECT username FROM user");
            //    bool flag=false;
            if(!qstate)
            {
                res = mysql_store_result(conn);
                int i=1;
                while(row = mysql_fetch_row(res))
                {
                    cout<<i<<"."<<row[0]<<endl;
                    i++;
                }
            }
        }


    }
    void login()
    {
        if(curr_user==1)
        {
            cout<<"Already logged in";
            return;
        }
        if(count_attempt==2)
        {
            cout<<endl<<endl;
            cout<<"No more attempts";
            exit(0);
        }
        cout<<"Enter Credentials for Login (ID Password)"<<endl;
        string user_name;
        string pass_word;

        cout<<"Username:";
        cin>>user_name;
        cout<<"Password:";
        cin>>pass_word;
        cin.ignore();
        system("cls");


        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* res;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn ,"localhost" ,"root", "", "librarydb" ,0,NULL,0);
        if(conn)
        {
            int qstate = mysql_query(conn,"SELECT username,password FROM user");
            bool flag=false;
            if(!qstate)
            {
                res = mysql_store_result(conn);
                while(row = mysql_fetch_row(res))
                {
                    if(row[0]==user_name && row[1]==pass_word)
                    {
                        cout<<"Login Succesful"<<endl;
                        loggedin_user = row[0];
                        curr_user=1;
                        flag=true;
                        break;
                    }
                }
                if(!flag)
                {
                    cout<<"Try again"<<endl;
                    count_attempt++;
                    cin.ignore();
                    system("cls");
                    login();
                }


            }
            else
            {
                cout<<"No Accounts Registered";
            }

        }
    }

    void logout()
    {
        curr_user=0;
    }


};
class book : public user
{
    long long int bno;
    string bookname;
    string aname;
public:
    void addbook()
    {
        if(loggedin_user=="")
        {
            cout<<"Please Login"<<endl;
            return ;
        }

        cout<<"Enter book number \n";
        cin>>bno;
        cin.ignore();
        cout<<"Enter bookname: ";
        getline(cin,bookname);
        cin.ignore();
        cout<<"Enter author name :";
        getline(cin,aname);
        string nul="";
        MYSQL* conn;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn ,"localhost" ,"root", "", "librarydb" ,0,NULL,0);
        stringstream ss;
        ss<<"INSERT INTO book(BookNo,Book_Name,Author) VALUES('"<<bno<<"','"<<bookname<<"','"<<aname<<"')";
        int qstate=0;
        string query =  ss.str();
        const char* q= query.c_str();
        qstate = mysql_query(conn,q);
        if(qstate==0)
        {
            cout<<"Book Added Succesfully ... "<<endl;
            return;
        }
        else
        {
            cout<<"Failed"<<endl;
            return;
        }

    }

    bool searchbook(string no)
    {
        if(loggedin_user=="")
        {
            cout<<"Please Login"<<endl;
            return false;
        }

        bool flag=false;
        cout<<"No"<<"  "<<"Name"<<"  "<<"Author"<<"  "<<"Issued"<<endl;

        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* res;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn ,"localhost" ,"root", "", "librarydb" ,0,NULL,0);
        if(conn)
        {
            int qstate = mysql_query(conn,"SELECT BookNo,Book_Name,Author from book");
            if(!qstate)
            {
                res = mysql_store_result(conn);
                while(row = mysql_fetch_row(res))
                {
                    //     cout<<row[]<<endl;
                    if(row[0]== no)
                    {
                        cout<<row[0]<<"  "<<row[1]<<"   "<<row[2]<<endl;
                        cout<<"Book Found"<<endl;
                        flag=true;
                        return true;
                    }
                }
            }
            else cout<<"Failed"<<endl;
            if(!flag)
            {
                cout<<"Book Not Found"<<endl;
                return false;
            }
        }
    }
    void allbooks()
    {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* res;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn ,"localhost" ,"root", "", "librarydb" ,0,NULL,0);
        if(conn)
        {
            int qstate = mysql_query(conn,"SELECT BookNo,Book_Name,Author,Issued_By from book");
            cout<<"No"<<"  "<<"Name"<<"  "<<"Author"<<"Issued"<<endl;
            if(!qstate)
            {
                res = mysql_store_result(conn);
                while(row = mysql_fetch_row(res))
                {
                    cout<<row[0]<<"  "<<row[1]<<"  "<<row[2]<<"  "<<row[3]<<endl;
                }

            }
        }
        else cout<<"Failed"<<endl;
    }

    void issue()
    {
        if(loggedin_user=="")
        {
            cout<<"Please Login"<<endl;
            return ;
        }
        string bno;
        cout<<"Enter book number to be issued"<<endl;
        cin>>bno;
        bool found = searchbook(bno);
        if(found)
        {
            MYSQL* conn;
            MYSQL_ROW row;
            MYSQL_RES* res;
            conn = mysql_init(0);
            conn = mysql_real_connect(conn ,"localhost" ,"root", "", "librarydb" ,0,NULL,0);
            stringstream ss;
            int qstate=0;
            if(conn)
            {
                int qstate = mysql_query(conn,"SELECT BookNo,Book_Name,Author,Issued_By from book");
                cout<<"No"<<"  "<<"Name"<<"  "<<"Author"<<endl;
                if(!qstate)
                {
                    res = mysql_store_result(conn);
                    while(row = mysql_fetch_row(res))
                    {
                        if(bno==row[0] && row[3]=="")
                        {
                            if(row[3]==loggedin_user)
                                cout<<"You have already issued this book"<<endl;
                            ss<<"INSERT INTO book(Issued_By) VALUES('"<<loggedin_user<<"')";
                            string query =  ss.str();
                            const char* q= query.c_str();
                            qstate = mysql_query(conn,q);
                            if(qstate==0)
                                cout<<"Book Issued Succesfully ... "<<endl;
                            else cout<<"Failed"<<endl;
                            return;
                        }
                    }

                }


            }
        }
        else cout<<"Book Not Found"<<endl;

    }
    void deposit()
    {
        map<string ,string>::iterator itr;
        for(itr=issued.begin();itr!=issued.end();itr++)
        {
            if(itr->second==loggedin_user)
            {
                issued.erase(loggedin_user);
                cout<<"Book Deposited";
                return ;
            }
        }
    }
    void print_user()
    {
        map<string ,string>:: iterator itr;
        bool flag=false;
        for(itr=issued.begin();itr!=issued.end();itr++)
        {
            if(itr->second==loggedin_user )
            {
                cout<<"Current user is "<<itr->second<<"   has issued book no   : "<<itr->first;
                flag=true;

            }

        }
        if(!flag)
            cout<<loggedin_user<<" has issued no book";
        cout<<endl;
    }

};


int main()
{
    showtime();

    cout<<" \t \t \t \t \t Library Management System "<<endl<<endl<<endl<<endl;
    user u1;
    int x;
    int choice=0;

    book b1;
    do
    {
        cout<<endl;
        cout<<"Choose from the Following:"<<endl;
        cout<<"1. Login"<<endl;
        cout<<"2. Add user "<<endl;
        cout<<"3. Check no of users "<<endl;
        cout<<"4. Print users"<<endl;
        cout<<"5. Check current user details"<<endl;
        cout<<"6. Add Book"<<endl;
        cout<<"7. Search Book"<<endl;
        cout<<"8. All Books"<<endl;
        cout<<"9. Logout"<<endl;
        cout<<"10. Issue Book"<<endl;
        cout<<"11. Deposit Book"<<endl;
        cout<<"0 to exit"<<endl;
        cin>>x;
        string no2;
        switch(x)
        {
            case 1 : u1.login();
                break;
            case 2 : u1.adduser();
                u1.login();
                break;
            case 3 : cout<<users;
                break;
            case 4 : u1.no_users();
                break;
            case 5 : b1.print_user();
                break;
            case 6 : b1.addbook();
                break;
            case 7 : cout<<"Enter bno";
                cin>>no2;
                b1.searchbook(no2);
                break;
            case 8 : b1.allbooks();
                break;
            case 9 : u1.logout();
                break;
            case 10: b1.issue();
                break;
            case 11: b1.deposit();
                break;
            case 0 : choice=1;

        }
    }
    while(choice==0);

}
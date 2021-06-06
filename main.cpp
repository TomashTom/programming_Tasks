#include <iostream>
#include <fstream>
#include <string>

using  namespace std;
const int maxrow = 100;
string EmpName[maxrow] = {};
string EmpOwner[maxrow] = {};

string EmpID[maxrow] = {};





int option;
class Register{

public:
  string username = "123", password = "123";

};

class Goin{


public:
   string inpUsername,  inpPassword;

};





void OpenFile()
{
    string line;
    ifstream myfile("C:\\Users\\User\\Documents\\book.txt");
    if (myfile.is_open())
    {   int x = 0;
        while (getline(myfile, line))
        {
            int l = line.length();
            EmpID[x] = line.substr(0, 3);

            EmpOwner[x] =line.substr(4, 1 - 4);
            EmpName[x] =line.substr(1, 7  );
            x++;

        }

    }
    else
        {
        //cout<< "Enable to open the file!" <<endl;

    }

}





void Addbook()
{
 char name[50];
 char Book_Name[50];
 char ID[50];


 cin.ignore();
 cout << "ID:";
 cin.getline(ID, 500);
 cout << "Owner: ";
 cin.getline(Book_Name, 50);
 cout << "Book name:" ;
 cin.getline(name,50);










for (int x = 0; x < maxrow; x++ )
{
    if (EmpOwner[x] == "\0")
    {
        EmpOwner[x] = name;
        EmpName[x] = Book_Name;
        EmpID[x] = ID;


        break;

    }

}



}
void Listbook()
{
    system("cls");
    cout << "Current Record" <<endl;
    cout << "=======================================" <<endl;
    int counter = 0;
    cout <<"| No.| ID.| Owner.    | Book_Name."   <<     endl << "----------------------------------------------\n";
    for (int x = 0; x < maxrow; x++)
    {
        if (EmpOwner[x] != "\0")
        {
            counter++;
            cout <<"  "<<counter<<"  "<<EmpID[x]<<"   "<< EmpOwner[x]<<"       " <<EmpName[x]<< endl;
        }

      }

    if(counter == 0)
    {
        cout << "No Record found! "<<endl;
    }
    cout <<"-------------------------------------"<<endl;
}
void Searchbook(string search)
{
    system("CLS");
    cout<< "Current Records" <<endl;
    cout << "========================================"<<endl;

    for (int x = 0; x < maxrow; x++)

    {
        int counter = 0;
        if(EmpID[x] == search)
        {
            counter ++;
            cout <<"  "<<counter<<"  "<<EmpID[x]<<"   "<< EmpOwner[x]<<"         " <<EmpName[x]<< endl;
            break;

        }
    }int counter;
        if(counter == 0 )
        {
         cout <<"No Record found!"<<endl;
        }
    cout << "==========================================================="<<endl;
}
void Updatebooks(string search)
{
    char name[50];
    char Book_Name[50];
    char ID[500];
    int counter = 0;
    for (int x = 0; x < maxrow; x++)
    {
        if(EmpID[x] == search)

        {counter++;
        cout <<"Owner Name: ";
        cin.getline(name, 50);
        EmpOwner[x] = name;
        cout <<"Update Successfull"<<endl;

            cout <<"Book Name: ";
            cin.getline(Book_Name, 50);
            EmpName[x] = Book_Name;
            cout <<"Update Successfull"<<endl;
            break;
        }
    }
    if(counter == 0)
    {
        cout <<"ID Doesnt not exist!"<<endl;

    }


}
void Deletebooks(string search) {

    int counter = 0;
    for (int x = 0; x < maxrow; x++) {
        if (EmpID[x] == search) {
            counter++;
            EmpName[x] = "";
            EmpOwner[x] = "";
            EmpID[x] = "";

            cout << "Successfully Deleted! " << endl;
            break;


        }

        if (counter == 0) {
            cout << "ID Number does not exist!";

        }


    }
}

void SaveToFile()
{

    ofstream myfile;
    myfile.open("C:\\Users\\User\\hzzzzzzzzzzzzzzzzzzzzzzz\\book.txt");

    for (int x = 0 ; x < maxrow; x++)
    {
        if (EmpID[x] == "\0")
        {
            break;

        }
        else{

            myfile <<EmpID[x] + ", " + EmpName[x] + ", " + EmpOwner[x] <<endl;

        }

    }


}

int main ()
{





    Register newUser;

    cout << "Welcome Back please register " << endl;
    cout << "Enter your desired username: " << endl;
    cin >> newUser.username;
    cout << "Enter your desired password: " << endl;
    cin >> newUser.password;

    cout << "Successfully Register your account, Please login below.";


    Goin newLogin;

    cout << "Username: " << endl;
    cin >> newLogin.inpUsername;

    cout << "Password: " << endl;
    cin >> newLogin.inpPassword;

    if (newLogin.inpUsername == newUser.username && newLogin.inpPassword == newUser.password) {
        cout << "Successfully logged in, loading dashboard..." << endl;


    } else {
        cout << "Register Failed Please try again later!" << endl;

    }
    system("pause") ;






    int option;
    string empID;

    system("CLS");
    OpenFile();
    do { cout << "\t MENU \n";
        cout << "1 Add New Books" << endl;
        cout << "2 Update Books" << endl;
        cout << "3 Delete Books" << endl;
        cout << "4 Search Book" << endl;
        cout << "5 Display all Records" << endl;
        cout << "6 Exit and save to Textfile" << endl;
        cout << "============================ " << endl;
        cout << "Select option>>";
        cin >> option;

        switch (option) {
            case 1: {
                int i = 10;
                Addbook();
                system("CLS");
                break;
            }
            case 2:{
                int i = 20;
                cin.ignore();
                cout << "Search by ID >>";
                getline(cin, empID);
                Updatebooks(empID);
                system("CLS");
                break;
            }
            case 3:
                cin.ignore();
                cout << "Delete by ID >>";
                getline(cin, empID);
                Deletebooks(empID);
                cin.ignore();
                system("CLS");
                break;
            case 4:
                cin.ignore();
                cout << "Search by ID >>";
                getline(cin, empID);
                Searchbook(empID);
                break;
            case 5:
                Listbook();
                break;
                /*default:
                    break;
*/


        }


    } while (option != 6);

    SaveToFile();
    cout << "Exit.... Saving to file" <<endl;
    return 0;


}
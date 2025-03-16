#include <iostream>
#include <fstream>

using namespace std;

class shopping {
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

// Function to display menu
void shopping::menu() {
    int choice;
    string email, password;

    while (true) {
        cout << "\t\t\t\t____________________________________________\n";
        cout << "\t\t\t\t         Supermarket Main Menu              \n";
        cout << "\t\t\t\t____________________________________________\n";
        cout << "\t\t\t\t|  1) Administrator  |" << endl;
        cout << "\t\t\t\t|  2) Buyer         |" << endl;
        cout << "\t\t\t\t|  3) Exit          |" << endl;
        cout << "\t\t\t\t Please select: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\t\t\t Please Login!\n";
                cout << "\t\t\t Enter Email: ";
                cin >> email;
                cout << "\t\t\t Enter Password: ";
                cin >> password;

                if (email == "kanishkasharma2195@gmail.com" && password == "kanishka19") {
                    administrator();
                } else {
                    cout << "Invalid Email/Password!\n";
                }
                break;

            case 2:
                buyer();
                break;

            case 3:
                exit(0);
                break;

            default:
                cout << "Please select from the given options.\n";
        }
    }
}

// Administrator menu
void shopping::administrator() {
    int choice;
    while (true) {
        cout << "\n\n\n\t\t\t Administrator Menu  \n";
        cout << "\n\t\t\t|______1) Add Product_______|";
        cout << "\n\t\t\t|______2) Modify Product____|";
        cout << "\n\t\t\t|______3) Delete Product____|";
        cout << "\n\t\t\t|______4) Back to Main Menu_|";
        cout << "\n\n\t Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: add(); break;
            case 2: edit(); break;
            case 3: rem(); break;
            case 4: return;
            default: cout << "Invalid Choice!\n";
        }
    }
}

// Buyer menu
void shopping::buyer() {
    int choice;
    while (true) {
        cout << "\n\t\t\t   Buyer    \n";
        cout << "\t\t\t______________\n";
        cout << "\t\t\t 1) Buy Product\n";
        cout << "\t\t\t 2) Go Back\n";
        cout << "\t\t\t Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: receipt(); break;
            case 2: return;
            default: cout << "Invalid choice\n";
        }
    }
}

// Function to add a product
void shopping::add() {
    fstream data;
    int c, token = 0;
    float p, d;
    string n;

    cout << "\n\n\t\t\t Add new Product\n";
    cout << "\n\t Product code: ";
    cin >> pcode;
    cout << "\n\t Name of the Product: ";
    cin >> pname;
    cout << "\n\t Price of the Product: ";
    cin >> price;
    cout << "\n\t Discount on the Product: ";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (data) {
        data >> c >> n >> p >> d;
        while (!data.eof()) {
            if (c == pcode) {
                token = 1;
                break;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if (token == 1) {
        cout << "\nProduct with this code already exists!\n";
    } else {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
        cout << "\n\n\t\t Record Inserted!\n";
    }
}

// Function to edit a product
void shopping::edit() {
    fstream data, data1;
    int pkey, token = 0, c;
    float p, d;
    string n;

    cout << "\n\t\t\t Modify the Record\n";
    cout << "\n\t\t\t Enter Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\nFile does not exist!\n";
        return;
    }

    data1.open("database1.txt", ios::app | ios::out);
    data >> pcode >> pname >> price >> dis;
    while (!data.eof()) {
        if (pkey == pcode) {
            cout << "\n\t Enter new Product Code: ";
            cin >> c;
            cout << "\n\t Name of the Product: ";
            cin >> n;
            cout << "\n\t Price: ";
            cin >> p;
            cout << "\n\t Discount: ";
            cin >> d;
            data1 << c << " " << n << " " << p << " " << d << endl;
            token = 1;
        } else {
            data1 << pcode << " " << pname << " " << price << " " << dis << endl;
        }
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (token == 0) {
        cout << "\n\n Record not found!\n";
    } else {
        cout << "\n\n Record Edited!\n";
    }
}

// Function to delete a product
void shopping::rem() {
    fstream data, data1;
    int pkey, token = 0;

    cout << "\n\n\t Delete Product\n";
    cout << "\n\t Enter Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "File does not exist!\n";
        return;
    }

    data1.open("database1.txt", ios::app | ios::out);
    data >> pcode >> pname >> price >> dis;
    while (!data.eof()) {
        if (pcode == pkey) {
            cout << "\n\n Product deleted successfully!\n";
            token = 1;
        } else {
            data1 << pcode << " " << pname << " " << price << " " << dis << endl;
        }
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (token == 0) {
        cout << "\n\n Record not found!\n";
    }
}

// Function to list all products
void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\nProduct List:\n";
    cout << "ProNo\tName\tPrice\tDiscount\n";
    while (data >> pcode >> pname >> price >> dis) {
        cout << pcode << "\t" << pname << "\t" << price << "\t" << dis << endl;
    }
    data.close();
}
void shopping::receipt()
{
    m:
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEIPT"<<endl;
    data.open("database.txt",ios::in);
     if(!data)
     {
         cout<<"\n\n Empty database"<<endl;
     }
     else
     {
         data.close();
         list();
         cout<<"\n________________________________________\n";
         cout<<"\n|                                       \n";
         cout<<"\n       Please place the order           \n";
         cout<<"\n|                                       \n";
         cout<<"\n________________________________________\n";
             cout<<"\n\nEnter Product Code :"<<endl;
             cin>>arrc[c];
             cout<<"\n\n Enter the Product quantity :"<<endl;
             cin>>arrq[c];
             for(int i=0;i<c;i++)
             {
                 if(arrc[c]==arrc[i])
                 {
                     cout<<"\n\n Duplicate Product code.Please try again!"<<endl;
                     goto m;
                 }
             }
             c++;
             do {
             cout << "\n\n Do you want to buy another Product? If yes, press 'y'. To exit, press 'n'." << endl;
             cin >> choice;
             choice = tolower(choice); // Convert to lowercase to handle 'Y' input
    if (choice != 'y' && choice != 'n') {
        cout << "\nInvalid input! Please enter 'y' for yes or 'n' for no.\n";
    }
 } while (choice == 'y');

             //cout<<"\n\n Do you want to buy another Product? If yes then press y else no"<<endl;
             //cin>>choice;
         //} while(choice=='y');
         cout<<"\n\n\t\t\t_________________RECEIPT__________________\n";
         cout<<"\nProductNo\tProductQuantity\tPrice\tAmount\tAmount with Discount\n";
         for(int i=0;i<c;i++)
         {
             data.open("database.txt",ios::in);
             data>>pcode>>pname>>price>>dis;
             while(!data.eof())
             {
                 if(pcode==arrc[i])
                 {
                     amount=price*arrq[i];
                     dis=amount-(amount*dis/100);
                     total=total+dis;
                     cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t"<<price<<"\t"<<"\t\t"<<dis;
                 }
                 data>>pcode>>pname>>price>>dis;
             }
         }
         data.close();
     }
     cout<<"\n\n_____________________________________________________";
     cout<<"\n Total Amount : "<<total;
}

// Main function
int main() {
    shopping s;
    s.menu();
    return 0;
}

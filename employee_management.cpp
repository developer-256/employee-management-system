// username = qwe
// password = 123

#include <iostream>
#include <fstream>
using namespace std;

#define record_limit 100
string employees_data[record_limit][6]; // Global 2D array to store employee data
int rows = 0;                           // Global variable to keep track of current row

void import_data()
{
    employees_data[record_limit][6]; // initializing array in which we will import data

    ifstream file;                             // it must be ifstream not fstream
    file.open("Employees_data.txt", ios::app); // set file name and ios::app will not overwrite file while writing it again

    rows = 0;               // declaring rows
    while (file.eof() == 0) // reading file till end of file
    {
        string temp_row = "";
        getline(file, temp_row); // take line 1 of file as input in temp_row
        if (temp_row == "")      // if it is empty row you will skip to next row
        {
            rows++;
            continue;
        }
        int column = 0;
        string temp_col = "";
        for (int j = 0; j < temp_row.length(); j++) // breaking row that we input into different values
        {
            if (temp_row[j] != ',') // if , does not occur keep adding character in temp_row
            {
                temp_col += temp_row[j];
            }
            else // if , occur save temp_row into 2D array
            {
                employees_data[rows][column] = temp_col;
                temp_col = ""; // empty temp_col
                column++;
            }
        }
        rows++;
    }
    file.close(); // closing file
}

bool admin_auth();
void enter_data();
void show_employed_data();
void show_Unemployed_data();
void show_All_data();
void update_specific_data();
void set_unemployed();
void update_txt_file();

int main()
{
    while (admin_auth() == false)
    {
        cout << "Invalid Username or password\n";
        system("cls");
    }

    int choice;
    do
    {
        cin.clear();
        fflush(stdin);

        cout << "________________________________\n";
        cout << "| Choose one of the following:   |\n";
        cout << "**********************************\n";
        cout << "| 1: Register new employee       |\n";
        cout << "| 2: Show All Employeed Data     |\n";
        cout << "| 3: Show All Unemployeed Data   |\n";
        cout << "| 4: Show All Data               |\n";
        cout << "| 5: Update Employee's data      |\n";
        cout << "| 6: Mark Employee as Unemployed |\n";
        cout << "| 7: Exit                        |\n";
        cout << "**********************************\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            enter_data();
            break;

        case 2:
            system("cls");
            show_employed_data();
            break;
        case 3:
            system("cls");
            show_Unemployed_data();
            break;

        case 4:
            system("cls");
            show_All_data();
            break;

        case 5:
            system("cls");
            update_specific_data();
            break;

        case 6:
            system("cls");
            set_unemployed();
            break;

        case 7:
            system("cls");
            cout << "Thanks for using our software\n";
            break;

        default:
            system("cls");
            cout << "Invalid Input\n";
        }
    } while (choice != 7);
}

bool admin_auth()
{
    string user, pass;

    cout << "Enter your Username: ";
    cin >> user;

    cout << "Enter password: ";
    cin >> pass;

    return (user == "qwe" && pass == "123");
}

void enter_data()
{
    string name, ID, address, contact, salary, status = "employed";
    cout << "Enter name: ";
    getline(cin >> ws, name);
    cout << "Enter ID: ";
    getline(cin >> ws, ID);
    cout << "Enter Address: ";
    getline(cin >> ws, address);
    cout << "Enter Contact: ";
    getline(cin >> ws, contact);
    cout << "Enter salary: ";
    getline(cin >> ws, salary);

    ofstream file;
    file.open("Employees_data.txt", ios::app); // Open the file in append mode
    file << endl
         << status << "," << name << "," << ID << "," << address << "," << contact << "," << salary << ",";
    file.close();
}

void show_employed_data()
{
    import_data();
    for (int i = 0, j = 0; i < rows; i++)
    {
        if (employees_data[i][j] == "employed")
        {
            cout << "Status: " << employees_data[i][0] << endl;
            cout << "Name: " << employees_data[i][1] << endl;
            cout << "ID: " << employees_data[i][2] << endl;
            cout << "Address: " << employees_data[i][3] << endl;
            cout << "Contact: " << employees_data[i][4] << endl;
            cout << "Salary: " << employees_data[i][5] << endl
                 << endl;
        }
    }
}
void show_Unemployed_data()
{
    import_data();
    for (int i = 0, j = 0; i < rows; i++)
    {
        if (employees_data[i][j] == "unemployed")
        {
            cout << "Status: " << employees_data[i][0] << endl;
            cout << "Name: " << employees_data[i][1] << endl;
            cout << "ID: " << employees_data[i][2] << endl;
            cout << "Address: " << employees_data[i][3] << endl;
            cout << "Contact: " << employees_data[i][4] << endl;
            cout << "Salary: " << employees_data[i][5] << endl
                 << endl;
        }
    }
}

void show_All_data()
{
    import_data();
    for (int i = 0; i < rows; i++)
    {
        cout << "Status: " << employees_data[i][0] << endl;
        cout << "Name: " << employees_data[i][1] << endl;
        cout << "ID: " << employees_data[i][2] << endl;
        cout << "Address: " << employees_data[i][3] << endl;
        cout << "Contact: " << employees_data[i][4] << endl;
        cout << "Salary: " << employees_data[i][5] << endl
             << endl;
    }
}

void update_specific_data()
{
    import_data();
    string id;
    cout << "Enter the employee id: ";
    cin >> id;
    for (int i = 0, j = 2; i < rows; i++)
    {
        if (employees_data[i][j] == id)
        {
            string name, ID, address, contact, salary, status = "employed";
            cout << "Enter name: ";
            getline(cin >> ws, name);
            cout << "Enter ID: ";
            getline(cin >> ws, ID);
            cout << "Enter Address: ";
            getline(cin >> ws, address);
            cout << "Enter Contact: ";
            getline(cin >> ws, contact);
            cout << "Enter salary: ";
            getline(cin >> ws, salary);
            employees_data[i][0] = status;
            employees_data[i][1] = name;
            employees_data[i][2] = ID;
            employees_data[i][3] = address;
            employees_data[i][4] = contact;
            employees_data[i][5] = salary;
            update_txt_file();
            return;
        }
    }
}

void set_unemployed()
{
    import_data();
    string id;
    cout << "Enter the employee id: ";
    cin >> id;
    for (int i = 0; i < rows; i++)
    {
        if (employees_data[i][2] == id)
        {
            employees_data[i][0] = "unemployed";
            update_txt_file();
            return;
        }
    }
}

void update_txt_file()
{
    ofstream file;
    file.open("Employees_data.txt");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            file << employees_data[i][j] << ',';
        }
        if (i < rows - 1) // if we dont do this after last row, an empty row will be added
        {
            file << endl;
        }
    }
    file.close();
}
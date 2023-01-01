#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <mysql.h>

struct CONNECTION
{
    const char *server = "localhost";
    const char *user = "root";
    const char *password = "password";
    const char *database = "project";
};

static MYSQL *connection;

MYSQL *connection_to_database(CONNECTION connection)
{
    MYSQL *newConnection = mysql_init(NULL);
    if (!newConnection)
    {
        std::cout << "Failed to create an object" << std::endl;
        std::cout << mysql_error(newConnection) << std::endl;
        exit(0);
    }
    if (!mysql_real_connect(newConnection, connection.server, connection.user,
                            connection.password, connection.database, 3306, NULL, 0))
    {
        std::cout << "Failed to connect to database:" << std::endl;
        std::cout << mysql_error(newConnection) << std::endl;
        exit(0);
    }
    return newConnection;
}

MYSQL_RES *execute_query(MYSQL *connection, const std::string query)
{
    if (mysql_query(connection, query.c_str()))
    {
        std::cout << "MYSQL query error:\n"
                  << mysql_error(connection) << std::endl;
        exit(0);
    }
    return mysql_store_result(connection);
}

std::string takePassword()
{
    std::string password;
    while (true)
    {
        char input = getch();
        if (input == 13)
        {
            std::cout << std::endl;
            break;
        }
        else if (input == 8 and password.length() != 0)
        {
            password.pop_back();
            std::cout << "\b \b";
            continue;
        }
        else if (input == 8 and password.length() == 0)
        {
            continue;
        }
        password.push_back(input);
        std::cout << "*";
    }
    return password;
}

void showInfo(const MYSQL_ROW &row)
{
    std::cout << "First Name: " << row[2] << std::endl;
    std::cout << "Last Name: " << row[3] << std::endl;
    std::string birthDate = row[4];
    birthDate = birthDate.substr(8, 2) + "." + birthDate.substr(5, 2) + "." + birthDate.substr(0, 4);
    std::cout << "Date of Birth: " << birthDate << std::endl;
    std::cout << "Email address: " << row[0] << std::endl;
    std::cout << "Password: " << row[1] << std::endl;
    std::cout << "GPA: " << row[7] << std::endl;
    std::cout << "Monthly scholarship: " << row[8] << std::endl;
    std::cout << "Student of " << row[6] << " year" << std::endl;
}

void updateStudent(const std::string &email)
{
    std::cout << "[1] Email address\n[2] Password\n";
    int opt;
    std::cin >> opt;
    if (opt == 1)
    {
        std::cout << "Enter a new email:" << std::endl;
        std::string newEmail;
        std::cin >> newEmail;
        std::cout << "Do you want to save changes? {1} - yes, {0} - no" << std::endl;
        int approve;
        std::cin >> approve;
        if (approve)
        {
            execute_query(connection, "UPDATE students SET email = '" + newEmail + "' " + "WHERE email = '" + email + "';");
            std::cout << "Updated successfully!" << std::endl;
        }
    }
    else
    {
        std::cout << "Enter a new password:" << std::endl;
        std::string newPassword;
        std::cin >> newPassword;
        std::cout << "Do you want to save changes? {1} - yes, {0} - no" << std::endl;
        int approve;
        std::cin >> approve;
        if (approve)
        {
            execute_query(connection, "UPDATE students SET password = '" + newPassword + "' " + "WHERE email = '" + email + "';");
            std::cout << "Updated successfully!" << std::endl;
        }
    }
}

void showStudents()
{
    MYSQL_RES *res = execute_query(connection, "SELECT * FROM students");
    MYSQL_ROW row;
    int k = 1;
    while ((row = mysql_fetch_row(res)))
    {
        std::cout << k << ". ";
        for (int i = 2; i < mysql_num_fields(res); i++)
        {
            std::cout << row[i] << ' ';
        }
        std::cout << "Email address: " << row[0] << std::endl;
        k++;
    }
}

void deleteStudent()
{
    while (true)
    {
        std::string email;
        system("cls");
        std::cout << "Enter student's email address:" << std::endl;
        std::cin >> email;
        execute_query(connection, "DELETE FROM students WHERE email = '" + email + "';");
        std::cout << "Deleted successfully!" << std::endl;
        std::cout << "Would you like to proceed? [1] - yes, [0] - no" << std::endl;
        int proceed;
        std::cin >> proceed;
        if (!proceed)
        {
            break;
        }
    }
}

void updateAdministrator()
{
    system("cls");
    std::cout << "Enter student's email address:" << std::endl;
    std::cout << "Enter 's' to see the list of students" << std::endl;
    char c;
    std::cin >> c;
    if (c == 's')
    {
        showStudents();
    }
    std::string email;
    std::cin >> email;
    while (true)
    {
        std::cout << "Select what you want to update:" << std::endl;
        std::cout << "[1] GPA\n[2] Monthly scholarship\n";
        int upd;
        std::cin >> upd;
        if (upd == 1)
        {
            std::cout << "Enter student's new GPA:" << std::endl;
            std::string newGpa;
            std::cin >> newGpa;
            execute_query(connection, "UPDATE students SET gpa = " + newGpa + " WHERE email = '" + email + "';");
        }
        else
        {
            std::cout << "Enter student's new scholarship:" << std::endl;
            std::string newScholarship;
            std::cin >> newScholarship;
            execute_query(connection, "UPDATE students SET scholarship = " + newScholarship + " WHERE email = '" + email + "';");
        }
        std::cout << "Updated successfully! Do you want to proceed updating? [1] - yes, [0] - no" << std::endl;
        int proceed;
        std::cin >> proceed;
        if (!proceed)
        {
            break;
        }
    }
}

void login()
{
    system("cls");
    MYSQL_RES *res;
    std::string email;
    while (true)
    {
        std::cout << "PLEASE ENTER YOUR EMAIL:" << std::endl;
        std::cin >> email;
        std::cout << "PLEASE ENTER YOUR PASSWORD:" << std::endl;
        std::string password = takePassword();
        res = execute_query(connection, "SELECT * FROM students WHERE email = '" + email + "' AND password = '" + password + "';");
        if (!mysql_affected_rows(connection))
        {
            system("cls");
            std::cout << "Your email address or password is incorrect. Please try again" << std::endl;
        }
        else
        {
            break;
        }
    }
    system("cls");
    MYSQL_ROW row = mysql_fetch_row(res);
    std::cout << ("\t\t\tLogged in successfully!\n\t\t\t Welcome " + (std::string)row[2] + " " + row[3] + "!") << std::endl;
    std::cout << std::endl;
    showInfo(row);
    while (true)
    {
        std::cout << "Exit[0]\nUpdate info[1]\n";
        int exit;
        std::cin >> exit;
        if (!exit)
        {
            break;
        }
        else
        {
            updateStudent(email);
        }
    }
}

void signup()
{
    system("cls");
    std::cout << "------>>>>>     WELCOME     <<<<<-----" << std::endl;
    std::string name;
    std::string surname;
    std::string birthday;
    int year;
    while (true)
    {
        std::cout << "Please enter your first name: " << std::endl;
        std::cin >> name;
        std::cout << "Please enter your last name: " << std::endl;
        std::cin >> surname;
        std::cout << "Please enter your birth date in yyyy-mm-dd format:" << std::endl;
        std::cin >> birthday;
        std::cout << "Please enter the year when you enrolled to the university:" << std::endl;
        std::cin >> year;
        std::cout << "Would you like to save changes? {1} - yes, {0} - no" << std::endl;
        int temp;
        std::cin >> temp;
        if (temp)
        {
            break;
        }
    }
    MYSQL_RES *res;
    system("cls");
    std::string email;
    while (true)
    {
        std::cout << "Please enter an email:" << std::endl;
        std::cin >> email;
        res = execute_query(connection, "SELECT * FROM students WHERE email = '" + email + "';");
        if (mysql_affected_rows(connection))
        {
            system("cls");
            std::cout << "This email already exists. Please choose a different email address" << std::endl;
        }
        else
        {
            break;
        }
    }
    std::cout << "Please enter a new password:" << std::endl;
    std::string password;
    std::cin >> password;
    system("cls");
    execute_query(connection, "INSERT INTO students(email, password, name, surname, birthDate, enrolled_year) VALUES('" + email + "','" + password + "','" + name + "','" + surname + "','" + birthday + "'," + std::to_string(year) + ");");
    std::cout << "Successfully signed up! Would you like to log in?\n[1] - yes\n[0] - no" << std::endl;
    int proceed;
    std::cin >> proceed;
    if (proceed)
    {
        login();
    }
    else
    {
        system("cls");
    }
}

int main()
{
    CONNECTION id;
    connection = connection_to_database(id);

    while (true)
    {
        system("cls");
        std::cout << "----- SIGN IN [1] / SIGN UP [2] / RUN AS ADMINISTRATOR [3] -----" << std::endl;
        int opt;

        std::cin >> opt;
        switch (opt)
        {
        case 1:
            login();
            break;

        case 2:
            signup();
            break;
        case 3:
            std::cout << "Show all students[0]\nUpdate student's info[1]\nDelete a student from database[2]\n";
            int choose;
            std::cin >> choose;
            switch (choose)
            {
            case 0:
                showStudents();
                break;
            case 1:
                updateAdministrator();
                break;
            case 2:
                deleteStudent();
                break;
            }
            break;
        }
        std::cout << "\n########### EXIT THE PROGRAM? [1] YES / [0] NO ##############" << std::endl;
        int exit;
        std::cin >> exit;
        if (exit)
        {
            break;
        }
    }
}

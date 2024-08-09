#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

class Student
{
    private:
        string name ,roll_no,course,address,email_id,contact_no;
    public:
       void menu();
       void insert();
       void display();
       void modify();
       void search();
       void deleted();

};

void Student :: menu()
{
    menustart:
    int choice;
    char x;
    system("cls");

    cout<<"---------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"|                                              STUDENT MANEGEMENT SYSTEM                                                  |\n";
    cout<<"---------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\t 1. Enter New Record "<<endl;
    cout<<"\t 2. Display Record "<<endl;
    cout<<"\t 3. Modify Record "<<endl; 
    cout<<"\t 4. Search Record "<<endl;
    cout<<"\t 5. Delete Record "<<endl;
    cout<<"\t 6. Exit"<<endl;

    cout<<"---------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"|                                            Choose Option : [1/2/3/4/5/6]                                                |\n";
    cout<<"---------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Enter your choose : ";
    cin>>choice;

    switch (choice)
    {
    case 1:
    do
    {
        insert();
        cout<<"\n Add another student record (Y,N) : ";
        cin>>x;
    }while(x == 'y' || x =='Y');
        break;

    case 2:
    {
        display();
        break;
    }
     case 3:
    {
        modify();
        break;
    }
     case 4:
    {
        search();
        break;
    }
     case 5:
    {
        deleted();
        break;
    }
    case 6:
        exit(0);
    default:
        cout<<"\n Invalid choice........ Please try again....\n";
        break;
    }
    getch();
   goto menustart;
}

void Student :: insert()
{
    system("cls");
    fstream file;
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\n---------------------------------------------------- Add Student details ------------------------------------------------\n";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\t Enter Name: ";
    cin>>name;
    cout<<"\t Enter Roll_no: ";
    cin>>roll_no;
    cout<<"\t Enter Course: ";
    cin>>course;
    cout<<"\t Enter Email Id: ";
    cin>>email_id;
    cout<<"\t Enter Address: ";
    cin>>address;
    cout<<"\t Enter Contact_no: ";
    cin>>contact_no;
    file.open("StudentData.txt", ios :: app | ios :: out);
    file<<" "<< name <<" "<< roll_no <<" "<< course <<" "<< email_id <<" "<< address <<" "<< contact_no <<"\n";
    file.close();
}

void Student :: display()
{
    system("cls");
    fstream file;
    int total=1;
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\n---------------------------------------------------- Student Record Table -----------------------------------------------\n";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------\n";
    file.open("StudentData.txt", ios :: in);
    if (!file)
    {
        /* code */
        cout<<"\n\t No Data Is Present....";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> address >> contact_no; 
        while (!file.eof())
        {
            cout<<"\n\t Student No. : "<< total++ <<endl;
            cout<<"\t Student Name : "<< name <<endl;
            cout<<"\t Student Roll No. : "<< roll_no <<endl;
            cout<<"\t Student Course : "<< course <<endl;
            cout<<"\t Student Email Id : "<< email_id <<endl;
            cout<<"\t Student Address : "<< address <<endl;
            cout<<"\t Student Contact No. : "<< contact_no <<endl;
            file >> name >> roll_no >> course >> email_id >> address >> contact_no; 
        }
        if (total == 0)
        {
            /* code */
            cout<<"\n\t No Data Is Present....";
        }    
    }
    file.close();
}

void Student :: modify()
{
    system("cls");
    fstream file,file1;
    int found=0;
    string rollno;
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\n--------------------------------------------------- Student Modify Details ----------------------------------------------\n";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------\n";
    file.open("StudentData.txt", ios :: in);
    if (!file)
    {
        /* code */
        cout<<"\n\t No Data Is Present....";
        file.close();
    }
    else
    {
        cout<<"\n Enter Roll No. of student which you want to modify : ";
        cin>>rollno;
        file1.open("Data.txt", ios :: app | ios :: out);
        file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                /* code */
                file1<<" "<< name <<" "<< roll_no <<" "<< course <<" "<< email_id <<" "<< address <<" "<< contact_no <<"\n";
            }
            else
            {
                 cout<<"\t Enter Name: ";
                 cin>>name;
                 cout<<"\t Enter Roll_no: ";
                 cin>>roll_no;
                 cout<<"\t Enter Course: ";
                 cin>>course;
                 cout<<"\t Enter Email Id: ";
                 cin>>email_id;
                 cout<<"\t Enter Address: ";
                 cin>>address;
                 cout<<"\t Enter Contact_no: ";
                 cin>>contact_no;
                 file1<<" "<< name <<" "<< roll_no <<" "<< course <<" "<< email_id <<" "<< address <<" "<< contact_no <<"\n";
                 found++;
            }
        file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        if (found == 0)
        {
            cout<<"\n\t Student Roll No. Not Found......";
        }                  
        }
        file1.close();
        file.close();
        remove("StudentData.txt");
        rename("Data.txt","StudentData.txt");
    }
}

void Student :: search()
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("StudentData.txt", ios :: in);
    if (!file)
    {
        /* code */
        cout<<"\n---------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\n----------------------------------------------- Student Search Data -------------------------------------------------\n";
        cout<<"\n---------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\n\t No Data Is Present....";
    }
    else
    {
        string rollno;
        cout<<"\n---------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\n----------------------------------------------- Student Search Data -------------------------------------------------\n";
        cout<<"\n--------------------------------------------------------------------------------------------------------- -----------\n";
        cout<<"\n Enter Roll No. of student which you want to search : ";
        cin>>rollno;
        file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout<<"\t Student Name : "<< name <<endl;
                cout<<"\t Student Roll No. : "<< roll_no <<endl;
                cout<<"\t Student Course : "<< course <<endl;
                cout<<"\t Student Email Id : "<< email_id <<endl;
                cout<<"\t Student Address : "<< address <<endl;
                cout<<"\t Student Contact No. : "<< contact_no <<endl;
                found++;
            }
        file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        }
        if (found == 0)
        {
            cout<<"\n\t Student Roll No. Not Found......";
        }                  
    file.close();
    }
}

void Student :: deleted()
{
    system("cls");
    fstream file,file1;
    string rollno;
    int found = 0;
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\n----------------------------------------------- Delete Student Details --------------------------------------------------\n";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------\n";
    file.open("StudentData.txt", ios :: in);
    if (!file)
    {
        /* code */
        cout<<"\n\t No Data Is Present....";
        file.close();
    }
    else
    {
        cout<<"\n Enter Roll No. of student which you want to delete data : ";
        cin>>rollno;
        file1.open("Data.txt", ios :: app | ios :: out);
        file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                /* code */
                file1 <<" "<< name <<" "<< roll_no <<" "<< course <<" "<< email_id <<" "<< address <<" "<< contact_no <<"\n";
            }
            file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        }
        if(found == 0)
        {
            cout<<"\n\t Student Roll No. Not Found......";                  
        }
        file1.close();
        file.close();
        remove("StudentData.txt");
        rename("Data.txt","StudentData.txt"); 
    }
    
}

int main()
{
    Student project;
    project.menu();
    return 0;
}
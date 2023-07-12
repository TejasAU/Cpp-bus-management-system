#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Student
{
protected:
    long long int prn;
    int fees_per_sem;

public:
    void get_data_student()
    {
        cout << "Enter prn of the student: ";
        cin >> prn;
        cout << "Enter fees of the student: ";
        cin >> fees_per_sem;
    }

    void display_data_student()
    {
        cout << "\nPRN of the student is " << prn << endl;
        cout << "Fees of the student is " << fees_per_sem << endl;
    }
};

class Staff
{
protected:
    long long int emp_id;
    int fees_per_sem;

public:
    void get_data_staff()
    {
        cout << "Enter employee id of the staff: ";
        cin >> emp_id;
        cout << "Enter fees of the staff: ";
        cin >> fees_per_sem;
    }

    void display_data_staff()
    {
        cout << "\nEmployee id of the staff is " << emp_id << endl;
        cout << "Fees of the staff is " << fees_per_sem << endl;
    }
};

class members : public Student, public Staff
{
protected:
    string surname;
    long long int contact;
    string email;

public:
    string institute;
    string obj_status;
    string name;
    void get_data()
    {
        cout << "\nEnter details of the new members:";

    status_check:
        cout << "\nWhat do you want to enter student or staff (enter in lower case)? ";
        cin >> obj_status;

        if (obj_status != "student" && obj_status != "staff")
        {
            cout << "\nEnter valid input";
            goto status_check;
        }

        if (obj_status == "student")
        {
            cout << "\nEnter name of the student: ";
            cin >> name;
            cout << "Enter surname of the student: ";
            cin >> surname;
            cout << "\nEnter E-mail of the student: ";
            cin >> email;
        institute_check1:
            cout << "\nEnter institute name of the student (SIT/SSCA/SSBS/SSODL/SCEW/SCON/SMCW/SUHRC/OTHER) in UPPER case: ";
            cin >> institute;

            if (institute != "SIT" && institute != "SSBS" && institute != "SSCA" && institute != "SSODL" && institute != "SCEW" && institute != "SCON" && institute != "SMCW" && institute != "SUHRC" && institute != "OTHER")
            {
                cout << "Invalid Input! System accepts only accepts the following inputs SIT/SSCA/SSBS/SSODL/SCEW/SCON/SMCW/SUHRC/OTHER! Re-enter choice\n";
                goto institute_check1;
            }

            get_data_student();

        check_contact1:
            cout << "\nEnter contact of the student: ";
            cin >> contact;
            if ((contact < 1000000000) || (contact > 9999999999))
            {
                cout << "Mobile number must be 10 digits! Re-enter mobile number!\n";
                goto check_contact1;
            }
        }

        if (obj_status == "staff")
        {
            cout << "\nEnter name of the staff: ";
            cin >> name;
            cout << "Enter surname of the staff: ";
            cin >> surname;
            cout << "\nEnter E-mail of the staff: ";
            cin >> email;
        institute_check2:
            cout << "\nEnter institute name of the staff (SIT/SSCA/SSBS/SSODL/SCEW/SCON/SMCW/SUHRC/OTHER) in UPPER case: ";
            cin >> institute;

            if (institute != "SIT" && institute != "SSBS" && institute != "SSCA" && institute != "SSODL" && institute != "SCEW" && institute != "SCON" && institute != "SMCW" && institute != "SUHRC" && institute != "OTHER")
            {
                cout << "Invalid Input! System accepts only accepts the following inputs SIT/SSCA/SSBS/SSODL/SCEW/SCON/SMCW/SUHRC/OTHER! Re-enter choice\n";
                goto institute_check2;
            }
            get_data_staff();

        check_contact2:
            cout << "\nEnter contact of the staff: ";
            cin >> contact;
            if ((contact < 1000000000) || (contact > 9999999999))
            {
                cout << "Mobile number must be 10 digits! Re-enter mobile number!\n";
                goto check_contact2;
            }
        }
    }

    void display_data()
    {

        cout << "\n\t\t*********DETAILS OF NEW MEMBER**********" << endl;
        if (obj_status == "student")
        {
            cout << "\n***DETAILS OF THE STUDENT***" << endl;
            cout << "Name of student is " << name << " " << surname << endl;
            cout << "Email of the student is " << email << endl;
            cout << "Institute of the student is " << institute << endl;
            display_data_student();
            cout << "contact of the student is " << contact << endl;
        }
        if (obj_status == "staff")
        {
            cout << "\n***DETAILS OF THE STAFF***" << endl;
            cout << "Name of staff is " << name << " " << surname << endl;
            cout << "Email of the staff is " << email << endl;
            cout << "Institute of the staff is " << institute << endl;
            display_data_staff();
            cout << "Contact of the staff is " << contact << endl;
        }
    }
};

class Nodemembers
{
public:
    members obj;
    Nodemembers *next;
};

class memberslinked
{
    Nodemembers *head;
    Nodemembers **head_ref;
    friend class Nodemembers;

public:
    memberslinked()
    {
        head = NULL;
        head_ref = &head;
    }
    void pushMember(int num);
    void printMemberList();
    void del(int position);
    int searchMember(string str);
    void SearchAndDisplayMember();
    void deleteMember();
};

void memberslinked::pushMember(int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        Nodemembers *new_node = new Nodemembers;

        new_node->obj.get_data();

        new_node->next = (*head_ref);

        (*head_ref) = new_node;
    }
}

void memberslinked::printMemberList()
{
    Nodemembers *node = head;
    cout << "Name of member:                Designation:                Institute:" << endl;
    while (node != NULL)
    {
        cout << node->obj.name << "                    " << node->obj.obj_status << "                    " << node->obj.institute << endl;
        node = node->next;
    }
}

void memberslinked::del(int position)
{

    if (*head_ref == NULL)
        return;

    Nodemembers *temp = *head_ref;

    if (position == 0)
    {

        *head_ref = temp->next;

        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    Nodemembers *next = temp->next->next;

    free(temp->next);

    temp->next = next;
}

int memberslinked::searchMember(string str)
{
    int position = 0;
    Nodemembers *tmp = *head_ref;
    while (tmp != NULL)
    {
        if (tmp->obj.name == str)
        {
            return position;
        }
        position++;
        tmp = tmp->next;
    }
    position = -1;
    return position;
}

void memberslinked::SearchAndDisplayMember()
{
    cout << "SEARCH MEMBER BY NAME & DISPLAY!" << endl;
    cout << "------------------------------------------<<endl";
    string search;
    int pos, i;
    cout << "Enter the name of member whose details you wish to search &display: ";
    cin >> search;
    pos = searchMember(search);
    Nodemembers *tmp = *head_ref;
    if (pos == -1)
    {
        cout << "The member you wish to search is not in data base!";
        return;
    }
    else
    {
        for (i = 0; i < pos; i++)
        {
            tmp = tmp->next;
        }
        cout << "The member details you wish to access are:" << endl;
        tmp->obj.display_data();
    }
}

void memberslinked::deleteMember()
{
    int pos, i;
    string toDelete, boolean;
    cout << "DELETE MEMBER" << endl;
    cout << "------------------------------------" << endl;
    cout << "Enter name of member you wish to delete: ";
    cin >> toDelete;
    pos = searchMember(toDelete);
    if (pos == -1)
    {
        cout << "The member you wish to delete is not in data base!";
        return;
    }
    else
    {
        cout << "The member you wish to delete is found in database!" << endl;
    booleancheck:
        cout << "Do you really wish to delete " << toDelete << "?(y/n): " << endl;
        cin >> boolean;
        if (boolean == "n")
        {
            return;
        }
        else if (boolean == "y")
        {
            del(pos);
            cout << "Member deleted!";
        }
        else
        {
            goto booleancheck;
        }
    }
}

class stops
{
protected:
    memberslinked ml;
    string report_time;

public:
    string stop_name;
    void get_stop();
    void display_stop();
    void display_member_list();
};

void stops ::get_stop()
{
    cout << "Enter stop name : ";
    cin >> stop_name;
    cout << "Enter arrival time at the stop : ";
    cin >> report_time;
}

void stops ::display_stop()
{
    cout << setw(6) << setfill(' ') << stop_name << setw(10) << setfill(' ') << report_time << endl;
}

void stops::display_member_list()
{
    cout << "The members climbing on the stop are: " << endl;
    ml.printMemberList();
}

class arrayStops
{
public:
    int i;
    stops *st;
    int number_stops;
    int stops_count_1;
    int stops_count_2;
    int add_num_stops;
    string stop_search;
    int searchstop();
    void display_all_stops();
    void get_stops();
    void add_stops();
    void searchStopArr();
    arrayStops()
    {
        stops_count_1 = 0;
        stops_count_2 = 0;
    }
};

void arrayStops::get_stops()
{
    cout << "Please Enter number of stops to enter : ";
    cin >> number_stops;
    st = new stops[number_stops];
    for (i = 0; i < number_stops; i++)
    {
        (st + i)->get_stop();
        stops_count_1 += 1;
    }
    display_all_stops();
}

void arrayStops::add_stops()
{
    cout << "How many to add furthur : ";
    cin >> add_num_stops;
    for (i = stops_count_1; i < (number_stops + add_num_stops); i++)
    {
        (st + i)->get_stop();
        stops_count_2 += 1;
    }
    stops_count_1 += stops_count_2;
    display_all_stops();
}

void arrayStops::display_all_stops()
{
    cout << "\n"
         << "Stop Details";
    cout << setw(50) << setfill('-') << endl;
    cout << "\nStop name " << setw(11) << setfill(' ') << " Arrival time" << endl;
    for (i = 0; i < (number_stops + stops_count_1); i++)
    {
        (st + i)->display_stop();
    }
}

int arrayStops::searchstop()
{
    int k;
    for (i = 0; i < number_stops; i++)
    {
        if (stop_search == (st + i)->stop_name)
        {
            k = i;
        }
    }
    return k;
}

void arrayStops::searchStopArr()
{
    cout << "Enter stop to find : ";
    cin >> stop_search;
    int search = searchstop();
    cout << search + 1 << endl;
}

class routes
{
protected:
    arrayStops as;
    string route_name;
    int seats;
    string driver_name;
    string bus_number;

public:
    void get_route();
    void display_route_details();
};

class arrayRoutes
{
protected:
    routes rt[10];
};

int main()
{
    // memberslinked m;
    // m.pushMember(3);
    // m.deleteMember();
    arrayStops a;
    a.get_stops();
    // a.add_stops();
    a.searchStopArr();
}

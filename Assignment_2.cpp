#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string auther;
    float price;
    int stock;

public:
    Book()
    {
        title = 'N/A';
        auther = 'N/A';
        price = 0.0;
        stock = 0;
    }

    void getData()
    {
        cout << "Enter The Book Name: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Auther Name: ";
        getline(cin, auther);
        cout << "Enter The Price: $";
        cin >> price;
        cout << "Enter The Stock: ";
        cin >> stock;
    }

    void display(int index)
    {
        cout << "\nBook " << index + 1 << endl;
        cout << "Title  :" << title << endl;
        cout << "Auther :" << auther << endl;
        cout << "Price  : $" << price << endl;
        cout << "Stock  :" << stock << endl;
    }

    bool search(string t, string a)
    {
        return (t == title && a == auther);
    }

    void buyBook()
    {
        int qty;
        cout << "Enter number of copies to buy: ";
        cin >> qty;

        if (qty <= stock)
        {
            float total = qty * price;
            stock -= qty;
            cout << "Purches Successfully ! Amount: $" << total << endl;
        }
        else
        {
            cout << "Not Enough Stock Available: " << stock << endl;
        }
    }
};

int main()
{
    Book book[50];
    int count = 0;
    int choice;

    do
    {
        cout << "\n===========================\n";
        cout << "Welcome to Library System";
        cout << "\n===========================\n";
        cout << "1.Librerian.\n";
        cout << "2.Student.\n";
        cout << "3.Exit.\n";
        cout << "Enter your Choice......";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int opt;
            do
            {
                cout << "\nLibrerian Menu\n";
                cout << "1.Add Book.\n";
                cout << "2.View All Book.\n";
                cout << "3.Back to Menu.\n";
                cout << "Enter The Choice.....";
                cin >> opt;

                if (opt == 1)
                {
                    book[count].getData();
                    count++;
                    cout << "Book Added Successfully !\n";
                }
                else if (opt == 2)
                {
                    if (count == 0)
                    {
                        cout << "No Book in Inventrory !";
                    }
                    else
                    {
                        for (int i = 0; i < count; i++)
                        {
                            book[i].display(i);
                        }
                    }
                }
            } while (opt != 3);
            break;
        }
        case 2:
        {
            int opt;

            do
            {
                cout << "\nStudent menu\n";
                cout << "1.Search Book.\n";
                cout << "2.Buy Book.\n";
                cout << "3.Back to Meu.\n";
                cout << "Enter your choice ......";
                cin >> opt;

                if (opt == 1 || opt == 2)
                {
                    string t, a;
                    cin.ignore();
                    cout << "Enter Book Title: ";
                    getline(cin, t);
                    cout << "Enter Auther Name: ";
                    getline(cin, a);
                    bool found = false;

                    for (int j = 0; j < count; j++)
                    {
                        if (book[j].search(t, a))
                        {
                            book[j].display(j);
                            found = true;

                            if (opt == 2)
                            {
                                book[j].buyBook();
                            }
                            break;
                        }
                    }
                    if (!found)
                    {
                        cout << "Book Not Found.";
                    }
                }
            } while (opt != 3);
            break;
        }

        case 3:
            cout<<"Thank you for using the Library System. Goodbye!\n";
            break;

        default:
            cout<<"Invalid Choice. Please Try Again.\n";
    }    
  }while(choice!=3);

 return 0;
} 
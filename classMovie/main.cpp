// #include <ctime>
// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// class Movies
// {
// public:
//     void addMovie();
//     void movieInfo();

// private:
//     string film;    // The name of the movie
//     string director;    // The name of the director
//     string genre;   // In what genre the movie falls in.. ex romance, action, drama

//     int day, month, year;
// };

// time_t t = time(0);
// tm *local_time = localtime(&t);

// int n;

// void Movies::addMovie()
// {
//     // cin.clear();
//     // cin.sync();

//     cin.ignore();
//     cout << "\nPlease enter the information about the movie...\n"
//          << "\nWhat is the name of the movie? ";
//     getline(cin, film);

//     cout << "\nWho is the director of the movie? ";
//     getline(cin, director);

//     cout << "\nIn what genre the movie falls in?..(ex romance, action, etc..) ";
//     cin >> genre;

//     do
//     {
//         n = 0;
//         cout << "\nWhen was/is the released date of the movie?(mm dd yyyy) ";
//         cin >> month >> day >> year;

//         if ((month<1 || month> 12 || to_string(month).length() < 1 || to_string(month).length() > 2) || (day<1 || day> 31 || to_string(day).length() < 1 || to_string(day).length() > 2) || (year < 1888 || (year > 1938 + local_time->tm_year) || to_string(year).length() != 4))
//         {
//             cout << "Please enter a valid date!\n\n";
//             n = 1;
//         }
//     } while (n == 1);
// }
// void Movies :: movieInfo()
// {

//     cout << "\nFilm: " << film
//          << "\nDirector: " << director
//          << "\nGenre: " << genre
//          << "\nRelease(d) date: " << month << '/' << day << '/' << year;
// }
// int main()
// {
//     // Movies mov;
//     vector<Movies> mov;
//     vector<Movies> :: iterator it;

//     int choice;
//     do
//     {
//         cout << "\n\n-------------------------------------"
//              << "\nWelcome to the movie theater...\nPlease select one of the options below\n "
//              << "-------------------------------------"
//              << "\n1. Display all movies playing in the theaters this week?"
//              << "\n2. Add a new movie to the list?"
//              << "\n3. Delete a movie from the list?"
//              << "\n4. Exit\nChoice: ";
//         cin >> choice;
//         //  cout << mov.size();
//         switch (choice)
//         {
//             case 1:
//             {
//                 if (mov.empty())
//                     cout << "\nThere is nothing to display because the list is empty!\n";
//                 else
//                 {
//                     for (int i = 0; i < mov.size(); i++)
//                     {
//                         cout << "\n-------------------------------------\nMovie " << i + 1 << ":\n";
//                         mov[i].movieInfo();
//                     }
//                 }
//                 break;
//             }

//             case 2:
//             {
//                 Movies *a = new Movies;
//                 a->addMovie();
//                 mov.push_back(*a);
//                 delete (a);
//                 break;
//             }

//             case 3:
//             {
//                 int num;
//                 if (mov.empty())
//                     cout << "\nThere is nothing to delete because the list is empty!";
//                 do
//                 {
//                     cout << "\nPlease enter the number of the movie would you like to remove: ";
//                     cin >> num;
//                     if (num > mov.size() || num < 0)
//                     {
//                         cout << "\nI couldn't find movie #" << num << " in the list, please try again!\n";
//                     }
//                 } while (num > mov.size() || num < 0);
//                 it = mov.begin() + num - 1;
//                 mov.erase(it);
//                 cout << "\nBook " << num << " is successfully deleted.";
//                 break;
//             }
//         }
//     } while (choice != 4);

//     cout << "\n\n";

//     return 0;
// }


#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

class Movies
{
public:
    void addMovie();
    void movieInfo();
private:
    string film;
    string director;
    string genre;

    int month, day, year;
};

time_t t = time(0);
tm *local_time = localtime(&t);
int n;

void Movies::addMovie()
{
    cin.ignore();
    cout << "\nPlease enter the information about the movie...\n"
         << "\nWhat is the name of the movie? ";
    getline(cin, film);

    cout << "\nWho is the director of the movie? ";
    getline(cin, director);

    cout << "\nIn what genre the movie falls in?.. (e.g. Romance, Action, Horror, etc...) ";
    getline(cin, genre);

    do
    {
        n = 0;
        cout << "When was/is the released date of the movie? (mm dd yyyy) ";
        cin >> month >> day >> year;
        if((month<0 || month>12 || to_string(month).length()<1 || to_string(month).length()>2) || (day<0 || day>31 || to_string(day).length()<1 || to_string(day).length()>2) || (year<1888 || (year>1938 + local_time->tm_year) || to_string(year).length()!=4))
        {
            cout << "Please enter a valid date!\n\n";
            n = 1;
        }
    }while(n == 1);
}

void Movies::movieInfo()
{
    cout << "\nFilm: " << film
         << "\nDirector: " << director
         << "\ngenre: " << genre
         << "\nRelease(d) date: " << month << "/" << day << "/" << year;
}

int main()
{
    vector<Movies> mov;
    vector<Movies>::iterator it;
    int choice;

    do
    {
        cout << "\n\n-------------------------------------------"
             << "\nWelcome to the movie theater...\nPlease select one of the options below\n"
             << "------------------------------------------------"
             << "\n1.Display all the movie playing in the theaters this week?"
             << "\n2.Add a new movie to list? "
             << "\n3.Remove a movie from list? "
             << "\n4.Exit\nChoice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                if(mov.empty())
                    cout << "\nThe list is empty! Try adding a movie\n";
                else
                {
                    for(int i = 0; i < mov.size(); i++){
                        cout << "\n------------------------------------\nMovie " << i+1 << ":\n";
                        mov[i].movieInfo();
                    }
                }
                break;
            }
            case 2:
            {
                Movies *a = new Movies();
                a->addMovie();
                mov.push_back(*a);
                delete(a);
                break;
            }
            case 3:
            {
                int num;
                if(mov.empty())
                    cout << "There is nothing to remove because the list is empty!\n";
                else
                {
                    do
                    {
                        cout << "\nPlease enter the number of the movie you would like to remove: ";
                        cin >> num;
                        if(num > mov.size() || num < 0){
                            cout << "\nI couldn't find movie #" << num << " in the list, please try again!\n";
                        }
                    } while (num > mov.size() || num < 0);
                    it = mov.begin();
                    mov.erase(it); 
                    cout << "\nMovie " << num << " is successfully deleted.";
                }
                break;
            }
        }
    }while(choice!=4);

    cout << endl;
    return 0;
}
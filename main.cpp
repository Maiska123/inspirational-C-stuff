#include "test.hh"
#include "classes.hh"

int main()
{
    std::string x, y;

    std::cout << "give me two names: ";
    std::cin >> x >> y;
    
    User user1(x);
    User user2(y);
    User user3;

    user1.printInfo();
    user2.printInfo();
    user3.printInfo();

    std::cout << "lisätään osallistujat palaveriin..." << std::endl;
    
    std::vector<User*> attendees = {&user1, &user2, &user3};

    Meeting meeting("palaveri",attendees);

    std::cout << "palaverin nimi: " << meeting.name_ << std::endl;

    std::cout << "palaveriin osallistuu: " << meeting.getAttendeeCount() << " henkilöä. " << std::endl << "Henkilöt: " << meeting.getAttendees() << std::endl;
    
    Status userState = Pending;

    std::cout << "users state: " << userState << std::endl;

    // test1();
    // test2();

    // templates
    // classes
    // threading
    // threadpool
    // threadworkers

    return 0;
}
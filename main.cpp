#include "test.hh"
#include "classes.hh"

int main()
{
    std::string x, y;

    std::cout << "give me two names: ";
    std::cin >> x >> y;
    
    std::cout << std::endl;

    User user1(x);
    User user2(y);
    User user3;

    user1.printInfo();
    user2.printInfo();
    user3.printInfo();

    std::cout << "lisätään osallistujat palaveriin..." << std::endl;
    
    std::vector<User*> attendees = {&user1, &user2, &user3};

    Meeting meeting("palaveri",attendees);

    meeting.attendees_.find(&user1)->second = Status::Approved;
    meeting.attendees_.find(&user2)->second = Status::Cancelled;

    meeting.printMeetingInfo();


    user1.points(Modifier::add, 1000);
    user2.points(Modifier::deduct, 10); // watch this bitches


    user1.printInfo();
    user2.printInfo();
    user3.printInfo();

    return 0;
}



    // Status userState = Pending;

    // std::cout << "users state: " << userState << std::endl;

    // test1();
    // test2();

    // templates
    // classes
    // threading
    // threadpool
    // threadworkers
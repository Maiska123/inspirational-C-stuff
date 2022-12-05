#include "classes.hh"
#include <algorithm>
#include <sstream>

    void Meeting::printMeetingInfo() const {
        std::cout << "\nPalaverin nimi: " << name_ << std::endl;

        std::cout << "\nPalaveriin osallistuu: " << getAttendeeCount() << " henkilöä. " << std::endl << "Henkilöt: " << getAttendees() << std::endl << std::endl;
    }

    unsigned int Meeting::getAttendeeCount() const {
        return Meeting::attendees_.size();
    }

    std::string Meeting::getAttendees() const {  
        std::stringstream attendeesString;

        std::for_each(Meeting::attendees_.begin(), 
                        Meeting::attendees_.end(), 
                        [&](std::pair< User*, Status> user) {
                            attendeesString << "\n\t* ";

                            ((user.first)->getName()).length() == 0 
                            ? (attendeesString << "Mr.Nimetön" << " ") 
                            : (attendeesString << (user.first)->getName() << " ");

                            attendeesString << "tila: ";

                            switch((user.second)) {
                                case Status::Cancelled:
                                    attendeesString << "Ei osallistu";
                                    break;
                                case Status::Approved:
                                    attendeesString << "Osallistuu";
                                    break;
                                default:
                                    attendeesString << "Ei vastannut";
                                }
                            
                            attendeesString << std::endl;
                        });
        return attendeesString.str();
    }

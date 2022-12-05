#include "classes.hh"
#include <algorithm>
#include <sstream>

    unsigned int Meeting::getAttendeeCount() const {
        return Meeting::attendees_.size();
    }

    std::string Meeting::getAttendees() const {  
        std::stringstream attendeesString;

        std::for_each(Meeting::attendees_.begin(), 
                        Meeting::attendees_.end(), 
                        [&](std::pair< User*, Status> user) {
                            ((user.first)->getName()).length() == 0 
                            ? (attendeesString << "Mr.Nimetön" << " ") 
                            : (attendeesString << (user.first)->getName() << " ");
                        });
        return attendeesString.str();
    }

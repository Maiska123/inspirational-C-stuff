#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>


#ifndef CLASSES_HH
#define CLASSES_HH


// using Data = std::unordered_map<std::string, User*>;
// Data meetings_;

class User {

    private:
        std::string name_;
        uint32_t score_ = 0;
    
    public:
        User(std::string name);
        User()=default; // makes "User user1;" possible!
        ~User();
        std::string getName() const;
        void printInfo() const;

};


struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

enum Status {
    Pending,
    Approved,
    Cancelled
};


struct Meeting {


    Meeting(std::string name, std::vector<User*> users):name_(name){
        auto addToAttendees = [this](User* n) {
            auto m = std::pair(n,Status::Pending);
            attendees_.insert(m); 
            //  for(auto it = attendees_.begin(); it!= attendees_.end();){}
             };
        std::for_each(users.begin(), users.end(), addToAttendees);
    };
    std::string name_;
    std::unordered_map<User*, Status> attendees_; 

    unsigned int getAttendeeCount() const;
    std::string getAttendees() const;
};

enum class FileError {
    notfound,
    ok
};

enum class NetworkError {
    disconnected,
    ok
};

#endif // CLASSES_HH
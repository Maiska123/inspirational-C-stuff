#pragma once

#ifndef CLASSES_HH
#define CLASSES_HH

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>



// using Data = std::unordered_map<std::string, User*>;
// Data meetings_;

enum Modifier {
    add,
    deduct
};

// template function
template <class T>
T betterOne(T const& t1, T const& t2){
    return t1 < t2 ? t2 : t1;
}

// template class
template <class T>
class Accum{
    private:
        T total;
    public:
        Accum(T start): total(start) {};
        T operator += (T const& t)
            {return total = total + t;};
        T GetTotal() const {return total;}
};

Accum<int> integers(0);
Accum<std::string> strings("");



class User {

    private:
        std::string name_;
        uint32_t score_ = 0;
    
    // if you want to give private member access to some function
    // declare friend
    // friend bool operator<(int i, User const& u); 

    public:
        User(std::string name);
        User()=default; // makes "User user1;" possible!
        ~User();
        std::string getName() const;
        int getPoints() const;
        void printInfo() const;
        void points(Modifier modifier, uint32_t amount);

        bool operator<(User const& u) const;
        bool operator<(int i) const;

};
bool operator<(int i, User const& u);

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

    void printMeetingInfo() const;
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
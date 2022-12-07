#pragma once

#ifndef CLASSES_HH
#define CLASSES_HH

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>



// using Data = std::unordered_map<std::wstring, User*>;
// Data meetings_;

enum Modifier {
    add,
    deduct
};

class User {

    private:
        std::wstring name_;
        uint32_t score_ = 0;
    
    // if you want to give private member access to some function
    // declare friend
    // friend bool operator<(int i, User const& u); 

    public:
        User(std::wstring name);
        User()=default; // makes "User user1;" possible!
        ~User();
        std::wstring getName() const;
        uint32_t getPoints() const;
        void printInfo() const;
        void points(Modifier modifier, uint32_t amount);

        bool operator<(User const& u) const;
        bool operator<(uint32_t i) const;

};
bool operator<(uint32_t i, User const& u);


// template function
template <class T>
T betterOne(T const& t1, T const& t2){
    return t1 < t2 ? t2 : t1;
}// template class
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

// template specialization
// template class with specific class implements (eg. now increments User points)
template <>
class Accum<User>{
    private:
        uint32_t total;
    public:
        Accum(uint32_t start): total(start) {};
        uint32_t operator += (User const& t)
            {return total = total + t.getPoints();};
        uint32_t GetTotal() const {return total;}
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


    Meeting(std::wstring name, std::vector<User*> users):name_(name){
        auto addToAttendees = [this](User* n) {
            auto m = std::pair(n,Status::Pending);
            attendees_.insert(m); 
            //  for(auto it = attendees_.begin(); it!= attendees_.end();){}
             };
        std::for_each(users.begin(), users.end(), addToAttendees);
    };
    std::wstring name_;
    std::unordered_map<User*, Status> attendees_; 

    void printMeetingInfo() const;
    unsigned int getAttendeeCount() const;
    std::wstring getAttendees() const;
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
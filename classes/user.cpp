#include "classes.hh"
#include <algorithm>
// using namespace User;

    User::User(std::wstring name)
    :name_(name)
    {
        // empty constructor
    }

    User::~User(){
        // for each meeting delete me
    }

    std::wstring User::getName() const{
        return User::name_;
    }

    uint32_t User::getPoints() const{
        return User::score_;
    }


    void User::printInfo() const{
        std::wcout << "User info: " << std::endl;
        std::wcout << "Name: " << User::getName() << "\tScore: "<< User::score_ << std::endl;
        std::wcout << std::endl;
    }

    void User::points(Modifier modifier, uint32_t amount){
        switch(modifier){
            case Modifier::add:
                score_ += amount;
                break;
            case Modifier::deduct:
                if (amount > score_){
                    score_ -= score_;
                    break;
                }
                score_ -= amount;  
                break;
            default:
                break;
        }
    }
    
    bool User::operator<(User const& u) const {
        return score_ < u.score_;
    }

    bool User::operator<(uint32_t i) const {
        return score_ < i;
    }

    bool operator<(uint32_t i, User const& u){
        return i < u.getPoints();
    }


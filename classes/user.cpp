#include "classes.hh"
#include <algorithm>
// using namespace User;

    User::User(std::string name)
    :name_(name)
    {
        // empty constructor
    }

    User::~User(){
        // for each meeting delete me
    }

    std::string User::getName() const{
        return User::name_;
    }

    int User::getPoints() const{
        return User::score_;
    }


    void User::printInfo() const{
        std::cout << "User info: " << std::endl;
        std::cout << "Name: " << User::getName() << "\tScore: "<< User::score_ << std::endl;
        std::cout << std::endl;
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

    bool User::operator<(int i) const {
        return score_ < i;
    }

    bool operator<(int i, User const& u){
        return i < u.getPoints();
    }


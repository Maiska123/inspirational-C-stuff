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

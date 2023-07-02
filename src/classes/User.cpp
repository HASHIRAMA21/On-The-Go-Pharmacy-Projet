//
// Created by krohn on 4/20/23.
//

#include "../headers/User.h"

namespace baune {

    User::User(const std::string &firstName, const std::string &lastName, const std::string &email,
               const std::string &phoneNumber, const std::string &password, const std::list<Prescription> &prescription,
               const std::list<Product> &product, const Shopping_cart &shoppingCart) : first_name(firstName),
                                                                                       last_name(lastName),
                                                                                       email(email),
                                                                                       phone_number(phoneNumber),
                                                                                       password(password),
                                                                                       prescription(prescription),
                                                                                       product(product),
                                                                                       shopping_cart(shoppingCart) {}

    User::User() {}

    const std::string &User::getFirstName() const {
        return first_name;
    }

    void User::setFirstName(const std::string &firstName) {
        first_name = firstName;
    }

    const std::string &User::getLastName() const {
        return last_name;
    }

    void User::setLastName(const std::string &lastName) {
        last_name = lastName;
    }

    const std::string &User::getEmail() const {
        return email;
    }

    void User::setEmail(const std::string &email) {
        User::email = email;
    }

    const std::string &User::getPhoneNumber() const {
        return phone_number;
    }

    void User::setPhoneNumber(const std::string &phoneNumber) {
        phone_number = phoneNumber;
    }

    const std::string &User::getPassword() const {
        return password;
    }

    void User::setPassword(const std::string &password) {
        User::password = password;
    }

    const std::list<Prescription> &User::getPrescription() const {
        return prescription;
    }

    void User::setPrescription(const std::list<Prescription> &prescription) {
        User::prescription = prescription;
    }

    const std::list<Product> &User::getProduct() const {
        return product;
    }

    void User::setProduct(const std::list<Product> &product) {
        User::product = product;
    }

    const Shopping_cart &User::getShoppingCart() const {
        return shopping_cart;
    }

    void User::setShoppingCart(const Shopping_cart &shoppingCart) {
        shopping_cart = shoppingCart;
    }

    std::ostream &operator<<(std::ostream &os, const User &user) {
        os << "first_name: " << user.first_name << " last_name: " << user.last_name << " email: " << user.email
           << " phone_number: " << user.phone_number << " password: " << user.password << " prescription: "
           << user.prescription << " product: " << user.product << " shopping_cart: " << user.shopping_cart;
        return os;
    }

    bool User::operator<(const User &rhs) const {
        if (first_name < rhs.first_name)
            return true;
        if (rhs.first_name < first_name)
            return false;
        if (last_name < rhs.last_name)
            return true;
        if (rhs.last_name < last_name)
            return false;
        if (email < rhs.email)
            return true;
        if (rhs.email < email)
            return false;
        if (phone_number < rhs.phone_number)
            return true;
        if (rhs.phone_number < phone_number)
            return false;
        if (password < rhs.password)
            return true;
        if (rhs.password < password)
            return false;
        if (prescription < rhs.prescription)
            return true;
        if (rhs.prescription < prescription)
            return false;
        if (product < rhs.product)
            return true;
        if (rhs.product < product)
            return false;
        return shopping_cart < rhs.shopping_cart;
    }

    bool User::operator>(const User &rhs) const {
        return rhs < *this;
    }

    bool User::operator<=(const User &rhs) const {
        return !(rhs < *this);
    }

    bool User::operator>=(const User &rhs) const {
        return !(*this < rhs);
    }
} // baune
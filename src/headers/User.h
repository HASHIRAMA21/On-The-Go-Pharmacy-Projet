//
// Created by krohn on 4/20/23.
//

#ifndef BAUNE_PROJECT_USER_H
#define BAUNE_PROJECT_USER_H

#include <string>
#include <ostream>
#include <list>
#include "Prescription.h"
#include "Product.h"
#include "Shopping_cart.h"

namespace baune {

    class User {

    private:
        std::string first_name;
        std::string last_name;
        std::string email;
        std::string phone_number;
        std::string password;
        User prescription;
        std::list<Product> product;
        Shopping_cart shopping_cart;

    public:
        typedef User* (*constructeur) (std::istream& prFlux);

        virtual ~User();

                User(const std::string &firstName, const std::string &lastName, const std::string &email,
             const std::string &phoneNumber, const std::string &password, const std::list<Prescription> &prescription,
             const std::list<Product> &product, const Shopping_cart &shoppingCart);

        User();

        const std::string &getFirstName() const;

        void setFirstName(const std::string &firstName);

        const std::string &getLastName() const;

        void setLastName(const std::string &lastName);

        const std::string &getEmail() const;

        void setEmail(const std::string &email);

        const std::string &getPhoneNumber() const;

        void setPhoneNumber(const std::string &phoneNumber);

        const std::string &getPassword() const;

        void setPassword(const std::string &password);

        const std::list<Prescription> &getPrescription() const;

        void setPrescription(const std::list<Prescription> &prescription);

        const std::list<Product> &getProduct() const;

        void setProduct(const std::list<Product> &product);

        const Shopping_cart &getShoppingCart() const;

        void setShoppingCart(const Shopping_cart &shoppingCart);

        friend std::ostream &operator<<(std::ostream &os, const User &user);

        bool operator<(const User &rhs) const;

        bool operator>(const User &rhs) const;

        bool operator<=(const User &rhs) const;

        bool operator>=(const User &rhs) const;

    };

} // baune

#endif //BAUNE_PROJECT_USER_H

//
// Created by krohn on 4/20/23.
//

#ifndef BAUNE_PROJECT_PRODUCT_H
#define BAUNE_PROJECT_PRODUCT_H

#include <string>
#include <list>
#include "User.h"
#include "Prescription.h"

namespace baune {

    class Product {

    private:
        std::string product_name;
        int quantity;
        double price;
        std::string product_info;
        std::list<User> user;
        std::list<Prescription> prescription;
        std::list<Category> category;
    public:
        const std::string &getProductName() const;

        void setProductName(const std::string &productName);

        int getQuantity() const;

        void setQuantity(int quantity);

        double getPrice() const;

        void setPrice(double price);

        const std::string &getProductInfo() const;

        void setProductInfo(const std::string &productInfo);

        const std::list<User> &getUser() const;

        void setUser(const std::list<User> &user);

        const std::list<Prescription> &getPrescription() const;

        void setPrescription(const std::list<Prescription> &prescription);

        const std::list<Category> &getCategory() const;

        void setCategory(const std::list<Category> &category);

    public:
        Product();

    public:
        Product(const std::string &productName, int quantity, double price, const std::string &productInfo,
                const std::list<User> &user, const std::list<Prescription> &prescription,
                const std::list<Category> &category);


    };

} // baune

#endif //BAUNE_PROJECT_PRODUCT_H

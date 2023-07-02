//
// Created by krohn on 4/20/23.
//

#include "../headers/Product.h"
#include "../headers/Category.h"

namespace baune {
    Product::Product(const std::string &productName, int quantity, double price, const std::string &productInfo,
                     const std::list<User> &user, const std::list<Prescription> &prescription,
                     const std::list<Category> &category) : product_name(productName), quantity(quantity), price(price),
                                                            product_info(productInfo), user(user),
                                                            prescription(prescription), category(category) {}

    Product::Product() {}

    const std::string &Product::getProductName() const {
        return product_name;
    }

    void Product::setProductName(const std::string &productName) {
        product_name = productName;
    }

    int Product::getQuantity() const {
        return quantity;
    }

    void Product::setQuantity(int quantity) {
        Product::quantity = quantity;
    }

    double Product::getPrice() const {
        return price;
    }

    void Product::setPrice(double price) {
        Product::price = price;
    }

    const std::string &Product::getProductInfo() const {
        return product_info;
    }

    void Product::setProductInfo(const std::string &productInfo) {
        product_info = productInfo;
    }

    const std::list<User> &Product::getUser() const {
        return user;
    }

    void Product::setUser(const std::list<User> &user) {
        Product::user = user;
    }

    const std::list<Prescription> &Product::getPrescription() const {
        return prescription;
    }

    void Product::setPrescription(const std::list<Prescription> &prescription) {
        Product::prescription = prescription;
    }

    const std::list<Category> &Product::getCategory() const {
        return category;
    }

    void Product::setCategory(const std::list<Category> &category) {
        Product::category = category;
    }
} // baune
//
// Created by krohn on 4/20/23.
//

#include "../headers/Shopping_cart.h"

namespace baune {
    Shopping_cart::Shopping_cart(const User &user, double totalAmount, int numProduct, const Prescription &prescription)
            : user(user), total_amount(totalAmount), num_product(numProduct), prescription(prescription) {}

    Shopping_cart::Shopping_cart() {}

    Shopping_cart::~Shopping_cart() {

    }

    const User &Shopping_cart::getUser() const {
        return user;
    }

    void Shopping_cart::setUser(const User &user) {
        Shopping_cart::user = user;
    }

    double Shopping_cart::getTotalAmount() const {
        return total_amount;
    }

    void Shopping_cart::setTotalAmount(double totalAmount) {
        total_amount = totalAmount;
    }

    int Shopping_cart::getNumProduct() const {
        return num_product;
    }

    void Shopping_cart::setNumProduct(int numProduct) {
        num_product = numProduct;
    }

    const Prescription &Shopping_cart::getPrescription() const {
        return prescription;
    }

    void Shopping_cart::setPrescription(const Prescription &prescription) {
        Shopping_cart::prescription = prescription;
    }
} // baune
//
// Created by krohn on 4/20/23.
//

#ifndef BAUNE_PROJECT_SHOPPING_CART_H
#define BAUNE_PROJECT_SHOPPING_CART_H

#include "User.h"

namespace baune {

    class Shopping_cart {

    public:
        Shopping_cart();

    public:
        Shopping_cart(const User &user, double totalAmount, int numProduct, const Prescription &prescription);

    private:
        User user;
        double total_amount;
        int num_product;
        Prescription prescription;
    public:
        const User &getUser() const;

        void setUser(const User &user);

        double getTotalAmount() const;

        void setTotalAmount(double totalAmount);

        int getNumProduct() const;

        void setNumProduct(int numProduct);

        const Prescription &getPrescription() const;

        void setPrescription(const Prescription &prescription);

        virtual ~Shopping_cart();

    };
} // baune


#endif //BAUNE_PROJECT_SHOPPING_CART_H

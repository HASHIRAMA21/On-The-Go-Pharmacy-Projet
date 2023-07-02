//
// Created by krohn on 4/20/23.
//

#include "../headers/Admin.h"

namespace baune {
    Admin::Admin(int count) : count(count) {}

    Admin::~Admin() {

    }

    int Admin::getCount() const {
        return count;
    }

    void Admin::setCount(int count) {
        Admin::count = count;
    }
} // baune
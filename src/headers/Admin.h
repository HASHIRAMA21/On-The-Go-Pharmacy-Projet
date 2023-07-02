//
// Created by krohn on 4/20/23.
//

#ifndef BAUNE_PROJECT_ADMIN_H
#define BAUNE_PROJECT_ADMIN_H

#include "User.h"

namespace baune {

    class Admin : public User {

    private:
        int count;

    public:
        Admin(int count);

        virtual ~Admin();

        int getCount() const;

        void setCount(int count);


    };

} // baune

#endif //BAUNE_PROJECT_ADMIN_H

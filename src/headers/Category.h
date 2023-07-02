//
// Created by krohn on 4/20/23.
//

#ifndef BAUNE_PROJECT_CATEGORY_H
#define BAUNE_PROJECT_CATEGORY_H

#include <string>
#include <list>
#include "Product.h"

namespace baune {

    class Category {

    private:
        Category();

        Category(const std::string &categoryName, const std::string &categoryDescription);

        std::string category_name;
        std::string category_description;
        std::list<Product> product;

    public:
        Category(const std::string &categoryName, const std::string &categoryDescription,
                 const std::list<Product> &product);

        const std::string &getCategoryName() const;

        void setCategoryName(const std::string &categoryName);

        const std::string &getCategoryDescription() const;

        void setCategoryDescription(const std::string &categoryDescription);

        const std::list<Product> &getProduct() const;

        void setProduct(const std::list<Product> &product);
        

    };
};


#endif //BAUNE_PROJECT_CATEGORY_H

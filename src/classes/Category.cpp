//
// Created by krohn on 4/20/23.
//

#include "../headers/Category.h"

namespace baune {
    Category::Category(const std::string &categoryName, const std::string &categoryDescription) : category_name(
            categoryName), category_description(categoryDescription) {}

    Category::Category() {}

    Category::~Category() {

    }

    const std::string &Category::getCategoryName() const {
        return category_name;
    }

    void Category::setCategoryName(const std::string &categoryName) {
        category_name = categoryName;
    }

    const std::string &Category::getCategoryDescription() const {
        return category_description;
    }

    void Category::setCategoryDescription(const std::string &categoryDescription) {
        category_description = categoryDescription;
    }

    const std::string &Category::getCategoryName() const {
        return category_name;
    }

    Category::Category(const std::string &categoryName, const std::string &categoryDescription,
                       const std::list<Product> &product) : category_name(categoryName),
                                                            category_description(categoryDescription),
                                                            product(product) {}

    void Category::setCategoryName(const std::string &categoryName) {
        category_name = categoryName;
    }

    const std::string &Category::getCategoryDescription() const {
        return category_description;
    }

    void Category::setCategoryDescription(const std::string &categoryDescription) {
        category_description = categoryDescription;
    }

    const std::list<Product> &Category::getProduct() const {
        return product;
    }

    void Category::setProduct(const std::list<Product> &product) {
        Category::product = product;
    }
} // baune

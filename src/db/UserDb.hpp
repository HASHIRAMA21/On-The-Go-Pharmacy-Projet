
#ifndef EXAMPLE_POSTGRESQL_USERDB_HPP
#define EXAMPLE_POSTGRESQL_USERDB_HPP

#include "dto/UsersDto.h"
#include "dto/CategoryDto.h"
#include "dto/ProductDto.h"
#include "dto/UserDto.hpp"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen


/**
 * UserDb client definitions.
 */
class UserDb : public oatpp::orm::DbClient {
public:

  UserDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {

    oatpp::orm::SchemaMigration migration(executor);
    migration.addFile(2/* start from version 1 */, DATABASE_MIGRATIONS "/001_init.sql");
    // TODO - Add more migrations here.
    migration.addFile(2,DATABASE_MIGRATIONS "/airbnb.sql");
    //
    migration.migrate(); // <-- run migrations. This guy will throw on error.

    auto version = executor->getSchemaVersion();
    OATPP_LOGD("UserDb", "Migration - OK. Version=%d.", version);

  }

  QUERY(createUser,
        "INSERT INTO AppUser"
        "(id, username, email, password, role) VALUES "
        "(uuid_generate_v4(), :user.username, :user.email, :user.password, :user.role)"
        "RETURNING *;",
        PREPARE(true), // user prepared statement!
        PARAM(oatpp::Object<UserDto>, user))

  QUERY(updateUser,
        "UPDATE AppUser "
        "SET "
        " username=:user.username, "
        " email=:user.email, "
        " password=:user.password, "
        " role=:user.role "
        "WHERE "
        " id=:user.id "
        "RETURNING *;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::Object<UserDto>, user))

  QUERY(getUserById,
        "SELECT * FROM AppUser WHERE id=:id;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::String, id))

  QUERY(getAllUsers,
        "SELECT * FROM AppUser LIMIT :limit OFFSET :offset;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteUserById,
        "DELETE FROM AppUser WHERE id=:id;",
        PREPARE(true), //<-- user prepared statement!
        PARAM(oatpp::String, id))

    QUERY(createUsers,
          "INSERT INTO users"
          "(id, first_name, last_name, username, email,phone_number,password) VALUES "
          "(uuid_generate_v4(), :user.first_name, :user.last_name, :user.username, :user.email, :user.phone_number, :user.password)"
          "RETURNING *;",
          PREPARE(true), // user prepared statement!
          PARAM(oatpp::Object<UsersDto>, user))

    QUERY(getUsersById,
          "SELECT * FROM users WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(updateUsers,
          "UPDATE user "
          "SET "
          " username=:user.username, "
          " email=:user.email, "
          " password=:user.password, "
          " role=:user.role "
          "WHERE "
          " id=:user.id "
          "RETURNING *;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::Object<UsersDto>, user))

    QUERY(deleteUsersById,
          "DELETE FROM users WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getAllsUsers,
          "SELECT * FROM users LIMIT :limit OFFSET :offset;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))
          //category managment

    QUERY(createCategory,
          "INSERT INTO category"
          "(id, name, description) VALUES "
          "(uuid_generate_v4(), :category.name, :category.description)"
          "RETURNING *;",
          PREPARE(true), // user prepared statement!
          PARAM(oatpp::Object<CategoryDto>, category))

    QUERY(getCategoryById,
          "SELECT * FROM category WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))


    QUERY(deleteCategoryById,
          "DELETE FROM category WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getAllCategory,
          "SELECT * FROM category LIMIT :limit OFFSET :offset;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))

    QUERY(updateCategory,
          "UPDATE category "
          "SET "
          " name=:category.name, "
          " description=:category.description, "
          "WHERE "
          " id=:category.id "
          "RETURNING *;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::Object<CategoryDto>, category))


   //product managment
    QUERY(createProduct,
          "INSERT INTO products"
          "(id, product_name, quantity, price, product_info,prescription_need) VALUES "
          "(uuid_generate_v4(), :product.product_name, :product.quantity, :product.price, :product.product_info, :product.prescription_need)"
          "RETURNING *;",
          PREPARE(true), // user prepared statement!
          PARAM(oatpp::Object<ProductDto>, product))

    QUERY(updateProduct,
          "UPDATE products "
          "SET "
          " product_name=:product.product_name, "
          " quantity=:product.quantity, "
          " price=:product.price, "
          " product_info=:product.product_info,"
          " prescription_need=:product.prescription_need,"
          "WHERE "
          " id=:user.id "
          "RETURNING *;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::Object<ProductDto>, product))

    QUERY(getProductById,
          "SELECT * FROM products WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

    QUERY(getAllProducts,
          "SELECT * FROM products LIMIT :limit OFFSET :offset;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))

    QUERY(deleteProductById,
          "DELETE FROM products WHERE id=:id;",
          PREPARE(true), //<-- user prepared statement!
          PARAM(oatpp::String, id))

};







#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //EXAMPLE_POSTGRESQL_USERDB_HPP

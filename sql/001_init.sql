
CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

CREATE TABLE IF NOT EXISTS AppUser (
    id                      varchar (256) PRIMARY KEY,
    username                varchar (256) NOT NULL,
    email                   varchar (256) NOT NULL,
    password                varchar (256) NOT NULL,
    role                    varchar (256) NULL,
    CONSTRAINT              UK_APPUSER_USERNAME UNIQUE (username),
    CONSTRAINT              UK_APPUSER_EMAIL UNIQUE (email)
);

CREATE TABLE IF NOT EXISTS "prescriptions" (
                                 "id" bigint PRIMARY KEY,
                                 "patient_name" varchar,
                                 "doctor_name" varchar,
                                 "statut" bool,
                                 "user_id" bigint,
                                 "shopping_cart_id" bigint,
                                 "created_at" timestamp
);

CREATE TABLE IF NOT EXISTS "products" (
                            "id" bigint PRIMARY KEY,
                            "product_name" varchar,
                            "quantity" bigint,
                            "price" float,
                            "product_info" varchar
                             --"prescription_need" varchar
                            -- "created_at" timestamp
);

CREATE TABLE IF NOT EXISTS "users"  (
                         "id" bigint PRIMARY KEY,
                         "first_name" varchar,
                         "last_name" varchar,
                         "username" varchar,
                         "email" varchar,
                         "phone_number" varchar,
                         "password" varchar
                         -- "created_at" timestamp
);

CREATE TABLE IF NOT EXISTS "category" (
                            "id" bigint PRIMARY KEY,
                            "name" varchar,
                            "description" varchar
                           -- "created_at" timestamp
);

CREATE TABLE IF NOT EXISTS "shopping_cart" (
                                 "id" bigint PRIMARY KEY,
                                 "total_amount" float,
                                 "date" timestamp ,
                                 "id_product" bigint,
                                 "admin_id" bigint,
                                 "created_at" timestamp
);

ALTER TABLE "shopping_cart" ADD FOREIGN KEY ("admin_id") REFERENCES "users" ("id");

ALTER TABLE "prescriptions" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("id");

CREATE TABLE "prescriptions_products" (
                                          "prescriptions_id" bigint,
                                          "products_id" bigint,
                                          PRIMARY KEY ("prescriptions_id", "products_id")
);

ALTER TABLE "prescriptions_products" ADD FOREIGN KEY ("prescriptions_id") REFERENCES "prescriptions" ("id");

ALTER TABLE "prescriptions_products" ADD FOREIGN KEY ("products_id") REFERENCES "products" ("id");


CREATE TABLE "products_users" (
                                  "products_id" bigint,
                                  "users_id" bigint,
                                  PRIMARY KEY ("products_id", "users_id")
);

ALTER TABLE "products_users" ADD FOREIGN KEY ("products_id") REFERENCES "products" ("id");

ALTER TABLE "products_users" ADD FOREIGN KEY ("users_id") REFERENCES "users" ("id");


ALTER TABLE "prescriptions" ADD FOREIGN KEY ("shopping_cart_id") REFERENCES "shopping_cart" ("id");

CREATE TABLE "category_products" (
                                     "category_id" bigint,
                                     "products_id" bigint,
                                     PRIMARY KEY ("category_id", "products_id")
);

ALTER TABLE "category_products" ADD FOREIGN KEY ("category_id") REFERENCES "category" ("id");

ALTER TABLE "category_products" ADD FOREIGN KEY ("products_id") REFERENCES "products" ("id");



INSERT INTO AppUser
(id, username, email, password, role) VALUES (uuid_generate_v4(), 'admin', 'admin@domain.com', 'admins', 'ROLE_ADMIN');

//
// Created by krohn on 5/7/23.
//

#ifndef BAUNE_PROJECT_PRODUCTSERVICE_H
#define BAUNE_PROJECT_PRODUCTSERVICE_H


#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"
#include "db/UserDb.hpp"
#include "dto/StatusDto.hpp"
#include "dto/PageDto.hpp"

class ProductService {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<UserDb>, m_database); // Inject database component
public:

    oatpp::Object<ProductDto> createProduct(const oatpp::Object<ProductDto>& dto);
    oatpp::Object<ProductDto>  updateProduct(const oatpp::Object<ProductDto>& dto);
    oatpp::Object<ProductDto>  getProductById(const oatpp::String& id);
    oatpp::Object<PageDto<oatpp::Object<ProductDto>>> getAllProducts(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
    oatpp::Object<StatusDto> deleteProductById(const oatpp::String& id);

};


#endif //BAUNE_PROJECT_PRODUCTSERVICE_H

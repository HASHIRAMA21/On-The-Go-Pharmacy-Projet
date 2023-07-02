//
// Created by krohn on 5/7/23.
//

#ifndef BAUNE_PROJECT_PRODUCTCONCTROLLER_H
#define BAUNE_PROJECT_PRODUCTCONCTROLLER_H


#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
#include "service/ProductService.h"

/**
 * User REST controller.
 */
class ProductController : public oatpp::web::server::api::ApiController {
public:
    ProductController(const std::shared_ptr<ObjectMapper>& objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
    ProductService m_productService; // Create user service.
public:

    static std::shared_ptr<ProductController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    ){
        return std::make_shared<ProductController>(objectMapper);
    }

    ENDPOINT_INFO(createProduct) {
        info->summary = "Create new Product";

        info->addConsumes<Object<ProductDto>>("application/json");

        info->addResponse<Object<ProductDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "products", createProduct,
             BODY_DTO(Object<ProductDto>, productDto))
    {
        return createDtoResponse(Status::CODE_200, m_productService.createProduct(productDto));
    }


    ENDPOINT_INFO(putProduct) {
        info->summary = "Update Product by productId";

        info->addConsumes<Object<ProductDto>>("application/json");

        info->addResponse<Object<ProductDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["productId"].description = "Product Identifier";
    }
    ENDPOINT("PUT", "/api/product/{product}", putProduct,
             PATH(String, productId),
             BODY_DTO(Object<ProductDto>, productDto))
    {
        productDto->id = productId;
        return createDtoResponse(Status::CODE_200, m_productService.updateProduct(productDto));
    }


    ENDPOINT_INFO(getProductById) {
        info->summary = "Get one Product by prdductId";

        info->addResponse<Object<ProductDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["productId"].description = "Product Identifier";
    }
    ENDPOINT("GET", "/api/product/{productId}", getProductById,
             PATH(String, productId))
    {
        return createDtoResponse(Status::CODE_200, m_productService.getProductById(productId));
    }


    ENDPOINT_INFO(getAllProducts) {
        info->summary = "get all stored products";

        info->addResponse<oatpp::Object<ProductsPageDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "api/products/offset/{offset}/limit/{limit}", getAllProducts,
             PATH(UInt32, offset),
             PATH(UInt32, limit))
    {
        return createDtoResponse(Status::CODE_200, m_productService.getAllProducts(offset, limit));
    }


    ENDPOINT_INFO(deleteProduct) {
        info->summary = "Delete product by userId";

        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["productId"].description = "product Identifier";
    }
    ENDPOINT("DELETE", "/api/product/{productId}", deleteProduct,
             PATH(String, productId))
    {
        return createDtoResponse(Status::CODE_200, m_productService.deleteProductById(productId));
    }

};

#include OATPP_CODEGEN_BEGIN(ApiController) //<- End Codegen


#endif //BAUNE_PROJECT_PRODUCTCONCTROLLER_H

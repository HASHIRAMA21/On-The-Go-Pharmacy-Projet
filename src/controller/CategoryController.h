//
// Created by krohn on 5/7/23.
//

#ifndef BAUNE_PROJECT_CATEGORYCONTROLLER_H
#define BAUNE_PROJECT_CATEGORYCONTROLLER_H


#include "service/UserService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
#include "service/CategoryService.h"

/**
 * User REST controller.
 */
class CategoryController : public oatpp::web::server::api::ApiController {
public:
    CategoryController(const std::shared_ptr<ObjectMapper>& objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
    CategoryService m_categoryService; // Create user service.
public:

    static std::shared_ptr<CategoryController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    ){
        return std::make_shared<CategoryController>(objectMapper);
    }

    ENDPOINT_INFO(createCategory) {
        info->summary = "Create new Category";

        info->addConsumes<Object<CategoryDto>>("application/json");

        info->addResponse<Object<CategoryDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<CategoryDto>>(Status::CODE_500, "application/json");
        info->addResponse<Object<CategoryDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "users", createCategory,
             BODY_DTO(Object<CategoryDto>, categoryDto))
    {
        return createDtoResponse(Status::CODE_200, m_categoryService.createCategory(categoryDto));
    }


    ENDPOINT_INFO(putCategory) {
        info->summary = "Update Category by categoryId";

        info->addConsumes<Object<CategoryDto>>("application/json");

        info->addResponse<Object<CategoryDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<CategoryDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["userId"].description = "Category Identifier";
    }
    ENDPOINT("PUT", "/api/category/{categoryId}", putCategory,
             PATH(String, categoryId),
             BODY_DTO(Object<CategoryDto>, categoryDto))
    {
        categoryDto->id = categoryId;
        return createDtoResponse(Status::CODE_200, m_categoryService.updateCategory(categoryDto));
    }


    ENDPOINT_INFO(getCategoryById) {
        info->summary = "Get one Category by categoryId";

        info->addResponse<Object<CategoryDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<CategoryDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["categoryId"].description = "Category Identifier";
    }
    ENDPOINT("GET", "/api/category/{categoryId}", getCategoryById,
             PATH(String, categoryId))
    {
        return createDtoResponse(Status::CODE_200, m_categoryService.getCategoryById(categoryId));
    }


    ENDPOINT_INFO(getAllCategory) {
        info->summary = "get all stored category";

        info->addResponse<oatpp::Object<CategoryPageDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "/api/category/offset/{offset}/limit/{limit}", getAllCategory,
             PATH(UInt32, offset),
             PATH(UInt32, limit))
    {
        return createDtoResponse(Status::CODE_200, m_categoryService.getAllCategory(offset, limit));
    }


    ENDPOINT_INFO(deleteCategory) {
        info->summary = "Delete Category by categoryId";

        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["categoryId"].description = "Category Identifier";
    }
    ENDPOINT("DELETE", "api/category/{categoryId}", deleteCategory,
             PATH(String, categoryId))
    {
        return createDtoResponse(Status::CODE_200, m_categoryService.deleteCategoryById(categoryId));
    }

};

#include OATPP_CODEGEN_BEGIN(ApiController) //<- End Codegen

#endif //BAUNE_PROJECT_CATEGORYCONTROLLER_H

#include "User.h"
#include <cppcms/service.h>  
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_response.h>

User::User(cppcms::service &srv) : cppcms::application(srv)
{
    dispatcher().assign("", &User::getUser, this);
    mapper().assign("");

    dispatcher().assign("/(\\d+)", &User::getUserById, this, 1);
    mapper().assign("/{1}");
}

void User::getUser()
{
    response().out() <<"get all users";
}

void User::getUserById(std::string id)
{
    response().out() <<"get user by id "<< id;
}
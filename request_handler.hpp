//
// request_handler.hpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2019 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HTTP_REQUEST_HANDLER_HPP
#define HTTP_REQUEST_HANDLER_HPP

#include <string>
#include <map> // for handler map
#include <functional>

namespace http
{
namespace server
{

struct reply;
struct request;

/// The common handler for all incoming requests.
class request_handler
{
public:
    request_handler(const request_handler&) = delete;
    request_handler& operator=(const request_handler&) = delete;

    /// Construct with a directory containing files to be served.
    explicit request_handler(const std::string& doc_root);

    /// Handle a request and produce a reply.
    void handle_request(const request& req, reply& rep);

    // add handler with callable functions, example:
    // add_handler("/", [](){ return std::string("hello world"); };
    void add_handler(std::string path, std::function<void(const request& req, reply& rep)> handler);

private:
    /// The directory containing the files to be served.
    std::string doc_root_;

    /// Perform URL-decoding on a string. Returns false if the encoding was
    /// invalid.
    static bool url_decode(const std::string& in, std::string& out);

    std::map<std::string, std::function<void(const request& req, reply& rep)>> dynamic_handlers_; // request with callbacks
};

} // namespace server
} // namespace http

#endif // HTTP_REQUEST_HANDLER_HPP

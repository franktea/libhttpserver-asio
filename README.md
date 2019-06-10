# libhttpserver-asio

A simple embedded http server lib modified from http server example source code of asio.

```
// Initialise the server.
http::server::server s("127.0.0.1", 8000, ".");

s.add_handler("/", [](const request& req, reply& rep)
{
    rep.set_content("hello from http server.", "text/plain");
});

// Run the server until stopped.
s.run();
```

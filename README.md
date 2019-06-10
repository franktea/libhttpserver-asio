# libhttpserver-asio

```
// Initialise the server.
http::server::server s(argv[1], argv[2], argv[3]);

s.add_handler("/", [](const request& req, reply& rep)
{
    rep.set_content("hello from http server.", "text/plain");
});

// Run the server until stopped.
s.run();
```

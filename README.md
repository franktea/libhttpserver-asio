# libhttpserver-asio

```
    // Initialise the server.
    http::server::server s("127.0.0.1", 8000, ".");

    s.add_handler("/", []()->std::string {
        return "hello from http server.";
    });

    // Run the server until stopped.
    s.run();
```

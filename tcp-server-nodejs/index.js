const net = require('net');

const server = net.createServer(socket => {
    console.log(`TCP Connection Established with ${socket.remoteAddress}:${socket.remotePort}`);
    socket.write("Hello Client");
    socket.on("data", data => {
        console.log("Received data", data.toString());
    });
});

server.listen(8800, "127.0.0.1");

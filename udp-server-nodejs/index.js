const dgram = require('dgram');

const socket = dgram.createSocket("udp4");
socket.bind(7000, "127.0.0.1");

socket.on("message", (msg, info) => {
    console.log(`server got a datagram ${msg}, from: ${info.address}:${info.port}`);
});

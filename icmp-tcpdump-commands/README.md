1. sudo tcpdump -n -i en0 icmp
2. ping example.com

For verbose use,
1. sudo tcpdump -n -v -i en0 icmp

How to capture packets from one src address?
- tcpdump -n -v -i en0 src 93.184.216.34

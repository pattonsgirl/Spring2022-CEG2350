# Quiz 6 Answer Key

1. Given the following Makefile contents:

```
hello: code.c
        gcc -E code.c

rainbow:
        gcc -Wall -o prog code.c

batman:
        ./prog
```

What make command will compile source code in code.c?

- Correct selection: **`make rainbow`** will compile `code.c` and name the compiled program `prog`
- `make` will run target `hello` since it is listed first (it will be the default target)
- `make hello` will **pre-compile** the code (at a basic level, remove comments, replace global varaibles references with the real value), not compile the code
- `make batman` will run `prog` if `prog` exists and is executable

2. T/F If c/c++ code is compiled in gcc on a Unix / Linux system, the compiled program will run in Windows.

- False. Code compiled in a Unix/Linux system (like our Ubuntu OS) is compiled as an ELF executable. C/C++ code compiled in Windows creates an exe exectuable. The Windows executable cannot run in Unix/Linux, and the Unix/Linux executable cannot run in Windows.
  - Note: this does assume you are given nothing else that would create an exeption, such as running a VM of one OS or the other and running the executable in the correct environment.

3. T/F A compiled Java program can run on any system with a JVM installed.

- True, and this is a major factor in the popularity of Java. Compiled Java bytecode can run on any system with a Java Virtual Machine installed to run the bytecode.

4. I want to disallow traffic coming from `google.com`. Where should a firewall rule be placed?

- Correct selection: **input / inbound / ingress**
  - this would block traffic coming from `google.com` from proceeding
- output / outbound / egress
  - this would prevent me from sending traffic to `google.com`
- forward
  - this would prevent traffic from `google.com` going to another device (think router style)

5. Given the following:

```
67.32.12.90/24
```

What is the subnet mask?

- /24 = 24 1's in the network portion, the remainder are 0's and the host portion of the subnet mask
  - 24 1's -> 11111111111111111111111100000000
  - Broken into 4 sets of 8 bits: 11111111.11111111.11111111.00000000
  - Translated to base 10: 255.255.255.0
- Correct selection: **255.255.255.0**
- 255.0.0.0 = 11111111.00000000.00000000.00000000 = /8 CIDR
- 255.255.0.0 = 11111111.11111111.00000000.00000000 = /16 CIDR
- 255.255.255.255 = 11111111.11111111.11111111.11111111 = /32 CIDR

6. Given the following:

```
67.32.12.90/24
```

What would be a valid IP of another host on the network that the NIC with IP `67.32.12.90` can communicate with?

- Subnet mask is 255.255.255.0 - first 24 bits are network bits, so address must begin with `67.32.12`
- Correct selection: `67.32.12.198`
- 72.89.32.90 - if subnet mask were 0.0.0.0 or CIDR /0
- 67.45.57.32 - if subnet mask were 255.0.0.0 or CIDR /8
- 67.32.90.122 - if subnet mask were 255.255.0.0 or CIDR /16

7. What port does SSH listen on given a system running a standard SSH server (such as the AWS instance you have been using throughout this course)?

- Correct selection: **22**
- 80 = default HTTP
- 443 = default HTTPS
- 8657309 is not actually a valid port. Port numbers range from 0 to 65535

8. \_\_\_\_ is responsible for translating hostnames (xkcd.com) to IP addresses (98.34.201.78)

- Correct selection: **DNS** Domain Name System
  - contains records (lists) of IP addresses and their registered corresponding hostnames
- NAT = Network Address Translation
  - performed at border gateways when packet is destined outside of a private subnet
  - typically used to translate a private internal IP address to a public IP for Internet communication. Return packets are translated back to the private IP to reach the correct device on the network
- DHCP = Dynmanic Host Configuration Protocol
  - allows hosts to obtain required TCP/IP configuration information from a DHCP server
- CIDR = Classless Inter-Domain Routing
  - subnet masks, but cooler
  - https://en.wikipedia.org/wiki/Classless_Inter-Domain_Routing

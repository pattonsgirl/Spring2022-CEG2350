# Lab 10

- [Lab Procedure](#Lab-Procedure)
- [Part 1 - Network Discovery](#Part-1---Network-Discovery)
- [Part 2 - Network Sniffing](#Part-2---Network-Sniffing)
- [Part 3 - Silly Server](#Part-3---Silly-Server)
- [Part 4 - Get Off My Port](#Part-4---Get-Off-My-Port)
- [Extra Credit - Message in a Bottle](#Extra-Credit---Message-in-a-Bottle)
- [Submission](#Submission)
- [Rubric](#Rubric)

## Lab Procedure

In your terminal, head to your repository (the folder named `ceg2350-yourgithubusername).

Create a new directory, `Lab10`

Create a file named `Lab10.md` [based on the template](LabTemplate.md).

- [Raw version of LabTemplate.md](https://raw.githubusercontent.com/pattonsgirl/Fall2021-CEG2350/main/Labs/Lab10/LabTemplate.md)

For each part below, you will be asked to do an action or answer a question. The actions are going to be commands - you will write the command you used as "answers" to the action requested. You are allowed to use multiple commands to solve an action. Just write down all that were needed to complete. Check with the TAs if you need clarification.

If you did something "wrong" make a note of it in your lab. These are learning experiences - writing them down will help you ask good questions later.

## Part 1 - Network Discovery

With your PC (not the AWS instance) connected to a network, identify the following information. I give you permission to use GUIs to dig it up, or the system terminal (don't use WSL2)

1. The hostname:
2. The IP address:
3. The MAC address using that IP address:
4. The subnet mask:
5. The gateway address:
6. The DHCP server address:
7. The DNS server address:

- Note: These results are going to look boring at home, but interesting on more complex networks, like Wright State. At home you likely have one device (your router) that is the first stop for most requests (DHCP, DNS, and gateway to route traffic to the next stop). On a complex network, you'll see these addresses getting distributed to different devices - there is a device to connect to to request an address and network information (DHCP server), another that is a first stop for DNS resolution, and maybe another that is the gateway address that packets outside the network are forwarded to to find their destination.

## Part 2 - Network Sniffing

Perform the following on your system in a terminal. I recommend Windows users go with WSL2.

- **Useful Commands: `traceroute`, `nmap`, `nc`**

1. For a website of your choice, identify the ip addresses of the first four hops that your packet is sent to.
2. For a website of your choice, scan for open ports. Identify which ports are open and what service is listening on the port.
3. Using `nmap` or `nc`, find out what version of SSH your AWS instance is running.
   - Hint: read your output, it is there to help you

- Resources: [nmap service and version detection](https://nmap.org/book/man-version-detection.html)

## Part 3 - Silly server

Perform the following on your AWS instance unless otherwise specified.

1. Install `python3` and `pip3`
2. In your GitHub repo folder, run `python3 -m http.server 4141` to start a minimal web server listening on port `4141`. Leave this running in it's own terminal.
   - you'll see why I have you go into a specific folder in a minute...
3. For your AWS instance, identify:
   - localhost IP:
   - instance IP:
   - instance public IP:
4. Your http server is serving content / listening on port `4141`. Give a description of what content is being served.
   - **Useful commands: `wget`, `curl`**
5. Use your browser on your system, and connect to the instance on the port your service is running on.
6. Peek back at the terminal running the server and answer the following

   - A successful request log:
   - A breakdown of the meaning:

7. This content is likely something you did not intend to put on the web. So here are where firewalls come into play. Using either `iptables` or the Security Groups on AWS, disallow this port `4141` from being public. Describe what step(s) you took and how you know the port is now blocked.
   - For `iptables`, DROP any public addresses 0.0.0.0/0 incoming to port `4141`
     - Do NOT save these rules. Just type them out - if something breaks, you can reboot and the iptables will be flushed. If you save, well, you could premanently lock yourself out of say, port 22 (SSH)
   - For Security Groups, if you read through the list of Inbound rules, you'll see one of these rules opens all the ports from any IP

## Part 4 - Get Off My Port

A common issue is that a port you want to listen on (run a service on) is already taken by another service / process. Let's use one (of many) ways to find out what service is running and how to kill it. Perform the following on your AWS instance unless otherwise specified.

1. Run `python3 -m http.server 4141` to start a minimal web server listening on port `4141`. Leave this running in it's own terminal.
   - If this is still running from Part 2, you don't need to do it again - but you would get the exact error we are trying to hunt down! A service is already bound to that port, and you can't run something else there until the first one terminates
2. In another terminal, use `lsof` to show only the LISTEN[ing] services on the system.
   - Useful commands: `lsof`, `|`, `grep`
3. Identify the process ID and `kill` the process.

## Extra Credit - Message in a Bottle

Use `nc` (netcat) to create a simple chat server that listens and can be connected to on port 2222. You should be able to use the server's public ip to connect and chat.

Depending on what you did for part 3, your firewall may need patching to open this port externally.

Proof is documentation on what commands create, how to connect, and any changes you needed to make to your firewall.

Hint: [Netcat nc command with examples](https://linuxize.com/post/netcat-nc-command-with-examples/)

## Submission

1. Verify that your GitHub repo has a `Lab10` folder with at minimum:

   - `Lab10.md`

2. In the Pilot Dropbox, paste the URL to the `Lab10` folder in your GitHub repo
   - URL should look like: https://github.com/WSU-kduncan/ceg2350-YOURGITHUBUSERNAME/tree/main/Lab10

## Rubric

- 1 pt per question (20 pts total)

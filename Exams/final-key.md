# Spring 2022 CEG 2350 Final Exam Key

1. Which file contains a list of public keys used for SSH authentication for the given user on the system?

- Correct selection: `~/.ssh/authorized_keys`
  - to authenticate from a client machine to a remote server using SSH, the client machine needs the private key file, but the remote SSH server (what you are connecting to) needs the public key stored in the user's `~/.ssh/authorized_keys`
  - Example: I am going to connect to a remote machine using SSH via the username `bob`. On the remote machine, there needs to exist the user `bob`. In `bob`'s `home` directory, there must exist a `.ssh` folder with an `authorized_keys` file. In that file needs to be a public key. Locally (on the client machine) I need a private key that pairs with that public key in order to authenticate as `bob`.
- `~/.ssh/known_hosts` - list of server keys that have been seen before
- `~/.ssh/config` - configuration file for SSH connections. Contains information such as which private key to use for authentication, which username to use for the connection (note, this username must be the one that exists on the remote system), and what the hostname of the system is (ip address or URL)
- `~/.ssh/ed_25519` - when an ssh key pair is generated using `-t ed25519` and defaults are used, a private key of this filename will be generated.

2. Assume my local machine has made a successful sftp connection to a remote machine with IP 152.45.27.90  
   A file named shareme.txt in the folder /share on the remote machine needs to be copied to my local machine in the folder /home/user/demos/  
   Using sftp, which command will download the file from the remote machine and place it in the specified local folder?

- `get` downloads a file from remote to local
- `put` uploads a file from local to remote
- the order of arguments matters here
- Correct selection: `get /share/shareme.txt /home/user/demos/`

3. Write a command to extract the contents of `foo.tar.gz`

- `tar` options to note:
  - `x` = extract
  - `f` = filename to extract from
  - `z` = uses gz compression (other compression types would use a different letter)
  - `v` = verbose (show output as command runs)`
- `tar -zxvf foo.tar.gz` OR `tar -xf foo.tar.gz`
- would uncompress, but not extract the tar archive

  - `gunzip tar.gz`
  - `gzip -d foo.tar.gz`

4. My machine is wirelessly connected to a private subnet. How does is traffic sent and received from outside the subnet?  
   Put differently, if I am on a private subnet with IP 10.0.0.89/24, how is traffic sent and received from a website, like https://pilot.wright.edu?  
   Use NAT in your answer.

- Student answer 1:
  - My packet goes to the gateway
  - The gateway sends the packet to border router
  - Border router rewrites packet so that the IP address says it's from the public IP address of the router rather than my computer's IP address (this is the NAT, network address translation)
  - Packet comes back, border router sends it back the the original IP address
  - Packet goes through the same series of gateways in reverse
  - I see my grades [in Pilot]
- Student answer 2:
  - Private subnet data are handled using NAT (network address translation) which essentially rewrites the source and/or destination address of IP packets when they pass through a router or firewall. The NAT process works as follows:
  - Computers within the local network send IP packets w/ the recipient's TCP/IP socket (which are used for connections between computers, and include ip address and host port data) to a router, and the router replaces the sender's socket with an unused socket of its own. Replies to the sender socket are forwarded to the appropriate computer in the local net, replacing the recipient address (router socket) w/ the client's socket.
  - This way, the private subnet address replaces all sender addresses for packets on the local subnet (and this can be set up as a router rule). This can be very useful for security rules and traffic control in general.
- Student answer 3:
  - Your machine in the private subnet is unable to receive traffic from the internet directly, but by using the NAT device your machine could then send and receive internet traffic (e.g. https://pilot.wright.edu) in the public subnet.
- Student answer 4:
  - Your browser requests a connection to a website. It uses DNS to find the website's IP, which is not part of the local subnet. Because it's outside its subnet, it turns to it's configured gateway.
  - The gateway then sends packets to the website's IP (which may involve other gateways). Because this involves communication between a private and public IPs, NAT is involved. NAT remembers which private IP and port was used to initiate communication.
  - The website server responds similarly, communicating back to the originating public IP and port. NAT sees this incoming connection, remembers the private IP and port that initiated communication, and sends those packets to your local machine.

5. Service logs show IP address 28.45.32.10 is being bothersome. They have been trying username / password pairs to attempt to log in via SSH, they've been sending non-stop requests to my webserver on ports 80 and 443 and are generally causing a headache.  
   Which iptables rule would best block traffic from the offending IP address?

- `iptables` needs to block incoming traffic, so this will be an `INPUT` rule.
- The source is `28.45.32.10` - but only that IP is causing trouble.
- SSH is port 22, HTTP is port 80, HTTPS is port 443, but all ports need to be dropped, not just one of these
- Correct selection: `iptables -A INPUT -s 28.45.32.10/32 -j DROP`

  - `/32` = subnet mask `255.255.255.255`, which means the only host ip in the subnet is `28.45.32.10`

- Incorrect things:

  - `/0` = subnet mask `0.0.0.0`, which means all ips are in the subnet (no network bits are set). This would `DROP` **all** incoming traffic from anywhere
  - An `OUTPUT` rule would mean the server could not talk **out** to IP `28.45.32.10`. Packets going to, not coming from, that IP would be dropped
  - `iptables -A INPUT-s 28.45.32.10/32 -p tcp --destination-port 8080 -j DROP` - this rule only drops if IP `28.45.32.10` tries to connect to port 8080, which is not among there ports they are bothering - they could continue to try SSH, HTTP, and HTTPS

6. Write a snippet of a Makefile per the details given:  
   Runs with: make myday  
   Depends on code.c  
   Compiles code.c into a program named spring

```
# target = myday: dependency = code.c
myday: code.c
    # gcc = compile c code with code.c
    # -o option to specify compiled executable name
    gcc -o spring code.c
```

7. A child process exits, but a parent process has not yet cleaned it up. What process status would the child process have?

- Correct selection: zombie
- orphan - child process still running (active) but original parent process has exited
- running - process is currently taking a turn on a CPU core
- sleeping - process is in a wait state for a turn with a CPU core

8. A installed program takes up space in RAM.

- False. A running **process** takes up space in RAM (memory). An installed program takes up disk space.

9. As part of the boot process, when a computer is turned on the operating system is loaded into RAM

- False. The operating system is a massive amount of files and executables - only some run at a given time. The **kernel** is loaded into RAM.

10. In a cloned git repository, you have created a new file.  
    Write the steps to synchronize your local changes with GitHub.

```
git add filename # file needs to be tracked by git
git commit # text editor will open, enter a message, save and quit
# OR git commit -m "message here"
# OR git commit -am "message here" - this one would add files that are already being tracked to the commit
git push # pushes local commits to GitHub
```

11. I have a new feature I would like to add to my project, which is in a git repository. In terms of git workflow, where should I develop the new feature?

- Correct selection: a new branch
  - if the feature is an add on to the project, a branch is the best choice. The `main` branch shuold be a working, stable version of the project. Branches should be used for development, patches, and expiriments, that may or may not be merged into `main` at a later time.

12. A pull in git is a combination of what?

- Correct selection: `git fetch` and `git merge`
  - Content is fetched from remote, then merged with local.
- `add` and `commit` - there is no combo command for this one, but you _could_ alias it... I wouldn't recommend it ;)
- `clone` and `checkout` - `clone` is when a remote repo exists, and you want to `clone` a copy to your local machine. `checkout` is to specify branches
- `commit` and `push` - there is no combo command for this one, but you _could_ alias it... I wouldn't recommend it ;)

13. I have a brand new disk. I plug it into my system as a secondary drive. What needs to be defined in order to use the disk?

- a partition table (to know where partitions are)
- a partition (one or more to define the bounds of the filesystem)
- a filesystem (to organize data stored on the disk)

14. When two files are hard linked, they will have the same \_\_\_\_

- Correct selection: inode
- The filename does not need to be the same, nor does the location

15. Currently the default filesystem optimized for use with Linux operating systems:

- Correct selection: ext4
- NTFS - Windows
- HFS / HFS+ - Apple
- FAT / exFAT - Windows once upon a time (still seen in USB drives)

16. Why is it best practice to eject / unmount a filesystem?

- TLDR: changes may be pending. Unplugging without using "eject" or "unmount" can cause problems with writing out data
- Changes are not written live / frequently. Using an open file as an example, changes to that file are not written as they are made - they are written in bulk as more of a new file state. When a filesystem is unmounted, it is a safe way for the system to check that there are no current processes dependent on data on that filesystem and that data has finished being written out.
- The most common / frequent case is when using a USB drive. If the drive (filesystem) is not ejected, all data changes may not have been written. This can cause corruption of the individual file - in worse cases, it can cause corruption of the filesystem.

17. `ls -lah` shows a file with the following permissions:  
    `---------- 1 sally org 1.7K Jun 2 22:01 demo`  
    The user sally needs to read and write, member of org need to read and execute, and others on the system cannot use the file.  
    Write a command or commands to change the permissions as specified.

- numeric permissions:
  - read = 4
  - write = 2
  - execute = 1
  - add together the values of permissions to set for user group other in that order
- `chmod 650 demo` OR `chmod u+rw,g+rx,o-rwx demo` (or variation of)

18. A computer is hosting a website and has an SSH server installed for me to remotely connect and manage things via command line. Assume all things have been left in their default configurations and there is a public key on the system and I have a copy of the corresponding private key.  
    The firewall is configured to allow inbound traffic to ports 80 and 443.  
    Why can't I connect to the machine with SSH?

- Port 80 and 443 handle HTTP and HTTPS (respectively) traffic by default. Port 22 is the default port for SSH, and has not been listed as open in the inbound rules.

19. Forks of a process work within the process memory - resources for the process are shared. Threads are independent processes that report their status to the parent process, but otherwise have their own resources.

- False. Definitions are flipped

20. In virtual machines, the \_\_\_\_ manages shared resources, such as CPU, RAM, and disk operations, between the host OS and the guest OS(s).

- hypervisor

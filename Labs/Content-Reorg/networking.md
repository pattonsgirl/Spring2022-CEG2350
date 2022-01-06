# Lab 09 - NOT FINALIZED

## Lab Procedure

**For each step, include the command you used to perform the direction or answer the question posed.** If you did something "wrong" make a note of it in your lab. These are learning experiences - writing them down will help you ask good questions later.  
`ssh` in to your AWS environment. If you've forgotten your key, you'll need to provision a new stack in AWS Educate and create a new key.  
See [Remaking your AWS Educate environment](../../..) for instructions.

1. Go to the folder in which you cloned your Git repository for this course.
   - Path of `/home/ubuntu/spring2021-ceg2350-YOURGITHUBUSERNAME/` OR `/home/ubuntu/git/spring2021-ceg2350-YOURGITHUBUSERNAME/` depending on your setup
2. Create a directory called `Lab09`
   - Path of `/home/ubuntu/spring2021-ceg2350-YOURGITHUBUSERNAME/Lab09` OR `/home/ubuntu/git/spring2021-ceg2350-YOURGITHUBUSERNAME/Lab09` depending on your setup
3. In this directory, create a file called `README.md`
4. This `README.md` file is where you will put your answers to this lab. I recommend creating two connections to your Linux AWS so you can keep the `README.md` file open while you expirement with the lab.
   - At the top of the file please enter your personal details as follows:

```
Name: Your name
Email: Your email

```

## Part 1: [/insert AOL noises here/](https://www.youtube.com/watch?v=D1UY7eDRXrs) (15 pts)

For your local / personal system, identify the following information regarding your machine's network connection:

1. Network interface of your current connection
2. MAC address of the network interface
3. System hostname
4. IP Address (of your machine, not your address from your ISP)
5. Subnet mask
6. Gateway
7. Is your IP for your machine a public or private address?

On your AWS system, use `ifconfig` and `curl ipinfo.io` and read `/etc/hostname` to fill out the following:

8. Network interface
9. MAC address of the network interface
10. Hostname
11. IP address:
12. Subnet mask:
13. Gateway: 
14. AWS system public IP address:
15. Which of these IP addresses do you use to access your AWS system?

## Part 2: Snakes and Browsers (6 pts)

The Jupyter Notebook is an open-source web application that allows you to create and share documents that contain live code, equations, visualizations and narrative text. Uses include: data cleaning and transformation, numerical simulation, statistical modeling, data visualization, machine learning, and much more.  The programming language you would like to use in the notebook must be installed on the machine.  python and python3 are pre-installed on your AWS machines.  Jupyter, when run, will start up an HTTP connection that you can access via the web browser on the default port for jupyter, 8888.

1. Install the `jupyter` package. Write the command(s) you used. (1 pt)
2. Before we play with jupyter notebook, let's look at the local port.  Run `curl localhost:8888`.  Write what you see. (1 pt)
3. On your AWS system, start a `jupyter notebook` with the "no browser" option. Copy the output to your lab writeup. (1 pt)
   - Note: use `jupyter notebook --help`
4. Open a second terminal on your local system (do not `ssh` into the AWS system). 
5. Forward the port running `jupyter notebook` to your local system and open the notebook in your browser by following the steps below:
   - Use `ssh` to forward the port as follows, but replace `your_elastic_ip` with your AWS system's IP:
   - `ssh -N -f -i your_private_key -L localhost:8888:localhost:8888 ubuntu@your_elastic_ip`
   - In your browser, type the following URL: `localhost:8888`
   - Paste the token (see your output from step 2) to get in.
   - Write the token in your lab (1 pt)
6. Answer the following: (2 pts)
   - What flags are in the `ssh` command in Step 5, and what do they do?
      - Note: full list of flags is `-N`, `-f`, `-i`, and `-L`
   - What files are displayed in the browser (what system are they from)?

Note: you may want to take a moment and look at the extra credit once you have this part done.

**Resources**

- [Running a Jupyter Notebook](https://ljvmiranda921.github.io/notebook/2018/01/31/running-a-jupyter-notebook/)
- [Jupyter Notebook Tutorial - Go to Creating Your First Notebook](https://www.dataquest.io/blog/jupyter-notebook-tutorial/)
- [How To Use Bash's Job Control to Manage Foreground and Background Processes](https://www.digitalocean.com/community/tutorials/how-to-use-bash-s-job-control-to-manage-foreground-and-background-processes)
- [Understanding foreground and background Linux processes](https://linuxconfig.org/understanding-foreground-and-background-linux-processes)

## Part 3: Get Off my Port (3 pts)

A common issue is that a port you want to listen on (run a service on) is already taken by another service / process. Let’s learn how to discover that process pid.

1. Install the `http` package for python using `pip` (1 pt)
   - Write the command to install `pip` for `python`
   - Write the command to install `http` with `pip`
2. In one terminal, execute `python3 -m http.server 4444` to start a minimal web server listening on port 4444.
3. Craft a command that uses `lsof` to show only the LISTEN[ing] ports on the system. Write the command in your notes and paste the output of running the command. (1 pt)
   - Useful commands: `lsof`, `|`, `grep`
4. Find that process pid and terminate it by running `kill <PID>`. Write the command you used (1 pt)

## Part 4: The Git Part (1 pt)

1. Use `git` commands to `add`, `commit` and `push` the `Lab09` folder to GitHub.

## Extra Credit: Exploring Jupyter (2.5 pts)

- Create a jupyter notebook.  Have the notebook print "Hello World" when the notebook is run.  You will need to select python as the programming language.
   - [Hint](https://www.dataquest.io/blog/jupyter-notebook-tutorial/)
- Use `git` commands to `add`, `commit` and `push` your notebook to your `Lab09` folder to GitHub.

## Extra Credit: Good listening (2.5 pts)

- Echo a message over a port. When a connection is made on `localhost` or using the public IP, the message should print until the connection is terminated.
- Document your steps in your `README.md` file, along with any resources you used.
- Use `git` commands to `add`, `commit` and `push` to your `Lab09` folder to GitHub.

## Submission

In your GitHub repository, select the green `Code` button then select `Download ZIP`. Upload this zip file to the Pilot Dropbox.

In the `Comment` area in the Pilot Dropbox, copy URL / link to the repository corresponding to the project your are submitting.


### Credits:

Exercise based on https://missing.csail.mit.edu/2020/debugging-profiling/

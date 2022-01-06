# Lab 11

- [Lab Procedure](#Lab-Procedure)
- [Part 1 - SSH config](#Part-1---SSH-config)
- [Part 2 - tar it up](##Part-2---tar-it-up)
- [Part 3 - SFTP](##Part-3---SFTP)
- [Part 4 - Install miniconda](##Part-4---Install-miniconda)
- [Part 5 - New account - who this](##Part-5---New-account---who-this)
- [Extra Credit - Solving Conflict](##Extra-Credit---Solving-Conflict)
- [Submission](#Submission)
- [Rubric](#Rubric)

## Lab Procedure

In your terminal, head to your repository (the folder named `ceg2350-yourgithubusername).

Create a new directory, `Lab11`

Create a file named `Lab11.md` [based on the template](LabTemplate.md).

- [Raw version of LabTemplate.md](https://raw.githubusercontent.com/pattonsgirl/Fall2021-CEG2350/main/Labs/Lab11/LabTemplate.md)

For each part below, you will be asked to do an action or answer a question. The actions are going to be commands - you will write the command you used as "answers" to the action requested. You are allowed to use multiple commands to solve an action. Just write down all that were needed to complete. Check with the TAs if you need clarification.

If you did something "wrong" make a note of it in your lab. These are learning experiences - writing them down will help you ask good questions later.

## Part 1 - SSH config

The alias command I had you make so long ago, while inconvenient, needs an update. Go ahead and comment it out / remove it (maybe comment for now so you don't have to hunt down your ip to your instance again).

1. For an SSH `config` file, determine what values the following values hold:
   - Host
   - Hostname
   - User
   - Port
   - IdentityFile
2. Edit your `~/.ssh/config` with an entry that will let you SSH in to your AWS instance.
   - Copy / paste the entry into your lab notes as well
3. Write the command to `ssh` to your AWS instance now that your `config` file is operational.

- **Resources**
  - [Create SSH config file on linux / unix](https://www.cyberciti.biz/faq/create-ssh-config-file-on-linux-unix/)
  - [Using the SSH config file](https://linuxize.com/post/using-the-ssh-config-file/)

## Part 2 - tar it up

1. For the `tar` command, write what each option below does:
   - `-c`
   - `-v`
   - `-f`
   - `-z`
   - `-x`
2. On your AWS instance, find the size of your user's home directory.
3. tar and compress your user's home directory
4. What is the size of the tarball?

## Part 3 - SFTP

1. `sftp` on to your AWS instance.
2. Describe what the following options do:
   - `ls`
   - `lls`
   - `put`
   - `get`
3. Retrieve the tarball from your AWS instance and download it to your local system
4. Uncompress the tarball to a folder on your system, maybe `2350-archive`

## Part 4 - Install miniconda

Anaconda is a super popular python + common science and machine learning library bundle - it's also quite bulky since we aren't getting into the python deep end. We are going to use miniconda, a lightweight version - from there you could still get more libraries, but the initial install is way smaller.

- **Useful commands: `wget`**
- **_NOTE: please do NOT put the files for this part in your `Lab11` folder or anywhere near GitHub._**

1. On your AWS instance, download the miniconda installer to your user's home directory
   - [https://docs.conda.io/en/latest/miniconda.html](https://docs.conda.io/en/latest/miniconda.html)
2. Compare the sha256sum of your download to the `SHA256SUM` posted on the installation site

- Before installing, I want you to take a look (use `vim` or `less` or `more`) at the installation script (using `cat` will likely crash your current `ssh` connection). Note two things:
  1.  It starts off as a script: they have menus via f statements, a massive print statement of the license agreement, etc.
  2.  As you scroll down, you'll start seeing some really weired text that isn't "words"
      - _Here's why this is cool_: The installation file, it includes all needed base libraries to install Miniconda - offline. There are a chunk of base libraries (as you'll see during the install). These libraries have been tarred and gnu-zipped, the contents of which has been put at the bottom of the install script. This script includes (all in one file) a **tarball payload** so that it doesn't need to contact anything else on the network to finish the install, it just un-zips and un-tars the libraries. This is an example of tarball payload being used for good. This is a good moment to reflect of how tarball payloads could be snuck into an installer for less good.

3. Install miniconda. What does the ending output state you need to do next?
   - (Do the thing)
4. What has been added to `PATH`?
5. Check the current version of `python` when run with `python --version`.
   - You can also run `python` to start the python interpreter, which will report the version when the interpreter starts.
6. What does it mean to have `conda` activated (written in Linux at the start of the terminal line)?
7. How can you deactivate `conda`?

## Part 5 - New account - who this

- **Useful commands: `adduser`, `ssh-keygen`, `vim`, `ssh`**

1. On your AWS instance, create a new user
2. On your system, make a new key pair - you can use the default file name and location or a name of choice.
3. Put the public key of the key pair you just made in the new user's `~/.ssh/authorized_keys` file
4. From your system, `ssh` in to the AWS instance using the new user's username and the new private key.

## Extra Credit - Solving Conflict

For this extra credit, you are going to create and solve a merge conflict. I'm going to walk you into one way these are created - conflicts between branches. Conflicts can also occur when you `push` on a repo within a team - someone else on the team has also been making changes, and now you need to `pull`, figure out which changes stay, then tell `git` the conflict has been resolved.

### Setup the conflict

1. Confirm you are on the `main` branch of your repository.
2. Create a new file in your `Lab11` folder called `problem-child.txt`  
   Add some text to this file, just to get the party started.
3. `add`, `commit` and `push` the file, and confirm you see the file on GitHub.
4. Create and switch to a new branch called `improvements`
5. On the `improvements` branch, make some edits to `problem-child.txt`
6. `commit` and `push` you changes on your branch
7. Switch back to the `main` branch

- Don't `merge` yet - you'll ruin the expirement

9. Making sure you are on the `main` branch, make some edits to `problem-child.txt` and `commit` (`push` is optional)
10. `merge` the `improvements` branch with `main`

### Solve the conflict

1. Summarize the output from making the `merge` between the two branches.
2. Head to your file in the terminal. What do you see?
3. Resolve your conflict by modifying the file to no longer have the scary >>'s of doom and have the content you want to keep.
4. Run `status`. Summarize the output given and what you need to do next now that your file is in a happy state.
5. Do the things. Write the command(s) you used.

- **Resources:**
  - [Git - Basic Branching & Merging](https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging)
  - [Merge conflicts](https://www.atlassian.com/git/tutorials/using-branches/merge-conflicts)

## Submission

1. Verify that your GitHub repo has a `Lab11` folder with at minimum:

   - `Lab11.md`
   - `problem-child.txt` (if extra credit)

2. In the Pilot Dropbox, paste the URL to the `Lab11` folder in your GitHub repo
   - URL should look like: https://github.com/WSU-kduncan/ceg2350-YOURGITHUBUSERNAME/tree/main/Lab11

## Rubric

- Part 1 - 3 pts
- Part 2 - 4 pts
- Part 3 - 4 pts
- Part 4 - 7 pts
- Part 5 - 4 pts
- Extra Credit - 4 pts (20%)
